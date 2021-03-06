// generated by Fast Light User Interface Designer (fluid) version 1.0300

#ifndef VisCompUI_h
#define VisCompUI_h
#include <FL/Fl.H>
#include <FL/Fl_Double_Window.H>
#include "matting/matting.h"
#include "vxl_includes.h"
#include <FL/Fl_Group.H>
#include <FL/Fl_Menu_Bar.H>
#include "file/load_image.h"
#include <FL/Fl_Choice.H>
#include "gl/glutils.h"
#include "imdraw/imdraw.h"
#include <FL/Fl_Output.H>
#include <FL/Fl_Input.H>

class VisCompUI {
  vil_image_view<vil_rgb<vxl_byte> > left_im; 
  vil_image_view<vil_rgb<vxl_byte> > right_im; 
  matting M; 
public:
  void show();
  vil_image_view<vil_rgb<vxl_byte> > interactive_load_image(vcl_string title);
  void display_matting_image(ImDraw* panel, matting::im_type imt);
  void display_matting_image1(ImDraw* panel, matting::im_type imt);
  void load_and_display_matting_image(ImDraw* panel, matting::im_type imt);
  void drawRect(int j1, int i1, int j2, int i2);
  void set_matting(matting m);
  VisCompUI();
  Fl_Double_Window *mainWindow;
  static Fl_Menu_Item menu_[];
private:
  void cb_Open_i(Fl_Menu_*, void*);
  static void cb_Open(Fl_Menu_*, void*);
  void cb_Open1_i(Fl_Menu_*, void*);
  static void cb_Open1(Fl_Menu_*, void*);
  void cb_Open2_i(Fl_Menu_*, void*);
  static void cb_Open2(Fl_Menu_*, void*);
  void cb_Save_i(Fl_Menu_*, void*);
  static void cb_Save(Fl_Menu_*, void*);
  void cb_Save1_i(Fl_Menu_*, void*);
  static void cb_Save1(Fl_Menu_*, void*);
  void cb_Quit_i(Fl_Menu_*, void*);
  static void cb_Quit(Fl_Menu_*, void*);
  void cb_Display_i(Fl_Menu_*, void*);
  static void cb_Display(Fl_Menu_*, void*);
  void cb_back1_i(Fl_Menu_*, void*);
  static void cb_back1(Fl_Menu_*, void*);
  void cb_back2_i(Fl_Menu_*, void*);
  static void cb_back2(Fl_Menu_*, void*);
  void cb_comp1_i(Fl_Menu_*, void*);
  static void cb_comp1(Fl_Menu_*, void*);
  void cb_comp2_i(Fl_Menu_*, void*);
  static void cb_comp2(Fl_Menu_*, void*);
  void cb_Run_i(Fl_Menu_*, void*);
  static void cb_Run(Fl_Menu_*, void*);
  void cb_Create_i(Fl_Menu_*, void*);
  static void cb_Create(Fl_Menu_*, void*);
  void cb_Alpha_i(Fl_Menu_*, void*);
  static void cb_Alpha(Fl_Menu_*, void*);
  void cb_Object_i(Fl_Menu_*, void*);
  static void cb_Object(Fl_Menu_*, void*);
  void cb_New_i(Fl_Menu_*, void*);
  static void cb_New(Fl_Menu_*, void*);
  static Fl_Menu_Item menu_1[];
  void cb_Browse_i(Fl_Menu_*, void*);
  static void cb_Browse(Fl_Menu_*, void*);
  void cb_Draw_i(Fl_Menu_*, void*);
  static void cb_Draw(Fl_Menu_*, void*);
public:
  ImDraw *left_panel;
  Fl_Output *left_pos;
  Fl_Output *left_val;
  Fl_Input *left_mag;
private:
  void cb_left_mag_i(Fl_Input*, void*);
  static void cb_left_mag(Fl_Input*, void*);
public:
  Fl_Input *left_center_i;
private:
  void cb_left_center_i_i(Fl_Input*, void*);
  static void cb_left_center_i(Fl_Input*, void*);
public:
  Fl_Input *left_center_j;
private:
  void cb_left_center_j_i(Fl_Input*, void*);
  static void cb_left_center_j(Fl_Input*, void*);
public:
  Fl_Output *left_title;
  ImDraw *right_panel;
  Fl_Output *right_pos;
  Fl_Output *right_val;
  Fl_Input *right_mag;
private:
  void cb_right_mag_i(Fl_Input*, void*);
  static void cb_right_mag(Fl_Input*, void*);
public:
  Fl_Input *right_center_i;
private:
  void cb_right_center_i_i(Fl_Input*, void*);
  static void cb_right_center_i(Fl_Input*, void*);
public:
  Fl_Input *right_center_j;
private:
  void cb_right_center_j_i(Fl_Input*, void*);
  static void cb_right_center_j(Fl_Input*, void*);
public:
  Fl_Output *right_title;
  Fl_Double_Window *mattingDisplayWindow;
  static Fl_Menu_Item menu_Left[];
private:
  void cb_back11_i(Fl_Menu_*, void*);
  static void cb_back11(Fl_Menu_*, void*);
  void cb_back21_i(Fl_Menu_*, void*);
  static void cb_back21(Fl_Menu_*, void*);
  void cb_comp11_i(Fl_Menu_*, void*);
  static void cb_comp11(Fl_Menu_*, void*);
  void cb_comp21_i(Fl_Menu_*, void*);
  static void cb_comp21(Fl_Menu_*, void*);
  void cb_alpha_i(Fl_Menu_*, void*);
  static void cb_alpha(Fl_Menu_*, void*);
  void cb_object_i(Fl_Menu_*, void*);
  static void cb_object(Fl_Menu_*, void*);
  void cb_nback_i(Fl_Menu_*, void*);
  static void cb_nback(Fl_Menu_*, void*);
  void cb_ncomp_i(Fl_Menu_*, void*);
  static void cb_ncomp(Fl_Menu_*, void*);
};
#endif
