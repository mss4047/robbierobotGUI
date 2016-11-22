#ifndef ROBOT_MODELSH_H
#define ROBOT_MODELSH_H

#include <string>
#include <iostream>
#include <vector>
#include <fstream>
#include<iterator>
#include "parts.h"

using namespace std;
class model
{
public:

	string name;
	int modelNumber;
	double price;
	vector<Torso*> Torsosm;
};

class Orders
{
public:

	int orderNumber;
	string date;
	string customer;
	string salesAss;
	model mod;
	string status;
	double shipping, tax, price, total;


};

#endif