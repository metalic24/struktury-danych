#pragma once
#include<iostream>

struct Table {

	int *tablica;
	int ile;

	void wyswietl();
	void dodaj_element( int v, int miejsce); //jesli miejsce bedzie rowne 0, to element zostanie dodany na pocz¹tek tablicy, a gdy miejsce bêdzie równe wielkoœci tablicy, to zostanie dodany na koniec
	void znajdz(int szukana);
	void usun(int usuwana);
	void min_max();

	Table(int ile);

};


