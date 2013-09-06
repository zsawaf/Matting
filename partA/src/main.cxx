// main.cxx : Defines the entry point for the console application.
//
// This is the top-level function of an example program that displays a VXL
// image on an fltk OpenGL panel

#include "VisCompUI.h"

// include various VXL include files needed for the application
#include "vxl_includes.h"

// code for loading VXL images
#include "file/load_image.h"

// code that implements the matting computations
#include "matting/matting.h"


// Routine for processing the command-line arguments (defined below)
// It returns false if the program should exit immediately after this
// function returns
bool process_args(int argc, char** argv, matting& M)
{
     // What follows is the argument definition for the program
     // in the format required for automatic processing with vul_arg
	 //
     // First, we create a list to contain the descriptions for
     // each argument.
	 //
	 vul_arg_info_list arg_list;

     // Then, for each argument in the program, we add a description
     // to the list with
     //
     // vul_arg<type> var_name(list_name,"flag","Description",default_val);
     //
     // where "flag" is the flag name for a given argument, for example
     // "-cmd" or "-im", "Description" is a small text description of
     // the argument, and default_value is what gets assigned to the
     // corresponding variable if the argument is not found in the command
     // line

     // we want to create a command with the following command-line options:
	 //     -no_gui                do not open any fltk windows (non-interactive mode)
	 //     -matting               run the matting algorithm (this is the only algorithm we have for now)
	 //     -mback1 <filename>     input image that will serve as Background 1
	 //     -mcomp1 <filename>                                    Composite 1
	 //     -mback2 <filename>                                    Background 2
	 //     -mcomp2 <filename>                                    Composite 2
	 //     -mobj   <filename>     output image that will hold computed Object image
	 //     -malpha <filename>                                          alpha image
	 //     -mnewback <filename>   input image that will be used for compositing
	 //     -mnewcomp <filename>   output of the compositing operation
	 //     -help                  a brief description of command-line options

	 vul_arg<bool> no_gui(arg_list, "-no_gui", "Do not open any fltk windows (non-interactive mode)", false);
	 vul_arg<bool> matting(arg_list, "-matting", "Run the matting algorithm", true);
     vul_arg<vcl_string> mback1(arg_list,"-mback1","Input image that will serve as Background 1","");
     vul_arg<vcl_string> mcomp1(arg_list,"-mcomp1","Input image that will serve as Composite 1","");
     vul_arg<vcl_string> mback2(arg_list,"-mback2","Input image that will serve as Background 2","");
     vul_arg<vcl_string> mcomp2(arg_list,"-mcomp2","Input image that will serve as Composite 2","");
     vul_arg<vcl_string> mobj(arg_list,"-mobj","Output Object image","");
     vul_arg<vcl_string> malpha(arg_list,"-malpha","Output Alpha matte","");
     vul_arg<vcl_string> mnewback(arg_list,"-mnewback","Input image that will serve as the new Background","");
     vul_arg<vcl_string> mnewcomp(arg_list,"-mnewcomp","Output image that will hold the new Composite","");
     
	 //vul_arg<vcl_string> cmd_name(arg_list,"-cmd","Command file name","");
     //vul_arg<int> thresh_val(arg_list,"-thresh","Threshold value",128);

     // Now set the switch for the help option

     arg_list.set_help_option("-help");

     // Once we've added the argument descriptions, we call on the
     // lists parse() function to do the work! the third argument
     // in the call to parse() is a boolean flag, when set to 1,
     // the parse function warns of un-recognized commands.

     arg_list.parse(argc,argv,(bool)1);

     // After this is done, the variables will contain either the
     // values entered by the user, or the defaults. One can check
     // whether a particular argument was found in the command
     // line by checking the appropriate variable's set() function
     // as shown below... 
     //
	 // Note that to access the VALUE of a given argument we use the
	 // notation arg_name()

	 // 
	 // first, we load the input images (if any)
	 //
	 
	 // write a string to standard error 
	 // note that vcl_endl just adds a linebreak to the stream

	 // did the user supply an image for Background 1?
	 if (mback1.set() == true) {
		 vcl_cerr << "process_args(): loading input image(s) ..." << vcl_endl;
		 // if so, load it into the matting data structure
		 M.set(M.Back1, load_image(mback1()));
	 }
	 if (mback2.set() == true)
		 M.set(M.Back2, load_image(mback2()));
	 if (mcomp1.set() == true)
		 M.set(M.Comp1, load_image(mcomp1()));
	 if (mcomp2.set() == true)
		 M.set(M.Comp2, load_image(mcomp2()));
	 if (mnewback.set() == true)
		 M.set(M.NewBack, load_image(mnewback()));
		
	 //
	 // if all input images are given,
	 // we run the matting algorithm automatically
	 //
	 if ((mback1.set() == true) && (mback2.set() == true) &&
		 (mcomp1.set() == true) && (mcomp2.set() == true)) {

		 vcl_cerr << "process_args(): computing alpha matte..." << vcl_endl;

		 // ok, we have all the input images, so let's run the algorithm
		 if (M.compute() == false)
			 // there was a problem in the computation, so we do not continue
			 // the non-interactive processing
			 return (no_gui.set() == false);

		 // ok, the processing was successful.
		 // now, if the user has specified output image files, write the
		 // result to disk

		 if (mobj.set() == true) {
			 vcl_cerr << "Writing the result(s) to disk ...\n";

			 // write the object image
			 // note that we need to use the method c_str()
			 // to convert a vcl_string to a C-type string (i.e. const char*)
			 if (vil_save((vil_image_view<vxl_byte>)M.get(M.Object), mobj().c_str()) == false) 
				 // the vcl_endl just adds a linebreak to the stream 
				 vcl_cerr << "vil_save: error occured while saving object image" << vcl_endl;
		 } 
		 if (malpha.set() == true)
			 // write the object image
			 // note that we need to use the method c_str()
			 // to convert a vcl_string to a C-type string (i.e. const char*)
			 if (vil_save(M.get1(M.Alpha), malpha().c_str()) == false)
				 vcl_cerr << "vil_save: error occured while saving alpha image" << vcl_endl;

		 // finally, if the user has supplied a new background 
		 // image, perform a compositing operation
		 if (mnewback.set() == true) {
			 vil_image_view<vil_rgb<vxl_byte> > im1, im2;
			 // first load the image corresponding to the new background
			 im1 = load_image(mnewback());
			 // if the load was successful, run the compositing operation
			 if ((bool)im1 == true) {
				 vcl_cerr << "Computing a new composite ..." << vcl_endl;

				 if (M.compute_composite(im1, im2) == true) {
					 // if the compositing was successful and the user has
					 // supplied an output filename, we save the composite to 
					 // a file
					 if (mnewcomp.set() == true)
					      if (vil_save((vil_image_view<vxl_byte>)im2, mnewcomp().c_str()) == false)
							 vcl_cerr << "vil_save: error occured while saving new composite image" << vcl_endl; 
				 } else
					 vcl_cerr << "process_args():: an error occured during the compositing operation" << vcl_endl;
			 }
		 }

	 }

	 // if the user requested that no windows are opened we should
	 // tell main() that it should exit now
	 return (no_gui.set() == false);

}


// Program entry point
int main(int argc, char **argv) {
	matting M;

	// Get the command-line arguments (if any)  
	if (process_args(argc, argv, M) == false)
		return 0;
	else {
		 //
		 // run in interactive mode---we have to create the 
		 // fltk interface, etc
		 //
		 // Initialize fluid
	     Fl::visual(FL_INDEX || FL_DOUBLE);
	
		 // Create the UI windows for the interface
	     VisCompUI *window = new VisCompUI();
		 window->set_matting(M);

	     // Display the UI windows
	     window->show();
     

	     return Fl::run();
	 }
}


