#pragma once
#ifndef STRUKTURY
#define STRUKTURY
#include<iostream>
#include"struktury.h"
#include"Lista.h"

template<class Typ>
struct Wierzcholek {
	Typ Wartosc;
	unsigned int Klucz;
	friend std::ostream & operator<< (std::ostream &wyjscie, const Wierzcholek<int> &s);
};


std::ostream & operator<< (std::ostream &wyjscie, const Wierzcholek<int> &s) {
	return wyjscie << "Wartosc: " << s.Wartosc << " Klucz: " << s.Klucz;
}

template<class Typ>
struct Krawedz {
	Typ Waga;
	Wierzcholek<Typ> Start, Koniec;
	unsigned int Klucz;
	friend std::ostream & operator<< (std::ostream &wyjscie, const Krawedz<int> &s);
};

std::ostream & operator<< (std::ostream &wyjscie, const Krawedz<int> &s) {
	return wyjscie << " Waga: " << s.Waga << " | " << s.Start << " -> " << s.Koniec;
}

template<class Typ>
class Graph {
public:
	Lista<Wierzcholek<Typ>> ListaWierzcholkow;
	Lista<Krawedz<Typ>> ListaKrawedzi;
	Krawedz<Typ> ***MacierzSasiedztwa;
	//Graph();
	//~Graph();
	bool insertVertex(Typ W);
	bool insertEdge(Wierzcholek<Typ> Start, Wierzcholek<Typ> Koniec, Typ Wartosc);
	bool removeVertex(Wierzcholek<Typ> W);
	bool removeEdge(Krawedz<Typ> K);
	unsigned int Stopien(Wierzcholek<Typ> W);
	void vertices();
	void edges();
};
/*
template<class Typ>
Graph<Typ>::~Graph()
{
		for (unsigned int i = 0; i < ListaWierzcholkow.Size(); ++i)
			delete[] MacierzSasiedztwa[i];
	delete[] MacierzSasiedztwa;
}
*/

template<class Typ>
void Graph<Typ>::vertices()
{
	ListaWierzcholkow.Wyswietl_liste();
}

template<class Typ>
void Graph<Typ>::edges()
{
	for (unsigned int i = 0; i < ListaWierzcholkow.Size(); i++)
	{
		for (unsigned int j = 0; j < ListaWierzcholkow.Size(); j++)
		{
			if (MacierzSasiedztwa[i][j] != NULL)
				std::cout << " ! ";
			//std::cout << *MacierzSasiedztwa[i][j] << " ";
			else
				if (i > j)
					std::cout << i << " ";
				else
					std::cout << j << " ";
		}
		std::cout << std::endl;
	}
	ListaKrawedzi.Wyswietl_liste();
}

template<class Typ>
bool Graph<Typ>::insertVertex(Typ W)
{
	Wierzcholek<Typ> K;
	K.Wartosc = W;
	K.Klucz = ListaWierzcholkow.Size();
	Krawedz<Typ> ***Pomoc;
	Pomoc = new Krawedz<Typ>**[ListaWierzcholkow.Size()];
	for (unsigned int i = 0; i < ListaWierzcholkow.Size(); i++)
	{
		Pomoc[i] = new Krawedz<Typ>*[ListaWierzcholkow.Size()];
		for (unsigned int j = 0; j < ListaWierzcholkow.Size(); j++) Pomoc[i][j] = MacierzSasiedztwa[i][j];
	}
	for (unsigned int i = 0; i < ListaWierzcholkow.Size(); ++i)
		delete[] MacierzSasiedztwa[i];
	delete[] MacierzSasiedztwa;

	ListaWierzcholkow.Dodaj_element_na_koniec(K);
	MacierzSasiedztwa = new Krawedz<Typ>**[ListaWierzcholkow.Size()];
	for (unsigned int i = 0; i < ListaWierzcholkow.Size(); i++)
	{
		MacierzSasiedztwa[i] = new Krawedz<Typ>*[ListaWierzcholkow.Size()];
		for (unsigned int j = 0; j < ListaWierzcholkow.Size(); j++) MacierzSasiedztwa[i][j] = NULL;
	}

	for (unsigned int i = 0; i < ListaWierzcholkow.Size() - 1; i++)
		for (unsigned int j = 0; j < ListaWierzcholkow.Size() - 1; j++) MacierzSasiedztwa[i][j] = Pomoc[i][j];

	for (unsigned int i = 0; i < ListaWierzcholkow.Size() - 1; ++i)
		delete[] Pomoc[i];
	delete[] Pomoc;
	return true;
}

template<class Typ>
bool Graph<Typ>::insertEdge(Wierzcholek<Typ> Start, Wierzcholek<Typ> Koniec, Typ Wartosc)
{
	Krawedz<Typ> K;
	K.Waga = Wartosc;
	K.Start = Start;
	K.Koniec = Koniec;
	K.Klucz = ListaKrawedzi.Size();
	ListaKrawedzi.Dodaj_element_na_koniec(K);

	if (ListaWierzcholkow.Size() != 0)
		if (MacierzSasiedztwa[K.Start.Klucz][K.Koniec.Klucz] != NULL) return false;
		else {
			MacierzSasiedztwa[K.Start.Klucz][K.Koniec.Klucz] = &ListaKrawedzi.Ostatni()->Wartosc;
			MacierzSasiedztwa[K.Koniec.Klucz][K.Start.Klucz] = &ListaKrawedzi.Ostatni()->Wartosc;   // krawêdŸ symetryczna
			return true;
		}
	else return false;
}

template<class Typ>
bool Graph<Typ>::removeEdge(Krawedz<Typ> K)
{
	if (MacierzSasiedztwa[K.Start.Klucz][K.Koniec.Klucz] == NULL) return false; // nie ma co usun¹æ 
	else {
		MacierzSasiedztwa[K.Start.Klucz][K.Koniec.Klucz] = NULL;
		MacierzSasiedztwa[K.Koniec.Klucz][K.Start.Klucz] = NULL;
		ListaKrawedzi.Usun_element(K.Klucz + 1);
		return true;
	}
}

template<class Typ>
unsigned int Graph<Typ>::Stopien(Wierzcholek<Typ> W)
{
	unsigned int Wynik = 0;
	for (unsigned int i = 0; i < ListaWierzcholkow.Size(); ++i)
		if (MacierzSasiedztwa[W.Klucz][i] != NULL)
			Wynik++;
	return Wynik;
}

#endif