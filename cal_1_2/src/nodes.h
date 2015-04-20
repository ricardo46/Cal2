#ifndef _NODES_H_
#define _NODES_H_

#include <string>
#include <vector>
#include "Links.h"
#include "Hotspot.h"
using namespace std;


template <class T> class Links;

template <class T>
class Nodes {
	T info;
	vector<Links<T>  > adj;
	bool visited, linked;
	Nodes<T> * previous;

public:
	Nodes(T in);
	T getInfo();
	bool getLinked();
	vector<Links<T>	> getAdj();
	void setAdj(Links<T> &arg);
	void setLinked(bool f);
	void setInfo(T info);
	void setVisited(bool t);
	void setPrevious(Nodes<T> * previous);
	Nodes<T> * getPrevious();
};

template<class T>
vector<Links<T>> Nodes<T>::getAdj(){
	return adj;
}

template <class T>
Nodes<T>::Nodes(T in) : info(in), visited(false),linked(false){}

template <class T>
T Nodes<T>::getInfo(){
	return info;
}

template <class T>
void Nodes<T>::setInfo(T info){
	this->info= info;
}

template<class T>
bool Nodes<T>::getLinked(){
	return this->linked;
}

template<class T>
void Nodes<T>::setAdj(Links<T> &arg){
	adj.push_back(arg);
}

template<class T>
void Nodes<T>::setLinked(bool t){
	this->linked = t;
}

template<class T>
void Nodes<T>::setVisited(bool t){
	this->visited = t;
}

template<class T>
void Nodes<T>::setPrevious(Nodes<T> * previous){
this->previous= previous;
}

template<class T>
Nodes<T> * Nodes<T>::getPrevious(){
return this->previous;
}
#endif
