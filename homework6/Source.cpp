#include "parts.h"

void create_robot_partCB(Fl_Widget* w, void* p);
void cancel_robot_partCB(Fl_Widget* w, void* p);
class Robot_Part_Dialog;

Fl_Window *win;
Fl_Menu_Bar *menubar;
Robot_Part_Dialog *robot_part_dlg;

vector<Torso*> torsos;
vector<Head*> heads;
vector<Battery*> batteries;
vector <Arm*> arms;
vector<Locomotor*> locomotors;

class Robot_Part_Dialog {
public:
	Robot_Part_Dialog() { 
		dialog = new Fl_Window(340, 270, "Robot Part");
		rp_name = new Fl_Input(120, 10, 210, 25, "Name:");
		rp_name->align(FL_ALIGN_LEFT);
		rp_part_number = new Fl_Input(120, 40, 210, 25, "Part Number:");
		rp_part_number->align(FL_ALIGN_LEFT);
		rp_type = new Fl_Input(120, 70, 210, 25, "Type (torso, head, arm, battery, or locomotor:");
		rp_type->align(FL_ALIGN_LEFT);
		rp_weight = new Fl_Input(120, 100, 210, 25, "Weight:");
		rp_weight->align(FL_ALIGN_LEFT);
		rp_cost = new Fl_Input(120, 130, 210, 25, "Cost:");
		rp_cost->align(FL_ALIGN_LEFT);
		rp_description = new Fl_Multiline_Input(120, 160, 210, 75, "Description:");
		rp_description->align(FL_ALIGN_LEFT);
		rp_create = new Fl_Return_Button(145, 240, 120, 25, "Create");
		rp_create->callback((Fl_Callback *)create_robot_partCB, 0);
		rp_cancel = new Fl_Button(270, 240, 60, 25, "Cancel");
		rp_cancel->callback((Fl_Callback *)cancel_robot_partCB, 0);
		dialog->end();
		dialog->set_non_modal();
	}

	void show() { dialog->show(); }
	void hide() { dialog->hide(); }
	string name() { return rp_name->value(); }
	string part_number() { return rp_part_number->value(); }
	string type() { return rp_type->value(); }
	string weight() { return rp_weight->value(); }
	string cost() { return rp_cost->value(); }
	string description() { return rp_description->value(); }

private:
	Fl_Window *dialog;
	Fl_Input *rp_name;
	Fl_Input *rp_part_number;
	Fl_Input *rp_type;
	Fl_Input *rp_weight;
	Fl_Input *rp_cost;
	Fl_Input *rp_description;
	Fl_Return_Button *rp_create;
	Fl_Button *rp_cancel;
};


void CB(Fl_Widget* w, void* p) { } // No action
void menu_create_robot_partCB(Fl_Widget* w, void* p) {
	robot_part_dlg->show();
}
void create_robot_partCB(Fl_Widget* w, void* p) { // Replace with call to model!
	cout << "### Creating robot part" << endl;
	cout << "Name : " << robot_part_dlg->name() << endl;
	cout << "Part # : " << robot_part_dlg->part_number() << endl;
	cout << "Type : " << robot_part_dlg->type() << endl;
	cout << "Weight : " << robot_part_dlg->weight() << endl;
	cout << "Cost : " << robot_part_dlg->cost() << endl;
	cout << "Descript: " << robot_part_dlg->description() << endl;
	robot_part_dlg->hide();
}
void cancel_robot_partCB(Fl_Widget* w, void* p) {
	robot_part_dlg->hide();
}

Fl_Menu_Item menuitems[] = {
	{ "&File", 0, 0, 0, FL_SUBMENU },
	{ "&New", FL_ALT + 'n', (Fl_Callback *)CB },
	{ "&Open", FL_ALT + 'o', (Fl_Callback *)CB },
	{ "&Save", FL_ALT + 's', (Fl_Callback *)CB },
	{ "Save As", FL_ALT + 'S', (Fl_Callback *)CB },
	{ "&Quit", FL_ALT + 'q', (Fl_Callback *)CB },
	{ 0 },
	{ "&Edit", 0, 0, 0, FL_SUBMENU },
	{ "&Undo", 0, (Fl_Callback *)CB },
	{ "Cu&t", 0, (Fl_Callback *)CB },
	{ "&Copy", 0, (Fl_Callback *)CB },
	{ "&Paste", 0, (Fl_Callback *)CB },
	{ 0 },
	{ "&Create", 0, 0, 0, FL_SUBMENU },
	{ "Order", 0, (Fl_Callback *)CB, 0, FL_MENU_DIVIDER },
	{ "Customer", 0, (Fl_Callback *)CB },
	{ "Sales Associate", 0, (Fl_Callback *)CB, 0, FL_MENU_DIVIDER },
	{ "Robot Part", 0, (Fl_Callback *)menu_create_robot_partCB },
	{ "Robot Model", 0, (Fl_Callback *)CB },
	{ 0 },
	{ "&Report", 0, 0, 0, FL_SUBMENU },
	{ "Invoice", 0, (Fl_Callback *)CB, 0, FL_MENU_DIVIDER },
	{ "All Orders", 0, (Fl_Callback *)CB } };

int main() {
	Fl::scheme("gtk+");
	const int X = 400;
	const int Y = 260;
	// Create dialogs
	robot_part_dlg = new Robot_Part_Dialog{};
	// Create a window
	win = new Fl_Window{ X, Y, "Robbie Robot Shop Manager" };
	win->color(FL_WHITE);
	// Install menu bar
	menubar = new Fl_Menu_Bar(0, 0, X, 30);
	menubar->menu(menuitems);
	// Wrap it up and let FLTK do its thing
	win->end();
	win->show();
	cout << robot_part_dlg->name() << endl;
	return(Fl::run());
}

//aaa