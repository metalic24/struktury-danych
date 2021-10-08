#include"funkcje.h"

clock_t start, stop;
double czas;
float dodawanie[3], wyswietlanie[3], min_max[3], wyszukiwanie[3], wstawianie_poczatek[3], wstawianie_koniec[3], wstawianie_losowe[3], usuwanie[3]; // zmienne bêd¹ przechowywa³y sumy czasów funkcji 0-tablica, 1 lista 2 drzewo

// dane do testu
string nazwa_pliku = "losowe.txt";
int ile_liczb = 100000;
int ile_prob = 1;
unsigned int przedzial = 30000;
int dane;
int ile_elementow;
fstream plik;


unsigned int losuj(unsigned int przedzial)
{
	return rand()%przedzial+1;
}

float srednia(float suma, int ile_prob)
{
	return (suma/ile_prob);
}

void wczytaj_do_pliku(string nazwa, int ile, unsigned int przedzial)
{
	fstream plik;

	plik.open(nazwa, ios::in | ios::out);

	plik << ile << endl;
	int dodawana = losuj(przedzial);
	for (int i = 0; i < ile; i++)
	{
		//generowanie liczb losowych
		plik << losuj(przedzial) << endl;

		//generowanie liczb rosn¹co

		//plik << i + dodawana << endl;
	}


	plik.close();

}

