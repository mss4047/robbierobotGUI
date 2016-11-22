#include <Fl/Fl.H>                     
#include <Fl/Fl_Window.H>      
#include <FL/Fl_Button.H>   
#include <FL/Fl_Text_Display.H>
#include <FL/Fl_Text_Editor.H>
#include <stdio.h> 
#include "parts.h"
#include "create.h"


void createCB(Fl_Widget*w, void* p)
{

	win->hide();
	//pm();
}
void viewCB(Fl_Widget*w, void* p)
{
	win->hide();
	//cm();

}

int main()
{
	Fl::scheme("gtk+");
	win = new Fl_Window{ 600, 400, "Robbie Robot Shop" };
	Fl_Button create(200, 50, 200, 30, "Create");
	Fl_Button view(200, 100, 200, 30, "View");

	create.callback(createCB);
	view.callback(viewCB);
	win->end();
	win->show();

	return(Fl::run());
}