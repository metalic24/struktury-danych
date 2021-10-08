#include "lista.h"

void lista::dodaj_element_na_koniec(int value)
{
    element_listy* element = new element_listy;    // tworzy nowy element listy

   // wype³niamy naszymi danymi
    element->value = value;


    if (this->begin == 0) // sprawdzamy czy to pierwszy element listy
    {
        // je¿eli tak to nowy element jest teraz pocz¹tkiem listy
        this->begin = element;
        element->next = 0;
    }
    else
    {
        // w przeciwnym wypadku wêdrujemy na koniec listy
        element_listy* temp = this->begin;

        while (temp->next)
        {
            // znajdujemy wskaŸnik na ostatni element
            temp = temp->next;
        }

        temp->next = element;  // ostatni element wskazuje na nasz nowy
        element->next = 0;     // ostatni nie wskazuje na nic
        
    }
}

void lista::dodaj_na_poczatek(int value)
{
      element_listy* element = new element_listy();    // tworzy nowy element listy

   // wype³niamy naszymi danymi
    element->value = value;
    
     element->next = this->begin;
    this->begin = element;
  
}

void lista::dodaj_na_miejsce(int value, int miejsce)
{
    element_listy* element = new element_listy();    // tworzy nowy element listy

   // wype³niamy naszymi danymi
    element->value = value;


    if (begin == 0) // sprawdzamy czy to pierwszy element listy
    {
        // je¿eli tak to nowy element jest teraz pocz¹tkiem listy
        begin = element;
    }
    else
    {
        
        element_listy* temp = begin;

        while (miejsce>1)
        {
            // znajdujemy wskaŸnik na ostatni element
            temp = temp->next;
            miejsce--;
        }
        element->next = temp->next;
        temp->next = element;
       
      
    }

  


}

void lista::wyswietl()
{

    // wskaznik na pierszy element listy
    element_listy* temp = begin;

    
    while (temp)
    {
        std::cout << temp->value<<" ";
        temp = temp->next;
    }

    std::cout << std::endl;

   
}

void lista::znajdz(int szukana)
{
    element_listy* temp = begin;
    while (temp!=0)
    {
        if (temp->value == szukana)
        {
            std::cout << std::endl << "Podana wartosc istnieje.";
           
            return;
        }
        temp = temp->next;
    }
    std::cout << std::endl << "Element nie istnieje";

   

}

void lista::usun(int usuwana)
{
    if (begin->value == usuwana)
    {
        begin = begin->next;
        
    }
    else
    {


        element_listy* temp = begin;
        while (temp->next != 0)
        {
            if (temp->next->value == usuwana)
            {
                temp->next = temp->next->next;
                
            }
            else
            {
                temp = temp->next;
            }

           
        }
   

       

    }
    

    
}

void lista::min_max()
{
    element_listy* temp = begin;
    int min = temp->value;
    int max = min;

    while (temp !=NULL)
    {
        if (min > temp->value)
        {
            min = temp->value;
        }

        if (max < temp->value)
        {
            max = temp->value;
        }

        temp = temp->next;
    }

    std::cout << std::endl << "Minimalna wartosc w liscie to: " << min << ". Maksymalna w liscie to  " << max;

  


}

lista::lista()
{
    begin = 0; 
}

element_listy::element_listy()
{
    next = 0;
    value = 0;
}
