
/**Callback method to save images of the algorithm**/
{
	if (M.is_composite_computed() == false) {
		fl_alert("New Composite has not been computed.");
	}

	else {
		//for some reason file_chooser doesn't work.
		vil_save(M.get(M.NewComp), "newcomp.jpeg");
		fl_alert("Saved Successfully");
	}
}
