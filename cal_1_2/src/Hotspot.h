#ifndef _HOTSPOT_H_
#define _HOTSPOT_H_

#include <iostream>
#include "stdlib.h"
#include <string>


using namespace std;

const int MAXDIST = 1000000000;

class Hotspot{
	string nome;
	double coordX, coordY, minDist;
public:
	Hotspot();
	Hotspot(string nome, double coordX, double coordY);

	string getNome();
	double getCoordX();
	double getCoordY();
	double getMinDist();
	void setMinDist(double minDist);
	bool operator == (const Hotspot &h2) const;

	friend std::ostream & operator << (std::ostream &os, Hotspot &p);
};

#endif 
