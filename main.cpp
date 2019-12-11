#include <iostream>
#include <time.h>
#include <cstdlib>
#include <string>
#include <windows.h>
using namespace std;
HANDLE tlo;

string wyraz = {"abcdefghijklmnopqrstuvwxyz"};
string miejsca =  {"_________"};
string temp = {"a"};


char decyzja_wczesniej;

int ile_liter,zamiana_miejsc,pozycja = -1;
int random,liczba = 0;
int decyzja;

string zwroc_litere(string s,int l)
{
    string x;
    for(int i = 0 ; i < 1 ; i++)
    {

        random = rand()%(26 - l);
        x = s[random];

    }
    return x;
}


void Menu()
{
    do
    {
        if(decyzja != 2)
            {
        cout<<"WITAJ W GRZE HANGMAN! WPISZ ILE LITER MA SLOWO (5-9).PROGRAM BEDZIE PO KOLEI PYTAL \n";
        cout<<"CZY DANA LITERA WYSTEPUJE W TYCH (5-9) LITERACH!.DZIEKI WPISYWANIU Y LUB N PROGRAM W KONCU\n";
        cout<<"ODGADNIE WYRAZ, KTORY MIALES NA MYSLI. MILEJ GRY!\n";
        cout<<"----Wprowadz ile liter ma wyraz o ktorym myslisz---\n\n";
            }
        cout<<"Ile liter (5-9) : ";
        cin>>ile_liter;
        zamiana_miejsc = ile_liter;

        for(int i = 1 ; i <= zamiana_miejsc ; i++)
        {
            cout<<miejsca[i]<<" ";
        }

        while(ile_liter > 0)
        {

            temp = zwroc_litere(wyraz,liczba);
            cout<<"\n\n\nCzy litera ("<<temp<<") wystepuje w twoim slowie ? ";
            cout<<" y/n? ";
            cin>>decyzja_wczesniej;
            if(decyzja_wczesniej == 'y' || decyzja_wczesniej == 'Y')
            {

                cout<<"\n\n\n Na ktorej pozycji ? : ";
                cin>>pozycja;
                Sleep(1000);
                system("CLS");
                wyraz.erase(random,1);
                liczba++;
                ile_liter--;


            }
            else if (decyzja_wczesniej == 'n' || decyzja_wczesniej == 'N')
            {
                pozycja = -1;
                wyraz.erase(random,1);
                liczba++;
                system("CLS");
            }
            if(ile_liter == 0 )
            {
                cout<<"Twoje slowo to : \n\n";
            }
            for(int i = 1 ; i <= zamiana_miejsc ; i++)
            {
                if(i == pozycja)
                {
                    miejsca[i] = temp[0];
                }
                cout<<miejsca[i]<<" ";

            }

        }

        cout<<"\n\n---Gramy od nowa, czy konczymy gre ?---\n";
        cout<<"1 - konczymy "<<endl;
        cout<<"2 - nie konczymy "<<endl;
        cin>>decyzja;
        if(decyzja == 1)
        {
            break;
        }

    }
    while(true);
}
int main()
{
    tlo = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute( tlo, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
    srand(time(0));
    Menu();

    return 0;
}
