#include "drzewo.h"


Drzewo::Drzewo()
{
	root = NULL;
}

void Drzewo::dodaj(int v)
{
	Wezel* nowy = new Wezel(), * korzen = root, * poprzeni = NULL; 

	nowy->l = NULL;
	nowy->p = NULL;
	nowy->value = v;
	//jesli drzewo jest puste to wartoœæ staje siê korzeniem
	if (korzen == NULL)
	{
		root = nowy; 
	}
	else
	{

		//szukamy miejsca dla naszego elementu
		while (korzen != NULL)
		{
			poprzeni = korzen;
			//jeœli jest mniejszy idziemy na lewo
			if (korzen->value >= v)
			{
				korzen = korzen->l;
			}
			else //w przeciwnym przypadku na prawo
			{
				korzen = korzen->p;
			}

		}
		//dodajemy nasz element na swoje miejsce 
		if (poprzeni->value >= v)
		{
			poprzeni->l = nowy;
		}
		else
		{
			poprzeni->p = nowy;
		}

		//dodajemy wskaŸnk nowego elementu na swojego rodzica 
		nowy->rodzic = poprzeni;
	}



}

void Drzewo::wyswietl(Wezel *s)
{

		if (s != NULL) {
			
			std::cout << s->value << " [";
			wyswietl(s->l);
			 std::cout << "][";
			wyswietl(s->p);
			std::cout << "]" ;
		}
	
		
}

void Drzewo::znajdz(int szukana)
{
	Wezel* temp = root;
	while (temp !=NULL)
	{
		if (temp->value == szukana)
		{
			std::cout << std::endl << "Podana wartosc istnieje.";
			return;
		}

		if (temp->value > szukana) //jesli wartosc jest wieksza idz w lewo
		{
			temp=temp->l;
		}
		else //w przeciwnym wypadku idz w prawo
		{
			temp = temp->p;
		}
	}

	std::cout << std::endl << "Element nie istnieje";





}

void Drzewo::usun(int usuwana)
{
	Wezel* temp = root;
	while (temp != NULL)
	{
		if (temp->value == usuwana)
		{
			

			usun_wezel(temp);
			return;
		}

		if (temp->value > usuwana) //jesli wartosc jest wieksza idz w lewo
		{
			temp = temp->l;
		}
		else //w przeciwnym wypadku idz w prawo
		{
			temp = temp->p;
		}
	}

	delete temp;

}

void Drzewo::usun_wezel(Wezel* s)
{
	if (s->l == NULL && s->p == NULL)
	{
		//jezeli wezel jest korzeniem
		if (s->rodzic == NULL)
		{
			root = NULL;
		}
		//jezeli wezel jest po lewej stronie rodzica,
		else if (s->rodzic->l == s)
		{
			//usun wezel z lewej strony wezla rodzica
			s->rodzic->l = NULL;
		}
		else
		{
			//usun wezel z prawej strony wezla rodzica     
			s->rodzic->p = NULL;
		}
		delete s;
	}
	//jezeli wezel ma tylko jedno dziecko
	else if (s->l == NULL || s->p == NULL)
	{
		//jezeli po lewej stronie nie ma dziecka
		if (s->l == NULL)
		{
			//jezeli wezel jest korzeniem
			if (s->rodzic == NULL)
			{
				root = s->p;
			}
			//jezeli wezel jest po lewej stronie rodzica
			else if (s->rodzic->l == s)
			{
				//przyczep z lewej strony rodzica wezel bedacy po prawej stronie usuwanego wezla
				s->rodzic->l = s->p;
			}
			else
			{
				//przyczep z prawej strony rodzica wezel bedacy po prawej stronie usuwanego wezla
				s->rodzic->p = s->p;
			}
		}
		else
		{
			//jezeli wezel jest korzeniem
			if (s->rodzic == NULL)
			{
				root = s->l;
			}
			//jezeli wezel jest po lewej stronie rodzica
			else if (s->rodzic->l == s)
			{
				//dodajemy na lewo
				s->rodzic->l= s->l;
			}
			else
			{
				//dodajemy na prawo
				s->rodzic->p = s->l;
			}
		}
		delete s;
	}
	else
	{
		//wstawiamy najmiejsz¹ watoœc z prawego podrzewa
		struct Wezel* temp;
		temp = s->p;
		while (temp->l!=NULL)
		{
			temp = temp->l;
		}
	
		s->value = temp->value;
		usun_wezel(temp);
		
		
	}
}

void Drzewo::min()
{
	Wezel* temp = root;

	//wedzrujemy po drzewie w lewo
	while (temp->l != NULL)
	{
		temp = temp->l;
	}

	std::cout<<std::endl << "Minimalna wartosc w drzewie to: " << temp->value << std::endl;




}

void Drzewo::max()
{
	Wezel* temp = root;
	//wêdrujemy po drzewie w prawo
	while (temp->p != NULL)
	{
		temp = temp->p;
	}
	std::cout << std::endl << "Maksymalna wartosc w drzewie to: " << temp->value<<std::endl;

	

}
