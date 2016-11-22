#include <Fl/Fl.H>                     
#include <Fl/Fl_Window.H>      
#include <FL/Fl_Button.H>   
#include <FL/Fl_Text_Display.H>
#include <FL/Fl_Text_Editor.H>
#include <stdio.h> 
#include "parts.h"
#include "create.h"
Fl_Window *win1;

void createCB(Fl_Widget*w, void* p)
{

	win1->hide();
	create();
}
void viewCB(Fl_Widget*w, void* p)
{
	win1->hide();
	//cm();

}

int main()
{
	Fl::scheme("gtk+");
	win1 = new Fl_Window{ 600, 400, "Robbie Robot Shop" };
	Fl_Button create(200, 50, 200, 30, "Create");
	Fl_Button view(200, 100, 200, 30, "View");

	create.callback(createCB);
	view.callback(viewCB);
	win1->end();
	win1->show();

	return(Fl::run());
}