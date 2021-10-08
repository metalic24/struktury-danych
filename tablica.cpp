#include "tablica.h"

Table::Table(int ile)
{
	tablica = new int[ile];
	this->ile = ile;
}

void Table::wyswietl()
{
	for (int i = 0; i < this->ile; i++)
	{
		std::cout << this->tablica[i] << " ";
	}
}

void Table::dodaj_element( int v, int miejsce)
{
	int* pomoc = new int[this->ile + 1];
	for(int i = miejsce; i <=this->ile; i++)
	{
		pomoc[i] = this->tablica[i];
	}
	for (int i = miejsce + 1; i <this->ile+1; i++)
	{
		this->tablica[i] = pomoc[i-1];
	}
	
	//delete[] pomoc;
	//czasami wystêpuje przerwanie w tym miejscu a czasami nie nie wiem dlaczego, szuka³em rozwi¹zania. Najprawdopodobniej jest to b¹³d z jakimœ plikiem .dll

	this->tablica[miejsce] = v;
	this->ile = this->ile + 1;
}

void Table::znajdz(int szukana)
{
	for (int i = 0; i < this->ile; i++)
	{
		if (this->tablica[i] == szukana)
		{
			std::cout << std::endl << "Szukany element istnieje i znajduje sie na pozycji " << i;
			return;
		}
	}

	std::cout << std::endl << "Element nie istnieje";



}

void Table::usun(int usuwana)
{
	int* pomoc = new int[this->ile -1];
	int j = 0;
	bool czy_znaleziono = true;
	for (int i = 0; i < this->ile; i++)
	{
		if (this->tablica[i] == usuwana && czy_znaleziono)
		{
		
			i++; //jesli znajdzie element to przeskakuje ten element tablicy
			czy_znaleziono = false; // jesli znajdzie, to nie usunie kolejnych elementow o tej samej wartosci;
			
		}
		pomoc[j] = this->tablica[i];
		j++;

	}
	//tworzymy tablice o ile-1 miejscach
	this->tablica = new int[this->ile - 1];

	for (int i = 0; i < this->ile-1; i++)
	{
		this->tablica[i] = pomoc[i];
	}

	this->ile = this->ile - 1;

	//delete[] pomoc;

}

void Table::min_max()
{
	int min = this->tablica[0];
	int max = this->tablica[0];

	for (int i = 0; i < this->ile; i++)
	{
		if (min > this->tablica[i])
		{
			min = this->tablica[i];
		}

		if (max < this->tablica[i])
		{
			max = tablica[i];
		}

		

	}

	std::cout << std::endl << "Minimum w tablicy to: " << min << ". Maksymalna wartosc w tablicy to: " << max;

}
