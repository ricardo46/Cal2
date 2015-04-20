#include "Hotspot.h"


using namespace std;

Hotspot::Hotspot(){
	nome = "undefined";
	coordX = NULL;
	coordY = NULL;
	minDist=NULL;
}

Hotspot::Hotspot(string nome, double coordX, double coordY){
	this->nome = nome;
	this->coordX = coordX;
	this->coordY = coordY;
	this->minDist=MAXDIST;
}

string Hotspot::getNome(){
	return this->nome;
}

double Hotspot::getCoordX(){
	return this->coordX;
}

double Hotspot::getCoordY(){
	return this->coordY;
}

double Hotspot::getMinDist(){
	return this->minDist;
}

void Hotspot::setMinDist(double minDist){
	this->minDist=minDist;
}

bool Hotspot::operator==(const Hotspot &h) const{

	return this->nome == h.nome;
}

std::ostream & operator << (std::ostream &os, Hotspot &n){
	os << n.getNome();
	return os;
}
