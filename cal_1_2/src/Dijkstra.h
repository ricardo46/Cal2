/*
 * Dijkstra.h
 *
 *  Created on: 19/04/2015
 *      Author: Ricardo
 */

#ifndef SRC_DIJKSTRA_H_
#define SRC_DIJKSTRA_H_
#include "nodes.h"
#include "Hotspot.h"

using namespace std;

class Dijkstra {
public:
	Dijkstra();
	void findPath(Nodes<Hotspot> * source);
	virtual ~Dijkstra();
};

#endif /* SRC_DIJKSTRA_H_ */

