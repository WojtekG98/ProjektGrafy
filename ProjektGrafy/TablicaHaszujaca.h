#pragma once
#ifndef TABLICAHASZUJACA
#define TABLICAHASZUJACA
#include<iostream>
#include"Lista.h"

class TablicaHaszujaca
{
	unsigned int N;
	Lista<int> **Tab;
public:
	TablicaHaszujaca(unsigned int n);
};
#endif
