/**Callback method to save images of the algorithm**/
{
	//we can handle alpha and object the same, since if alpha is not computed, then object can't be computed.
	if (M.is_alpha_or_object() == false) {
		fl_alert("Object has not been computed");
	}

	else {
		char *filename;
		filename = fl_file_chooser("Filename", "", "");
		vil_save(M.get(M.Object), filename);
		fl_alert("Saved Successfully");
	}
}
