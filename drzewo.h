#pragma once
#include <stdio.h>
#include<stdlib.h>
#include<iostream>


struct Wezel
{
	Wezel* l;
	Wezel* p;
	Wezel* rodzic;
	int value;

};


struct Drzewo
{
public: 
	Wezel* root; // korzen

	
	void dodaj(int v); //funkcja dodawania wezla
	void wyswietl(Wezel *s);
	void znajdz(int szukana);
	void usun(int usuwana);
	void usun_wezel(Wezel* s);
	void min();
	void max();
	Drzewo(); // konstruktor
};

