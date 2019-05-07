#pragma once
#ifndef LISTASASIEDZTWA
#define LISTASASIEDZTWA
#include<iostream>
#include"Lista.h"
/*
template<class Typ>
struct Vertex {
public:
	Typ Waga;
	Element<Typ> *Pos;
	Lista<Vertex<Typ>> *Incydentne;
	friend std::ostream & operator<< (std::ostream &wyjscie, const Vertex<int> &s);
};


std::ostream & operator<< (std::ostream &wyjscie, const Vertex<int> &s) {
	return wyjscie << "Waga: " << s.Waga;
}

template<class Typ>
struct Edge {
public:
	Typ Waga;
	Vertex<Typ> Start, Koniec;
	Lista<Vertex<Typ>> *Incydentne;
	Element<Typ> *Pos;
	friend std::ostream & operator<< (std::ostream &wyjscie, const Edge<int> &s);
};

std::ostream & operator<< (std::ostream &wyjscie, const Edge<int> &s) {
	return wyjscie << " Waga: " << s.Waga << " | " << s.Start << " -> " << s.Koniec;
}

template<class Typ>
class ListaSasiedztwa {
public:
	Lista<Edge<Typ>> ListaKrawedzi;
	Lista<Vertex<Typ>> ListaWierzcholkow;
	Lista<Lista<Vertex<Typ>>> ListaListIncydencji;

public:
	//Graph();
	//~Graph();
	bool insertVertex(Typ W);
	bool insertEdge(Vertex<Typ> Start, Vertex<Typ> Koniec, Typ Wartosc);
	bool removeVertex(Vertex<Typ> W);
	bool removeEdge(Edge<Typ> K);
	unsigned int Stopien(Vertex<Typ> W);
	void vertices();
	void edges();
};

template<class Typ>
bool ListaSasiedztwa<Typ>::insertVertex(Typ W)
{
	Vertex<Typ> K;
	K.Waga = W;
	ListaWierzcholkow.Dodaj_element_na_koniec(K);
	return true;
}
*/
#endif