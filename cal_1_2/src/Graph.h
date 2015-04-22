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
#include "Dijkstra.h"
#include "Hotspot.h"

using namespace std;

template<class T> class Links;
template<class T> class Graph;

template<class T>
class Graph {
	vector<Nodes<T> *> vertexSet;
public:
	vector<Nodes<T> *> getVertexSet();
	int getNumVertex();
	bool addNode(const T &in);
	bool addEdge(const T &sourc, const T &dest, double w);
	void fill();
	double getEstruturaLength();
	void setShortestPaths(int posVertice);
	void showPaths(int posVertice);
	Nodes<T> * findNode(string name);
	void createGraph();
};

template<class T>
bool Graph<T>::addNode(const T &in) {

	for (unsigned int i = 0; i < vertexSet.size(); i++) {
		if ((vertexSet.at(i)->getInfo()) == in)
			return false;
	}
	Nodes<T> *vertice = new Nodes<T>(in);
	vertexSet.push_back(vertice);
	return true;
}


/*
 * Cria um link entre node sourc e o node dest se ambos pertencerem ao vertexSet
 */
template<class T>
bool Graph<T>::addEdge(const T &sourc, const T &dest, double w) {

	Nodes<T> *v1 = new Nodes<T>(sourc);
	Nodes<T> *v2 = new Nodes<T>(dest);

	for (unsigned int i = 0; i < vertexSet.size(); i++) {

		if (vertexSet.at(i)->getInfo() == v1->getInfo()) {
			for (unsigned int j = 0; j < vertexSet.size(); j++) {
				if ((vertexSet.at(j)->getInfo()) == dest) {

					Links<T> e1(vertexSet.at(j), w);

					vertexSet.at(i)->setAdj(e1);

					return true;
				}
			}
		}
	}
	return false;
}

template<class T>
int Graph<T>::getNumVertex() {
	return vertexSet.size();
}
template<class T>
vector<Nodes<T> *> Graph<T>::getVertexSet() {
	return vertexSet;
}

template<class T>
void Graph<T>::fill() {
	for (unsigned int i = 0; i < vertexSet.size(); i++) {
		if (!vertexSet[i]->getLinked()) {
			Links<T> l1(
					this->vertexSet[nearestNode(this->vertexSet,
							vertexSet[i]->getInfo())],
					calcDist(this->vertexSet, vertexSet[i]->getInfo()));
			vertexSet[i]->setAdj(l1);
			vertexSet[i]->setLinked(true);

		}
	}
}


template<class T>
double Graph<T>::getEstruturaLength() {
	double ret = 0;
	for (unsigned int i = 0; i < vertexSet.size(); i++) {
		for (unsigned int j = 0; j < vertexSet.at(i)->getAdj().size(); j++) {
			ret += vertexSet.at(i)->getAdj()[j].getWeight();

			cout << "vertice: " << vertexSet.at(i)->getInfo().getNome()
					<< " no mais proximo: "
					<< vertexSet.at(i)->getAdj()[j].getDest()->getInfo().getNome()
					<< endl;
			cout << "vertice: " << vertexSet.at(i)->getInfo().getNome()
					<< " dist ao mais proximo: "
					<< vertexSet.at(i)->getAdj()[j].getWeight() << endl;
		}

	}

	return ret;
}

/*
 * Para cada node do vertexSet é definido o nó anterior a que o nó actual deve estar ligado para se obter o caminho mais curto
 * Recebe a posicao do vertice (posVertice) escolhido para ser a central.
 * posVertice pode ser qualquer valor entre 0 e vertexSet.size()-1
 */
template<class T>
void Graph<T>::setShortestPaths(int posVertice) {


	Dijkstra<Hotspot> dj;
	Nodes<Hotspot> * vert1 = vertexSet[posVertice];
	dj.findPath(vert1);


}

/*
 * Faz o display do Graph. Recebe a posicao do vertice (posVertice) escolhido para ser a central. Mostra o caminho mais curto desde a central até cada um dos vertices
 * posVertice pode ser qualquer valor entre 0 e vertexSet.size()-1
 */
template<class T>
void Graph<T>::showPaths(int posVertice) {
	for (int i = 0; i < vertexSet.size(); i++) {
		Nodes<Hotspot> * vert = vertexSet[i];
		cout << "Caminho mais curto ate " << vert->getInfo() << " dist("
				<< vert->getInfo().getMinDist() << ")";
		while (vert != vertexSet.at(posVertice)) {
			//cout << "vert name: " << vert->getInfo() << endl;
			cout << " <-- " << vert->getPrevious()->getInfo() << " dist("
					<< vert->getPrevious()->getInfo().getMinDist() << ")";

			vert = vert->getPrevious();
		}
		cout << endl;
	}
}

/*
 * Retorna o Node que tem o Info com o nome igual a name
 */
template<class T>
Nodes<T> * Graph<T>::findNode(string name) {
	Nodes<Hotspot> * vert;
	for (int i = 0; i < vertexSet.size(); i++) {
		if (vertexSet[i]->getInfo().getNome() == name) {
			vert = vertexSet[i];
		}
	}
return vert;
}

/*
 * Criação do Graph a partir da leitura do ficheiro de Hotspots (nodes.txt) e do ficheiro de Links (links.txt)
 */
template<class T>
void Graph<T>::createGraph(){

			ifstream file;


			file.open("nodes.txt");
			string name;
			while (!file.eof()){
				file >> name;
				Hotspot h1(name, 0, 0);
				addNode(h1);
			}

			file.close();

			file.open("links.txt");
					string sourceName, destName, weightStr;
					while (!file.eof()){
						file >> sourceName;
						file >> destName;
						file >> weightStr;

						Hotspot hsource=findNode(sourceName)->getInfo();
						Hotspot hdest=findNode(destName)->getInfo();
						double weight=stod(weightStr);
						addEdge(hsource, hdest, weight);
						addEdge(hdest, hsource, weight);
					}

					file.close();
}

#endif
