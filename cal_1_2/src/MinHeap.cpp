/*
 * MinHeap.cpp
 *
 *  Created on: 19/04/2015
 *      Author: Ricardo
 */

#include "MinHeap.h"

struct greater1 {
	bool operator()(Nodes<Hotspot> *& a, Nodes<Hotspot> *& b) {

		return a->getInfo().getMinDist() > b->getInfo().getMinDist();
	}
};

void Push(vector<Nodes<Hotspot> *>& heap, Nodes<Hotspot> * val) {
	heap.push_back(val);
	push_heap(heap.begin(), heap.end(), greater1());
}

Nodes<Hotspot> * Pop(vector<Nodes<Hotspot> *>& heap) {
	Nodes<Hotspot> * val = heap.front();

	//This operation will move the smallest element to the end of the vector
	pop_heap(heap.begin(), heap.end(), greater1());

	//Remove the last element from vector, which is the smallest element
	heap.pop_back();
	return val;
}

void Remove(vector<Nodes<Hotspot> *>& heap, Nodes<Hotspot> * val) {
	heap.erase(std::remove(heap.begin(), heap.end(), val), heap.end());

}
