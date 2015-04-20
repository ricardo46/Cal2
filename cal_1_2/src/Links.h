#ifndef _LINKS_H_
#define _LINKS_H_


#include <vector>
#include <iostream>
#include <fstream>
#include "nodes.h"

using namespace std;

template <class T> class Nodes;

template <class T>
class Links {
	Nodes<T> * dest;
	double weight;
public:
	Links(Nodes<T> *d, double w);
	double getWeight();
	Nodes<T>* getDest();
	friend class Nodes<T>;
};

template <class T>
Links<T>::Links(Nodes<T> *d, double w) : dest(d), weight(w){}

template <class T>
double Links<T>::getWeight(){
	return weight;
}

template <class T>
Nodes<T>* Links<T>::getDest(){
	return dest;
}

#endif
