

#include "Utilitarios.h"


double distancia(Hotspot & obj1, Hotspot & obj2) {

	double ret;
	ret = sqrt(pow(obj1.getCoordY() - obj2.getCoordY(), 2.0) + pow(obj1.getCoordX() - obj2.getCoordX(), 2.0));
	return ret;
}

double calcDistMinima(vector<Nodes<Hotspot> *> const &g1) {
	double dist = DMAX, temp = 0;


	for (unsigned int i = 0; i < g1.size(); i++){
		for (unsigned int j = 0; j < g1.size(); j++){
			if (i == j)
				continue;
			temp = distancia(g1.at(i)->getInfo(), g1.at(j)->getInfo());
			if (dist > temp){
				dist = temp;
			}
		}
	}

	return dist;

}
