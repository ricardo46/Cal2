/*
 * Dijkstra.cpp
 *
 *  Created on: 19/04/2015
 *      Author: Ricardo
 */

#include "Dijkstra.h"
#include "MinHeap.h"
#include "Links.h"

Dijkstra::Dijkstra() {
	// TODO Auto-generated constructor stub

}

Dijkstra::~Dijkstra() {
	// TODO Auto-generated destructor stub
}

void Dijkstra::findPath(Nodes<Hotspot> * source) {
	Hotspot sourceHotspot = source->getInfo();
	sourceHotspot.setMinDist(0);
	source->setInfo(sourceHotspot);
	vector<Nodes<Hotspot> *> vertHeap;
	Push(vertHeap, source);

	while (vertHeap.size() != 0) {
		Nodes<Hotspot> * u = Pop(vertHeap);
		u->setVisited(true);
		for (int i = 0; i < u->getAdj().size(); i++) {
			Nodes<Hotspot> * v = u->getAdj()[i].getDest();
			double weight = u->getAdj()[i].getWeight();
			double distanceThroughU = u->getInfo().getMinDist() + weight;
			if (distanceThroughU < v->getInfo().getMinDist()) {
				Remove(vertHeap, v);
				Hotspot hotspot = v->getInfo();
				hotspot.setMinDist(distanceThroughU);
				v->setInfo(hotspot);
				v->setPrevious(u);
				Push(vertHeap, v);
			}
		}
	}



//Nodes<Hotspot> * no2=source->getAdj()[0].getDest();
//
//Hotspot no2Hotspot= source->getAdj()[0].getDest()->getInfo();
//no2Hotspot.setMinDist(3);
//no2->setInfo(no2Hotspot);
//
//Nodes<Hotspot> * no3=source->getAdj()[1].getDest();
//
//Push(vertHeap, no2);
//Push(vertHeap, no3);

//for(int i=0; i<vertHeap.size();i++){
//	cout<<vertHeap[i]->getInfo().getNome()<<endl;
//	if(no2==vertHeap[i])
//		cout<<"siiiiimmmmmm"<<endl;
//}
//
//cout<<"no dist :"<<vertHeap->getInfo().getMinDist()<<endl;
//cout<<"no dist :"<<Pop(vertHeap)->getInfo().getMinDist()<<endl;
//cout<<"no dist :"<<Pop(vertHeap)->getInfo().getMinDist()<<endl;

//cout<<"no "<<Pop(vertHeap)->getInfo().getNome()<<"; dist :"<<Pop(vertHeap)->getInfo().getMinDist()<<endl;
//cout<<"no "<<Pop(vertHeap)->getInfo().getNome()<<"; dist :"<<Pop(vertHeap)->getInfo().getMinDist()<<endl;
//cout<<"no "<<Pop(vertHeap)->getInfo().getNome()<<"; dist :"<<Pop(vertHeap)->getInfo().getMinDist()<<endl;
//Pop(vertHeap);
}

// public static void computePaths(Vertex source)
//    {
//        source.minDistance = 0.;
//        PriorityQueue<Vertex> vertexQueue = new PriorityQueue<Vertex>();
//      	vertexQueue.add(source);
//
//	while (!vertexQueue.isEmpty()) {
//	    Vertex u = vertexQueue.poll();
//
//            // Visit each edge exiting u
//            for (Edge e : u.adjacencies)
//            {
//                Vertex v = e.target;
//                double weight = e.weight;
//                double distanceThroughU = u.minDistance + weight;
//		if (distanceThroughU < v.minDistance) {
//		    vertexQueue.remove(v);
//		    v.minDistance = distanceThroughU ;
//		    v.previous = u;
//		    vertexQueue.add(v);
//		}
//            }
//        }
//    }
