// Wykonał Mateusz Kraszewski
#include<iomanip>
#include <iostream>
#include<chrono>
#include"funkcje.h"

using  namespace std;


fstream pliktest;



int main()
{

	srand(time(NULL));
	string nazwa;
	int wybor = 0;
	int dane;
	int ile_elementow;
	int miejsce;
	int dodawana;

	cout << endl << "[1] podanie nazwy pliku";
	cout << endl << "[2] domyslny plik"<<endl;
	cin >> wybor;
	switch (wybor)
	{
	case 1:
		cout << endl;
		cout << "Podaj sciezke do pliku: ";
		cin >> nazwa;
		break;
	default:
		nazwa = "losowe.txt";
		break;
	}


	pliktest.open(nazwa, ios::in | ios::out);
	pliktest >> ile_elementow;


	Table* tablica = new Table(ile_elementow);
	lista* list = new lista();
	Drzewo* drzewo = new Drzewo();

	for (int i = 0; i < ile_elementow; i++)
	{
		pliktest >> dane;
		tablica->tablica[i] = dane;
		list->dodaj_element_na_koniec(dane);
		drzewo->dodaj(dane);
	}

	pliktest.close();

	do
	{
		cout << endl;
		cout << endl << "[1] dodanie danych";
		cout << endl << "[2] szukanie danych";
		cout << endl << "[3] usuwanie danych";
		cout << endl << "[4] minimum i maksimum";
		cout << endl << "[5] wyswietlanie danych";
		cout << endl << "[6] koniec";
		cout << endl;
		cin >> wybor;
		switch (wybor)
		{
		case 1:
			cout << endl;
			cout << endl << "Jaka wartosc chesz dodac: ";
			 dodawana;
			cin >> dodawana;
			//dodawanie elementów
			
			//dodawanie na początek
			
			tablica->dodaj_element(dodawana, 0);

			list->dodaj_na_poczatek(dodawana);
			

			//dodawanie na losowe miejsce

			 miejsce = losuj(ile_elementow);


			tablica->dodaj_element(dodawana, miejsce);
			list->dodaj_na_miejsce(dodawana, miejsce);
		
			//dodawaniena koniec;
			tablica->dodaj_element(dodawana + 2, tablica->ile);
			list->dodaj_element_na_koniec(dodawana + 2);
			drzewo->dodaj(dodawana);
		
			

			break;

		case 2:

			cout << endl;
			cout << endl << "Jaka wartosc chesz znalezc: ";
			int szukana;
			cin >> szukana;

			tablica->znajdz(szukana);
			list->znajdz(szukana);
			drzewo->znajdz(szukana);


			break;

		case 3:

			cout << endl;
			cout << endl << "Jaka wartosc chesz usunac: ";
			int uwana;
			cin >> uwana;

			tablica->usun(uwana);
			list->usun(uwana);
			drzewo->usun(uwana);

			break;
		case 4:

			tablica->min_max();
			list->min_max();

			drzewo->max();
			drzewo->min();

			break;

		case 5:

			cout << endl;
			cout << endl << "Tablica: ";
			tablica->wyswietl();

			cout << endl << "Lista: ";
			list->wyswietl();

			cout << endl << "Drzewo:";
			drzewo->wyswietl(drzewo->root);



			break;




		}
	} while (wybor != 6);
	

	//funkcja wykonująca eksperyment
	//eksperyment();

}

