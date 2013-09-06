
/**Callback method to save images of the algorithm**/
#include "../matting/matting.h"
{
	
	vil_image_view<vil_rgb<vxl_byte> > to_save;

	to_save = matting::get1(Alpha);

	if (vil_save(to_save, "alpha.jpg") == true){
		fl_alert("Saved Successfuly.");
	}
}
