#ifndef CREATE_H
#define CREATE_H

#include "create_parts.h"

Fl_Window *createwin;
Fl_Window *rpwin;
void rp_createCB(Fl_Widget* w, void* p)
{
	createwin->hide();

	rpwin = new Fl_Window{ 600,400,"Create Robot Part" };
	Fl_Button head(200, 25, 200, 30, "Head");
	Fl_Button arm(200, 75, 200, 30, "Arms");
	Fl_Button battery(200, 125, 200, 30, "Battery");
	Fl_Button locomotor(200, 175, 200, 30, "Locomotor");
	Fl_Button torso(200, 225, 200, 30, "Torso");

	head.callback(create_headCB);
	arm.callback(create_armCB);
	battery.callback(create_batteryCB);
	locomotor.callback(create_locomotorCB);
	torso.callback(create_torsoCB);

	rpwin->end();
	rpwin->show();

	Fl::run();
}

void rm_createCB(Fl_Widget* w, void* p)
{

}

void userCB(Fl_Widget* w, void* p)
{

}

void create()
{
	createwin= new Fl_Window{ 600, 400, "Create" };
	Fl_Button parts(200, 50, 200, 30, "Robot Parts");
	Fl_Button models(200, 100, 200, 30, "Robot Models");
	Fl_Button user(200, 150, 200, 30, "User");

	parts.callback(rp_createCB);
	models.callback(rm_createCB);
	user.callback(userCB);
	createwin->end();
	createwin->show();
	Fl::run();
}


#endif