// funckie wykonuj¹ca eksperyment
void eksperyment()
{

	for (int i = 0; i < ile_prob; i++)
	{


		//	wczytaj_do_pliku(nazwa_pliku, ile_liczb, przedzial);



		plik.open(nazwa_pliku, ios::in | ios::out);
		plik >> ile_elementow;


		Table* tablica = new Table(ile_elementow);
		lista* list = new lista();
		Drzewo* drzewo = new Drzewo();

		for (int i = 0; i < ile_elementow; i++)
		{
			plik >> dane;
			tablica->tablica[i] = dane;
			list->dodaj_element_na_koniec(dane);
			drzewo->dodaj(dane);
		}

		plik.close();
		plik.clear();
		//dodawanie elementów
		int dodawany = losuj(przedzial);
		//dodawanie na pocz¹tek
		start = clock();
		tablica->dodaj_element(dodawany, 0);
		stop = clock();
		czas = (double)(stop - start) / CLOCKS_PER_SEC;

		wstawianie_poczatek[0] += (float)czas;

		start = clock();
		list->dodaj_na_poczatek(dodawany);
		stop = clock();
		czas = (double)(stop - start) / CLOCKS_PER_SEC;
		wstawianie_poczatek[1] += (float)czas;

		//dodawanie na losowe miejsce

		int miejsce = losuj(ile_elementow);

		start = clock();
		tablica->dodaj_element(dodawany + 1, miejsce);
		stop = clock();
		czas = (double)(stop - start) / CLOCKS_PER_SEC;

		wstawianie_losowe[0] += (float)czas;

		start = clock();
		list->dodaj_na_miejsce(dodawany + 1, miejsce);
		stop = clock();
		czas = (double)(stop - start) / CLOCKS_PER_SEC;
		wstawianie_losowe[1] += (float)czas;
		//dodawanie na koniec
		start = clock();
		tablica->dodaj_element(dodawany + 2, tablica->ile);
		stop = clock();
		czas = (double)(stop - start) / CLOCKS_PER_SEC;
		wstawianie_koniec[0] += (float)czas;

		start = clock();
		list->dodaj_element_na_koniec(dodawany + 2);
		stop = clock();
		czas = (double)(stop - start) / CLOCKS_PER_SEC;
		wstawianie_koniec[1] += (float)czas;

		start = clock();
		drzewo->dodaj(dodawany);
		stop = clock();
		czas = (double)(stop - start) / CLOCKS_PER_SEC;
		wstawianie_koniec[2] += (float)czas;

		//szukanie elementów
		int szukany = losuj(przedzial);

		start = clock();
		tablica->znajdz(szukany);
		stop = clock();
		czas = (double)(stop - start) / CLOCKS_PER_SEC;
		wyszukiwanie[0] += (float)czas;

		start = clock();
		list->znajdz(szukany);
		stop = clock();
		czas = (double)(stop - start) / CLOCKS_PER_SEC;
		wyszukiwanie[1] += (float)czas;

		start = clock();
		drzewo->znajdz(szukany);
		stop = clock();
		czas = (double)(stop - start) / CLOCKS_PER_SEC;
		wyszukiwanie[2] += (float)czas;
		//usuwanie elementów
		int usuwany = dodawany + 1;

		start = clock();
		tablica->usun(usuwany);
		stop = clock();
		czas = (double)(stop - start) / CLOCKS_PER_SEC;
		usuwanie[0] += (float)czas;


		start = clock();
		list->usun(usuwany);
		stop = clock();
		czas = (double)(stop - start) / CLOCKS_PER_SEC;
		usuwanie[1] += (float)czas;

		start = clock();
		drzewo->usun(usuwany);
		stop = clock();
		czas = (double)(stop - start) / CLOCKS_PER_SEC;
		usuwanie[2] += (float)czas;

		//minimum i maksimum
	//	drzewo->wyswietl(drzewo->root);

		start = clock();
		tablica->min_max();
		stop = clock();
		czas = (double)(stop - start) / CLOCKS_PER_SEC;
		min_max[0] += (float)czas;

		start = clock();
		list->min_max();
		stop = clock();
		czas = (double)(stop - start) / CLOCKS_PER_SEC;
		min_max[1] += (float)czas;

		start = clock();
		drzewo->min();
		drzewo->max();
		stop = clock();
		czas = (double)(stop - start) / CLOCKS_PER_SEC;
		min_max[2] += (float)czas;


		delete tablica;
		delete drzewo;
		delete list;


	}


	cout << endl << wstawianie_poczatek[0];

	cout.precision(10);

	cout << endl << wstawianie_poczatek[0];
	cout << endl << endl;
	cout << endl << "------DODAWANIE ELEMENTOW-------";
	cout << endl << "Czas dodawania elementow na poczatek tablicy: " << (double)srednia(wstawianie_poczatek[0], ile_prob) << "s.";
	cout << endl << "Czas dodawania elementow na poczatek listy: " << (double)srednia(wstawianie_poczatek[1], ile_prob) << "s.";
	cout << endl;
	cout << endl << "Czas dodawania elementow na losowe miejsce tablicy: " << (double)srednia(wstawianie_losowe[0], ile_prob) << "s.";
	cout << endl << "Czas dodawania elementow na losowe miejsce liczby: " << (double)srednia(wstawianie_losowe[1], ile_prob) << "s.";
	cout << endl;
	cout << endl << "Czas dodawania elementow na koniec tablicy: " << (double)srednia(wstawianie_losowe[0], ile_prob) << "s.";
	cout << endl << "Czas dodawania elementow na koniec listy: " << (double)srednia(wstawianie_koniec[1], ile_prob) << "s.";
	cout << endl << "Czas dodawania elementow do drzewa: " << (double)srednia(wstawianie_koniec[2], ile_prob) << "s.";

	cout << endl;

	cout << endl << "------SZUKANIE ELEMENTOW-------";

	cout << endl << "Czas wyszukiwania elementu w tablicy: " << (double)srednia(wyszukiwanie[0], ile_prob) << "s.";
	cout << endl << "Czas wyszukiwania elementu w liscie : " << (double)srednia(wyszukiwanie[1], ile_prob) << "s.";
	cout << endl << "Czas wyszukiwania elementu w drzewie: " << (double)srednia(wyszukiwanie[2], ile_prob) << "s.";

	cout << endl;

	cout << endl << "------USUWANIE ELEMENTOW-------";

	cout << endl << "Czas usuwania elementu w tablicy: " << (double)srednia(usuwanie[0], ile_prob) << "s.";
	cout << endl << "Czas usuwania elementu w liscie: " << (double)srednia(usuwanie[1], ile_prob) << "s.";
	cout << endl << "Czas usuwania elementu w drzewie: " << (double)srednia(usuwanie[2], ile_prob) << "s.";

	cout << endl;

	cout << endl << "------ Wyszukiwanie minimum i maksimum-------";

	cout << endl << "Czas wyszukania minimum i maksimum w tablicy : " << (double)srednia(min_max[0], ile_prob) << "s.";
	cout << endl << "Czas wyszukania minimum i maksimum w liscie : " << (double)srednia(min_max[1], ile_prob) << "s.";
	cout << endl << "Czas wyszukania minimum i maksimum w drzewie : " << (double)srednia(min_max[2], ile_prob) << "s.";
}
