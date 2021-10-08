#pragma once
#include "drzewo.h"
#include "tablica.h"
#include "lista.h"
#include <fstream>
#include<time.h>

using namespace std;

unsigned int losuj(unsigned int przedzial);
float srednia(float suma, int ile_prob);
void wczytaj_do_pliku(string nazwa, int ile, unsigned int przedzial);
void eksperyment();