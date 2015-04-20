#ifndef _GRAPH_H_
#define _GRAPH_H_

#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>
#include <string>
#include <vector>
#include "nodes.h"
#include "Utilitarios.h"

using namespace std;

template <class T> class Links;
template <class T> class Graph;


template <class T>
class Graph {
	vector<Nodes<T> *> vertexSet;
public:
	vector<Nodes<T> * > getVertexSet();
	int getNumVertex();
	bool addNode(const T &in);
	bool addEdge(const T &sourc, const T &dest, double w);
	void fill();
	double getEstruturaLength();
};



template <class T>
bool Graph<T>::addNode(const T &in){

	for (unsigned int i = 0; i < vertexSet.size(); i++){
		if ((vertexSet.at(i)->getInfo()) == in)
			return false;
	}
	Nodes<T>  *vertice = new Nodes<T>(in);
	vertexSet.push_back(vertice);
	return true;
}

template <class T>
bool Graph<T>::addEdge(const T &sourc, const T &dest, double w){

	Nodes<T> *v1 = new Nodes<T>(sourc);
	Nodes<T> *v2 = new Nodes<T>(dest);
	Links<T> *e1 = new Links<T>(v2, w);

	for (unsigned int i = 0; i < vertexSet.size(); i++){

		if (vertexSet.at(i)->info == v1->info){
			for (unsigned int j = 0; j < vertexSet.size(); j++){
				if ((vertexSet.at(j)->info) == dest){
					vertexSet.at(i)->adj.push_back(*e1);
					return true;
				}
			}
		}
	}
	return false;
}

template <class T>
int Graph<T>::getNumVertex() {
	return vertexSet.size();
}
template <class T>
vector<Nodes<T> * > Graph<T>::getVertexSet() {
	return vertexSet;
}

template <class T>
void Graph<T>::fill(){
	for (unsigned int i = 0; i < vertexSet.size(); i++){
		if (!vertexSet[i]->getLinked()){
			Links<T> l1(this->vertexSet[nearestNode(this->vertexSet, vertexSet[i]->getInfo())], calcDist(this->vertexSet, vertexSet[i]->getInfo()));
			vertexSet[i]->setAdj(l1);
			vertexSet[i]->setLinked(true);

		}
	}
}

template <class T>
double Graph<T>::getEstruturaLength(){
	double ret = 0;
	for (unsigned int i = 0; i < vertexSet.size(); i++){
		for (unsigned int j = 0; j < vertexSet.at(i)->getAdj().size(); j++){
			ret += vertexSet.at(i)->getAdj()[j].getWeight();

			cout<<"vertice: "<<vertexSet.at(i)->getInfo().getNome()<<" no mais proximo: "<<vertexSet.at(i)->getAdj()[j].getDest()->getInfo().getNome()<<endl;
			cout<<"vertice: "<<vertexSet.at(i)->getInfo().getNome()<<" dist ao mais proximo: "<<vertexSet.at(i)->getAdj()[j].getWeight()<<endl;
		}
		
	}

	return ret;
}


#endif
