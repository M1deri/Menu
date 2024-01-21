#include <iostream>
#include <fstream>

using namespace std;

int Menu()
{
    int x;
    cout<<endl;
    cout<<"1. Dodaj element tablicy"<<endl;
    cout<<"2. Wstaw element tablicy"<<endl;
    cout<<"3. Usun element tablicy"<<endl;
    cout<<"4. Wyświetl elementy tablicy"<<endl;
    cout<<"5. Zapisz do pliku"<<endl;
    cout<<"6. Wczytaj z pliku"<<endl;
    cout<<"7. Wyjscie z programu"<<endl;
    cin>>x;
    cout<<endl;
    return x;
}

int main()
{
    int m;
    int *p = NULL;
    int n = 0;
    while(true)
    {
        m = Menu();
        switch(m)
        {
        case 7:
            {
                return 0;
            }
        case 1:
            {
                int * tmp = NULL;
                tmp = new int[n+1];
                if(p != NULL)
                {
                    for(int i=0;i<n;i++)
                    {
                        tmp[i] = p[i];
                    }
        
                    delete[] p;

                }
                cout<<"Podaj wartosc elementu tablicy: ";
                cin>>tmp[n];
                p = tmp;
                n++;
                break;
            }
        case 2:
            {
                if (n == 0) {
                cout << "Tablica jest pusta. Nie mozna wstawic elementu." << endl;
                break;
            }

            int index;
            cout << "Podaj indeks, na ktory chcesz wstawic element: ";
            cin >> index;

            if (index < 0 || index > n) {
                cout << "Nieprawidlowy indeks" << endl;
                break;
            }

            int wartosc;
            cout << "Podaj wartosc elementu: ";
            cin >> wartosc;

            wskaz* tmp = new int[n + 1];

            for (int i = 0; i < index; i++) {
                tmp[i] = p[i];
            }
            tmp[index] = wartosc;
            for (int i = index + 1; i <= n; i++) {
                tmp[i] = p[i - 1];
            }   
            delete[] p;
            p = tmp;
            n++;

                break;
            }
        case 3:
            {
                if (n == 0) 
                {
                    cout << "Tablica jest pusta, nie ma co usunac." << endl;
                    break;
                }

                int index;
                cout << "Podaj indeks elementu do usuniecia: ";
                cin >> index;

                if (index < 0 || index >= n) 
                {
                    cout << "Nieprawidlowy indeks." << endl;
                   break;
                }

                int* tmp = new int[n - 1];
                for (int i = 0; i < index; i++) 
                {
                    tmp[i] = p[i];
                }

                for (int i = index + 1; i < n; i++) 
                {
                    tmp[i - 1] = p[i];
                }

                delete[] p;
                p = tmp;
                n--;
                cout << "Element o indeksie zostal usuniety." << endl;

                break;
            }
        case 4:
            {
                cout<<"Zawartosc tablicy:"<<endl;
                for(int i=0;i<n;i++)
                {
                    cout<<p[i]<<", ";
                }
                cout<<endl;
                break;
            }
        case 5:
            {
                if (n == 0) {
                    cout << "Tablica jest pusta. Nie ma danych do zapisu." << endl;
                    break;
                }

                ofstream plik("out.txt", ios::out | ios::app);

                if (plik.is_open()) 
                {
                    for (int i = 0; i < n; i++) 
                    {
                        plik << p[i] << " ";
                    }

                    plik.close();
                    cout << "Dane zostaly zapisane" << endl;
               }else 
               {
                    cout << "Nie udalo sie zapisac danych" << endl;
               }
                break;
            }
        case 6:
            {
                fstream plik;
                plik.open("in.txt", ios::out | ios::app);
                string w;
                while (!plik.eof())
                {
                    getline(plik, w);
                    cout << w << endl;
                }
                plik.close();
                break;
            }
        default:
            {
                cout<<"Nieprawidlowa opcja"<<endl;
            }

        }
    }
    return 0;
}