#include <algorithm>
#include <iostream>
#include <vector>
#include <iterator>
#include <functional>

#include "Utilitarios.h"
#include "Graph.h"
#include "Hotspot.h"
#include <string>

using namespace std;

int main() {

	Graph<Hotspot> g1;
	g1.createGraph();//

	int posVertice=0;//vertice de partida ou central e corresponde à ordem pela qual Hotspot foi adicionado ao Graph. Neste caso sendo 0 é o primeiro Hotspot do ficheiro nodes.txt
	g1.setShortestPaths(posVertice);
	g1.showPaths(posVertice);

	return 0;
}

