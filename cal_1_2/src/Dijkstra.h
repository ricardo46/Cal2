
#ifndef _DIJKSTRA_H_
#define _DIJKSTRA_H_

#include <vector>
#include <iostream>
#include <fstream>
#include "nodes.h"
#include "MinHeap.h"

using namespace std;

template<class T> class Nodes;

template<class T>
class Dijkstra {

public:

	Dijkstra();
	void findPath(Nodes<T> * source);

	friend class Nodes<T> ;
};

template<class T>
Dijkstra<T>::Dijkstra() {
}

/*
 * Para cada node do vertexSet é definido o nó anterior a que o nó actual deve estar ligado para se obter o caminho mais curto
 * Recebe a posicao do vertice (posVertice) escolhido para ser a central.
 * posVertice pode ser qualquer valor entre 0 e vertexSet.size()-1
 */
template<class T>
void Dijkstra<T>::findPath(Nodes<T> * source) {
	T sourceHotspot = source->getInfo();
	sourceHotspot.setMinDist(0);
	source->setInfo(sourceHotspot);
	vector<Nodes<T> *> vertHeap;
	Push(vertHeap, source);

	while (vertHeap.size() != 0) {
		Nodes<T> * u = Pop(vertHeap);
		u->setVisited(true);
		string nome=u->getInfo().getNome();
		for (int i = 0; i < u->getAdj().size(); i++) {
			Nodes<T> * v = u->getAdj()[i].getDest();
			double weight = u->getAdj()[i].getWeight();
			double distanceThroughU = u->getInfo().getMinDist() + weight;

			if (distanceThroughU < v->getInfo().getMinDist()) {

				Remove(vertHeap, v);
				T hotspot = v->getInfo();
				hotspot.setMinDist(distanceThroughU);
				v->setInfo(hotspot);
				v->setPrevious(u);
				Push(vertHeap, v);
			}
		}
	}

}

#endif
