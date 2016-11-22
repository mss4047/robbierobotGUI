#ifndef CREATE_PARTS_H
#define CREATE_PARTS_H

Fl_Input *rp_name;
Fl_Input *rp_part_number;
Fl_Input *rp_type;
Fl_Input *rp_weight;
Fl_Input *rp_cost;
Fl_Input *rp_description;
Fl_Input *rp_maxspeed;
Fl_Input *rp_power_con_loco;
Fl_Input *rp_energy;
Fl_Input *rp_max_power;
Fl_Input *rp_battery_compartments;
Fl_Window *win;

Arm* temp;
Battery* tempbat;
Head* temphead;
Locomotor* temploco;
Torso* temptorso;

vector<Locomotor*> locomotors;
vector<Arm*> arms;
vector<Battery*> batterys;
vector<Head*> heads;
vector<Torso*> torsos;

void save_torso(Fl_Widget* w, void* p)
{
	win->hide();
	cout << "Name " << rp_name->value() << endl;
	cout << "Part Number " << rp_part_number->value() << endl;
	cout << "Weight " << rp_weight->value() << endl;
	cout << "Cost " << rp_cost->value() << endl;
	cout << "Description " << rp_description->value() << endl;
	cout << "Battery Compartments " << rp_battery_compartments->value() << endl;


	temptorso->name = rp_name->value();
	temptorso->cost = stod(rp_cost->value());
	temptorso->desc = rp_description->value();
	temptorso->p_num = stoi(rp_part_number->value());
	temptorso->type = "torso";
	temptorso->weight = stod(rp_weight->value());
	temptorso->battery_compartments = stoi(rp_battery_compartments->value());

	heads.push_back(temphead);
}

void save_head(Fl_Widget* w, void* p)
{
	win->hide();
	cout << "Name " << rp_name->value() << endl;
	cout << "Part Number " << rp_part_number->value() << endl;
	cout << "Weight " << rp_weight->value() << endl;
	cout << "Cost " << rp_cost->value() << endl;
	cout << "Description " << rp_description->value() << endl;


	temphead->name = rp_name->value();
	temphead->cost = stod(rp_cost->value());
	temphead->desc = rp_description->value();
	temphead->p_num = stoi(rp_part_number->value());
	temphead->type = "head";
	temphead->weight = stod(rp_weight->value());

	heads.push_back(temphead);

}

void save_battery(Fl_Widget* w, void* p)
{
	win->hide();
	cout << "Name " << rp_name->value() << endl;
	cout << "Energy " << rp_energy->value() << endl;
	cout << "Max Power " << rp_max_power->value() << endl;
	cout << "Part Number " << rp_part_number->value() << endl;
	cout << "Weight " << rp_weight->value() << endl;
	cout << "Cost " << rp_cost->value() << endl;
	cout << "Description " << rp_description->value() << endl;


	tempbat->name = rp_name->value();
	tempbat->cost = stod(rp_cost->value());
	tempbat->desc = rp_description->value();
	tempbat->maxPower = stoi(rp_max_power->value());
	tempbat->energy = stoi(rp_energy->value());
	tempbat->p_num = stoi(rp_part_number->value());
	tempbat->type = "battery";
	tempbat->weight = stod(rp_weight->value());

	batterys.push_back(tempbat);

	
}

void save_arm(Fl_Widget* w, void* p)
{
	win->hide();
	cout << "Name " << rp_name->value()<<endl;
	cout << "Power " << rp_power_con_loco->value()<<endl;
	cout << "Part Number " << rp_part_number->value()<<endl;
	cout << "Weight " << rp_weight->value() << endl;
	cout << "Cost " << rp_cost->value() << endl;
	cout << "Description " << rp_description->value() << endl;

	
	temp->name = rp_name->value();
	temp->cost = stod(rp_cost->value());
	temp->desc = rp_description->value();
	temp->power_con = stoi(rp_power_con_loco->value());
	temp->p_num = stoi(rp_part_number->value());
	temp->type = "arm";
	temp->weight = stod(rp_weight->value());

	arms.push_back(temp);

}


void save_locomotor(Fl_Widget* w, void* p)
{
	win->hide();
	cout << "Name " << rp_name->value();
	cout << "Power " << rp_power_con_loco->value();
	cout << " Speed " << rp_maxspeed->value();
	cout << "Part Number " << rp_part_number->value();
	cout << "Weight " << rp_weight->value();
	cout << "Cost " << rp_cost->value();
	cout << "Description " << rp_description->value();

	
	temploco->name = rp_name->value();
	temploco->cost = stod(rp_cost->value());
	temploco->desc = rp_description->value();
	temploco->max_speed = stoi(rp_maxspeed -> value());
	temploco->power_conloco = stoi(rp_power_con_loco->value());
	temploco->p_num = stoi(rp_part_number->value());
	temploco->type = "locomotor";
	temploco->weight = stod(rp_weight->value());

	locomotors.push_back(temploco);
	
}


void create_torsoCB(Fl_Widget* w, void* p)
{
	win = new Fl_Window{ 480,430, "Torso" };

	rp_name = new Fl_Input(150, 40, 210, 25, "Name");
	rp_name->align(FL_ALIGN_LEFT);

	rp_battery_compartments = new Fl_Input(150, 70, 210, 25, "Number of Batteries(1-3)");
	rp_battery_compartments->align(FL_ALIGN_LEFT);

	rp_part_number = new Fl_Input(150, 180, 210, 25, "Part Number");
	rp_part_number->align(FL_ALIGN_LEFT);

	rp_weight = new Fl_Input(150, 220, 210, 25, "Weight");
	rp_weight->align(FL_ALIGN_LEFT);

	rp_cost = new Fl_Input(150, 260, 210, 25, "Cost");
	rp_cost->align(FL_ALIGN_LEFT);

	rp_description = new Fl_Input(150, 300, 210, 25, "Description");
	rp_description->align(FL_ALIGN_LEFT);

	Fl_Button *rp_confirm;
	rp_confirm = new Fl_Button(180, 340, 120, 25, "Confirm");
	rp_confirm->callback((Fl_Callback *)save_torso, 0);

	win->show();
	Fl::run();

}

