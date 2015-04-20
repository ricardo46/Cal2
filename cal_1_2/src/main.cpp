#include <algorithm>
#include <iostream>
#include <vector>
#include <iterator>
#include <functional>

#include "Utilitarios.h"
#include "Graph.h"
#include "Hotspot.h"
#include <string>
#include "Dijkstra.h"

using namespace std;



int main() {

	Hotspot hA("A", 0, 0);
	Hotspot hB("B", 0, 0);
	Hotspot hC("C", 0, 0);
	Hotspot hD("D", 0, 0);
	Hotspot hE("E", 0, 0);
	Hotspot hF("F", 0, 0);
	Hotspot hG("G", 0, 0);

	Nodes<Hotspot> *vA = new Nodes<Hotspot>(hA);
	Nodes<Hotspot> *vB = new Nodes<Hotspot>(hB);
	Nodes<Hotspot> *vC = new Nodes<Hotspot>(hC);
	Nodes<Hotspot> *vD = new Nodes<Hotspot>(hD);
	Nodes<Hotspot> *vE = new Nodes<Hotspot>(hE);
	Nodes<Hotspot> *vF = new Nodes<Hotspot>(hF);
	Nodes<Hotspot> *vG = new Nodes<Hotspot>(hG);

	Links<Hotspot> linkAB(vB, 4);
	Links<Hotspot> linkAC(vC, 3);
	Links<Hotspot> linkAE(vE, 7);
	vA->setAdj(linkAB);
	vA->setAdj(linkAC);
	vA->setAdj(linkAE);
	vA->setLinked(true);

	Links<Hotspot> linkBA(vA, 4);
	Links<Hotspot> linkBC(vC, 6);
	Links<Hotspot> linkBD(vD, 5);
	vB->setAdj(linkBA);
	vB->setAdj(linkBC);
	vB->setAdj(linkBD);
	vB->setLinked(true);

	Links<Hotspot> linkCA(vA, 3);
	Links<Hotspot> linkCB(vB, 6);
	Links<Hotspot> linkCD(vD, 11);
	Links<Hotspot> linkCE(vE, 8);
	vC->setAdj(linkCA);
	vC->setAdj(linkCB);
	vC->setAdj(linkCD);
	vC->setAdj(linkCE);
	vC->setLinked(true);

	Links<Hotspot> linkEC(vC, 8);
	Links<Hotspot> linkED(vD, 2);
	Links<Hotspot> linkEG(vG, 5);
	Links<Hotspot> linkEA(vA, 7);
	vE->setAdj(linkEC);
	vE->setAdj(linkED);
	vE->setAdj(linkEG);
	vE->setAdj(linkEA);
	vE->setLinked(true);

	Links<Hotspot> linkDB(vB, 5);
	Links<Hotspot> linkDC(vC, 11);
	Links<Hotspot> linkDE(vE, 2);
	Links<Hotspot> linkDG(vG, 10);
	Links<Hotspot> linkDF(vF, 2);
	vD->setAdj(linkDB);
	vD->setAdj(linkDC);
	vD->setAdj(linkDE);
	vD->setAdj(linkDG);
	vD->setAdj(linkDF);
	vD->setLinked(true);

	Links<Hotspot> linkGE(vE, 5);
	Links<Hotspot> linkGD(vD, 10);
	Links<Hotspot> linkGF(vF, 3);
	vG->setAdj(linkGE);
	vG->setAdj(linkGD);
	vG->setAdj(linkGF);
	vG->setLinked(true);

	Links<Hotspot> linkFD(vD, 2);
	Links<Hotspot> linkFG(vG, 3);
	vF->setAdj(linkFD);
	vF->setAdj(linkFG);
	vF->setLinked(true);

	vector<Nodes<Hotspot> *> vertices;
	vertices.push_back(vA);
	vertices.push_back(vB);
	vertices.push_back(vC);
	vertices.push_back(vD);
	vertices.push_back(vE);
	vertices.push_back(vF);
	vertices.push_back(vG);

//	for(int i=0; i<vertices.size();i++) {
//		cout<<"Vertice: "<<vertices[i]->getInfo().getNome()<<endl;
//for(int nlink=0; nlink<vertices[i]->getAdj().size(); nlink++)
//	cout<<"link "<<vertices[i]->getAdj()[nlink].getDest()->getInfo().getNome()<<"; dist :"<<vertices[i]->getAdj()[nlink].getWeight()<<endl;
//	}

	Dijkstra dj;
	dj.findPath(vB);

	Nodes<Hotspot> * vert=vG;
		while(vert!=vB){
			cout<<"vert name: "<<vert->getInfo()<<endl;
			cout<<"vert anterior: "<<vert->getPrevious()->getInfo()<<endl;
			cout<<endl;
			vert=vert->getPrevious();
		}

	//system("pause");
	return 0;
}


