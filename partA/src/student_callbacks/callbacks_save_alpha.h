
/**Callback method to save images of the algorithm**/
{
	if (M.is_alpha_or_object() == false) {
		fl_alert("Alpha has not been computed");
	}

	else {
		char *filename;
		filename = fl_file_chooser("Filename", "", "");
		vil_save(M.get1(M.Alpha), filename);
		fl_alert("Saved Successfully");
	}
}