void create_locomotorCB(Fl_Widget* w, void* p)
{
	win = new Fl_Window{ 600, 400, "Locomotor" };

	rp_name = new Fl_Input(130, 40, 210, 25, "Name");
	rp_name->align(FL_ALIGN_LEFT);

	rp_power_con_loco = new Fl_Input(130, 70, 210, 25, "Power");
	rp_power_con_loco->align(FL_ALIGN_LEFT);

	rp_maxspeed = new Fl_Input(130, 100, 210, 25, "Max Speed(Mph)");
	rp_maxspeed->align(FL_ALIGN_LEFT);

	rp_part_number = new Fl_Input(130, 140, 210, 25, "Part Number");
	rp_part_number->align(FL_ALIGN_LEFT);

	rp_weight = new Fl_Input(130, 180, 210, 25, "Weight");
	rp_weight->align(FL_ALIGN_LEFT);

	rp_cost = new Fl_Input(130, 220, 210, 25, "Cost");
	rp_cost->align(FL_ALIGN_LEFT);

	rp_description = new Fl_Input(130, 260, 210, 25, "Description");
	rp_description->align(FL_ALIGN_LEFT);

	Fl_Button *rp_confirm;
	rp_confirm = new Fl_Button(150, 300, 120, 25, "Confirm");
	rp_confirm->callback((Fl_Callback *)save_locomotor, 0);

	win->show();
	Fl::run();
}

void create_armCB(Fl_Widget* w, void* p)
{
	win = new Fl_Window{ 600, 400, "Arm" };

	rp_name = new Fl_Input(130, 40, 210, 25, "Name");
	rp_name->align(FL_ALIGN_LEFT);

	rp_power_con_loco = new Fl_Input(130, 70, 210, 25, "Power Consumption");
	rp_power_con_loco->align(FL_ALIGN_LEFT);

	rp_part_number = new Fl_Input(130, 140, 210, 25, "Part Number");
	rp_part_number->align(FL_ALIGN_LEFT);

	rp_weight = new Fl_Input(130, 180, 210, 25, "Weight");
	rp_weight->align(FL_ALIGN_LEFT);

	rp_cost = new Fl_Input(130, 220, 210, 25, "Cost");
	rp_cost->align(FL_ALIGN_LEFT);

	rp_description = new Fl_Input(130, 260, 210, 25, "Description");
	rp_description->align(FL_ALIGN_LEFT);

	Fl_Button *rp_confirm;
	rp_confirm = new Fl_Button(150, 300, 120, 25, "Confirm");
	rp_confirm->callback((Fl_Callback *)save_arm, 0);

	win->show();
	Fl::run();

}

void create_batteryCB(Fl_Widget* w, void* p)
{
	win = new Fl_Window{ 600, 400, "Battery" };

	rp_name = new Fl_Input(130, 40, 210, 25, "Name");
	rp_name->align(FL_ALIGN_LEFT);

	rp_energy = new Fl_Input(130, 70, 210, 25, "Energy");
	rp_power_con_loco->align(FL_ALIGN_LEFT);

	rp_power_con_loco = new Fl_Input(130, 70, 210, 25, "Max Power");
	rp_max_power->align(FL_ALIGN_LEFT);

	rp_part_number = new Fl_Input(130, 140, 210, 25, "Part Number");
	rp_part_number->align(FL_ALIGN_LEFT);

	rp_weight = new Fl_Input(130, 180, 210, 25, "Weight");
	rp_weight->align(FL_ALIGN_LEFT);

	rp_cost = new Fl_Input(130, 220, 210, 25, "Cost");
	rp_cost->align(FL_ALIGN_LEFT);

	rp_description = new Fl_Input(130, 260, 210, 25, "Description");
	rp_description->align(FL_ALIGN_LEFT);

	Fl_Button *rp_confirm;
	rp_confirm = new Fl_Button(150, 300, 120, 25, "Confirm");
	rp_confirm->callback((Fl_Callback *)save_battery, 0);

	win->show();
	Fl::run();

}

void create_headCB(Fl_Widget* w, void* p)
{
	win = new Fl_Window{ 600, 400, "Head" };

	rp_name = new Fl_Input(130, 40, 210, 25, "Name");
	rp_name->align(FL_ALIGN_LEFT);

	rp_part_number = new Fl_Input(130, 140, 210, 25, "Part Number");
	rp_part_number->align(FL_ALIGN_LEFT);

	rp_weight = new Fl_Input(130, 180, 210, 25, "Weight");
	rp_weight->align(FL_ALIGN_LEFT);

	rp_cost = new Fl_Input(130, 220, 210, 25, "Cost");
	rp_cost->align(FL_ALIGN_LEFT);

	rp_description = new Fl_Input(130, 260, 210, 25, "Description");
	rp_description->align(FL_ALIGN_LEFT);

	Fl_Button *rp_confirm;
	rp_confirm = new Fl_Button(150, 300, 120, 25, "Confirm");
	rp_confirm->callback((Fl_Callback *)save_head, 0);

	win->show();
	Fl::run();
}

#endif // !CREATE_PARTS_H
