// WARNING: DO NOT MODIFY THIS FILE EXCEPT WHERE EXPLICITLY NOTED

#include <math.h>
#include "../gl/glutils.h"
#include "../vxl_includes.h"
#include "../fltk_includes.h"

#include "imdraw.h"




// DO NOT MODIFY THIS FILE FOR A1
// IT IS A PLACEHOLDER FOR FUTURE ASSIGNMENTS

////// PUT YOUR EVENT-HANDLING CODE BETWEEN THESE LINES ///////

// force the interface into image-browsing mode
void ImDraw::set_browsing_mode(void)
{
	view_mode = Browse;
}

// force the interface into image-drawing mode
void ImDraw::set_drawing_mode(void)
{
	view_mode = Draw;
}


// define an example event handler that intercepts Mouse-1 events in
// order to draw a rectangle over an image by clicking and dragging
// the Mouse-1 button
int ImDraw::handle(int event) {
     int mousex, mousey;
     //  flag that specifies whether the event was handled by the
     //  code below or whether it should be passed on to the default
     //  fltk handler
     int intercepted=0;
     
     // this is how you can change the appearance of the cursor
     cursor(FL_CURSOR_CROSS, FL_WHITE, FL_BLACK);
    
	 // event handling depends on the current mode of the interface
	 switch (view_mode) {
     //
	 // Handling events in image-drawing mode
	 //
	 // In image-drawing mode, dragging the mouse causes a rectangle to
	 // be drawn
	 //
	 case Draw:
	     switch (event) {
		 case FL_ENTER:
	     case FL_MOVE:
		  break;
	     case FL_PUSH:
		  // user starts drawing a rectangle
		  if (Fl::event_button() == 1) {
			   // get position of the mouse pointer
		       mousex = Fl::event_x();
			   mousey = Fl::event_y();
	
		       // convert mouse coordinates to VXL coordinates
			   if (!gl2vxl(mousex, mousey, rect_i1, rect_j1)) {
				// mouse was clicked outside the image, so reset
			    rect_drawn = 0;
		       } else {
			    rect_j2 = rect_j1;
				rect_i2 = rect_i1;
			    rect_drawn = 1;
		       }
			   intercepted = 1;
		  }
		  break;
		  case FL_DRAG:
		  // user resizes the rectangle by dragging the mouse
		  if (Fl::event_button() == 1) {
		       int j2, i2;
		       
		       mousex = Fl::event_x();
			   mousey = Fl::event_y();
		       
		       // convert mouse coordinates to VXL coordinates
		       if (!gl2vxl(mousex, mousey, i2, j2)) {
			    // mouse was clicked outside the image, so do not
			    // update the rectangle's size
		       } else {
			    rect_j2 = j2;
			    rect_i2 = i2;
		       }	
		       intercepted = 1;
		  }
		  break; 
	      default:
		       ;
		 }
		 break;
	 //
	 // Handling events in image-browsing mode
	 //
     // In image-browsing mode, clicking the left mouse recenters the
	 // image on the OpenGL canvas
     //
	 case Browse:
	     switch (event) {
		 case FL_MOVE:
			   int center_j, center_i;
			   mousex = Fl::event_x();
			   mousey = Fl::event_y();

		       // convert mouse coordinates to VXL coordinates
			   if (!gl2vxl(mousex, mousey, center_i, center_j)) {
					// mouse was clicked outside the image, so do nothing
			   } else if (valid_image == true)
				    // update the ui display
					update_pixel_data_in_ui(center_i, center_j,
											current_image(center_i,center_j).r,
											current_image(center_i,center_j).g,
											current_image(center_i,center_j).b);
		  break;
		 case FL_ENTER:
		  break;
	     case FL_PUSH:
		   // when user clicks the left mouse button
		   // the image is re-positioned so that the 
		   // clicked location is at the center of the GL 
		   // canvas
		  if (Fl::event_button() == 1) {
	           int center_j, center_i;

			   mousex = Fl::event_x();
			   mousey = Fl::event_y();

		       // convert mouse coordinates to VXL coordinates
			   if (!gl2vxl(mousex, mousey, center_i, center_j)) {
				   // mouse was clicked outside the image, so do nothing
		       } else {
				   if (valid_image == true) {
						// shift the image so that the pixel at the mouse position
						// is at the center of the OpenGL canvas
						recenter(center_i, center_j);
					    // update the ui display
						update_view_data_in_ui();
				   }
		       }
	 		   intercepted = 1;
		  }
	      default:
		       ;
		 }

	 }

     if (!intercepted) {
	  // delegate all other events to the regular Fl_Gl_Window handler
	  return(Fl_Gl_Window::handle(event));
     } else {
	  // otherwise, update the interface
	  redraw();
	  return 1;
     }
}

////////////////////////////////////////////////////////////////////////


