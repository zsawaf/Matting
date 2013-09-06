// WARNING: DO NOT MODIFY THIS FILE EXCEPT WHERE EXPLICITLY NOTED

#include <math.h>
#include "../gl/glutils.h"
#include "imdraw.h"


/// DO NOT MODIFY THIS FILE FOR A1
/// THIS IS A PLACEHOLDER FOR FUTURE ASSIGNMENTS

////// PUT ANY ADDITIONAL DRAWING-RELATED CODE BETWEEN THESE LINES ///////
void ImDraw::drawRect(int j1, int i1, int j2, int i2) {
     rect_j1 = j1;
     rect_i1 = i1;
     rect_j2 = j2;
     rect_i2 = i2;
     rect_drawn = 1;
     redraw();
}
//////////////////////////////////////////////////////////////////////////


// This is the main GL drawing routine. 
void ImDraw::draw() {
     if (!valid()) {
	  // These commands just tell GL what the size of the canvas is
	  glLoadIdentity(); 
	  glViewport(0,0,width,height);
	  // This command ensures that both GL and VXL coordinates 
	  // draw the (0,0) point at the top-left of the window
	  glOrtho(0, width, height, 0, -1.0, 1.0);
     }
     
     // Use black to clear the GL canvas
     glClearColor(0.0, 0.0, 0.0, 1.0);
     // Command to clear the GL canvas 
     glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

     // the routine below displays a VXL image in a GL canvas. For
     // now, you can skip the details of how this is done (ie. you
     // don't need to read that code or understand it)
     draw_image();

     ////// PUT YOUR DRAWING CODE BETWEEN THESE LINES ///////
     {
	  double glx1, gly1, glx2, gly2;

	  // Draw the border of the rectangular region in red 
	  glColor3d(1.0, 0.0, 0.0);

	  if (rect_drawn) {
	       // convert VXL coordinates to GL coordinates
	       vxl2gl(rect_i1, rect_j1, glx1, gly1);
	       vxl2gl(rect_i2, rect_j2, glx2, gly2);

	       glBegin(GL_LINE_LOOP);
	       {
		    glVertex2d(glx1, gly1);
		    glVertex2d(glx2, gly1);
		    glVertex2d(glx2, gly2);
		    glVertex2d(glx1, gly2);
	       }
	       glEnd();
	  }
     }
     ////////////////////////////////////////////////////////
     
}

