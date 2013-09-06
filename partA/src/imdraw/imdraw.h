// WARNING: DO NOT MODIFY THIS FILE EXCEPT WHERE EXPLICITLY NOTED
//

#include "../vxl_includes.h"

#include "../gl/Texture.h"

// DO NOT MODIFY THIS FILE FOR ASSIGNMENT 1
// THIS IS A PLACEHOLDER FOR FUTURE ASSIGNMENTS
////// PUT YOUR CODE (IF ANY) BETWEEN THESE LINES ///////

/////////////////////////////////////////////////////////

class ImDraw : public Fl_Gl_Window {  
 public:
     // The class constructor 
     ImDraw(int x,int y,int w,int h,const char *l=0);

     // The widget class draw() override.  The draw() function
     // initializes GL for another round of drawing and then calls
     // specialized functions for drawing each of the entities to be
     // displayed.
     void draw(void);

     // This is the event handling routine. All UI events go through
     // this routine, which can choose to pass them on to the default
     // handler or handle them itself.
     int handle(int event);

     // Set the image to be displayed on the GL canvas. The image will
     // be displayed the next time the method draw_image() is called.
     // The image must have a resolution of at most 1024x1024. If
     // larger images are needed, the file Texture.cxx must be
     // modified accordingly.
	 // The function returns false if the supplied image does not contain
	 // valid data
     bool set(vil_image_view<vil_rgb<vxl_byte> > im, vcl_string title);
     bool set(vil_image_view<vxl_byte> im, vcl_string title);

     // Draw the image on the GL canvas. This method is called by the
     // draw() method.
     void draw_image(void);

	 // Routine that intercepts window resize events caused by 
	 // the user trying to resize the window
     void resize(int x, int y, int w, int h);

	 // Returns the current magnification of the image displayed
	 // in the window
	 double mag(void);

	 // Sets the current magnification of the image displayed in the
	 // window; returns true if the magnification parameter is valid
	 bool mag(double);

	 // shift the image so that the given pixel, (i,j), in VXL coordinates, 
	 // is at the center of the OpenGL canvas
	 void recenter_j(int j);
	 void recenter_i(int i);
	 void recenter(int i, int j);

     // convert an (x,y) position given in GL canvas coordinates
     // (eg. generated through a mouse event or used to draw a vertex
     // with OpenGL) to an integer (i,j) coordinate
     // corresponding to a pixel in a VXL image
     int gl2vxl(double glx, double gly, int& i, int& j);

     // convert the (i,j) coordinate of a pixel in a VXL
     // image to an (x,y) position on the GL canvas.
     int vxl2gl(int i, int j, double& glx, double& gly);

	 // routies that switch display modes, i.e. the behavior of
	 // the drawing interface
	 void set_browsing_mode(void);
	 void set_drawing_mode(void);

	 // routines for passing information from input/output widgets to the
	 // imview class
	 void update_pixel_data_in_ui(int i, int j, int band1, int band2, int band3);
	 void update_view_data_in_ui();
	 void update_view_data_in_ui(vcl_string title);
	 void update_view_data_from_ui();

     ////// PUT YOUR CODE (IF ANY) BETWEEN THESE LINES ///////
     void drawRect(int j1, int i1, int j2, int i2);
     /////////////////////////////////////////////////////////

 private:   
     int width, height;
     int im_height, im_width;
     double aspect_ratio;
     double magnification;
	 int image_center_i, image_center_j;
	 int view_i, view_j;
	 int shift_i, shift_j;
	 double fit_magnification;
     Texture *imTexture;
	 vil_image_view<vil_rgb<vxl_byte> > current_image;
	 bool valid_image;

	 // display modes
	 enum mode {Browse, Draw};
	 mode view_mode;


	 // DO NOT MODIFY THIS CODE FOR A1
	 // IT IS A PLACEHOLDER FOR FUTURE ASSIGNMENTS

     ////// PUT YOUR CODE (IF ANY) BETWEEN THESE LINES ///////

     // Parameters of a rectangle drawn over a VXL image.
     // Rectangle expressed as the (i,j) coordinates
     // of two opposing vertices of the rectangle. Coordinates
     // are assumed to be VXL image coordinates
     int rect_i1, rect_j1, rect_i2, rect_j2;
     // Flag that is true if the user has begun drawing a rectangle
     int rect_drawn;

     /////////////////////////////////////////////////////////
};
