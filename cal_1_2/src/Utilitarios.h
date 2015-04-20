#ifndef UTILITARIOS_H_
#define UTILITARIOS_H_

#include <vector>
#include <cmath>

#include "Hotspot.h"
#include "nodes.h"
#include "Graph.h"

using namespace std;

const int X = 0;
const int Y = 1;

#define DMAX 999999999
/*
 template <class T>
 double comparaPontos(T p1, T p2, int type) {
 if (type == X)
 return p1.x - p2.x;
 return p1.y - p2.y;
 }


 template <class T>
 T & median3(vector<T> &v, int left, int right, int type)
 {
 int center = (left + right) / 2;
 if (comparaPontos(v[center], v[left], type) < 0)
 swap(v[left], v[center]);

 if (comparaPontos(v[right], v[left], type) < 0)
 swap(v[left], v[right]);

 if (comparaPontos(v[right], v[center], type) < 0)
 swap(v[center], v[right]);

 swap(v[center], v[right - 1]);     // put pivot in position 'right-1'
 return v[right - 1];
 }

 template <class T>
 void quickSort(vector<T> &v, int left, int right, int type)
 {

 T p = median3(v, left, right, type);  // x is pivot
 int i = left; int j = right - 1;            // partition step
 double comp;
 for (;;) {

 comp = -1;
 while (comp < 0) {
 comp = comparaPontos(v[++i], p, type);
 }

 comp = -1;
 while (comp < 0) {
 comp = comparaPontos(p, v[--j], type);
 }
 if (i < j)
 swap(v[i], v[j]);
 else break;
 }
 swap(v[i], v[right - 1]);  // reset pivot
 quickSort(v, left, i - 1, type);
 quickSort(v, i + 1, right, type);

 }


 template<class T>
 double np_DC(vector<T> &vp, int left, int right, T &pLeft, T &pRight) {

 if ((right - left) == 1) {
 pLeft = vp[left];
 pRight = vp[right];
 return vp[left].distancia(vp[right]);
 }
 if (right == left) {
 pLeft = vp[left];
 pRight = vp[right];
 return DMAXIMUM;
 }

 T p1L, p2L, p1R, p2R;
 int middle = (right + left) / 2;
 double dminL = np_DC(vp, left, middle, p1L, p2L);
 double dminR = np_DC(vp, middle + 1, right, p1R, p2R);
 double dminAux;
 if (dminR < dminL) {
 pLeft = p1R;
 pRight = p2R;
 dminAux = dminR;
 }
 else {
 pLeft = p1L;
 pRight = p2L;
 dminAux = dminL;
 }

 int indLeft = middle - 1;
 int indRight = middle + 1;
 while ((indLeft > left) && (vp[middle].x - vp[indLeft].x < dminAux))
 indLeft--;
 while ((indRight < right) && (vp[indRight].x - vp[middle].x < dminAux))
 indRight++;

 // strip area around middle point defined
 quickSort(vp, indLeft, indRight, Y);		// strip values ordered by Y coordinate

 for (int i = indLeft; i < indRight; i++) {
 for (int j = i + 1; j <= indRight; j++) {
 if (vp[j].y - vp[i].y > dminAux)
 break;
 else {
 double d = vp[i].distancia(vp[j]);
 if (d < dminAux) {
 pLeft = vp[i];		// save one point
 pRight = vp[j];		// save the other point
 dminAux = d;			// save minimum distance
 }
 }
 }
 }
 quickSort(vp, indLeft, indRight, X);		// strip values reordered by X coordinate
 return dminAux;
 }


 template <class T>
 double nearestPoints_DC(vector<T> &vp, vector<T> &vMP) {
 // TODO code must be placed here
 quickSort(vp, 0, vp.size() - 1, X);		// vp ordered by X coordinate

 // call divide and conquer algorithm for 'vp' vector of Ponto's
 T p1, p2;
 double dist = np_DC(vp, 0, vp.size() - 1, p1, p2);

 vMP.push_back(p1);		// save point 1
 vMP.push_back(p2);		// save point 2
 return dist;			// return minimum distance
 }

 */

double distancia(Hotspot & obj1, Hotspot & obj2);

double calcDistMinima(vector<Nodes<Hotspot> *> const &g1);

template<class T>
double calcDist(vector<Nodes<T> *> const &vec, T &obj) {
	double dist = DMAX, temp = 0;

	for (unsigned int i = 0; i < vec.size(); i++) {
		if (!(obj == vec[i]->getInfo())) {
			if (!vec[i]->getLinked()) {
				temp = distancia(vec.at(i)->getInfo(), obj);
				if (dist > temp) {
					dist = temp;
				}

			}
		}

	}
if(dist == DMAX)
	return 0;
	return dist;
}

template<class T>
int nearestNode(vector<Nodes<T> *> const &vec, T &obj) {
	double dist = DMAX, temp = 0;
	int j = -1;
	int n;
	for (unsigned int i = 0; i < vec.size(); i++) {
		if ((obj == vec[i]->getInfo())) {
			n=i;
		}
		if (!(obj == vec[i]->getInfo())) {
			if (!vec[i]->getLinked()) {
			temp = distancia(vec.at(i)->getInfo(), obj);
			if (dist > temp) {
				dist = temp;
				j = i;
			}
		}
		}

	}
if(j==-1)
{
	return n;
}
	return j;

}

#endif
