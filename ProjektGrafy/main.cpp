#include<iostream>
#include<cstdlib>
#include<ctime>
#include"struktury.h"
#include"ListaSasiedztwa.h"
#include"Lista.h"
#include"algorytmy.h"

int main()
{
	
	Graph<int> graf;
	Graph<int> MinDR;
	
	//ListaSasiedztwa<int> graf;
	unsigned int LiczbaWierzcholkow = 50;
	srand(time(NULL));
	for (unsigned int i = 0; i < LiczbaWierzcholkow; i++)
		graf.insertVertex(rand() % LiczbaWierzcholkow);
	for (unsigned int i = 0; i < LiczbaWierzcholkow; i++)
		for (unsigned int j = 0; j < LiczbaWierzcholkow; j++)
			graf.insertEdge(graf.ListaWierzcholkow.nr(i)->Wartosc, graf.ListaWierzcholkow.nr(j)->Wartosc, rand() % 100);
	graf.edges();
	graf.vertices();
	std::cin.ignore();
	return 0;
}