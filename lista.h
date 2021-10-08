#pragma once
#include <iostream>
struct element_listy {
    int value;
    element_listy* next; // wskaünik na nastÍpny element
    element_listy(); // konstruktor
};



struct lista {
public: 
    element_listy* begin; // wskaünik na poczπtek listy
    void dodaj_element_na_koniec(int value);
    void dodaj_na_poczatek(int value);
    void dodaj_na_miejsce(int value, int miejsce);
    void wyswietl();
    void znajdz(int szukana);
    void usun(int usuwana);
    void min_max();

    lista();
};




