#ifndef PARTS_H
#define PARTS_H
#include <string>
#include <vector>
#include <fstream>
#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Menu_Bar.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_Multiline_Input.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Return_Button.H>
#include <FL/Fl_Input_Choice.H>
#include <iostream>
#include <string>
#include<iterator>
#include"parts.h"
using namespace std;


class robo
{
public:
	string name;
	int p_num;
	string type;
	double weight;
	double cost;
	string desc;
	//robo();
	//void setter();
	virtual void mysetter(string name, int p_num, string type, double weight, double cost, string desc) = 0;
};

class Locomotor : public robo
{
public:
	//Locomotor();
	virtual void mysetter(string name, int p_num, string type, double weight, double cost, string desc);
	int max_speed;
	int power_conloco;
};

class Arm : public robo
{
public:
	//Arm();
	virtual void mysetter(string name, int p_num, string type, double weight, double cost, string desc);
	void setArm(int Power_Con);
	int power_con;
};

class Battery : public robo
{
public:
	virtual void mysetter(string name, int p_num, string type, double weight, double cost, string desc);
	//Battery();
	void setBattery(double Energy, double power);
	double energy;
	double maxPower;
};

class Head : public robo
{
public:
	//Head();
	virtual void mysetter(string name, int p_num, string type, double weight, double cost, string desc);
};

class Torso : public robo
{
public:
	//Torso();
	virtual void mysetter(string name, int p_num, string type, double weight, double cost, string desc);
	Head tHead;
	vector<Arm> tArm;
	int battery_compartments;
	Locomotor tLoco;
	vector<Battery> tBattery;
};
#endif