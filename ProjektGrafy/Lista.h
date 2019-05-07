#pragma once
#ifndef LISTA
#define LISTA
#include<iostream>
#include"struktury.h"
#include"Lista.h"

template<class Typ>
struct Element {
	Element * Nastepny;
	Typ Wartosc;
	Element();
};

template<class Typ>
Element<Typ>::Element() {
	Nastepny = NULL;
}

template<class Typ>
struct Lista {
	Element<Typ> * Pierwszy;
	void Dodaj_element_na_koniec(Typ W);
	void Dodaj_element_na_poczatek(Typ W);
	void Usun_element(unsigned int Nr);
	void Wyswietl_liste();
	unsigned int Size();
	Element<Typ>* Ostatni();
	Element<Typ>* nr(unsigned int n);
	Lista();
};

template<class Typ>
Lista<Typ>::Lista() {
	Pierwszy = NULL;
}

template<class Typ>
Element<Typ>* Lista<Typ>::Ostatni()
{
	if (Pierwszy == NULL)
		return NULL;
	else
	{
		// w przeciwnym wypadku wêdrujemy na koniec listy
		Element<Typ> *temp = Pierwszy;

		while (temp->Nastepny)
		{
			// znajdujemy wskaŸnik na ostatni element
			temp = temp->Nastepny;
		}
		return temp;
	}
}

template<class Typ>
Element<Typ>* Lista<Typ>::nr(unsigned int n)
{
	if (n > Size())
		return NULL;
	else
	{
		// w przeciwnym wypadku wêdrujemy na n-ty element
		Element<Typ> *temp = Pierwszy;

		for (unsigned int i = 0; i < n; i++)
		{
			// znajdujemy wskaŸnik na n-ty element
			temp = temp->Nastepny;
		}
		return temp;
	}
}

template<class
	Typ>
	void Lista<Typ>::Dodaj_element_na_koniec(Typ W)
{
	Element<Typ> *nowy = new Element<Typ>;    // tworzy nowy element listy

	nowy->Wartosc = W;
	if (Pierwszy == NULL) // sprawdzamy czy to pierwszy element listy
		Pierwszy = nowy;

	else
	{
		// w przeciwnym wypadku wêdrujemy na koniec listy
		Element<Typ> *temp = Pierwszy;

		while (temp->Nastepny)
		{
			// znajdujemy wskaŸnik na ostatni element
			temp = temp->Nastepny;
		}

		temp->Nastepny = nowy;  // ostatni element wskazuje na nasz nowy
		nowy->Nastepny = NULL;     // ostatni nie wskazuje na nic
	}
}

template<class Typ>
void Lista<Typ>::Dodaj_element_na_poczatek(Typ W)
{
	Element<Typ> * nowy = new Element<Typ>;

	nowy->Wartosc = W;    // inicjujemy element
	nowy->Nastepny = Pierwszy;
	Pierwszy = nowy;
}

template<class Typ>
void Lista<Typ>::Usun_element(unsigned int Nr)
{
	if (Nr == 1)
	{
		Element<Typ> *temp = Pierwszy;
		Pierwszy = temp->Nastepny;
	}

	if (Nr >= 2)
	{
		int j = 1;
		// do usuniecia srodkowego elemetnu potrzebujemy wskaznika na osobe n-1
		// wskaznik *temp bedzie wskaznikiem na osobe poprzedzajaca osobe usuwana
		Element<Typ> *temp = Pierwszy;

		while (temp)
		{
			// sprawdzamy czy wskaznik jest na osobie n-1 niz usuwana
			if ((j + 1) == Nr) break;

			// jezeli nie to przewijamy petle do przodu
			temp = temp->Nastepny;
			j++;
		}

		// wskaznik *temp wskazuje teraz na osobe n-1
		// nadpisujemy wkaznik osoby n na osobe n+1
		// bezpowrotnie tracimy osobe n-ta

		// dodatkowo sprawdzamy czy aby nie jest to ostatni element
		// wtedy nalezy wyzerowac ostatni wskaznik
		if (temp->Nastepny->Nastepny == NULL)
			temp->Nastepny = NULL;

		// jezeli nie byl to ostatni element
		else
			temp->Nastepny = temp->Nastepny->Nastepny;
	}
}

template<class Typ>
void Lista<Typ>::Wyswietl_liste()
{
	// wskaznik na pierszy element listy
	Element<Typ> *temp = Pierwszy;

	// przewijamy wskazniki na nastepne elementy
	while (temp)
	{
		std::cout << " " << temp->Wartosc << std::endl;
		temp = temp->Nastepny;
	}
}

template<class Typ>
unsigned int Lista<Typ>::Size()
{
	Element<Typ> *temp = Pierwszy;
	unsigned size = 0;

	while (temp)
	{
		size++;
		temp = temp->Nastepny;
	}

	return size;
}
#endif