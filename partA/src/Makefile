#CFLAGS = -Wno-deprecated  ## Use this if the path shown below is already in dot.cshrc!
VXLDIR = /u/csc320h/winter/pub/vxl-1.9.0

CFLAGS = -I$(VXLDIR)/ -I$(VXLDIR)/core -I$(VXLDIR)/vcl -I$(VXLDIR)/bin/vcl -I$(VXLDIR)/bin/core -I$(VXLDIR)/core/vil -Wno-deprecated -DJPEG_LIB_VERSION=62

#CC = g++-2.95

CC = g++
FLTKLDFLAGS = -L/local/lib -Wl,-rpath,/local/lib -lfltk_gl -lGLU -lGL -lfltk -L/usr/X11R6/lib -lpthread -lm -lXext -lX11 -lsupc++
VXLLDFLAGS = -L$(VXLDIR)/bin/lib -lvnl_algo -lvnl_io -lvnl -lv3p_netlib -lvil -lvcl -lvul -lpng -ltiff /usr/lib/i386-linux-gnu/libjpeg.so.62.0.0
LDFLAGS = -lstdc++ $(FLTKLDFLAGS) $(VXLLDFLAGS)

FLUID = fluid




%.o: %.cxx
	$(CC) -c $(CFLAGS) $(CPPFLAGS) -o $@ $<


%.cxx: %.fl
	$(FLUID) -c $<



BASIC_OBJ   = gl/glutils.o gl/Texture.o main.o file/load_image.o

IMDRAW_OBJ  = imdraw/imdraw_utils.o imdraw/imdraw_init.o imdraw/imdraw_draw.o imdraw/imdraw_handle.o imdraw/read_drawing.o

UI_OBJ      = VisCompUI.o

UI_CPP      = VisCompUI.cxx VisCompUI.h

MATTING_OBJ = matting/matting.o

STUDENT_OBJ = matting/matting_algorithm.o


imdraw-code/viscomp:	$(UI_CPP) $(BASIC_OBJ) $(UI_OBJ) $(STUDENT_OBJ) $(MATTING_OBJ) $(IMDRAW_OBJ)

	$(CC) -o ../bin/viscomp $(BASIC_OBJ) $(UI_OBJ) $(MATTING_OBJ) $(IMDRAW_OBJ) $(STUDENT_OBJ) $(LDFLAGS)



clean:		

	rm -rf $(BASIC_OBJ) $(UI_OBJ) $(STUDENT_OBJ) $(UI_CPP) $(MATTING_OBJ) $(IMDRAW_OBJ) 

