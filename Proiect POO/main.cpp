#include <iostream>
#include<string.h>
#include<ctime>
#include<sstream>
#include<bits/stdc++.h>

using namespace std;

ifstream fin("date.in");
ofstream fout("date.out");

class Pizza
{   private:
        int nr_toppinguri,nr_sosuri_disponibile,nr_dimensiuni;
        bool vegetariana;
        bool reducere;
        char* nume_pizza;
        char tip_blat[100];
        float* dimensiuni;
        float* pret_pizza_pe_dimensiune;
        int* cantitate_per_topping;
        double temperatura_coacere;
        float procent_reducere;
        const int id_pizza;
        string topinguri_folosite[20];
        string* sosuri_disponibile;



    public:
        static int contor_Id_pizza;

        //constructori
        Pizza();
        Pizza(char* nume_pizza,bool reducere,int nr_dimensiuni,float* dimensiuni);
        Pizza(int nr_toppinguri, int nr_sosuri_disponibile,int nr_dimensiuni, bool vegetariana, bool reducere, char* nume_pizza, char tip_blat[100], float* pret_pizza_pe_dimensiune, int* cantitate_per_topping,
              float* dimensiuni,double temperatura_coacere, float procent_reducere,string topinguri_folosite[20], string* sosuri_disponibile);
        Pizza(const Pizza& p);

        //operatori
        Pizza& operator=(const Pizza& p);
        friend ostream& operator<<(ostream& out,const Pizza& p);
        friend istream& operator>>(istream& in,Pizza& p);
        friend ifstream& operator>>(ifstream& in,Pizza& p);
        const Pizza& operator++();
        const Pizza operator++(int);
        friend Pizza operator+(const Pizza& p,string topping_nou);
        friend Pizza operator+(string topping_nou,const Pizza& p);
        friend Pizza operator-(const Pizza& p,string topping_nou);
        friend Pizza operator-(string topping_nou,const Pizza& p);
        string operator[](int index);
        friend bool operator<(const Pizza& p,const Pizza& p1);
        friend bool operator>(const Pizza& p,const Pizza& p1);
        bool operator==(const Pizza& p);
        explicit operator int();

        // setteri si getteri
        int get_nr_toppinguri();
        int get_nr_sosuri_disponibile();
        int get_nr_dimensiuni();
        bool get_vegetariana();
        bool get_reducere();
        char* get_nume_pizza();
        char* get_tip_blat();
        float* get_dimensiuni();
        float* get_pret_pizza_pe_dimensiune();
        int* get_cantitate_per_topping();
        double get_temperatura_coacere();
        float get_procent_reducere();
        string* get_toppinguri_folosite();
        string* get_sosuri_disponibile();
        int get_id_pizza();
        void set_nume_pizza(char* nume_pizza);
        void set_reducere(bool reducere);
        void set_nr_topping(int nr_toppinguri);
        void set_cantitate_per_topping(int nr_toppinguri,int* cantitate_per_topping);
        void set_topinguri_folosite(int nr_toppinguri,string topinguri_folosite[20]);
        void set_tip_blat(char tip_blat[100]);
        void set_nr_sosuri_disponibile(int nr_sosuri_disponibile);
        void set_nr_dimensiuni(int nr_dimensiuni);
        void set_dimensiuni(int nr_dimensiuni,float* dimensiuni);
        void set_pret_pizza_pe_dimensiune(int nr_dimensiuni,float* pret_pizza_pe_dimensiune);
        void set_sosuri_disponibile(int nr_sosuri_disponibile,string* sosuri_disponibile);
        void set_procent_reducere(float procent_reducere);
        void set_temperatura_coacere(double temperatura_coacere);
        void set_vegetariana(bool vegetariana);
        // functii
        void afis_toppinguri();
        void afis_sosuri();

        ~Pizza();

};
Pizza:: operator int()
{
    return (int)this -> temperatura_coacere;
}
bool operator<(const Pizza& p,const Pizza& p1)
{
    if(strcmp(p.nume_pizza,p1.nume_pizza))
        return true;
    return false;
}
bool operator>(const Pizza& p,const Pizza& p1)
{
    return p.temperatura_coacere>p1.temperatura_coacere;
}
bool Pizza::operator==(const Pizza& p)
{
    if(this -> temperatura_coacere == p.temperatura_coacere)
        return true;
    return false;
}
string Pizza::operator[](int index)
{
    if(0<=index && index<this -> nr_toppinguri)
        return this -> topinguri_folosite[index];
    else
    {
        cout<<"Ai introdus index gresit"<<endl;
        return "index gresit";
    }
}
Pizza operator-(string sos_eliminat,const Pizza& p)
{
    Pizza aux(p);
    string* lista_vehce_sosuri;
    lista_vehce_sosuri =  new string[aux.nr_sosuri_disponibile];
    for(int i=0;i<aux.nr_sosuri_disponibile;i++)
        lista_vehce_sosuri[i] = aux.sosuri_disponibile[i];
    int aparitii=0;
    for(int i=0;i<aux.nr_sosuri_disponibile;i++)
        if(aux.sosuri_disponibile[i]== sos_eliminat)
            aparitii++;
    if(aux.sosuri_disponibile!=NULL)
        delete[] aux.sosuri_disponibile;
    aux.nr_sosuri_disponibile = aux.nr_sosuri_disponibile - aparitii;
    aux.sosuri_disponibile =  new string[aux.nr_sosuri_disponibile];
    int j=0;
    for(int i=0;i<(aux.nr_sosuri_disponibile+aparitii);i++)
        if(lista_vehce_sosuri[i]!=sos_eliminat)
    {
        aux.sosuri_disponibile[j]=lista_vehce_sosuri[i];
        j++;
    }

    return aux;
}
Pizza operator-(const Pizza& p,string sos_eliminat)
{
    Pizza aux(p);
    string* lista_vehce_sosuri;
    lista_vehce_sosuri =  new string[aux.nr_sosuri_disponibile];
    for(int i=0;i<aux.nr_sosuri_disponibile;i++)
        lista_vehce_sosuri[i] = aux.sosuri_disponibile[i];
    int aparitii=0;
    for(int i=0;i<aux.nr_sosuri_disponibile;i++)
        if(aux.sosuri_disponibile[i]== sos_eliminat)
            aparitii++;
    if(aux.sosuri_disponibile!=NULL)
        delete[] aux.sosuri_disponibile;
    aux.nr_sosuri_disponibile = aux.nr_sosuri_disponibile - aparitii;
    aux.sosuri_disponibile =  new string[aux.nr_sosuri_disponibile];
    int j=0;
    for(int i=0;i<(aux.nr_sosuri_disponibile+aparitii);i++)
        if(lista_vehce_sosuri[i]!=sos_eliminat)
    {
        aux.sosuri_disponibile[j]=lista_vehce_sosuri[i];
        j++;
    }

    return aux;
}
Pizza operator+(string sos_nou,const Pizza& p)
{
    Pizza aux(p);
    string* lista_sosuri_vechi;
    lista_sosuri_vechi = new string[aux.nr_sosuri_disponibile];
    for(int i = 0;i<aux.nr_sosuri_disponibile;i++)
        lista_sosuri_vechi[i] = aux.sosuri_disponibile[i];
    if(aux.sosuri_disponibile!= NULL)
        delete[] aux.sosuri_disponibile;
    aux.nr_sosuri_disponibile++;
    aux.sosuri_disponibile = new string[aux.nr_sosuri_disponibile];
    for(int i=0;i<aux.nr_sosuri_disponibile-1;i++)
        aux.sosuri_disponibile[i] = lista_sosuri_vechi[i];
    aux.sosuri_disponibile[aux.nr_sosuri_disponibile-1] = sos_nou;;

    return aux;

}
Pizza operator+(const Pizza& p,string sos_nou)
{
    Pizza aux(p);
    string* lista_sosuri_vechi;
    lista_sosuri_vechi = new string[aux.nr_sosuri_disponibile];
    for(int i = 0;i<aux.nr_sosuri_disponibile;i++)
        lista_sosuri_vechi[i] = aux.sosuri_disponibile[i];
    if(aux.sosuri_disponibile!= NULL)
        delete[] aux.sosuri_disponibile;
    aux.nr_sosuri_disponibile++;
    aux.sosuri_disponibile = new string[aux.nr_sosuri_disponibile];
    for(int i=0;i<aux.nr_sosuri_disponibile-1;i++)
        aux.sosuri_disponibile[i] = lista_sosuri_vechi[i];
    aux.sosuri_disponibile[aux.nr_sosuri_disponibile-1] = sos_nou;;

    return aux;

}
const Pizza& Pizza::operator++()
{
    this -> temperatura_coacere = this -> temperatura_coacere+10;
    return *this;
}
const Pizza Pizza::operator++(int)
{
    Pizza aux(*this);
    this -> temperatura_coacere = this -> temperatura_coacere +10;
    return aux;
}
int Pizza::get_nr_toppinguri()
{
    return this -> nr_toppinguri;
}
int Pizza::get_nr_sosuri_disponibile()
{
    return this -> nr_sosuri_disponibile;
}
int Pizza::get_nr_dimensiuni()
{
    return this -> nr_dimensiuni;
}
bool Pizza::get_vegetariana()
{
    return this -> vegetariana;
}
bool Pizza::get_reducere()
{
    return this -> reducere;
}
char* Pizza::get_nume_pizza()
{
    return this -> nume_pizza;
}
char* Pizza::get_tip_blat()
{
    return this -> tip_blat;
}
float* Pizza::get_dimensiuni()
{
    return this -> dimensiuni;
}
float* Pizza::get_pret_pizza_pe_dimensiune()
{
    return this -> pret_pizza_pe_dimensiune;
}
int* Pizza::get_cantitate_per_topping()
{
    return this -> cantitate_per_topping;
}
double Pizza::get_temperatura_coacere()
{
    return this -> temperatura_coacere;
}
float Pizza::get_procent_reducere()
{
    return procent_reducere;
}
string* Pizza::get_toppinguri_folosite()
{
    return topinguri_folosite;
}
string* Pizza::get_sosuri_disponibile()
{
    return this -> sosuri_disponibile;
}
int Pizza::get_id_pizza()
{
    return this -> id_pizza;
}
void Pizza::set_nume_pizza(char* nume_pizza)
{
    if(this -> nume_pizza!= NULL)
        delete[] this -> nume_pizza;
    this -> nume_pizza = new char[strlen(nume_pizza)+1];
    strcpy(this -> nume_pizza,nume_pizza);
}
void Pizza::set_reducere(bool reducere)
{
    this -> reducere = reducere;
}
void Pizza::set_nr_topping(int nr_toppinguri)
{
    this -> nr_toppinguri = nr_toppinguri;
}
void Pizza::set_cantitate_per_topping(int nr_toppinguri,int* cantitate_per_topping)
{
    if(this -> cantitate_per_topping != NULL)
        delete[] this -> cantitate_per_topping;
    this -> cantitate_per_topping = new int[nr_toppinguri];
    for(int i=0; i<nr_toppinguri; i++)
        this -> cantitate_per_topping[i] = cantitate_per_topping[i];
}
void Pizza::set_topinguri_folosite(int nr_toppinguri,string topinguri_folosite[20])
{
    for(int i =0; i< nr_toppinguri; i++)
    {
        this -> topinguri_folosite[i] = topinguri_folosite[i];
    }
}
void Pizza::set_tip_blat(char tip_blat[100])
{
    strcpy(this -> tip_blat,tip_blat);
}
void Pizza::set_nr_sosuri_disponibile(int nr_sosuri_disponibile)
{
    this -> nr_sosuri_disponibile = nr_sosuri_disponibile;
}
void Pizza::set_nr_dimensiuni(int nr_dimensiuni)
{
    this -> nr_dimensiuni = nr_dimensiuni;
}
void Pizza::set_dimensiuni(int nr_dimensiuni,float* dimensiuni)
{
    if(this -> dimensiuni != NULL)
        delete[] this -> dimensiuni;
    this -> dimensiuni = new float[nr_dimensiuni];
    this -> nr_dimensiuni = nr_dimensiuni;
    for(int i=0; i<nr_dimensiuni; i++)
        this -> dimensiuni[i] = dimensiuni[i];
}
void Pizza::set_pret_pizza_pe_dimensiune(int nr_dimensiuni,float* pret_pizza_pe_dimensiune)
{
    if(this -> pret_pizza_pe_dimensiune != NULL)
        delete[] this -> pret_pizza_pe_dimensiune;
    this -> nr_dimensiuni = nr_dimensiuni;
    this -> pret_pizza_pe_dimensiune = new float[nr_dimensiuni];
    for(int i=0; i< nr_dimensiuni; i++)
        this -> pret_pizza_pe_dimensiune[i] = pret_pizza_pe_dimensiune[i];
}
void Pizza::set_sosuri_disponibile(int nr_sosuri_disponibile,string* sosuri_disponibile)
{
    if(this -> sosuri_disponibile != NULL)
        delete[] this -> sosuri_disponibile;
    this -> sosuri_disponibile = new string[nr_sosuri_disponibile];
    for(int i=0; i<nr_sosuri_disponibile; i++)
        this -> sosuri_disponibile[i] = sosuri_disponibile[i];
}
void Pizza::set_procent_reducere(float procent_reducere)
{
    this -> procent_reducere = procent_reducere;
}
void Pizza::set_temperatura_coacere(double temperatura_coacere)
{
    this -> temperatura_coacere = temperatura_coacere;
}
void Pizza::set_vegetariana(bool vegetariana)
{
    this -> vegetariana = vegetariana;
}
void Pizza::afis_sosuri()
{

    if(this -> nr_sosuri_disponibile != 0)
    {
        for(int i=0;i<this -> nr_sosuri_disponibile;i++)
            cout<<"sosul "<<i+1<<" = "<<this -> sosuri_disponibile[i]<<endl;
    }
    else
        cout<<"aceasta pizza nu are sosuri/n";

}
void Pizza::afis_toppinguri()
{
    if(this -> nr_toppinguri != 0)
    {
        for(int i=0;i<this -> nr_toppinguri;i++)
            cout<<"toppingul "<<i+1<<" = "<<this -> topinguri_folosite[i]<<endl;
    }
    else
        cout<<"aceasta pizza nu are niciun topping/n";
}
istream& operator>>(istream& in,Pizza& p)
{
    cout<<"\nNume pizza: ";
    char aux[100];
    in.get(aux,100);
    in.get();
    if(p.nume_pizza!=NULL)
        delete[] p.nume_pizza;
    p.nume_pizza = new char[strlen(aux)+1];
    strcpy(p.nume_pizza,aux);
    cout<<"Tip blat: ";
    in.get(p.tip_blat,100);
    in.get();
    cout<<"Temperatura coacere: ";
    in>>p.temperatura_coacere;
    cout<<"Numarul de toppinguri folosite: ";
    in>>p.nr_toppinguri;
    if(p.cantitate_per_topping!=NULL)
        delete[] p.cantitate_per_topping;
    p.cantitate_per_topping = new int[p.nr_toppinguri];
    for(int i=0;i<p.nr_toppinguri;i++)
    {
        cout<<"Toppingul "<<i+1<<": ";
        in.get();
        getline(in,p.topinguri_folosite[i]);
        cout<<"Cantitate topping in grame: ";
        in>>p.cantitate_per_topping[i];
    }
    cout<<"Numarul de dimensiuni: ";
    in>>p.nr_dimensiuni;
    if(p.dimensiuni!=NULL)
        delete[] p.dimensiuni;
    p.dimensiuni = new float[p.nr_dimensiuni];
    if(p.pret_pizza_pe_dimensiune!=NULL)
        delete[] p.pret_pizza_pe_dimensiune;
    p.pret_pizza_pe_dimensiune = new float[p.nr_dimensiuni];
    for(int i=0;i<p.nr_dimensiuni;i++)
    {
        cout<<"Dimensiunea "<<i+1<<" in cm: ";
        in>>p.dimensiuni[i];
        cout<<"Pretul pentru aceasta dimensiune in lei: ";
        in>>p.pret_pizza_pe_dimensiune[i];
    }
    cout<<"Numar de sosuri disponibile: ";
    in>>p.nr_sosuri_disponibile;
    if(p.sosuri_disponibile != NULL)
        delete[] p.sosuri_disponibile;
    p.sosuri_disponibile = new string[p.nr_sosuri_disponibile];
    in.get();
    for(int i=0;i<p.nr_sosuri_disponibile;i++)
    {
        cout<<"Sosul "<<i+1<<": ";
        getline(in,p.sosuri_disponibile[i]);
    }
    cout<<"Aceasta pizza are reducere [1 da/0 nu]? ";
    in>>p.reducere;
    if(p.reducere)
    {
        cout<<"procentul de reducere% = ";
        in>>p.procent_reducere;
        p.procent_reducere =  p.procent_reducere/100;
    }
    cout<<"Vegetariana [1 da/0 nu]: ";
    in>>p.vegetariana;

    return in;

}
ifstream& operator>>(ifstream& in,Pizza& p)
{
    char aux[100];
    in.get(aux,100);
    in.get();
    if(p.nume_pizza!=NULL)
        delete[] p.nume_pizza;
    p.nume_pizza = new char[strlen(aux)+1];
    strcpy(p.nume_pizza,aux);
    in.get(p.tip_blat,100);
    in.get();
    in>>p.temperatura_coacere;
    in>>p.nr_toppinguri;
    if(p.cantitate_per_topping!=NULL)
        delete[] p.cantitate_per_topping;
    p.cantitate_per_topping = new int[p.nr_toppinguri];
    for(int i=0;i<p.nr_toppinguri;i++)
    {

        in.get();
        getline(in,p.topinguri_folosite[i]);
        in>>p.cantitate_per_topping[i];
    }
    in>>p.nr_dimensiuni;
    if(p.dimensiuni!=NULL)
        delete[] p.dimensiuni;
    p.dimensiuni = new float[p.nr_dimensiuni];
    if(p.pret_pizza_pe_dimensiune!=NULL)
        delete[] p.pret_pizza_pe_dimensiune;
    p.pret_pizza_pe_dimensiune = new float[p.nr_dimensiuni];
    for(int i=0;i<p.nr_dimensiuni;i++)
    {

        in>>p.dimensiuni[i];
        in>>p.pret_pizza_pe_dimensiune[i];
    }
    in>>p.nr_sosuri_disponibile;
    if(p.sosuri_disponibile != NULL)
        delete[] p.sosuri_disponibile;
    p.sosuri_disponibile = new string[p.nr_sosuri_disponibile];
    in.get();
    for(int i=0;i<p.nr_sosuri_disponibile;i++)
    {
        getline(in,p.sosuri_disponibile[i]);
    }
    in>>p.reducere;
    if(p.reducere)
    {

        in>>p.procent_reducere;
        p.procent_reducere =  p.procent_reducere/100;
    }
    in>>p.vegetariana;

    return in;

}
ostream& operator<<(ostream& out,const Pizza& p)
{
    out<<"\nID Pizza: "<<p.id_pizza<<endl;

    out<<"Nume Pizza: "<<p.nume_pizza<<endl;
    out<<"Tip blat: "<<p.tip_blat<<endl;
    out<<"Temperatura coacere in grade celsius: "<<p.temperatura_coacere<<endl;
    out<<"Numarul de toppinguri folosite: "<<p.nr_toppinguri<<endl;
    out<<"Toppinguri folosite:"<<endl;
    for(int i=0;i<p.nr_toppinguri;i++)
    {
        out<<"Toppingul "<<i+1<<": "<<p.topinguri_folosite[i]<<endl;
        out<<"Cantitate din acest topping in grame: "<<p.cantitate_per_topping[i]<<endl;
    }
    out<<"Numarul de dimensiuni: "<<p.nr_dimensiuni<<endl;
    for(int i=0;i<p.nr_dimensiuni;i++)
    {
        out<<"Dimensiune in cm"<<i+1<<": "<<p.dimensiuni[i]<<endl;
        out<<"Pretul pentru aceasta dimensiune in lei: "<<p.pret_pizza_pe_dimensiune[i]<<endl;
    }
    out<<"Numarul de sosuri disponibile: "<<p.nr_sosuri_disponibile<<endl;
    for(int i=0;i<p.nr_sosuri_disponibile;i++)
        out<<"Sosul "<<i+1<<": "<<p.sosuri_disponibile[i]<<endl;
    if(p.reducere)
    {
        out<<"Aceasta pizza are reducere si este: "<<p.procent_reducere*100<<"%"<<endl;
    }
    else
    {
        out<<"Aceasta pizza nu are reducere"<<endl;
    }
    if(p.vegetariana)
    {
        out<<"Aceasta pizza e vegetariana"<<endl;
    }
    else
    {
        out<<"Aceasta pizza nu e vegetariana"<<endl;
    }

    return out;
}
Pizza& Pizza::operator=(const Pizza& p)
{
    if(this!=&p)
    {
        if(this -> nume_pizza!=NULL)
            delete[] this -> nume_pizza;

        if(this -> pret_pizza_pe_dimensiune!=NULL)
            delete[] this -> pret_pizza_pe_dimensiune;

        if(this -> cantitate_per_topping!=NULL)
            delete[] this -> cantitate_per_topping;

        if(this -> dimensiuni != NULL )
            delete[] this -> dimensiuni;

        if(this -> sosuri_disponibile != NULL)
            delete[] this -> sosuri_disponibile;

        this -> nr_toppinguri = p.nr_toppinguri;
        this -> nr_sosuri_disponibile = p.nr_sosuri_disponibile;
        this -> nr_dimensiuni =  p.nr_dimensiuni;
        this -> vegetariana = p.vegetariana;
        this -> reducere = p.reducere;
        this -> temperatura_coacere = p.temperatura_coacere;

        this -> nume_pizza = new char[strlen(p.nume_pizza)+1];
        strcpy(this -> nume_pizza,p.nume_pizza);

        strcpy(this -> tip_blat,p.tip_blat);
        this -> dimensiuni = new float[p.nr_dimensiuni];
        for(int i=0; i< p.nr_dimensiuni; i++)
            this -> dimensiuni[i] = p.dimensiuni[i];

        this -> pret_pizza_pe_dimensiune = new float[p.nr_dimensiuni];
        for(int i=0; i< p.nr_dimensiuni; i++)
            this -> pret_pizza_pe_dimensiune[i] = p.pret_pizza_pe_dimensiune[i];

        this -> cantitate_per_topping = new int[p.nr_toppinguri];
        for(int i=0; i<p.nr_toppinguri; i++)
            this -> cantitate_per_topping[i] = p.cantitate_per_topping[i];

        this -> temperatura_coacere = p.temperatura_coacere;
        this -> procent_reducere = p.procent_reducere;

        for(int i=0; i<p.nr_toppinguri; i++)
            this -> topinguri_folosite[i]=p.topinguri_folosite[i];

        this -> sosuri_disponibile = new string[p.nr_sosuri_disponibile];
        for(int i=0; i<p.nr_sosuri_disponibile; i++)
            this -> sosuri_disponibile[i] = p.sosuri_disponibile[i];

    }
    *this;
}
Pizza::Pizza(const Pizza& p):id_pizza(p.id_pizza)
{
    this -> nr_toppinguri = p.nr_toppinguri;
    this -> nr_sosuri_disponibile = p.nr_sosuri_disponibile;
    this -> nr_dimensiuni =  p.nr_dimensiuni;
    this -> vegetariana = p.vegetariana;
    this -> reducere = p.reducere;

    this -> nume_pizza = new char[strlen(p.nume_pizza)+1];
    strcpy(this -> nume_pizza,p.nume_pizza);

    strcpy(this -> tip_blat,p.tip_blat);
    this -> dimensiuni = new float[p.nr_dimensiuni];
    for(int i=0; i< p.nr_dimensiuni; i++)
        this -> dimensiuni[i] = p.dimensiuni[i];

    this -> pret_pizza_pe_dimensiune = new float[p.nr_dimensiuni];
    for(int i=0; i< p.nr_dimensiuni; i++)
        this -> pret_pizza_pe_dimensiune[i] = p.pret_pizza_pe_dimensiune[i];

    this -> cantitate_per_topping = new int[p.nr_toppinguri];
    for(int i=0; i<p.nr_toppinguri; i++)
        this -> cantitate_per_topping[i] = p.cantitate_per_topping[i];

    this -> temperatura_coacere = p.temperatura_coacere;
    this -> procent_reducere = p.procent_reducere;

    for(int i=0; i<p.nr_toppinguri; i++)
        this -> topinguri_folosite[i]=p.topinguri_folosite[i];

    this -> sosuri_disponibile = new string[p.nr_sosuri_disponibile];
    for(int i=0; i<p.nr_sosuri_disponibile; i++)
        this -> sosuri_disponibile[i] = p.sosuri_disponibile[i];
}
Pizza::Pizza():id_pizza(contor_Id_pizza++)
{
    this -> nr_toppinguri = 0;
    this -> nr_sosuri_disponibile = 0;
    this -> nr_dimensiuni =  0;
    this -> vegetariana = true;
    this -> reducere = true;

    this -> nume_pizza = NULL;

    strcpy(this -> tip_blat,"Nimic");
    this -> dimensiuni = NULL;
    this -> pret_pizza_pe_dimensiune = NULL;
    this -> cantitate_per_topping = NULL;
    this -> temperatura_coacere = 0;
    this -> procent_reducere = 0;

    for(int i=0; i<nr_toppinguri; i++)
        this -> topinguri_folosite[i]= "Nimic";
    this -> sosuri_disponibile = NULL;
}
Pizza::Pizza(char* nume_pizza,bool reducere,int nr_dimensiuni,float* dimensiuni):id_pizza(contor_Id_pizza++)
{
    this -> nume_pizza = new char[strlen(nume_pizza)+1];
    strcpy(this -> nume_pizza,nume_pizza);
    this -> reducere = reducere;
    this -> nr_dimensiuni = nr_dimensiuni;
    for(int i=0;i<nr_dimensiuni;i++)
        this -> dimensiuni[i] = dimensiuni[i];
}
Pizza::Pizza(int nr_toppinguri, int nr_sosuri_disponibile,int nr_dimensiuni, bool vegetariana, bool reducere, char* nume_pizza, char tip_blat[100], float* pret_pizza_pe_dimensiune, int* cantitate_per_topping,
      float* dimensiuni,double temperatura_coacere, float procent_reducere,string topinguri_folosite[20], string* sosuri_disponibile):id_pizza(contor_Id_pizza++)
{
    this -> nr_toppinguri = nr_toppinguri;
    this -> nr_sosuri_disponibile = nr_sosuri_disponibile;
    this -> nr_dimensiuni =  nr_dimensiuni;
    this -> vegetariana = vegetariana;
    this -> reducere = reducere;

    this -> nume_pizza = new char[strlen(nume_pizza)+1];
    strcpy(this -> nume_pizza,nume_pizza);

    strcpy(this -> tip_blat,tip_blat);
    this -> dimensiuni = new float[nr_dimensiuni];
    for(int i=0; i< nr_dimensiuni; i++)
        this -> dimensiuni[i] = dimensiuni[i];

    this -> pret_pizza_pe_dimensiune = new float[nr_dimensiuni];
    for(int i=0; i< nr_dimensiuni; i++)
        this -> pret_pizza_pe_dimensiune[i] = pret_pizza_pe_dimensiune[i];

    this -> cantitate_per_topping = new int[nr_toppinguri];
    for(int i=0; i<nr_toppinguri; i++)
        this -> cantitate_per_topping[i] = cantitate_per_topping[i];

    this -> temperatura_coacere = temperatura_coacere;
    this -> procent_reducere = procent_reducere;

    for(int i=0; i<nr_toppinguri; i++)
        this -> topinguri_folosite[i]=topinguri_folosite[i];

    this -> sosuri_disponibile = new string[nr_sosuri_disponibile];
    for(int i=0; i<nr_sosuri_disponibile; i++)
        this -> sosuri_disponibile[i] = sosuri_disponibile[i];


}
Pizza::~Pizza()
{

    if(this -> nume_pizza!=NULL)
        delete[] this -> nume_pizza;

    if(this -> pret_pizza_pe_dimensiune!=NULL)
        delete[] this -> pret_pizza_pe_dimensiune;

    if(this -> cantitate_per_topping!=NULL)
        delete[] this -> cantitate_per_topping;

    if(this -> dimensiuni != NULL )
        delete[] this -> dimensiuni;

    if(this -> sosuri_disponibile != NULL)
        delete[] this -> sosuri_disponibile;



}
class Topping
{   private:
        char* nume_topping;
        float pret_topping;
        double cantitate_totala_topping;
        float cantitate_per_portie;
        const int id_topping;
    public:
        static int contor_id_topping;

        //constructori
        Topping();
        Topping(char* nume_topping,float cantitate_per_portie);
        Topping(char* nume_topping,float pret_topping,double cantitate_totala_topping,float cantitate_per_portie);
        Topping(const Topping& t);

        //operatori
        Topping& operator=(const Topping& t);
        friend ostream& operator<<(ostream& out,const Topping& t);
        friend istream& operator>>(istream& in,Topping& t);
        friend ifstream& operator>>(ifstream& in, Topping& t);
        const Topping& operator++();
        const Topping operator++(int);
        friend Topping operator+(const Topping& t,double cantitate_noua);
        friend Topping operator+(double cantitate_noua,const Topping& t);
        friend Topping operator-(const Topping& t,double cantitate_noua);
        friend Topping operator-(double cantitate_noua,const Topping& t);
        char operator[](int index);
        bool operator<(const Topping& t);
        bool operator>(const Topping& t);
        bool operator==(const Topping& t);
        explicit operator string();


        //setteri si getteri
        char* get_nume_topping();
        float get_pret_topping();
        double get_cantitate_totala_topping();
        float get_cantitate_per_portie();
        int get_id_topping();
        void set_cantitate_totala_topping(double cantitate_totala_topping);
        void set_pret_topping(float pret_topping);
        void set_nume_topping(char* nume_topping);
        void set_cantitate_per_portie(float cantitate_per_portie);

        //functii
        void afis_nr_portii_ramase();
        virtual ostream& afisare_virtuala_topping(ostream& out)const;
        virtual istream& citire_virtuala_topping(istream& in);
        virtual ifstream& citire_virtuala_topping_fisier(ifstream& in);

        ~Topping();


};

ostream& Topping::afisare_virtuala_topping(ostream& out)const
{
    out<<"\nTopping ID: "<<this -> id_topping<<endl;
    if(this -> nume_topping == NULL)
        out<<"Nume topping: Fara nume"<<endl;
    else
        out<<"Nume topping: "<<this -> nume_topping<<endl;
    out<<"Pret topping in lei: "<<this -> pret_topping<<endl;
    out<<"Cantitate totala de topping in grame: "<<this -> cantitate_totala_topping<<endl;
    out<<"Cantitate pe portie in grame: "<<this -> cantitate_per_portie<<endl;
    return out;
}
istream& Topping::citire_virtuala_topping(istream& in)
{
    cout<<"\nNume topping: ";
    char aux[100];
    in.get(aux,100);
    in.get();
    if(this ->nume_topping!= NULL)
        delete[] this ->nume_topping;
    this ->nume_topping = new char[strlen(aux)+1];
    strcpy(this ->nume_topping,aux);
    cout<<"Pretul toppingului in lei: ";
    in>>this ->pret_topping;
    cout<<"Cantitate totala de topping in grame: ";
    in>>this ->cantitate_totala_topping;
    cout<<"Cantitate pe portie in grame: ";
    in>>this ->cantitate_per_portie;

    return in;
}
ifstream& Topping::citire_virtuala_topping_fisier(ifstream& in)
{
    char aux[100];
    in.get(aux,100);
    in.get();
    if(this ->nume_topping!= NULL)
        delete[] this ->nume_topping;
    this ->nume_topping = new char[strlen(aux)+1];
    strcpy(this ->nume_topping,aux);
    in>>this ->pret_topping;
    in>>this ->cantitate_totala_topping;
    in>>this ->cantitate_per_portie;

    return in;
}
Topping::operator string()
{
    return (string)this->nume_topping;
}
bool Topping::operator<(const Topping& t)
{
    if(this -> pret_topping < t.pret_topping)
        return true;
    return false;
}
bool Topping::operator>(const Topping& t)
{
    if(this -> pret_topping>t.pret_topping)
        return true;
    return false;
}
bool Topping::operator==(const Topping& t)
{
    if(this -> pret_topping == t.pret_topping )
        return true;
    return false;
}
char Topping::operator[](int index)
{
    if(0<=index && index<strlen(this -> nume_topping))
        return this -> nume_topping[index];
    else
    {
        cout<<"Ai introdus index gresit"<<endl;
        return '0';
    }
}
Topping operator-(const Topping& t,double cantitate_noua)
{
    Topping aux(t);
    aux.cantitate_totala_topping = aux.cantitate_totala_topping - cantitate_noua;
    return aux;
}
Topping operator-(double cantitate_noua,const Topping& t)
{
    Topping aux(t);
    aux.cantitate_totala_topping = aux.cantitate_totala_topping - cantitate_noua;
    return aux;
}
Topping operator+(const Topping& t,double cantitate_noua)
{
    Topping aux(t);
    aux.cantitate_totala_topping = aux.cantitate_totala_topping + cantitate_noua;
    return aux;
}
Topping operator+(double cantitate_noua,const Topping& t)
{
    Topping aux(t);
    aux.cantitate_totala_topping = aux.cantitate_totala_topping + cantitate_noua;
    return aux;
}
const Topping Topping::operator++(int)
{
    Topping aux(*this);
    this -> pret_topping++;
    return aux;
}
const Topping& Topping::operator++()
{
    this -> pret_topping++;
    return *this;
}
int Topping::get_id_topping()
{
    return this -> id_topping;
}
char* Topping::get_nume_topping()
{
    return this->nume_topping;
}
float Topping::get_pret_topping()
{
    return this -> pret_topping;
}
double Topping::get_cantitate_totala_topping()
{
    return this -> cantitate_totala_topping;
}
float Topping::get_cantitate_per_portie()
{
    return this -> cantitate_per_portie;
}
void Topping::set_cantitate_totala_topping(double cantitate_totala_topping)
{
    this -> cantitate_totala_topping = cantitate_totala_topping;
}
void Topping::set_pret_topping(float pret_topping)
{
    this -> pret_topping = pret_topping;
}
void Topping::set_nume_topping(char* nume_topping)
{
    if(this -> nume_topping != NULL)
        delete[] this -> nume_topping;
    this -> nume_topping =  new char[strlen(nume_topping)+1];
    strcpy(this -> nume_topping,nume_topping);
}
void Topping::set_cantitate_per_portie(float cantitate_per_portie)
{
    this -> cantitate_per_portie = cantitate_per_portie;
}
void Topping::afis_nr_portii_ramase()
{
    cout<<"numarul de portii ramase din acest topping = "<<cantitate_totala_topping/cantitate_per_portie;
}
istream& operator>>(istream& in,Topping& t)
{
   return t.citire_virtuala_topping(in);
}
ifstream& operator>>(ifstream& in,Topping& t)
{
    return t.citire_virtuala_topping_fisier(in);
}
ostream& operator<<(ostream& out,const Topping& t)
{
    return t.afisare_virtuala_topping(out);
}
Topping& Topping::operator=(const Topping& t)
{
    if(this != &t)
    {
        if(this -> nume_topping != NULL)
            delete[] this -> nume_topping;

        this -> nume_topping = new char[strlen(t.nume_topping)+1];
        strcpy(this -> nume_topping,t.nume_topping);
        this -> pret_topping = t.pret_topping;
        this -> cantitate_totala_topping = t.cantitate_totala_topping;
        this -> cantitate_per_portie = t.cantitate_per_portie;
    }
    *this;
}
Topping::Topping(const Topping& t):id_topping(t.id_topping)
{
    this -> nume_topping = new char[strlen(t.nume_topping)+1];
    strcpy(this -> nume_topping,t.nume_topping);
    this -> pret_topping = t.pret_topping;
    this -> cantitate_totala_topping = t.cantitate_totala_topping;
    this -> cantitate_per_portie = t.cantitate_per_portie;
}
Topping::Topping():id_topping(contor_id_topping++)
{
    this -> nume_topping = NULL;
    this -> pret_topping = 0;
    this -> cantitate_totala_topping = 0;
    this -> cantitate_per_portie = 0;
}
Topping::Topping(char * nume_topping,float cantitate_per_portie):id_topping(contor_id_topping++)
{
    this -> nume_topping = new char[strlen(nume_topping)+1];
    strcpy(this -> nume_topping,nume_topping);
    this -> cantitate_per_portie = cantitate_per_portie;
}
Topping::Topping(char* nume_topping,float pret_topping,double cantitate_totala_topping,float cantitate_per_portie):id_topping(contor_id_topping++)
{
    this -> nume_topping = new char[strlen(nume_topping)+1];
    strcpy(this -> nume_topping,nume_topping);
    this -> pret_topping = pret_topping;
    this -> cantitate_totala_topping = cantitate_totala_topping;
    this -> cantitate_per_portie = cantitate_per_portie;
}
Topping::~Topping()
{
    if(this -> nume_topping != NULL)
        delete[] this -> nume_topping;
    contor_id_topping--;
}

class Topping_Special:public Topping
{
    private:
        int durata_valabil_zile;
        string producator;
        int numar_alergeni;
        string* lista_alergeni;
    public:
        //constructori si destructori
        Topping_Special();
        Topping_Special(char* nume_topping,float pret_topping,double cantitate_totala_topping,float cantitate_per_portie,int durata_valabil_zile,string producator,int numar_alergeni,string* lista_alergeni);
        Topping_Special(const Topping_Special& t);
        ~Topping_Special();

        //operatorul =,>> si <<
        Topping_Special& operator=(const Topping_Special& t);
        friend istream& operator>>(istream& in,Topping_Special& t);
        friend ostream& operator<<(ostream& out,const Topping_Special& t);
        friend ifstream& operator>>(ifstream& in,Topping_Special& t);

        //setteri si getteri
        int get_durata_valabil_zile();
        string get_producator();
        int get_numar_alergeni();
        string* get_lista_alergeni();
        void set_durata_valabil_zile(int durata);
        void set_producator(string prod);
        void set_numar_alergeni(int numar);
        void set_lista_alergeni(string* lista_alergeni,int numar_alergeni);

        //afisare si citire virtuala
        virtual istream& citire_virtuala_topping(istream& in);
        virtual ostream& afisare_virtuala_topping(ostream& out)const;
        virtual ifstream& citire_virtuala_topping_fisier(ifstream& in);

        //metode proprii ale clasei
        void afis_are_alergeni();
        void afis_raritate();

};
void Topping_Special::afis_raritate()
{

    if(this -> durata_valabil_zile <10)
        cout<<"\nAcest topping este valabil pentru un scurt timp";
    if(this -> durata_valabil_zile >10)
        cout<<"\nAcest topping este valabil pentru un timp mai lung";
}
void Topping_Special::afis_are_alergeni()
{
    if(this -> numar_alergeni == 0)
        cout<<"\nAcest topping nu are alergeni";
    if(this -> numar_alergeni > 0)
    {
        cout<<"\nAcest topping are alergeni si acestia sunt: ";
        for(int i=0;i<this -> numar_alergeni;i++)
            cout<<"\nAlergen "<<i+1<<" : "<<this -> lista_alergeni[i];
    }
}
void Topping_Special::set_durata_valabil_zile(int durata)
{
    this -> durata_valabil_zile = durata;
}
void Topping_Special::set_producator(string prod)
{
    this -> producator = prod;
}
void Topping_Special::set_numar_alergeni(int numar)
{
    this -> numar_alergeni = numar;
}
void Topping_Special::set_lista_alergeni(string* lista_alergeni,int numar)
{
    this -> numar_alergeni = numar;
    if(this -> lista_alergeni!=NULL)
        delete[] this -> lista_alergeni;
    this -> lista_alergeni = new string[numar];
    for(int i=0;i<numar;i++)
        this -> lista_alergeni[i] = lista_alergeni[i];
}
int Topping_Special::get_durata_valabil_zile()
{
    return this -> durata_valabil_zile;
}
string Topping_Special::get_producator()
{
    return this -> producator;
}
int Topping_Special::get_numar_alergeni()
{
    return this -> numar_alergeni;
}
string* Topping_Special::get_lista_alergeni()
{
    return this -> lista_alergeni;
}
ostream& Topping_Special::afisare_virtuala_topping(ostream& out)const
{
    Topping::afisare_virtuala_topping(out);
    out<<"\nCate zile este valabil toppingul de la inceperea promotiei: "<<this -> durata_valabil_zile;
    out<<"\nProducator: "<<this -> producator;
    out<<"\nNumar de alergeni: "<<this -> numar_alergeni;
    out<<"\nLista alergeni: ";
    for(int i = 0;i<this -> numar_alergeni;i++)
    {
        out<<"\nAlergen "<<i+1<<" : "<<this -> lista_alergeni[i];
    }

    return out;
}
istream& Topping_Special::citire_virtuala_topping(istream& in)
{
    Topping::citire_virtuala_topping(in);
    cout<<"\nCate zile este valabil toppingul de la inceperea promotiei: ";
    in>>this -> durata_valabil_zile;
    cout<<"\nProducator: ";
    char aux[200];
    in.get();
    in.get(aux,200);
    in.get();
    this -> producator = aux;
    cout<<"\nNumar de alergeni: ";
    in>>this -> numar_alergeni;
    if(this -> lista_alergeni != NULL)
        delete[] this -> lista_alergeni;
    this -> lista_alergeni = new string[this -> numar_alergeni];
    for(int i=0;i<this -> numar_alergeni;i++)
    {
        cout<<"\nAlergenul "<<i+1<<" : ";
        in>> this -> lista_alergeni[i];
    }
    return in;
}
ifstream& Topping_Special::citire_virtuala_topping_fisier(ifstream& in)
{
    Topping::citire_virtuala_topping_fisier(in);
    in>>this -> durata_valabil_zile;
    char aux[200];
    in.get();
    in.get(aux,200);
    in.get();
    this -> producator=aux;
    in>>this -> numar_alergeni;
    if(this -> lista_alergeni != NULL)
        delete[] this -> lista_alergeni;
    this -> lista_alergeni = new string[this -> numar_alergeni];
    for(int i=0;i<this -> numar_alergeni;i++)
    {
        in>> this -> lista_alergeni[i];
    }
    return in;
}
ifstream& operator>>(ifstream& in,Topping_Special& t)
{
    return t.citire_virtuala_topping_fisier(in);
}
istream& operator>>(istream& in,Topping_Special& t)
{
    return t.citire_virtuala_topping(in);
}
ostream& operator<<(ostream& out,const Topping_Special& t)
{
    return t.afisare_virtuala_topping(out);
}
Topping_Special::Topping_Special():Topping()
{
    this -> durata_valabil_zile = 0;
    this -> numar_alergeni = 0;
    this -> lista_alergeni = NULL;
    this -> producator = "fara producator";
}
Topping_Special::Topping_Special(char* nume_topping,float pret_topping,double cantitate_totala_topping,float cantitate_per_portie,int durata_valabil_zile,string producator,int numar_alergeni,string* lista_alergeni):Topping(nume_topping,pret_topping,cantitate_totala_topping,cantitate_per_portie)
{
    this -> durata_valabil_zile = durata_valabil_zile;
    this -> numar_alergeni = numar_alergeni;
    this -> lista_alergeni = new string[numar_alergeni];
    for(int i=0;i<this -> numar_alergeni;i++)
        this -> lista_alergeni[i] = lista_alergeni[i];
    this -> producator = producator;
}
Topping_Special::Topping_Special(const Topping_Special& t):Topping(t)
{
    this -> durata_valabil_zile = t.durata_valabil_zile;
    this -> numar_alergeni = t.numar_alergeni;
    this -> lista_alergeni = new string[t.numar_alergeni];
    for(int i=0;i<this -> numar_alergeni;i++)
        this -> lista_alergeni[i] = t.lista_alergeni[i];
    this -> producator = t.producator;
}
Topping_Special& Topping_Special::operator=(const Topping_Special& t)
{
    if(this != &t)
    {
        if(this -> lista_alergeni != NULL)
            delete[] this -> lista_alergeni;
        Topping::operator=(t);

        this -> durata_valabil_zile = t.durata_valabil_zile;
        this -> numar_alergeni = t.numar_alergeni;
        this -> lista_alergeni = new string[t.numar_alergeni];
        for(int i=0; i<this -> numar_alergeni; i++)
            this -> lista_alergeni[i] = t.lista_alergeni[i];
        this -> producator = t.producator;
    }
    *this;
}
Topping_Special::~Topping_Special()
{
    if(this -> lista_alergeni != NULL)
        delete[] this -> lista_alergeni;
}
class Topping_Comun:public Topping
{
     private:
        int calorii_per_portie;
        string ziua_aprovizionare;
    public:
        //constructori si destructori
        Topping_Comun();
        Topping_Comun(char* nume_topping,float pret_topping,double cantitate_totala_topping,float cantitate_per_portie,int calorii_per_portie,string ziua_aprovizionare);
        Topping_Comun(const Topping_Comun& t);
        ~Topping_Comun(){};

        //operatorul =,>> si <<
        Topping_Comun& operator=(const Topping_Comun& t);
        friend istream& operator>>(istream& in,Topping_Comun& t);
        friend ostream& operator<<(ostream& out,const Topping_Comun& t);
        friend ifstream& operator>>(ifstream& in,Topping_Comun& t);

        //setteri si getteri
        int get_calorii_per_portie();
        string get_zi_aprovizionare();
        void set_calorii_per_portie(int calorii_per_portie);
        void set_zi_aprovizionare(string ziua_aprovizionare);

        //afisare si citire virtuala
        virtual istream& citire_virtuala_topping(istream& in);
        virtual ostream& afisare_virtuala_topping(ostream& out)const;
        virtual ifstream& citire_virtuala_topping_fisier(ifstream& in);

        //metode proprii ale clasei
        void afis_calorii_totale();

};
void Topping_Comun::afis_calorii_totale()
{
    float cal_total;
    cal_total = this -> calorii_per_portie * (Topping::get_cantitate_totala_topping()/Topping::get_cantitate_per_portie());
    cout<<"\nNumarul de calorii totale ale acestui topping: "<<cal_total;
}
int Topping_Comun::get_calorii_per_portie()
{
    return this -> calorii_per_portie;
}
string Topping_Comun::get_zi_aprovizionare()
{
    return this -> ziua_aprovizionare;
}
void Topping_Comun::set_calorii_per_portie(int calorii)
{
    this -> calorii_per_portie = calorii;
}
void Topping_Comun::set_zi_aprovizionare(string zi)
{
    this -> ziua_aprovizionare = zi;
}
istream& Topping_Comun::citire_virtuala_topping(istream& in)
{
    Topping::citire_virtuala_topping(in);
    cout<<"\nCalorii per portie [numar intreg]: ";
    in>>this -> calorii_per_portie;
    cout<<"\nZiua din saptamana in care este aprovizionat acest topping: ";
    char aux[100];
    in.get();
    in.get(aux,100);
    in.get();
    this -> ziua_aprovizionare = aux;

    return in;
}
ifstream& Topping_Comun::citire_virtuala_topping_fisier(ifstream& in)
{
    Topping::citire_virtuala_topping_fisier(in);
    in>>this -> calorii_per_portie;
    char aux[100];
    in.get();
    in.get(aux,100);
    in.get();
    this -> ziua_aprovizionare = aux;

    return in;
}
ifstream& operator>>(ifstream& in,Topping_Comun& t)
{
    return t.citire_virtuala_topping_fisier(in);
}
ostream& Topping_Comun::afisare_virtuala_topping(ostream& out)const
{
    Topping::afisare_virtuala_topping(out);
    out<<"\nCalorii per portie: "<<this -> calorii_per_portie;
    out<<"\nZiua de aprovizionare: "<<this -> ziua_aprovizionare;

    return out;
}
istream& operator>>(istream& in,Topping_Comun& t)
{
    return t.citire_virtuala_topping(in);
}
ostream& operator<<(ostream& out,const Topping_Comun& t)
{
    return t.afisare_virtuala_topping(out);
}
Topping_Comun::Topping_Comun():Topping()
{
    this -> calorii_per_portie = 0;
    this -> ziua_aprovizionare = "nu e setata";
}
Topping_Comun::Topping_Comun(char* nume_topping,float pret_topping,double cantitate_totala_topping,float cantitate_per_portie,int calorii_per_portie,string ziua_aprovizionare):Topping(nume_topping,pret_topping,cantitate_totala_topping,cantitate_per_portie)
{
    this -> calorii_per_portie = calorii_per_portie;
    this -> ziua_aprovizionare = ziua_aprovizionare;
}
Topping_Comun::Topping_Comun(const Topping_Comun& t):Topping(t)
{
    this -> calorii_per_portie = t.calorii_per_portie;
    this -> ziua_aprovizionare = t.ziua_aprovizionare;
}
Topping_Comun& Topping_Comun::operator=(const Topping_Comun& t)
{
    if(this != &t)
    {
        Topping::operator=(t);
        this -> calorii_per_portie = t.calorii_per_portie;
        this -> ziua_aprovizionare = t.ziua_aprovizionare;
    }
    *this;
}
class Angajat
{
private:
    char cnp[15];
    char* nume;
    char* prenume;
    float salariu;
    int locatie_la_care_lucreaza_id;
    string functie,data_angajarii;
    const int id_angajat;
public:
    static int contor_id_angajat;

    //constructori
    Angajat();
    Angajat(char cnp[15],char* nume,char* prenume,string functie);
    Angajat(char cnp[15],char* nume,char* prenume,float salariu, string functie, int locatie_la_care_lucreaza_id,string data_angajarii);
    Angajat(const Angajat& a);

    //operatori
    Angajat& operator=(const Angajat& a);
    friend istream& operator>>(istream& in, Angajat& a);
    friend ostream& operator<<(ostream& out, const Angajat& a);
    friend ifstream& operator>>(ifstream& in,Angajat& a);
    const Angajat& operator++();
    const Angajat operator++(int);
    friend Angajat operator+(const Angajat& a,float salariu_nou);
    friend Angajat operator+(float salariu_nou,const Angajat& a);
    friend Angajat operator-(const Angajat& a,float salariu_nou);
    friend Angajat operator-(float salariu_nou,const Angajat& a);
    char operator[](int index);
    bool operator<(const Angajat& a);
    bool operator>(const Angajat& a);
    bool operator==(const Angajat& a);
    explicit operator int();

    //setteri si getteri
    char* get_cnp();
    char* get_nume();
    char* get_prenume();
    float get_salariu();
    string get_functie();
    int get_locatie_la_care_lucreaza_id();
    string get_data_angajarii();
    int get_id_angajat();
    void set_cnp(char cnp[15]);
    void set_salariu(float salariu);
    void set_functie(string functie);
    void set_locatie_la_care_lucreaza_id(int locatie_la_care_lucreaza_id);
    void set_nume(char* nume);
    void set_prenume(char* prenume);
    void set_data_angajarii(string data_angajarii);

    //functii
    void afis_varsta();

    ~Angajat();

};
Angajat::operator int()
{
    return (int)this-> salariu;
}
bool Angajat::operator<(const Angajat& a)
{
    if(this->salariu<a.salariu)
        return true;
    return false;
}
bool Angajat::operator>(const Angajat& a)
{
    if(this->salariu>a.salariu)
        return true;
    return false;
}
bool Angajat::operator==(const Angajat& a)
{
    if(this->salariu==a.salariu)
        return true;
    return false;
}
char Angajat::operator[](int index)
{
    if(0<=index && index<13)
        return this -> cnp[index];
    else
    {
         cout<<"Ai introdus index gresit";
         return '0';
    }
}
Angajat operator-(const Angajat& a,float salariu_nou)
{
    Angajat aux(a);
    aux.salariu = aux.salariu - salariu_nou;
    return aux;

}
Angajat operator-(float salariu_nou,const Angajat& a)
{
    Angajat aux(a);
    aux.salariu = aux.salariu - salariu_nou;
    return aux;
}
Angajat operator+(const Angajat& a,float salariu_nou)
{
    Angajat aux(a);
    aux.salariu = aux.salariu + salariu_nou;
    return aux;

}
Angajat operator+(float salariu_nou,const Angajat& a)
{
    Angajat aux(a);
    aux.salariu = aux.salariu + salariu_nou;
    return aux;
}
const Angajat Angajat::operator++(int)
{
    Angajat aux(*this);
    this -> salariu = this -> salariu +50;
    return aux;
}
const Angajat& Angajat::operator++()
{
    this -> salariu = this -> salariu + 50;
    return *this;
}
int Angajat::get_id_angajat()
{
    return this -> id_angajat;
}
char* Angajat::get_cnp()
{
    char* aux;
    aux = new char[15];
    strcpy(aux,this->cnp);
    return aux;
}
char* Angajat::get_nume()
{
    return this -> nume;
}
char* Angajat::get_prenume()
{
    return this -> prenume;
}
float Angajat::get_salariu()
{
    return this -> salariu;
}
string Angajat::get_functie()
{
    return this -> functie;
}
int Angajat::get_locatie_la_care_lucreaza_id()
{
    return this -> locatie_la_care_lucreaza_id;
}
string Angajat::get_data_angajarii()
{
    return this -> data_angajarii;
}
void Angajat::set_data_angajarii(string data_angajarii)
{
    this -> data_angajarii = data_angajarii;
}
void Angajat::set_cnp(char cnp[15])
{
    strcpy(this -> cnp,cnp);
}
void Angajat::set_salariu(float salariu)
{
    this -> salariu = salariu;
}
void Angajat::set_functie(string functie)
{
    this -> functie = functie;
}
void Angajat::set_locatie_la_care_lucreaza_id(int locatie_la_care_lucreaza_id)
{
    this -> locatie_la_care_lucreaza_id = locatie_la_care_lucreaza_id;
}
void Angajat::set_nume(char* nume)
{
    if(strcmp(this -> nume,"Anonim"))
        delete[] this -> nume;
    this -> nume = new char[strlen(nume)+1];
    strcpy( this->nume, nume);
}
void Angajat::set_prenume(char* prenume)
{
    if(strcmp(this -> prenume,"Anonim"))
        delete[] this -> prenume;
    this -> prenume = new char[strlen(prenume)+1];
    strcpy(this -> prenume,prenume);
}
void Angajat::afis_varsta()
{
    if(this -> cnp[0] != '0')
    {
        string data_actuala;
        string copie_cnp = this -> cnp;
        cout<<"data actuala [ZZ/MM/YYYY] = ";
        cin>>data_actuala;
        int lungime = data_actuala.length();
        if(lungime!=10 || data_actuala.substr(0,2)<"01" || data_actuala.substr(0,2)>"31" || data_actuala[2]!='/'|| data_actuala[5]!= '/'
           || data_actuala.substr(3,2)<"01" || data_actuala.substr(3,2)>"12"|| data_actuala.substr(6,4)<"1900" )
        {
            cout<<"data a fost pusa incorect"<<endl;
            afis_varsta();
        }

        else
        {
            if(data_actuala.substr(3,2)>copie_cnp.substr(3,2))
            {

                stringstream data_int(data_actuala.substr(6,4));
                int data =0;
                data_int>>data;
                if(this -> cnp[0]=='1' || this -> cnp[0] =='2')
                {
                    int anul = 19;
                    anul = anul * 10 + (this -> cnp[1] - '0');
                    anul = anul * 10 + (this -> cnp[2] - '0');
                    cout<<"varsta angajatului = "<<data - anul;
                }
                else
                {
                    int anul = 20;
                    anul = anul * 10 + (this -> cnp[1] - '0');
                    anul = anul * 10 + (this -> cnp[2] - '0');
                    cout<<"varsta angajatului = "<<data - anul;
                }
            }
            if(data_actuala.substr(3,2)<copie_cnp.substr(3,2))
            {

                stringstream data_int(data_actuala.substr(6,4));
                int data =0;
                data_int>>data;
                if(this -> cnp[0]=='1' || this -> cnp[0] =='2')
                {
                    int anul = 19;
                    anul = anul * 10 + (this -> cnp[1] - '0');
                    anul = anul * 10 + (this -> cnp[2] - '0');
                    cout<<"varsta angajatului = "<<data - anul-1;
                }
                else
                {
                    int anul = 20;
                    anul = anul * 10 + (this -> cnp[1] - '0');
                    anul = anul * 10 + (this -> cnp[2] - '0');
                    cout<<"varsta angajatului = "<<data - anul-1;
                }
            }
            if(data_actuala.substr(3,2)==copie_cnp.substr(3,2))
            {
                if(data_actuala.substr(0,2)>=copie_cnp.substr(5,2))
                {
                    stringstream data_int(data_actuala.substr(6,4));
                    int data =0;
                    data_int>>data;
                    if(this -> cnp[0]=='1' || this -> cnp[0] =='2')
                    {
                        int anul = 19;
                        anul = anul * 10 + (this -> cnp[1] - '0');
                        anul = anul * 10 + (this -> cnp[2] - '0');
                        cout<<"varsta angajatului = "<<data - anul;
                    }
                    else
                    {
                        int anul = 20;
                        anul = anul * 10 + (this -> cnp[1] - '0');
                        anul = anul * 10 + (this -> cnp[2] - '0');
                        cout<<"varsta angajatului = "<<data - anul;
                    }
                }
                else
                {

                    stringstream data_int(data_actuala.substr(6,4));
                    int data =0;
                    data_int>>data;
                    if(this -> cnp[0]=='1' || this -> cnp[0] =='2')
                    {
                        int anul = 19;
                        anul = anul * 10 + (this -> cnp[1] - '0');
                        anul = anul * 10 + (this -> cnp[2] - '0');
                        cout<<"varsta angajatului = "<<data - anul-1;
                    }
                    else
                    {
                        int anul = 20;
                        anul = anul * 10 + (this -> cnp[1] - '0');
                        anul = anul * 10 + (this -> cnp[2] - '0');
                        cout<<"varsta angajatului = "<<data - anul-1;
                    }
                }
            }
        }

    }
    else
        cout<<"acest angajat nu are cnp-ul setat";
}
istream& operator>>(istream& in,Angajat& a)
{
    cout<<"\nCNP-ul angajatului: ";
    in>>a.cnp;
    char aux[100];
    cout<<"Numele angajatului: ";
    in.get();
    in.get(aux,100);
    in.get();
    if(a.nume!= NULL)
        delete[] a.nume;
    a.nume = new char[strlen(aux)+1];
    strcpy(a.nume,aux);
    cout<<"Prenumele angajatului: ";
    in.get(aux,100);
    in.get();
    if(a.prenume != NULL)
        delete[] a.prenume;
    a.prenume = new char[strlen(aux)+1];
    strcpy(a.prenume,aux);
    cout<<"Salariul acestui angajat: ";
    in>>a.salariu;
    cout<<"ID-ul locatiei la care lucreaza: ";
    in>>a.locatie_la_care_lucreaza_id;
    cout<<"Functia acestui angajat: ";
    in.get();
    getline(in,a.functie);
    cout<<"Data angajarii [ZZ/MM/YYYY]: ";
    getline(in,a.data_angajarii);

    return in;


}
ifstream& operator>>(ifstream& in,Angajat& a)
{
    in>>a.cnp;
    char aux[100];
    in.get();
    in.get(aux,100);
    in.get();
    if(a.nume!= NULL)
        delete[] a.nume;
    a.nume = new char[strlen(aux)+1];
    strcpy(a.nume,aux);
    in.get(aux,100);
    in.get();
    if(a.prenume != NULL)
        delete[] a.prenume;
    a.prenume = new char[strlen(aux)+1];
    strcpy(a.prenume,aux);
    in>>a.salariu;
    in>>a.locatie_la_care_lucreaza_id;
    in.get();
    getline(in,a.functie);
    getline(in,a.data_angajarii);

    return in;


}
ostream& operator<<(ostream& out,const Angajat& a)
{
    out<<"\nID-ul angajatului: "<<a.id_angajat<<endl;
    out<<"CNP-ul angajatului: "<<a.cnp<<endl;
    out<<"Numele angajatului: "<<a.nume<<endl;
    out<<"Prenumele angajatului: "<<a.prenume<<endl;
    out<<"Salariul angajatului: "<<a.salariu<<endl;
    out<<"ID-ul locatiei la care lucreaza: "<<a.locatie_la_care_lucreaza_id<<endl;
    out<<"Functia angajatului: "<<a.functie<<endl;
    out<<"Data angajarii: "<<a.data_angajarii<<endl;

    return out;
}
Angajat& Angajat::operator=(const Angajat& a)
{
    if(this != &a)
    {
        if(strcmp(this -> nume,"Anonim"))
            delete[] this -> nume;
        if(strcmp(this -> prenume,"Anonim"))
            delete[] this -> prenume;

        strcpy(this -> cnp,a.cnp);
        this -> nume = new char[strlen(a.nume)+1];
        strcpy(this -> nume,a.nume);
        this -> prenume = new char[strlen(a.prenume)+1];
        strcpy(this -> prenume,a.prenume);
        this -> salariu = a.salariu;
        this -> functie = a.functie;
        this -> locatie_la_care_lucreaza_id = a.locatie_la_care_lucreaza_id;
        this -> data_angajarii = a.data_angajarii;


    }
    *this;
}
Angajat::Angajat(const Angajat& a):id_angajat(a.id_angajat)
{
    strcpy(this -> cnp,a.cnp);
    this -> nume = new char[strlen(a.nume)+1];
    strcpy(this -> nume,a.nume);
    this -> prenume = new char[strlen(a.prenume)+1];
    strcpy(this -> prenume,a.prenume);
    this -> salariu = a.salariu;
    this -> functie = a.functie;
    this -> locatie_la_care_lucreaza_id = a.locatie_la_care_lucreaza_id;
    this -> data_angajarii = a.data_angajarii;
}
Angajat::Angajat():id_angajat(contor_id_angajat++)
{
    strcpy(this -> cnp, "0000000000000");
    this -> nume = new char[strlen("Anonim")+1];
    strcpy(this -> nume,"Anonim");

    this -> prenume = new char[strlen("Anonim")+1];
    strcpy(this -> prenume,"Anonim");
    this -> salariu = 0;
    this -> functie = "fara functie";
    this -> locatie_la_care_lucreaza_id = -1;
    this -> data_angajarii = "necunoscut";

}
Angajat::Angajat(char cnp[15],char* nume,char* prenume,string functie):id_angajat(contor_id_angajat++)
{
    strcpy(this -> cnp,cnp);
    this -> nume = new char[strlen(nume)+1];
    strcpy(this -> nume,nume);
    this -> prenume = new char[strlen(prenume)+1];
    strcpy(this -> prenume,prenume);
    this -> functie = functie;
}
Angajat::Angajat(char cnp[15],char* nume,char* prenume,float salariu, string functie, int locatie_la_care_lucreaza_id,string data_angajarii):id_angajat(contor_id_angajat++)
{
    strcpy(this -> cnp,cnp);
    this -> nume = new char[strlen(nume)+1];
    strcpy(this -> nume,nume);
    this -> prenume = new char[strlen(prenume)+1];
    strcpy(this -> prenume,prenume);
    this -> salariu = salariu;
    this -> functie = functie;
    this -> locatie_la_care_lucreaza_id = locatie_la_care_lucreaza_id;
    this -> data_angajarii = data_angajarii;
}
Angajat::~Angajat()
{
    if(strcmp(this -> nume,"Anonim"))
        delete[] this -> nume;
    if(strcmp(this -> prenume,"Anonim"))
        delete[] this -> prenume;



}

class Locatie
{   private:
        string adresa;
        int numar_angajati;
        double pret_intretinere_pe_luna;
        const int id_locatie;
        Angajat* angajati;
    public:
        static int contor_id_locatie;

        //constructori
        Locatie();
        Locatie(string adresa,double pret_intretinere_pe_luna);
        Locatie(string adresa,int numar_angajati,double pret_intretinere_pe_luna,Angajat* angajati);
        Locatie(const Locatie& l);

        //operatori
        Locatie& operator=(const Locatie& l);
        friend istream& operator>>(istream& in,Locatie& l);
        friend ostream& operator<<(ostream& out,const Locatie& l);
        friend ifstream& operator>>(ifstream& in,Locatie& l);
        const Locatie& operator++();
        const Locatie operator++(int);
        friend Locatie operator+(const Locatie& l,Angajat a);
        friend Locatie operator+(Angajat a,const Locatie& l);
        friend Locatie operator-(const Locatie& l,char* cnp_nou);
        friend Locatie operator-(char* cnp_nou,const Locatie& l);
        Angajat operator[](int index);
        bool operator<(const Locatie& l);
        bool operator>(const Locatie& l);
        bool operator==(const Locatie& l);
        explicit operator int();

        //setteri si getteri
        string get_adresa();
        int get_numar_angajati();
        float get_pret_intretinere_pe_luna();
        Angajat* get_angajati();
        int get_id_locatie();
        void set_adresa(string adresa);
        void set_numar_angajati(int numar_angajati);
        void set_pret_intretinere_pe_luna(double pret_intretinere_pe_luna);
        void set_angajati(int numar_angajati,Angajat* angajati);

        //functii
        void afis_salariu_total_al_angajatilor();
        virtual ostream& afisare_locatie_virtuala(ostream& out)const;
        virtual istream& citire_locatie_virtuala(istream& in);
        virtual ifstream& citire_locatie_virtuala_fisier(ifstream& in);


       ~Locatie();

};
ostream& Locatie::afisare_locatie_virtuala(ostream& out)const
{
    out<<"\nID-ul locatiei: "<<this ->id_locatie<<endl;
    out<<"Adresa locatiei: "<<this->adresa<<endl;
    out<<"Numarul de angajati: "<<this->numar_angajati<<endl;
    out<<"Pretul intretinerii pe luna: "<<this->pret_intretinere_pe_luna<<endl;
    out<<"Angajati ce lucreaza la aceasta locatie: "<<endl<<endl;
    for(int i=0;i<this ->numar_angajati;i++)
        out<<"Angajatul "<<i+1<<": "<<endl<<this->angajati[i];
    return out;
}
istream& Locatie::citire_locatie_virtuala(istream& in)
{
    cout<<"\nAdresa locatiei: ";
    char aux[500];
    in.get(aux,500);
    in.get();
    this -> adresa = aux;
    cout<<"Numar angajati: ";
    in>>this -> numar_angajati;
    cout<<"Pret intretinere pe luna: ";
    in>>this -> pret_intretinere_pe_luna;
    cout<<"Angajati ce lucreaza la aceasta locatie: "<<endl;
    if(this -> angajati != NULL)
        delete[] angajati;
    this -> angajati = new Angajat[this -> numar_angajati];
    for(int i=0;i<this ->numar_angajati;i++)
    {
        cout<<"Angajatul "<<i+1<<": ";
        in>>this -> angajati[i];
        cout<<"\n\n" ;
    }
    return in;
}
ifstream& Locatie::citire_locatie_virtuala_fisier(ifstream& in)
{
    char aux[500];
    in.get(aux,500);
    in.get();
    this -> adresa = aux;
    in>>this -> numar_angajati;
    in>>this -> pret_intretinere_pe_luna;
    if(this -> angajati != NULL)
        delete[] angajati;
    this -> angajati = new Angajat[this -> numar_angajati];
    for(int i=0;i<this ->numar_angajati;i++)
    {
        in>>this -> angajati[i];
    }
    return in;
}
Locatie::operator int()
{
    return (int)this -> pret_intretinere_pe_luna;
}
bool Locatie::operator<(const Locatie& l)
{
    if(this -> pret_intretinere_pe_luna <l.pret_intretinere_pe_luna)
        return true;
    return false;
}
bool Locatie::operator>(const Locatie& l)
{
    if(this -> pret_intretinere_pe_luna >l.pret_intretinere_pe_luna)
        return true;
    return false;
}
bool Locatie::operator==(const Locatie& l)
{
    if(this -> pret_intretinere_pe_luna==l.pret_intretinere_pe_luna)
        return true;
    return false;
}
Angajat Locatie::operator[](int index)
{
    if(0<=index && index<this -> numar_angajati)
        return this -> angajati[index];
    else
      {
          cout<<"index gresit"<<endl;
          Angajat aux;
          return aux;
      }

}
Locatie operator-(char* cnp_nou,const Locatie& l)
{
    Locatie aux(l);
    Angajat* ang;
    ang = new Angajat[aux.numar_angajati];
    int aparitii=0;
    for(int i=0;i<aux.numar_angajati;i++)
    {
        if(!strcmp(aux.angajati[i].get_cnp(),cnp_nou))
            aparitii++;
        ang[i] = aux.angajati[i];
    }
    if(aux.angajati!=NULL)
        delete[] aux.angajati;
    aux.numar_angajati = aux.numar_angajati-aparitii;
    aux.angajati = new Angajat[aux.numar_angajati];
    for(int i=0;i<(aux.numar_angajati+aparitii);i++)
    {
        if(strcmp(ang[i].get_cnp(),cnp_nou))
        {
            aux.angajati[i] = ang[i];

        }
    }
    return aux;

}
Locatie operator-(const Locatie& l, char* cnp_nou)
{
    Locatie aux(l);
    Angajat* ang;
    ang = new Angajat[aux.numar_angajati];
    int aparitii=0;
    for(int i=0;i<aux.numar_angajati;i++)
    {
        if(!strcmp(aux.angajati[i].get_cnp(),cnp_nou))
            aparitii++;
        ang[i] = aux.angajati[i];
    }
    if(aux.angajati!=NULL)
        delete[] aux.angajati;
    aux.numar_angajati = aux.numar_angajati-aparitii;
    aux.angajati = new Angajat[aux.numar_angajati];
    int j=0;
    for(int i=0;i<(aux.numar_angajati+aparitii);i++)
    {
        if(strcmp(ang[i].get_cnp(),cnp_nou))
        {
            aux.angajati[j] = ang[i];
            j++;
        }
    }
    return aux;

}
Locatie operator+(const Locatie& l,Angajat a)
{
    Locatie aux(l);
    a.set_locatie_la_care_lucreaza_id(aux.get_id_locatie());
    Angajat* lista_angajati;
    lista_angajati = new Angajat[aux.numar_angajati];
    for(int i=0;i<aux.numar_angajati;i++)
        lista_angajati[i] = aux.angajati[i];
    if(aux.angajati!=NULL)
        delete[] aux.angajati;
    aux.numar_angajati++;
    aux.angajati = new Angajat[aux.numar_angajati];
    for(int i=0;i<aux.numar_angajati-1;i++)
        aux.angajati[i] = lista_angajati[i];
    aux.angajati[aux.numar_angajati-1]=a;

    return aux;
}
Locatie operator+(Angajat a,const Locatie& l)
{
    Locatie aux(l);
    Angajat* lista_angajati;
    lista_angajati = new Angajat[aux.numar_angajati];
    for(int i=0;i<aux.numar_angajati;i++)
        lista_angajati[i] = aux.angajati[i];
    if(aux.angajati!=NULL)
        delete[] aux.angajati;
    aux.numar_angajati++;
    aux.angajati = new Angajat[aux.numar_angajati];
    for(int i=0;i<aux.numar_angajati-1;i++)
        aux.angajati[i] = lista_angajati[i];
    aux.angajati[aux.numar_angajati-1]=a;

    return aux;
}
const Locatie& Locatie::operator++()
{
    this -> pret_intretinere_pe_luna = this -> pret_intretinere_pe_luna + 100;
    return *this;
}
const Locatie Locatie::operator++(int)
{
    Locatie aux(*this);
    this -> pret_intretinere_pe_luna = this -> pret_intretinere_pe_luna + 100;
    return aux;
}
int Locatie::get_id_locatie()
{
    return this -> id_locatie;
}
string Locatie::get_adresa()
{
    return this -> adresa;
}
int Locatie::get_numar_angajati()
{
    return this -> numar_angajati;
}
float Locatie::get_pret_intretinere_pe_luna()
{
    return this -> pret_intretinere_pe_luna;
}
Angajat* Locatie::get_angajati()
{
    return this -> angajati;
}
void Locatie::set_adresa(string adresa)
{
    this -> adresa = adresa;
}
void Locatie::set_numar_angajati(int numar_angajati)
{
    this -> numar_angajati = numar_angajati;
}
void Locatie::set_pret_intretinere_pe_luna(double pret_intretinere_pe_luna)
{
    this -> pret_intretinere_pe_luna = pret_intretinere_pe_luna;
}
void Locatie::set_angajati(int numar_angajati,Angajat* angajati)
{
    if(this -> angajati != NULL)
        delete[] angajati;
    this -> angajati = new Angajat[numar_angajati];
    for(int i=0; i<numar_angajati; i++)
        this -> angajati[i] = angajati[i];
}
void Locatie::afis_salariu_total_al_angajatilor()
{
    double salariu_total = 0;
    for(int i = 0;i<this -> numar_angajati;i++)
        salariu_total = salariu_total + angajati[i].get_salariu();
    cout<<"salariu total al angajatilor de la aceasta locatie = "<<salariu_total;
}
istream& operator>>(istream& in,Locatie& l)
{
    return l.citire_locatie_virtuala(in);
}
ifstream& operator>>(ifstream& in,Locatie& l)
{
    return l.citire_locatie_virtuala_fisier(in);
}
ostream& operator<<(ostream& out,const Locatie& l)
{
    return l.afisare_locatie_virtuala(out);
}
Locatie& Locatie::operator=(const Locatie& l)
{
    if(this != &l)
    {

        if(this -> angajati != NULL)
            delete[] this -> angajati;

        this -> adresa = l.adresa;
        this -> numar_angajati = l.numar_angajati;
        this -> pret_intretinere_pe_luna = l.pret_intretinere_pe_luna;
        this -> angajati = new Angajat[l.numar_angajati];
        for(int i=0; i<l.numar_angajati; i++)
            this -> angajati[i] = l.angajati[i];
    }
    *this;
}
Locatie::Locatie(const Locatie& l):id_locatie(l.id_locatie)
{

    this -> adresa = l.adresa;
    this -> numar_angajati = l.numar_angajati;
    this -> pret_intretinere_pe_luna = l.pret_intretinere_pe_luna;
    this -> angajati = new Angajat[l.numar_angajati];
    for(int i=0; i<l.numar_angajati; i++)
        this -> angajati[i] = l.angajati[i];

}
Locatie::Locatie():id_locatie(contor_id_locatie++)
{
    this -> adresa = "fara adresa";
    this -> numar_angajati = 0;
    this -> pret_intretinere_pe_luna = 0;
    this -> angajati = NULL;
}
Locatie::Locatie(string adresa,double pret_intretinere_pe_luna):id_locatie(contor_id_locatie++)
{
    this -> adresa = adresa;
    this -> pret_intretinere_pe_luna = pret_intretinere_pe_luna;
}
Locatie::Locatie(string adresa,int numar_angajati,double pret_intretinere_pe_luna,Angajat* angajati):id_locatie(contor_id_locatie++)
{
    this -> adresa = adresa;
    this -> numar_angajati = numar_angajati;
    this -> pret_intretinere_pe_luna = pret_intretinere_pe_luna;
    this -> angajati = new Angajat[numar_angajati];
    for(int i=0; i<numar_angajati; i++)
        this -> angajati[i] = angajati[i];
}
Locatie::~Locatie()
{
    if(this -> angajati != NULL)
        delete[] this -> angajati;
}
class Locatie_Restaurant:public Locatie
{
    private:
        int nr_locuri;
        float spatiu_metri;
        Angajat* manager;
    public:
        //constructori, destructori, si operatorii de citire, afisare si operatorul =;
        Locatie_Restaurant();
        Locatie_Restaurant(string adresa,int numar_angajati,double pret_intretinere_pe_luna,Angajat* angajati,int nr_locuri,float spatiu_metri,Angajat* manager);
        Locatie_Restaurant(const Locatie_Restaurant& lr);
        Locatie_Restaurant& operator=(const Locatie_Restaurant& lr);
        friend istream& operator>>(istream& in,Locatie_Restaurant& lr);
        friend ostream& operator<<(ostream& out,const Locatie_Restaurant& lr);
        friend ifstream& operator>>(ifstream& in,Locatie& lr);
        ~Locatie_Restaurant();

        //citire si afisare virtuala
        virtual ostream& afisare_locatie_virtuala(ostream& out)const;
        virtual istream& citire_locatie_virtuala(istream& in);
        virtual ifstream& citire_locatie_virtuala_fisier(ifstream& in);

        //setteri si getteri
        void set_nr_locuri(int nr_locuri);
        void set_spatiu_merii(float spatiu_metri);
        void set_manager(Angajat* manager);
        int get_nr_locuri();
        float get_spatiu_metri();
        Angajat* get_manager();

        //metode proprii ale clasei
        string tip_locatie();
        void afis_program();
        int nr_locuri_rezervabile();


};
int Locatie_Restaurant::nr_locuri_rezervabile()
{
    return 0.60 * this ->nr_locuri;
}
void Locatie_Restaurant::afis_program()
{
    int i;
    cout<<"Ziua [1/luni] [2/marti] [3/miercuri] [4/joi] [5/vineri] [6/sambata] [7/duminica]: ";
    cin>>i;
    if(i>=1 && i<=5)
        cout<<"\n8:00 - 20:00";
    else
        cout<<"\n10:00 - 18:00";
}
string Locatie_Restaurant::tip_locatie()
{
    if(this -> spatiu_metri<=100)
        return "restaurant mic";
    if(this -> spatiu_metri<=300)
        return "restaurant mediu";
    return "restaurant mare";
}
int Locatie_Restaurant::get_nr_locuri()
{
    return this -> nr_locuri;
}
float Locatie_Restaurant::get_spatiu_metri()
{
    return this -> spatiu_metri;
}
Angajat* Locatie_Restaurant::get_manager()
{
    return this -> manager;
}
void Locatie_Restaurant::set_nr_locuri(int nr_locuri)
{
    this -> nr_locuri = nr_locuri;
}
void Locatie_Restaurant::set_spatiu_merii(float spatiu_metri)
{
    this -> spatiu_metri = spatiu_metri;
}
void Locatie_Restaurant::set_manager(Angajat* manager)
{
    if(this -> manager != NULL)
        delete this -> manager;
    if(manager!= NULL)
    {
        this -> manager = new Angajat();
        *this -> manager = *manager;
    }
    else this -> manager = NULL;
}
istream& Locatie_Restaurant::citire_locatie_virtuala(istream& in)
{
    Locatie::citire_locatie_virtuala(in);
    cout<<"\nNumar Locuri: ";
    in>>this -> nr_locuri;
    cout<<"\nSpatiu (metrii patrati): ";
    in>>this->spatiu_metri;
    cout<<"\nManagerul acestei locatii: ";
    this -> manager = new Angajat();
    in>>*this->manager;

    return in;
}
ifstream& Locatie_Restaurant::citire_locatie_virtuala_fisier(ifstream& in)
{
    Locatie::citire_locatie_virtuala_fisier(in);
    in>>this -> nr_locuri;
    in>>this->spatiu_metri;
    this -> manager = new Angajat();
    in>>*this->manager;

    return in;
}
ostream& Locatie_Restaurant::afisare_locatie_virtuala(ostream& out)const
{
    Locatie::afisare_locatie_virtuala(out);
    out<<"\nNumar Locuri: "<<this -> nr_locuri;
    out<<"\nSpatiu: "<<this -> spatiu_metri<<" metrii patrati";
    if(this -> manager!= NULL)
        out<<"\nManagerul acestei locatii: "<<*this-> manager;
    else
        out<<"\nAceasta locatie nu are manager";

    return out;
}
istream& operator>>(istream& in,Locatie_Restaurant& lr)
{
    return lr.citire_locatie_virtuala(in);
}
ifstream& operator>>(ifstream& in,Locatie_Restaurant& lr)
{
    return lr.citire_locatie_virtuala_fisier(in);
}
ostream& operator<<(ostream& out,const Locatie_Restaurant& lr)
{
    return lr.afisare_locatie_virtuala(out);
}
Locatie_Restaurant::Locatie_Restaurant():Locatie()
{
    this -> nr_locuri = 0;
    this -> spatiu_metri = 0;
    this -> manager = NULL;

}
Locatie_Restaurant::Locatie_Restaurant(string adresa,int numar_angajati,double pret_intretinere_pe_luna,Angajat* angajati,int nr_locuri,float spatiu_metri, Angajat* manager):Locatie(adresa,numar_angajati,pret_intretinere_pe_luna,angajati)
{
    this -> nr_locuri = nr_locuri;
    this -> spatiu_metri = spatiu_metri;
    this -> manager = new Angajat();
    *this -> manager = *manager;
}
Locatie_Restaurant::Locatie_Restaurant(const Locatie_Restaurant& lr):Locatie(lr)
{
    this -> nr_locuri = lr.nr_locuri;
    this -> spatiu_metri = lr.nr_locuri;
    this -> manager = new Angajat();
    *this -> manager = *lr.manager;
}
Locatie_Restaurant& Locatie_Restaurant::operator=(const Locatie_Restaurant& lr)
{
    if(this != &lr)
    {
        if(this -> manager != NULL)
            delete this -> manager;
        Locatie::operator=(lr);
        this -> nr_locuri = lr.nr_locuri;
        this -> spatiu_metri = lr.nr_locuri;
        this -> manager = new Angajat();
        *this -> manager = *lr.manager;
    }
    *this;
}
Locatie_Restaurant::~Locatie_Restaurant()
{
    if(this -> manager != NULL)
        delete this -> manager;


}
class Locatie_Livrari:public Locatie
{
    private:
        int numar_curieri;
        string timp_minim_livrare;
        char* numar_telefon;
    public:
         //constructori, destructori, si operatorii de citire, afisare si operatorul =;
        Locatie_Livrari();
        Locatie_Livrari(string adresa,int numar_angajati,double pret_intretinere_pe_luna,Angajat* angajati,int numar_curieri,string timp_minim_livrare,char* numar_telefon);
        Locatie_Livrari(const Locatie_Livrari& lr);
        Locatie_Livrari& operator=(const Locatie_Livrari& lr);
        friend istream& operator>>(istream& in,Locatie_Livrari& lr);
        friend ostream& operator<<(ostream& out,const Locatie_Livrari& lr);
        friend ifstream& operator>>(ifstream& in,Locatie_Livrari& lr);
        ~Locatie_Livrari();

        //setteri si getteri
        int get_numar_curieri();
        string get_timp_minim_livrare();
        char* get_numar_telefon();
        void set_numar_curieri(int numar_curieri);
        void set_timp_minim_livrare(string timp_minim_livrare);
        void set_numar_telefon(char* numar_telefon);

        //citire si afisare virtuala
        virtual ostream& afisare_locatie_virtuala(ostream& out)const;
        virtual istream& citire_locatie_virtuala(istream& in);
        virtual ifstream& citire_locatie_virtuala_fisier(ifstream& in);

        //metode ale clasei
        void afis_max_comenzi();
        void afis_livrare_gratis();
};
void Locatie_Livrari::afis_max_comenzi()
{
    cout<<"\nNumarul maxim de comenzi pe care le putem prelua intr-o zi: "<<this -> numar_curieri*10;
}
void Locatie_Livrari::afis_livrare_gratis()
{
    int i;
    cout<<"\nIn ce zi a saptamanii suntem? [1/luni] [2/marti] [3/miercuri] [4/joi] [5/vineri] [6/sambata] [7/duminica]: ";
    cin>>i;
    if(i%2==0)
        cout<<"\nAstazi aveti livrare gratuita";
    else
        cout<<"\nAstazi livrarea nu este gratuita";
}
int Locatie_Livrari::get_numar_curieri()
{
    return this -> numar_curieri;
}
string Locatie_Livrari::get_timp_minim_livrare()
{
    return this -> timp_minim_livrare;
}
char* Locatie_Livrari::get_numar_telefon()
{
    return this -> numar_telefon;
}
void Locatie_Livrari::set_numar_curieri(int nr_nou)
{
    this -> numar_curieri = nr_nou;
}
void Locatie_Livrari::set_timp_minim_livrare(string timp_nou)
{
    this -> timp_minim_livrare = timp_nou;
}
void Locatie_Livrari::set_numar_telefon(char* numar_telefon)
{
    if(this -> numar_telefon!= NULL)
        delete[] this -> numar_telefon;
    this -> numar_telefon = new char[strlen(numar_telefon)+1];
    strcpy(this -> numar_telefon,numar_telefon);
}
ostream& Locatie_Livrari::afisare_locatie_virtuala(ostream& out)const
{
    Locatie::afisare_locatie_virtuala(out);
    out<<"\nNumar curieri: "<<this -> numar_curieri;
    out<<"\nTimp minim livrare: "<<this -> timp_minim_livrare;
    out<<"\nNumar de Telefon: "<<this -> numar_telefon;
    return out;
}
istream& Locatie_Livrari::citire_locatie_virtuala(istream& in)
{
    Locatie::citire_locatie_virtuala(in);
    cout<<"\nNumar curieri: ";
    in>>this -> numar_curieri;
    cout<<"\nTimp minim livrare: ";
    in>> this -> timp_minim_livrare;
    cout<<"\nNumar de telefon: ";
    char aux[100];
    in>>aux;
    if(this -> numar_telefon!= NULL)
        delete[] this -> numar_telefon;
    this -> numar_telefon = new char[strlen(aux)+1];
    strcpy(this -> numar_telefon,aux);

    return in;

}
ifstream& Locatie_Livrari::citire_locatie_virtuala_fisier(ifstream& in)
{
    Locatie::citire_locatie_virtuala_fisier(in);
    in>>this -> numar_curieri;
    in>> this -> timp_minim_livrare;
    char aux[100];
    in>>aux;
    if(this -> numar_telefon!= NULL)
        delete[] this -> numar_telefon;
    this -> numar_telefon = new char[strlen(aux)+1];
    strcpy(this -> numar_telefon,aux);

    return in;

}
ifstream& operator>>(ifstream& in,Locatie_Livrari& lr)
{
    return lr.citire_locatie_virtuala_fisier(in);
}
istream& operator>>(istream& in,Locatie_Livrari& lr)
{
    return lr.citire_locatie_virtuala(in);
}
ostream& operator<<(ostream& out,const Locatie_Livrari& lr)
{
    return lr.afisare_locatie_virtuala(out);
}
Locatie_Livrari::Locatie_Livrari():Locatie()
{
    this -> numar_curieri = 0;
    this -> timp_minim_livrare = "0";
    this -> numar_telefon = NULL;
}
Locatie_Livrari::Locatie_Livrari(string adresa,int numar_angajati,double pret_intretinere_pe_luna,Angajat* angajati,int numar_curieri,string timp_minim_livrare,char* numar_telefon):Locatie(adresa,numar_angajati,pret_intretinere_pe_luna,angajati)
{
    this -> numar_curieri = numar_curieri;
    this -> timp_minim_livrare = timp_minim_livrare;
    this -> numar_telefon = new char[strlen(numar_telefon)+1];
    strcpy(this -> numar_telefon,numar_telefon);
}
Locatie_Livrari::Locatie_Livrari(const Locatie_Livrari& lr):Locatie(lr)
{
    this -> numar_curieri = lr.numar_curieri;
    this -> timp_minim_livrare = lr.timp_minim_livrare;
    this -> numar_telefon = new char[strlen(lr.numar_telefon)+1];
    strcpy(this -> numar_telefon,lr.numar_telefon);
}
Locatie_Livrari& Locatie_Livrari::operator=(const Locatie_Livrari& lr)
{
    if(this != &lr)
    {
         if(this -> numar_telefon != NULL)
            delete[] this ->numar_telefon;
        Locatie::operator=(lr);
        this -> numar_curieri = lr.numar_curieri;
        this -> timp_minim_livrare = lr.timp_minim_livrare;
        this -> numar_telefon = new char[strlen(lr.numar_telefon)+1];
        strcpy(this -> numar_telefon,lr.numar_telefon);
    }
    *this;
}
Locatie_Livrari::~Locatie_Livrari()
{
    if(this -> numar_telefon != NULL)
        delete[] this ->numar_telefon;

}
class Interfata_Paste
{
    private:
    public:
        virtual float Calculeaza_Gramaj_Total()=0;
        virtual float Calculeaza_Calorii()=0;
};
class Paste:public Interfata_Paste
{
    private:
        int numar_tip_paste;
        string* tipuri_paste;
    public:
        //constructori, destructori, si operatorii de citire, afisare si operatorul =;
        Paste();
        Paste(int numar_tip_paste,string* tipuri_paste);
        Paste(const Paste& ps);
        Paste& operator=(const Paste& ps);
        friend istream& operator>>(istream& in,Paste& ps);
        friend ostream& operator<<(ostream& out,const Paste& ps);
        friend ifstream& operator>>(ifstream& in,Paste& ps);
        ~Paste();
        virtual float calculeaza_pret()=0;
        virtual string get_nume()=0;

        //setteri si getteri
        int get_numar_tip_paste();
        string* get_tipuri_paste();
        void set_tipuri_paste(string* tipuri_paste,int numar);
        void set_numar_tip_paste(int numar);

        //citire si afisare virtuala
        virtual ostream& afisare_paste_virtuala(ostream& out)const;
        virtual istream& citire_paste_virtuala(istream& in);
        virtual ifstream& citire_paste_virtuala_fisier(ifstream& in);


};
int Paste::get_numar_tip_paste()
{
    return this -> numar_tip_paste;
}
string* Paste::get_tipuri_paste()
{
    return this -> tipuri_paste;
}
void Paste::set_numar_tip_paste(int numar)
{
    this -> numar_tip_paste = numar;
}
void Paste::set_tipuri_paste(string* tip,int numar)
{
    this -> numar_tip_paste =  numar;
    if(this -> tipuri_paste != NULL)
        delete[] this -> tipuri_paste;
    this -> tipuri_paste = new string[numar];
    for(int i=0;i<numar;i++)
        this -> tipuri_paste[i] = tip[i];

}
ostream& Paste::afisare_paste_virtuala(ostream& out)const
{
    out<<"\nNumarul tipurilor de paste: "<<this -> numar_tip_paste;
    out<<"\nTipurile de paste: ";
    for(int i=0;i<this -> numar_tip_paste;i++)
        out<<"\nTip "<<i+1<<" : "<<this -> tipuri_paste[i];

    return out;
}
istream& Paste::citire_paste_virtuala(istream& in)
{
    cout<<"\nNumarul tipurilor de paste: ";
    in>>this -> numar_tip_paste;
    cout<<"\nTipurile de paste: ";
    if(this -> tipuri_paste != NULL)
        delete[] this -> tipuri_paste;
    this -> tipuri_paste = new string[this -> numar_tip_paste];
    for(int i=0;i<this -> numar_tip_paste;i++)
    {
        cout<<"\nTip "<<i+1<<" : ";
        char aux[100];
        in.get();
        in.get(aux,100);
        this -> tipuri_paste[i] = aux;
    }
    return in;
}
ifstream& Paste::citire_paste_virtuala_fisier(ifstream& in)
{
    in>>this -> numar_tip_paste;
    if(this -> tipuri_paste != NULL)
        delete[] this -> tipuri_paste;
    this -> tipuri_paste = new string[this -> numar_tip_paste];
    for(int i=0;i<this -> numar_tip_paste;i++)
    {
        char aux[100];
        in.get();
        in.get(aux,100);
        this -> tipuri_paste[i] = aux;
    }
    return in;
}
ifstream& operator>>(ifstream& in,Paste& ps)
{
    return ps.citire_paste_virtuala_fisier(in);
}
istream& operator>>(istream& in,Paste& ps)
{
    return ps.citire_paste_virtuala(in);
}
ostream& operator<<(ostream& out, const Paste& ps)
{
    return ps.afisare_paste_virtuala(out);
}
Paste& Paste::operator=(const Paste& ps)
{
    if(this != &ps)
    {
        if(this -> tipuri_paste != NULL)
            delete[] tipuri_paste;
        this -> numar_tip_paste = ps.numar_tip_paste;
        this -> tipuri_paste = new string[ps.numar_tip_paste];
        for(int i =0;i<ps.numar_tip_paste;i++)
            this -> tipuri_paste[i] = ps.tipuri_paste[i];
    }
    *this;
}
Paste::Paste(const Paste& ps)
{
    this -> numar_tip_paste = ps.numar_tip_paste;
    this -> tipuri_paste = new string[ps.numar_tip_paste];
    for(int i =0;i<ps.numar_tip_paste;i++)
        this -> tipuri_paste[i] = ps.tipuri_paste[i];
}
Paste::Paste(int numar_tip_paste,string* tipuri_paste)
{
    this -> numar_tip_paste = numar_tip_paste;
    this -> tipuri_paste = new string[numar_tip_paste];
    for(int i =0;i<numar_tip_paste;i++)
        this -> tipuri_paste[i] = tipuri_paste[i];
}
Paste::Paste()
{
    this -> numar_tip_paste = 0;
    this -> tipuri_paste = NULL;
}
Paste::~Paste()
{
    if(this -> tipuri_paste != NULL)
        delete[] tipuri_paste;
}
class Paste_Carbonara:public Paste
{
    private:
        int gramaj_bacon;
        int gramaj_sos_alb;
    public:
        //constructori,destructori si operatorii =,>>,<<
        Paste_Carbonara();
        Paste_Carbonara(int numar_tip_paste,string* tipuri_paste,int gramaj_bacon, int gramaj_sos_alb);
        Paste_Carbonara(const Paste_Carbonara& ps);
        Paste_Carbonara& operator=(const Paste_Carbonara& ps);
        friend istream& operator>>(istream& in,Paste_Carbonara& ps);
        friend ostream& operator<<(ostream& out,const Paste_Carbonara& ps);
        friend ifstream& operator>>(ifstream& in, Paste_Carbonara& ps);
        ~Paste_Carbonara(){};
        //citire si afisare virtuala
        virtual ostream& afisare_paste_virtuala(ostream& out)const;
        virtual istream& citire_paste_virtuala(istream& in);
        virtual ifstream& citire_paste_virtuala_fisier(ifstream& in);
        //metoda virtuala pura a clasei abstracte
        virtual float calculeaza_pret();
        virtual string get_nume();

        //metode virtuale pure ale interfatei
        float Calculeaza_Calorii();
        float Calculeaza_Gramaj_Total();

        //setteri si getteri
        int get_gramaj_bacon();
        int get_gramaj_sos_alb();
        void set_gramaj_bacon(int bacon);
        void set_gramaj_sos_alb(int sos);


};
string Paste_Carbonara::get_nume()
{
    return "Paste Carbonara";
}
float Paste_Carbonara::Calculeaza_Calorii()
{
    return this -> gramaj_bacon*5+this -> gramaj_sos_alb*3 + 250 * 1.3;
}
float Paste_Carbonara::Calculeaza_Gramaj_Total()
{
    return this -> gramaj_bacon + this -> gramaj_sos_alb + 250;
}
int Paste_Carbonara::get_gramaj_bacon()
{
    return this -> gramaj_bacon;
}
int Paste_Carbonara::get_gramaj_sos_alb()
{
    return this -> gramaj_sos_alb;
}
void Paste_Carbonara::set_gramaj_bacon(int bacon)
{
    this -> gramaj_bacon = bacon;
}
void Paste_Carbonara::set_gramaj_sos_alb(int sos)
{
    this -> gramaj_sos_alb = sos;
}
float Paste_Carbonara::calculeaza_pret()
{
    return this -> gramaj_bacon*0.085 + this -> gramaj_sos_alb* 0.087 + 20;
}
istream& Paste_Carbonara::citire_paste_virtuala(istream& in)
{
    cout<<"Paste Carbonara\n";
    Paste::citire_paste_virtuala(in);
    cout<<"\nGramajul de bacon: ";
    in>>this -> gramaj_bacon;
    cout<<"\nGramajul de sos alb: ";
    in>>this -> gramaj_sos_alb;

    return in;
}
ifstream& Paste_Carbonara::citire_paste_virtuala_fisier(ifstream& in)
{
    Paste::citire_paste_virtuala_fisier(in);
    in>>this -> gramaj_bacon;
    in>>this -> gramaj_sos_alb;

    return in;
}
ifstream& operator>>(ifstream& in, Paste_Carbonara& ps)
{
    return ps.citire_paste_virtuala_fisier(in);
}
ostream& Paste_Carbonara::afisare_paste_virtuala(ostream& out)const
{
    out<<"\nPaste Carbonara\n";
    Paste::afisare_paste_virtuala(out);
    out<<"\nGramajul de bacon: "<<this -> gramaj_bacon;
    out<<"\nGramajul de sos alb: "<<this -> gramaj_sos_alb;

    return out;
}
istream& operator>>(istream& in,Paste_Carbonara& ps)
{
    ps.citire_paste_virtuala(in);
}
ostream& operator<<(ostream& out,const Paste_Carbonara& ps)
{
    return ps.afisare_paste_virtuala(out);
}
Paste_Carbonara::Paste_Carbonara():Paste()
{
    this -> gramaj_bacon = 0;
    this -> gramaj_sos_alb = 0;
}
Paste_Carbonara::Paste_Carbonara(int numar_tip_paste,string* tipuri_paste,int gramaj_bacon, int gramaj_sos_alb):Paste(numar_tip_paste,tipuri_paste)
{
    this -> gramaj_bacon = gramaj_bacon;
    this -> gramaj_sos_alb = gramaj_sos_alb;
}
Paste_Carbonara::Paste_Carbonara(const Paste_Carbonara& ps):Paste(ps)
{
    this -> gramaj_bacon = ps.gramaj_bacon;
    this -> gramaj_sos_alb = ps.gramaj_sos_alb;
}
Paste_Carbonara& Paste_Carbonara::operator=(const Paste_Carbonara& ps)
{
    if(this != &ps)
    {
        Paste::operator=(ps);
        this -> gramaj_bacon = ps.gramaj_bacon;
        this -> gramaj_sos_alb = ps.gramaj_sos_alb;
    }
    *this;
}
class Paste_Quatro_Formaggi:public Paste
{
    private:
        int gramaj_brie;
        int gramaj_gorgonzola;
        int gramaj_mozzarela;
        int gramaj_parmezan;
    public:
        //constructori,destructori si operatorii =,>>,<<
        Paste_Quatro_Formaggi();
        Paste_Quatro_Formaggi(int numar_tip_paste,string* tipuri_paste,int gramaj_brie,int gramaj_gorgonzola,int gramaj_mozzarela,int gramaj_parmezan);
        Paste_Quatro_Formaggi(const Paste_Quatro_Formaggi& ps);
        Paste_Quatro_Formaggi& operator=(const Paste_Quatro_Formaggi& ps);
        friend istream& operator>>(istream& in,Paste_Quatro_Formaggi& ps);
        friend ostream& operator<<(ostream& out,const Paste_Quatro_Formaggi& ps);
        friend ifstream& operator>>(ifstream& in,Paste_Quatro_Formaggi& ps);
        ~Paste_Quatro_Formaggi(){};
        //citire si afisare virtuala
        virtual ostream& afisare_paste_virtuala(ostream& out)const;
        virtual istream& citire_paste_virtuala(istream& in);
        virtual ifstream& citire_paste_virtuala_fisier(ifstream& in);
        //metoda virtuala pura a clasei abstracte
        virtual float calculeaza_pret();
        virtual string get_nume();

        //metode virtuale pure ale interfetei
        float Calculeaza_Calorii();
        float Calculeaza_Gramaj_Total();

        //setteri si getteri
        int get_gramaj_brie();
        int get_gramaj_gorgonzola();
        int get_gramaj_mozzarela();
        int get_gramaj_parmezan();
        void set_gramaj_brie(int branza);
        void set_gramaj_gorgonzola(int branza);
        void set_gramaj_mozzarela(int branza);
        void set_gramaj_parmezan(int branza);



};
string Paste_Quatro_Formaggi::get_nume()
{
    return "Paste Quatro_Formaggi";
}
float Paste_Quatro_Formaggi::Calculeaza_Calorii()
{
    return this -> gramaj_brie* 3.3 +this -> gramaj_gorgonzola* 3.5 + this -> gramaj_mozzarela * 2.8 + this -> gramaj_parmezan * 4.3 + 250 *1.3;
}
float Paste_Quatro_Formaggi::Calculeaza_Gramaj_Total()
{
    return this -> gramaj_brie+this -> gramaj_gorgonzola+this -> gramaj_mozzarela + this -> gramaj_parmezan +250;
}
int Paste_Quatro_Formaggi::get_gramaj_brie()
{
    return this -> gramaj_brie;
}
int Paste_Quatro_Formaggi::get_gramaj_gorgonzola()
{
    return  this -> gramaj_gorgonzola;
}
int Paste_Quatro_Formaggi::get_gramaj_mozzarela()
{
    return this -> gramaj_mozzarela;
}
int Paste_Quatro_Formaggi::get_gramaj_parmezan()
{
    return this -> gramaj_parmezan;
}
void Paste_Quatro_Formaggi::set_gramaj_brie(int branza)
{
    this -> gramaj_brie = branza;
}
void Paste_Quatro_Formaggi::set_gramaj_gorgonzola(int branza)
{
    this -> gramaj_gorgonzola = branza;
}
void Paste_Quatro_Formaggi::set_gramaj_mozzarela(int branza)
{
    this -> gramaj_mozzarela = branza;
}
void Paste_Quatro_Formaggi::set_gramaj_parmezan(int branza)
{
    this -> gramaj_parmezan = branza;
}
float Paste_Quatro_Formaggi::calculeaza_pret()
{
    return this -> gramaj_brie*0.09 + this -> gramaj_gorgonzola* 0.09+this-> gramaj_mozzarela*0.07 + this ->gramaj_parmezan*0.07 + 20;
}
istream& Paste_Quatro_Formaggi::citire_paste_virtuala(istream& in)
{
    cout<<"Paste Quatro Formaggi\n";
    Paste::citire_paste_virtuala(in);
    cout<<"\nGramajul de branza brie: ";
    in>>this -> gramaj_brie;
    cout<<"\nGramajul de branza gorgonzola: ";
    in>>this -> gramaj_gorgonzola;

    cout<<"\nGramajul de mozzarela: ";
    in>>this -> gramaj_mozzarela;

    cout<<"\nGramajul de parmezan: ";
    in>>this -> gramaj_parmezan;

    return in;
}
ifstream& Paste_Quatro_Formaggi::citire_paste_virtuala_fisier(ifstream& in)
{

    Paste::citire_paste_virtuala_fisier(in);
    in>>this -> gramaj_brie;
    in>>this -> gramaj_gorgonzola;
    in>>this -> gramaj_mozzarela;
    in>>this -> gramaj_parmezan;

    return in;
}
ifstream& operator>>(ifstream& in,Paste_Quatro_Formaggi& ps)
{
    return ps.citire_paste_virtuala_fisier(in);
}
ostream& Paste_Quatro_Formaggi::afisare_paste_virtuala(ostream& out)const
{
    out<<"\nPaste Quatro Formaggi\n";
    Paste::afisare_paste_virtuala(out);
    out<<"\nGramajul de branza brie: "<<this -> gramaj_brie;
    out<<"\nGramajul de branza gorgonzola: "<<this -> gramaj_gorgonzola;
    out<<"\nGramajul de mozzarela: "<<this -> gramaj_mozzarela;
    out<<"\nGramajul de parmezan: "<<this -> gramaj_parmezan;

    return out;
}
istream& operator>>(istream& in,Paste_Quatro_Formaggi& ps)
{
    ps.citire_paste_virtuala(in);
}
ostream& operator<<(ostream& out,const Paste_Quatro_Formaggi& ps)
{
    return ps.afisare_paste_virtuala(out);
}
Paste_Quatro_Formaggi::Paste_Quatro_Formaggi():Paste()
{
    this -> gramaj_brie = 0;
    this -> gramaj_mozzarela =0;
    this -> gramaj_parmezan =0;
    this -> gramaj_gorgonzola =0;
}
Paste_Quatro_Formaggi::Paste_Quatro_Formaggi(int numar_tip_paste,string* tipuri_paste,int gramaj_brie,int gramaj_gorgonzola,int gramaj_mozzarela,int gramaj_parmezan):Paste(numar_tip_paste,tipuri_paste)
{
    this -> gramaj_brie = gramaj_brie;
    this -> gramaj_gorgonzola = gramaj_gorgonzola;
    this -> gramaj_mozzarela = gramaj_mozzarela;
    this -> gramaj_parmezan = gramaj_parmezan;
}
Paste_Quatro_Formaggi::Paste_Quatro_Formaggi(const Paste_Quatro_Formaggi& ps):Paste(ps)
{
    this -> gramaj_brie = ps.gramaj_brie;
    this -> gramaj_gorgonzola = ps.gramaj_gorgonzola;
    this -> gramaj_mozzarela = ps.gramaj_mozzarela;
    this -> gramaj_parmezan = ps.gramaj_parmezan;
}
Paste_Quatro_Formaggi& Paste_Quatro_Formaggi::operator=(const Paste_Quatro_Formaggi& ps)
{
    if(this != &ps)
    {
        Paste::operator=(ps);
        this -> gramaj_brie = ps.gramaj_brie;
        this -> gramaj_gorgonzola = ps.gramaj_gorgonzola;
        this -> gramaj_mozzarela = ps.gramaj_mozzarela;
        this -> gramaj_parmezan = ps.gramaj_parmezan;
    }
    *this;
}
class Paste_Bolognese:public Paste
{
    private:
        int gramaj_carne;
        int gramaj_sos_rosu;
    public:
        //constructori,destructori si operatorii =,>>,<<
        Paste_Bolognese();
        Paste_Bolognese(int numar_tip_paste,string* tipuri_paste,int gramaj_carne, int gramaj_sos_rosu);
        Paste_Bolognese(const Paste_Bolognese& ps);
        Paste_Bolognese& operator=(const Paste_Bolognese& ps);
        friend istream& operator>>(istream& in,Paste_Bolognese& ps);
        friend ifstream& operator>>(ifstream& in,Paste_Bolognese& ps);
        friend ostream& operator<<(ostream& out,const Paste_Bolognese& ps);
        ~Paste_Bolognese(){};
        //citire si afisare virtuala
        virtual ostream& afisare_paste_virtuala(ostream& out)const;
        virtual istream& citire_paste_virtuala(istream& in);
        virtual ifstream& citire_paste_virtuala_fisier(ifstream& in);
        //metoda virtuala pura a clasei abstracte
        virtual float calculeaza_pret();
        virtual string get_nume();

        //metode virtuale pure ale interfetei
        float Calculeaza_Calorii();
        float Calculeaza_Gramaj_Total();

        //setteri si getteri
        int get_gramaj_carne();
        int get_gramaj_sos_rosu();
        void set_gramaj_carne(int carne);
        void set_gramaj_sos_rosu(int sos);


};
string Paste_Bolognese::get_nume()
{
    return "Paste Bolognese";
}
float Paste_Bolognese::Calculeaza_Calorii()
{
    return this -> gramaj_carne*2.4 + this -> gramaj_sos_rosu*2.6 + 250*1.3;
}
float Paste_Bolognese::Calculeaza_Gramaj_Total()
{
    return this -> gramaj_carne + this -> gramaj_sos_rosu + 250;
}
int Paste_Bolognese::get_gramaj_carne()
{
    return this -> gramaj_carne;
}
int Paste_Bolognese::get_gramaj_sos_rosu()
{
    return this -> gramaj_sos_rosu;
}
void Paste_Bolognese::set_gramaj_carne(int carne)
{
    this -> gramaj_carne = carne;
}
void Paste_Bolognese::set_gramaj_sos_rosu(int sos)
{
    this -> gramaj_sos_rosu = sos;
}
float Paste_Bolognese::calculeaza_pret()
{
    return this -> gramaj_carne*0.1 + this -> gramaj_sos_rosu*0.095 + 20;
}
istream& Paste_Bolognese::citire_paste_virtuala(istream& in)
{
    cout<<"Paste Bolognese\n";
    Paste::citire_paste_virtuala(in);
    cout<<"\nGramajul de carne: ";
    in>>this -> gramaj_carne;
    cout<<"\nGramajul de sos rosu: ";
    in>>this -> gramaj_sos_rosu;

    return in;
}
ifstream& Paste_Bolognese::citire_paste_virtuala_fisier(ifstream& in)
{
    Paste::citire_paste_virtuala_fisier(in);
    in>>this -> gramaj_carne;
    in>>this -> gramaj_sos_rosu;

    return in;
}
ifstream& operator>>(ifstream& in,Paste_Bolognese& ps)
{
    return ps.citire_paste_virtuala_fisier(in);
}
ostream& Paste_Bolognese::afisare_paste_virtuala(ostream& out)const
{
    out<<"\nPaste Bolognese\n";
    Paste::afisare_paste_virtuala(out);
    out<<"\nGramajul de carne: "<<this -> gramaj_carne;
    out<<"\nGramajul de sos rosu: "<<this -> gramaj_sos_rosu;

    return out;
}
istream& operator>>(istream& in,Paste_Bolognese& ps)
{
    ps.citire_paste_virtuala(in);
}
ostream& operator<<(ostream& out,const Paste_Bolognese& ps)
{
    return ps.afisare_paste_virtuala(out);
}
Paste_Bolognese::Paste_Bolognese():Paste()
{
    this -> gramaj_carne = 0;
    this -> gramaj_sos_rosu = 0;
}
Paste_Bolognese::Paste_Bolognese(int numar_tip_paste,string* tipuri_paste,int gramaj_carne, int gramaj_sos_rosu):Paste(numar_tip_paste,tipuri_paste)
{
    this -> gramaj_carne = gramaj_carne;
    this -> gramaj_sos_rosu = gramaj_sos_rosu;
}
Paste_Bolognese::Paste_Bolognese(const Paste_Bolognese& ps):Paste(ps)
{
    this -> gramaj_carne = ps.gramaj_carne;
    this -> gramaj_sos_rosu = ps.gramaj_sos_rosu;
}
Paste_Bolognese& Paste_Bolognese::operator=(const Paste_Bolognese& ps)
{
    if(this != &ps)
    {
        Paste::operator=(ps);
        this -> gramaj_carne = ps.gramaj_carne;
        this -> gramaj_sos_rosu = ps.gramaj_sos_rosu;
    }
    *this;
}




int Pizza::contor_Id_pizza = 1;
int Locatie::contor_id_locatie =1;
int Topping::contor_id_topping = 1;
int Angajat::contor_id_angajat=1;

int main () {

    //Aici sunt niste teste facute de mine, le-am lasat in caz ca va ajuta sa verificati functionalitatea programului

    int contor_comenzi=0;
    set<Pizza> Meniu_Pizza;
    string Parola_Administrator;
    fin>>Parola_Administrator;
    int numar_pizze;
    fin>>numar_pizze;
    fin.get();
    for(int i=0;i<numar_pizze;i++)
    {
        Pizza aux;
        fin>>aux;
        fin.get();
        Meniu_Pizza.insert(aux);


    }
    Paste_Carbonara P_Carbonara_default;
    Paste_Bolognese P_Bolognese_default;
    Paste_Quatro_Formaggi P_Quatro_Formaggi_default;
    fin>>P_Carbonara_default;
    fin>>P_Bolognese_default;
    fin>>P_Quatro_Formaggi_default;
    list<Locatie*> Lista_Locatii;
    unordered_map<char*,Locatie*> Map_ang_locatie;
    vector<Angajat*> vector_ang;
    int numar_locatii_Livrari;
    int numar_locatii_Restaurant;
    fin>>numar_locatii_Livrari;
    fin.get();
    for(int i=0;i<numar_locatii_Livrari;i++)
    {
        Locatie_Livrari* aux;
        aux = new Locatie_Livrari();
        fin>>*aux;
        fin.get();
        Lista_Locatii.push_back(aux);
        int nr_ang_aux = aux->get_numar_angajati();
        Angajat* aux2;
        aux2 = aux ->get_angajati();
        for(int i=0;i<nr_ang_aux;i++)
        {
            vector_ang.push_back(&aux2[i]);
            Map_ang_locatie[aux2[i].get_cnp()] = aux;
        }


    }
    //for(auto x:Map_ang_locatie)
    //    cout<<x.first<<":"<<*x.second<<"\n----------------------------------------\n";
    //for(auto itr= Lista_Locatii.begin();itr!= Lista_Locatii.end();itr++)
    //    cout<<*(*itr);
    //for(auto itr= vector_ang.begin();itr!=vector_ang.end();itr++)
    //    cout<<*itr;
    fin>>numar_locatii_Restaurant;
    fin.get();
    for(int i=0;i<numar_locatii_Restaurant;i++)
    {
        Locatie_Restaurant* aux;
        aux = new Locatie_Restaurant();
        fin>>*aux;
        fin.get();
        Lista_Locatii.push_back(aux);
        int nr_ang_aux = aux->get_numar_angajati();
        Angajat* aux2;
        aux2 = aux->get_angajati();
        for(int i=0;i<nr_ang_aux;i++)
        {
            vector_ang.push_back(&aux2[i]);
            Map_ang_locatie[aux2[i].get_cnp()] = aux;
        }
        vector_ang.push_back(aux->get_manager());
        Map_ang_locatie[aux->get_manager()->get_cnp()] = aux;



    }
    //for(auto x:Map_ang_locatie)
    //    cout<<x.first<<":"<<*x.second<<"\n----------------------------------------\n";
    //for(auto itr= Lista_Locatii.begin();itr!= Lista_Locatii.end();itr++)
    //    cout<<*(*itr);
    //for(auto itr= vector_ang.begin();itr!=vector_ang.end();itr++)
    //{
    //    cout<<*(*itr);
    //}
    vector<Topping*> vector_topping;
    int numar_top_comune;
    fin>>numar_top_comune;
    fin.get();
    for(int i=0;i<numar_top_comune;i++)
    {
        Topping_Comun* aux;
        aux = new Topping_Comun();
        fin>>*aux;
        vector_topping.push_back(aux);
    }
    int numar_top_speciale;
    fin>>numar_top_speciale;
    fin.get();
    for(int i=0;i<numar_top_speciale;i++)
    {
        Topping_Special* aux;
        aux = new Topping_Special();
        fin>>*aux;
        fin.get();
        vector_topping.push_back(aux);
    }


    /*for(auto itr=vector_topping.begin();itr!=vector_topping.end();itr++)
    {

        Topping_Special* aux = dynamic_cast<Topping_Special*> (*itr);
        if(aux != NULL)
            cout<<aux->get_durata_valabil_zile();
        //cout<<*(*itr);
    }*/







    //aici este un meniu interactiv pe care se pot rula teste pentru a fi exemplificata virtualizarea
    //cel mai evident test este citirea unor Paste Carbonare si a unor Paste Bolognese cu exact aceleasi date si afisarea pretului diferit pentru cele doua.
    int k=1;
    int i=0;
    while(k==1){

        cout<<"\nCum doriti sa va logati?";
        cout<<"\n1 User";
        cout<<"\n2 Administrator";
        cout<<"\n3 Stop\n";
        int comanda;
        cin>> comanda;
        switch(comanda){

            case 1:{

                vector<Paste*>vector_comanda_paste;
                vector<Pizza>vector_comanda_pizza;

                int k2 = 1;
                while(k2 == 1)
                {
                   cout<<"\n1 Comanda Paste";
                   cout<<"\n2 Comanda Pizza";
                   cout<<"\n3 Finalizeaza Comanda";
                   cout<<"\n4 Anuleaza Comanda\n";
                   int comanda1;
                   cin>>comanda1;
                   switch(comanda1)
                   {
                   case 1:
                    {
                        int k3 = 1;
                        while(k3 ==1 )
                        {
                            cout<<"\nMeniu Paste";
                            cout<<"\n\n1 "<<P_Carbonara_default;
                            cout<<"\n\n2 "<<P_Quatro_Formaggi_default;
                            cout<<"\n\n3 "<<P_Bolognese_default;
                            cout<<"\n\n4 Inapoi";
                            cout<<"\nAlgeti paste\n";
                            int comanda2;
                            cin>>comanda2;
                            switch(comanda2)
                            {
                                case 1:
                                {
                                    Paste_Carbonara* pc;
                                    pc = new Paste_Carbonara();
                                    *pc = P_Carbonara_default;
                                    int k4 =1;
                                    while(k4 == 1)
                                    {
                                        cout<<"\n1 Alege Tipul de Paste";
                                        cout<<"\n2 Adauga Bacon extra";
                                        cout<<"\n3 Adauga sos alb extra";
                                        cout<<"\n4 Adauga Produs in cos";
                                        int comanda3;
                                        cin>>comanda3;
                                        switch(comanda3)
                                        {
                                            case 1:

                                            {
                                                int nr_tip_paste = pc->get_numar_tip_paste();
                                                cout<<"\nTipurile de Paste:\n ";
                                                for(int i=0;i<nr_tip_paste;i++)
                                                    cout<<"\nTipul "<<i+1<<" :\n"<<pc->get_tipuri_paste()[i];
                                                cout<<"\nAlegeti tipul pastelor dupa indice";
                                                int indice;
                                                cin>>indice;
                                                if(indice<=0||indice>nr_tip_paste)
                                                {
                                                    cout<<"\nIndice incorect";
                                                    break;
                                                }
                                                else
                                                {
                                                    string* aux;
                                                    aux = new string[1];
                                                    aux[0] = pc->get_tipuri_paste()[indice-1];
                                                    pc->set_tipuri_paste(aux,1);
                                                    break;
                                                }
                                            }
                                            case 2:
                                            {
                                                pc->set_gramaj_bacon(pc->get_gramaj_bacon()+20);
                                                break;
                                            }
                                            case 3:
                                            {
                                                pc->set_gramaj_sos_alb(pc->get_gramaj_sos_alb()+30);
                                                break;
                                            }
                                            case 4:
                                            {
                                                vector_comanda_paste.push_back(pc);
                                                k4 = 0;
                                                break;
                                            }

                                        }
                                    }
                                    break;
                                }
                                case 2:
                                {
                                    Paste_Quatro_Formaggi* pc;
                                    pc = new Paste_Quatro_Formaggi();
                                    *pc = P_Quatro_Formaggi_default;
                                    int k4 =1;
                                    while(k4 == 1)
                                    {
                                        cout<<"\n1 Alege Tipul de Paste";
                                        cout<<"\n2 Adauga Mozzarella extra";
                                        cout<<"\n3 Adauga Branza Brie extra";
                                        cout<<"\n4 Adauga Branza Gorgonzola extra";
                                        cout<<"\n5 Adauga Parmezan extra";
                                        cout<<"\n6 Adauga Produs in cos";
                                        cout<<"\n7 Anuleaza\n";
                                        int comanda3;
                                        cin>>comanda3;
                                        switch(comanda3)
                                        {
                                            case 1:
                                            {
                                                int nr_tip_paste = pc->get_numar_tip_paste();
                                                cout<<"\nTipurile de Paste:\n ";
                                                for(int i=0;i<nr_tip_paste;i++)
                                                    cout<<"\nTipul "<<i+1<<" :\n"<<pc->get_tipuri_paste()[i];
                                                cout<<"\nAlegeti tipul pastelor dupa indice";
                                                int indice;
                                                cin>>indice;
                                                if(indice<=0||indice>nr_tip_paste)
                                                {
                                                    cout<<"\nIndice incorect";
                                                    break;
                                                }
                                                else
                                                {
                                                    string* aux;
                                                    aux = new string[1];
                                                    aux[0] = pc->get_tipuri_paste()[indice-1];
                                                    pc->set_tipuri_paste(aux,1);
                                                    break;
                                                }
                                            }
                                            case 2:
                                            {
                                                pc->set_gramaj_mozzarela(pc->get_gramaj_mozzarela()+20);
                                                break;
                                            }
                                            case 3:
                                            {
                                                pc->set_gramaj_brie(pc->get_gramaj_brie()+20);
                                                break;
                                            }
                                            case 4:
                                            {
                                                pc->set_gramaj_gorgonzola(pc->get_gramaj_gorgonzola()+20);
                                                break;
                                            }
                                            case 5:
                                            {
                                                pc->set_gramaj_parmezan(pc->get_gramaj_gorgonzola()+20);
                                                break;
                                            }
                                            case 6:
                                            {
                                                vector_comanda_paste.push_back(pc);
                                                k4 = 0;
                                                break;
                                            }
                                            case 7:
                                            {
                                                k4 = 0;
                                                break;
                                            }
                                        }
                                    }
                                    break;
                                }
                                case 3:
                                {
                                    Paste_Bolognese* pc;
                                    pc = new Paste_Bolognese();
                                    *pc = P_Bolognese_default;
                                    int k4 =1;
                                    while(k4 == 1)
                                    {
                                        cout<<"\n1 Alege Tipul de Paste";
                                        cout<<"\n2 Adauga carne extra";
                                        cout<<"\n3 Adauga sos rosu extra";
                                        cout<<"\n4 Adauga Produs in cos";
                                        cout<<"\n5 Anuleaza\n";
                                        int comanda3;
                                        cin>>comanda3;
                                        switch(comanda3)
                                        {
                                            case 1:
                                            {
                                                int nr_tip_paste = pc->get_numar_tip_paste();
                                                cout<<"\nTipurile de Paste:\n ";
                                                for(int i=0;i<nr_tip_paste;i++)
                                                    cout<<"\nTipul "<<i+1<<" :\n"<<pc->get_tipuri_paste()[i];
                                                cout<<"\nAlegeti tipul pastelor dupa indice";
                                                int indice;
                                                cin>>indice;
                                                if(indice<=0||indice>nr_tip_paste)
                                                {
                                                    cout<<"\nIndice incorect";
                                                    break;
                                                }
                                                else
                                                {
                                                    string* aux;
                                                    aux = new string[1];
                                                    aux[0] = pc->get_tipuri_paste()[indice-1];
                                                    pc->set_tipuri_paste(aux,1);
                                                    break;
                                                }
                                            }
                                            case 2:
                                            {
                                                pc->set_gramaj_carne(pc->get_gramaj_carne()+20);
                                                break;
                                            }
                                            case 3:
                                            {
                                                pc->set_gramaj_sos_rosu(pc->get_gramaj_sos_rosu()+30);
                                                break;
                                            }
                                            case 4:
                                            {
                                                vector_comanda_paste.push_back(pc);
                                                k4 = 0;
                                                break;
                                            }
                                            case 5:
                                            {
                                                k4 = 0;
                                                break;
                                            }

                                        }
                                    }
                                    break;
                                }
                                case 4:
                                {
                                    k3 = 0;
                                    break;
                                }

                            }

                        }
                        break;
                    }
                    case 2:
                    {
                            int contor = 0;
                            cout<<"\nMeniu Pizza";
                            for(auto itr= Meniu_Pizza.begin(); itr!=Meniu_Pizza.end(); itr++)
                            {
                                contor++;
                                cout<<"\nPizza "<<contor<<" :\n";
                                cout<<*itr;
                            }
                            cout<<"\nAlegeti Pizza dupa indice: ";
                            int indice;
                            cin>>indice;
                            if(indice<=0||indice>contor)
                            {
                                cout<<"\nIndice Incorect";
                                break;
                            }
                            else
                            {
                                int contor2= 1;
                                for(auto itr= Meniu_Pizza.begin(); itr!=Meniu_Pizza.end(); itr++)
                                {
                                    if(contor2 == indice)
                                    {

                                        Pizza aux;
                                        aux = *itr;
                                        int nr_dim = aux.get_nr_dimensiuni();
                                        float* aux2;
                                        aux2 = aux.get_dimensiuni();
                                        float* aux3;
                                        aux3 = aux.get_pret_pizza_pe_dimensiune();
                                        cout<<"\nAlegeti dimensiune\n";
                                        for(int i=0;i<nr_dim;i++)
                                        {
                                            cout<<"\nDimensiunea "<<i+1<<" si pretul ei :\n";
                                            cout<<aux2[i]<<" de cm\n";
                                            cout<<aux3[i]<<" de lei\n";
                                        }
                                        int indx;
                                        cin>>indx;
                                        if(indx<=0||indx>nr_dim)
                                        {
                                            cout<<"\nIndice Nonexistent va ruagam reluati comanda\n";
                                            break;

                                        }

                                        {
                                            float* aux4;
                                            aux4 = new float[1];
                                            aux4[0] = aux2[indx-1];
                                            float* aux5;
                                            aux5 = new float[1];
                                            aux5[0] = aux3[indx-1];
                                            aux.set_nr_dimensiuni(1);
                                            aux.set_dimensiuni(1,aux4);
                                            aux.set_pret_pizza_pe_dimensiune(1,aux5);

                                        }
                                        int k4 = 1;
                                        while(k4 == 1)
                                        {
                                            cout<<"\n1 Adauga Topping";
                                            cout<<"\n2 Adauga Produs in cos";
                                            cout<<"\n3 Anuleaza";
                                            int comanda2;
                                            cin>>comanda2;
                                            switch(comanda2)
                                            {
                                                case 1:
                                                {
                                                    if(aux.get_nr_toppinguri()==20)
                                                    {
                                                        cout<<"\nSunt deja prea multe toppinguri pe aceasta pizza\n";
                                                        break;
                                                    }
                                                    int contor3 = 0;
                                                    for(auto itr2=vector_topping.begin();itr2!=vector_topping.end();itr2++)
                                                    {
                                                        contor3++;
                                                        cout<<"\nToppingul "<<contor3<<" :\n"<<*(*itr2);
                                                    }
                                                    cout<<"\nAlegeti Toppingul dupa indice\n";
                                                    int indice2;
                                                    cin>>indice2;
                                                    if(indice2<=0||indice2>contor3)
                                                    {
                                                        cout<<"\nIndice gresit";
                                                        break;
                                                    }
                                                    else
                                                    {
                                                        int contor4=1;
                                                        for(auto itr2=vector_topping.begin();itr2!=vector_topping.end();itr2++)
                                                        {
                                                            if(contor4 == indice2)
                                                            {
                                                                Topping* t= *itr2;
                                                                aux.set_nr_topping(aux.get_nr_toppinguri()+1);
                                                                string sir_top_nou[20];
                                                                int* cant_nou_pe_top;
                                                                cant_nou_pe_top = new int[aux.get_nr_toppinguri()];
                                                                for(int i=0;i<aux.get_nr_toppinguri()-1;i++)
                                                                {
                                                                    cant_nou_pe_top[i] = aux.get_cantitate_per_topping()[i];
                                                                    sir_top_nou[i] = aux.get_toppinguri_folosite()[i];
                                                                }
                                                                cant_nou_pe_top[aux.get_nr_toppinguri()-1] =t->get_cantitate_per_portie();
                                                                sir_top_nou[aux.get_nr_toppinguri()-1] = t->get_nume_topping();
                                                                aux.set_cantitate_per_topping(aux.get_nr_toppinguri(),cant_nou_pe_top);
                                                                aux.set_topinguri_folosite(aux.get_nr_toppinguri(),sir_top_nou);
                                                                float* aux4;
                                                                aux4 = new float[1];
                                                                aux4[0] = aux.get_pret_pizza_pe_dimensiune()[0]+t->get_pret_topping();
                                                                aux.set_pret_pizza_pe_dimensiune(1,aux4);

                                                                break;
                                                            }
                                                            else
                                                                contor4++;
                                                        }
                                                        break;
                                                    }
                                                }
                                                case 2:
                                                {
                                                    vector_comanda_pizza.push_back(aux);
                                                    k4 = 0;
                                                    break;
                                                }
                                                case 3:
                                                {
                                                    k4 = 0;
                                                    break;
                                                }
                                            }
                                        }


                                        break;
                                    }
                                    else
                                        contor2++;

                                }
                                break;
                            }
                        }
                    case 3:
                    {
                        float pret_total=0;
                        string nume;
                        string prenume;
                        string numar_telefon;
                        char adresa[150];
                        cout<<"Nume: ";
                        cin>>nume;
                        cout<<"Prenume: ";
                        cin>>prenume;
                        cout<<"Numar de telefon: ";
                        cin>>numar_telefon;
                        cout<<"Adresa: ";
                        cin.get();
                        cin.get(adresa,150);
                        contor_comenzi++;
                        fout<<"Comanda "<<contor_comenzi<<" : \n\n\n";
                        fout<<"Nume: "<<nume;
                        fout<<"\nPrenume: "<<prenume;
                        fout<<"\nNumar de telefon: "<<numar_telefon;
                        fout<<"\nAdresa: "<<adresa<<"\n\n\n";
                        for(auto itr=vector_comanda_paste.begin();itr!=vector_comanda_paste.end();itr++)
                        {
                            fout<<(*(*itr));
                            Paste_Carbonara* aux1 = dynamic_cast<Paste_Carbonara*> (*itr);
                            if(aux1 != NULL)
                                pret_total = pret_total+aux1->calculeaza_pret();
                            Paste_Bolognese* aux2 = dynamic_cast<Paste_Bolognese*> (*itr);
                            if(aux2 != NULL)
                                pret_total = pret_total+aux2->calculeaza_pret();
                            Paste_Quatro_Formaggi* aux3 = dynamic_cast<Paste_Quatro_Formaggi*> (*itr);
                            if(aux3 != NULL)
                                pret_total = pret_total+aux3->calculeaza_pret();
                        }
                        for(auto itr=vector_comanda_pizza.begin();itr!=vector_comanda_pizza.end();itr++)
                        {
                            Pizza aux1;
                            aux1 = *itr;
                            fout<<*itr;
                            pret_total = pret_total+aux1.get_pret_pizza_pe_dimensiune()[0];
                        }
                        fout<<"\n\nPret Total: "<<pret_total<<"\n\n";
                        vector_comanda_pizza.clear();
                        for(auto itr= vector_comanda_paste.begin();itr!=vector_comanda_paste.end();itr++)
                        {
                            Paste* aux5;
                            aux5 = *itr;
                            if(aux5!=NULL)
                                delete aux5;
                        }
                        vector_comanda_paste.clear();
                        k2 = 0;
                        break;
                    }
                    case 4:
                    {
                        k2 = 0;
                        break;
                    }

                   }
                }
                break;
            }
            case 2:{

                int k1 =1;
                while(k1==1)
                {
                    cout<<"\n1 Introduceti Parola";
                    cout<<"\n2 Inapoi\n";
                    int comanda1;
                    cin>>comanda1;
                    switch(comanda1)
                    {
                    case 1:
                        {
                            cout<<"Parola:";
                            string parola;
                            cin>>parola;
                            if(parola==Parola_Administrator)
                            {
                                int k2 =1;
                                while(k2 == 1)
                                {
                                    cout<<"\n1 Sterge Pizza";
                                    cout<<"\n2 Sterge Angajat";
                                    cout<<"\n3 Sterge Locatie";
                                    cout<<"\n4 Sterge Topping";
                                    cout<<"\n5 Adauga Pizza";
                                    cout<<"\n6 Adauga Angajat";
                                    cout<<"\n7 Adauga Locatie";
                                    cout<<"\n8 Adauga Topping";
                                    cout<<"\n9 Modifica Pizza";
                                    cout<<"\n10 Modifica Angajat";
                                    cout<<"\n11 Modifica Locatie";
                                    cout<<"\n12 Modifica Topping";
                                    cout<<"\n13 Afiseaza Meniu Pizza";
                                    cout<<"\n14 Afiseaza Toti Angajatii";
                                    cout<<"\n15 Afiseaza Toate Toppingurile";
                                    cout<<"\n16 Afiseaza Toate Locatiile";
                                    cout<<"\n17 Inapoi\n";
                                    int comanda2;
                                    cin>>comanda2;
                                    switch(comanda2)
                                    {
                                    case 1:
                                        {
                                            int contor = 0;
                                            cout<<"Meniu Pizza";
                                            for(auto itr= Meniu_Pizza.begin();itr!=Meniu_Pizza.end();itr++)
                                            {
                                                contor++;
                                                cout<<"\nPizza "<<contor<<" :\n";
                                                cout<<*itr;
                                            }
                                            cout<<"\nAlegeti Pizza dupa indice: ";
                                            int indice;
                                            cin>>indice;
                                            if(indice<=0||indice>contor)
                                            {
                                                cout<<"\nIndice Incorect";
                                                break;
                                            }
                                            else
                                            {
                                                int contor2= 1;
                                                for(auto itr= Meniu_Pizza.begin();itr!=Meniu_Pizza.end();itr++)
                                                {
                                                    if(contor2 == indice)
                                                    {

                                                        Meniu_Pizza.erase(itr);
                                                        break;
                                                    }
                                                    else
                                                        contor2++;

                                                }
                                                break;
                                            }

                                        }
                                    case 2:
                                        {
                                            int contor = 0;
                                            for(auto itr=vector_ang.begin();itr!=vector_ang.end();itr++)
                                            {
                                                contor++;
                                                cout<<"\nAngajatul "<<contor<<" :\n";
                                                cout<<*(*itr);
                                            }
                                            cout<<"\nAlegeti angajat dupa indice: ";
                                            int indice;
                                            cin>>indice;
                                            if(indice<=0||indice>contor)
                                            {
                                                cout<<"Indice incorect";
                                                break;
                                            }
                                            else
                                            {
                                                int contor2=1;
                                                for(auto itr=vector_ang.begin(); itr!=vector_ang.end(); itr++)
                                                {
                                                    if(contor2==indice)
                                                    {
                                                        Angajat* aux;
                                                        aux = *itr;
                                                        Locatie* aux2;
                                                        for(auto itr2:Map_ang_locatie)
                                                            if(!strcmp(itr2.first,aux->get_cnp()))
                                                                aux2 = itr2.second;
                                                        *aux2 = *aux2 - aux->get_cnp();
                                                        if(aux->get_functie()=="Manager")
                                                            for(auto itr=Lista_Locatii.begin(); itr!=Lista_Locatii.end(); itr++)
                                                            {
                                                                Locatie_Restaurant* aux = dynamic_cast<Locatie_Restaurant*> (*itr);
                                                                if(aux != NULL)
                                                                {
                                                                    aux->set_manager(NULL);
                                                                }

                                                            }
                                                                vector_ang.clear();
                                                                for(auto itr=Lista_Locatii.begin(); itr!=Lista_Locatii.end(); itr++)
                                                                {

                                                                    Locatie_Livrari* aux = dynamic_cast<Locatie_Livrari*> (*itr);


                                                                    if(aux != NULL)
                                                                    {

                                                                        int nr_ang = aux->get_numar_angajati();
                                                                        for(i=0; i<nr_ang; i++)
                                                                        {
                                                                            vector_ang.push_back(&(aux->get_angajati()[i]));
                                                                        }
                                                                    }




                                                                }
                                                                for(auto itr=Lista_Locatii.begin(); itr!=Lista_Locatii.end(); itr++)
                                                                {

                                                                    Locatie_Restaurant* aux = dynamic_cast<Locatie_Restaurant*> (*itr);
                                                                    if(aux != NULL)
                                                                    {

                                                                        int nr_ang = aux->get_numar_angajati();
                                                                        for(i=0; i<nr_ang; i++)
                                                                        {
                                                                            vector_ang.push_back(&(aux->get_angajati()[i]));
                                                                        }
                                                                        if(aux->get_manager()!=NULL)
                                                                            vector_ang.push_back(&(*(aux->get_manager())));
                                                                    }



                                                                }
                                                                Map_ang_locatie.clear();
                                                                  for(auto itr=Lista_Locatii.begin(); itr!=Lista_Locatii.end(); itr++)
                                                                {

                                                                    Locatie_Restaurant* aux = dynamic_cast<Locatie_Restaurant*> (*itr);
                                                                    if(aux != NULL)
                                                                    {

                                                                        int nr_ang = aux->get_numar_angajati();
                                                                        for(i=0; i<nr_ang; i++)
                                                                        {
                                                                            Map_ang_locatie[aux->get_angajati()[i].get_cnp()]=aux;
                                                                        }
                                                                        if(aux->get_manager()!=NULL)
                                                                            Map_ang_locatie[aux->get_manager()->get_cnp()]=aux;
                                                                    }



                                                                }
                                                        for(auto itr=Lista_Locatii.begin(); itr!=Lista_Locatii.end(); itr++)
                                                        {

                                                            Locatie_Livrari* aux = dynamic_cast<Locatie_Livrari*> (*itr);
                                                            if(aux != NULL)
                                                            {

                                                                int nr_ang = aux->get_numar_angajati();
                                                                for(i=0; i<nr_ang; i++)
                                                                {
                                                                    Map_ang_locatie[aux->get_angajati()[i].get_cnp()]=aux;
                                                                }

                                                            }



                                                        }

                                                        break;

                                                    }
                                                        else
                                                            contor2++;

                                                    }
                                                    break;
                                                }


                                        }
                                    case 3:
                                    {
                                            int contor = 0;
                                            for(auto itr=Lista_Locatii.begin(); itr!=Lista_Locatii.end(); itr++)
                                            {
                                                contor++;
                                                cout<<"\nLocatia "<<contor<<" :\n";
                                                cout<<*(*itr);
                                            }
                                            cout<<"\nAlegeti Locatie dupa indice: ";
                                            int indice;
                                            cin>>indice;
                                            if(indice<=0||indice>contor)
                                            {
                                                cout<<"Indice incorect";
                                                break;
                                            }
                                            else
                                            {
                                                int contor2=1;
                                                for(auto itr=Lista_Locatii.begin(); itr!=Lista_Locatii.end(); itr++)
                                                {
                                                    if(contor2==indice)
                                                    {
                                                        Locatie* aux;
                                                        aux = *itr;
                                                        int ok =0;
                                                        for(auto itr2=vector_ang.begin();itr2!=vector_ang.end();itr2++)
                                                        {
                                                            Locatie* aux2;
                                                            for(auto itr3:Map_ang_locatie)
                                                                if(!strcmp(itr3.first,(*itr2)->get_cnp()))
                                                                    aux2 = itr3.second;;
                                                            if(aux == aux2)
                                                                ok++;
                                                        }
                                                        int ok2=0;
                                                        while(ok2<ok)
                                                        {
                                                            for(auto itr2=vector_ang.begin();itr2!=vector_ang.end();itr2++)
                                                            {
                                                            Locatie* aux2;
                                                            int ok =0;
                                                            for(auto itr3:Map_ang_locatie)
                                                                if(!strcmp(itr3.first,(*itr2)->get_cnp()))
                                                                    aux2 = itr3.second;;
                                                            if(aux == aux2)
                                                            {
                                                                ok2++;
                                                                Angajat* aux3;
                                                                aux3 = *itr2;
                                                                Locatie* aux4;
                                                                for(auto itr3:Map_ang_locatie)
                                                                    if(!strcmp(itr3.first,aux3->get_cnp()))
                                                                        aux4 = itr3.second;
                                                                *aux4 = *aux4 - aux3->get_cnp();
                                                                if(aux3->get_functie()=="Manager")
                                                                    for(auto itr3=Lista_Locatii.begin(); itr3!=Lista_Locatii.end(); itr3++)
                                                                    {
                                                                        Locatie_Restaurant* aux5 = dynamic_cast<Locatie_Restaurant*> (*itr3);
                                                                        if(aux5 != NULL)
                                                                        {
                                                                            aux5->set_manager(NULL);
                                                                        }
                                                                    }

                                                                vector_ang.clear();
                                                                for(auto itr3=Lista_Locatii.begin(); itr3!=Lista_Locatii.end(); itr3++)
                                                                {

                                                                    Locatie_Livrari* aux5 = dynamic_cast<Locatie_Livrari*> (*itr3);
                                                                    if(aux5 != NULL)
                                                                    {

                                                                        int nr_ang = aux5->get_numar_angajati();
                                                                        for(i=0; i<nr_ang; i++)
                                                                        {
                                                                            vector_ang.push_back(&(aux5->get_angajati()[i]));
                                                                        }
                                                                    }



                                                                }
                                                                for(auto itr2=Lista_Locatii.begin(); itr2!=Lista_Locatii.end(); itr2++)
                                                                {

                                                                    Locatie_Restaurant* aux3 = dynamic_cast<Locatie_Restaurant*> (*itr2);
                                                                    if(aux3 != NULL)
                                                                    {

                                                                        int nr_ang = aux3->get_numar_angajati();
                                                                        for(i=0; i<nr_ang; i++)
                                                                        {
                                                                            vector_ang.push_back(&(aux3->get_angajati()[i]));
                                                                        }
                                                                        if(aux3->get_manager()!=NULL)
                                                                            vector_ang.push_back(&(*(aux3->get_manager())));
                                                                    }



                                                                }
                                                                Map_ang_locatie.clear();
                                                                for(auto itr2=Lista_Locatii.begin(); itr2!=Lista_Locatii.end(); itr2++)
                                                                {

                                                                    Locatie_Restaurant* aux3 = dynamic_cast<Locatie_Restaurant*> (*itr2);
                                                                    if(aux3 != NULL)
                                                                    {

                                                                        int nr_ang = aux3->get_numar_angajati();
                                                                        for(i=0; i<nr_ang; i++)
                                                                        {
                                                                            Map_ang_locatie[aux3->get_angajati()[i].get_cnp()]=aux3;
                                                                        }
                                                                        if(aux3->get_manager()!=NULL)
                                                                            Map_ang_locatie[aux3->get_manager()->get_cnp()]=aux3;
                                                                    }



                                                                }
                                                                for(auto itr2=Lista_Locatii.begin(); itr2!=Lista_Locatii.end(); itr2++)
                                                                {

                                                                    Locatie_Livrari* aux3 = dynamic_cast<Locatie_Livrari*> (*itr2);
                                                                    if(aux3 != NULL)
                                                                    {

                                                                        int nr_ang = aux3->get_numar_angajati();
                                                                        for(i=0; i<nr_ang; i++)
                                                                        {
                                                                            Map_ang_locatie[aux3->get_angajati()[i].get_cnp()]=aux3;
                                                                        }

                                                                    }



                                                                }
                                                                break;




                                                                }


                                                            }
                                                    }
                                                    for(auto itr6=Lista_Locatii.begin();itr6!=Lista_Locatii.end();itr6++)
                                                    {
                                                        if(aux == *itr6)
                                                        {
                                                            Lista_Locatii.erase(itr6);
                                                            break;
                                                        }
                                                    }
                                                    break;
                                                    }
                                                    else
                                                    {
                                                        contor2++;
                                                    }
                                                }
                                                break;
                                            }

                                    }
                                    case 4:
                                    {

                                            int contor = 0;
                                            cout<<"Toate Toppingurile";
                                            for(auto itr= vector_topping.begin();itr!=vector_topping.end();itr++)
                                            {
                                                contor++;
                                                cout<<"\nTopping "<<contor<<" :\n";
                                                cout<<*(*itr);
                                            }
                                            cout<<"\n\nAlegeti Toppingul dupa indice: ";
                                            int indice;
                                            cin>>indice;
                                            if(indice<=0||indice>contor)
                                            {
                                                cout<<"\nIndice Incorect";
                                                break;
                                            }
                                            else
                                            {
                                                int contor2= 1;
                                                for(auto itr= vector_topping.begin();itr!=vector_topping.end();itr++)
                                                {
                                                    if(contor2 == indice)
                                                    {
                                                        if(*itr!=NULL)
                                                            delete *itr;
                                                        vector_topping.erase(itr);
                                                        break;
                                                    }
                                                    else
                                                        contor2++;

                                                }
                                                break;
                                            }


                                    }
                                    case 5:
                                    {
                                        Pizza aux;
                                        cout<<"\nScrieti detaliile pentru noua pizza:\n";
                                        cout<<"Aici este o lista cu toate toppingurile disponibile:\n";
                                        for(auto itr=vector_topping.begin();itr!=vector_topping.end();itr++)
                                        {
                                            Topping* aux2;
                                            aux2 = *itr;
                                            cout<<"\n"<<aux2->get_nume_topping();

                                        }
                                        cout<<"\n";
                                        cin.get();
                                        cin>>aux;
                                        cin.get();
                                        Meniu_Pizza.insert(aux);
                                        break;
                                    }
                                    case 6:
                                    {
                                        Angajat* aux;
                                        aux = new Angajat();
                                        int contor=1;
                                        cout<<"\nLa ce locatie doriti sa adaugati angajatul?\n";
                                        for(auto itr=Lista_Locatii.begin();itr!=Lista_Locatii.end();itr++)
                                        {
                                            cout<<"\n\nLocatia "<<contor<<":\n";
                                            cout<<*(*itr);
                                            contor++;
                                        }
                                        cout<<"\nAlegeti locatia dupa indice: ";
                                        int indice;
                                        cin>>indice;
                                        if(indice<=0||indice>contor)
                                        {
                                            cout<<"\nindice gresit";
                                            break;
                                        }
                                        else
                                        {
                                            cout<<"\nScrieti informatiile despre angajat:\n";
                                            cin.get();
                                            cin>>*aux;

                                            int contor2=1;
                                            for(auto itr=Lista_Locatii.begin();itr!=Lista_Locatii.end();itr++)
                                            {
                                                if(indice==contor2)
                                                {
                                                    Locatie* aux2;
                                                    aux2 = *itr;
                                                    aux->set_locatie_la_care_lucreaza_id(aux2->get_id_locatie());
                                                    Map_ang_locatie[aux->get_cnp()] = aux2;
                                                    *aux2 = *aux2 + *aux;
                                                    break;

                                                }
                                                else
                                                {
                                                    contor2++;
                                                }
                                            }
                                            vector_ang.push_back(aux);

                                            break;
                                        }

                                    }
                                    case 7:
                                    {
                                        int k3 =1;
                                        while(k3 == 1)
                                        {
                                            cout<<"\nCe fel de Locatie doriti sa adugati?";
                                            cout<<"\n1 Locatie restauratn ";
                                            cout<<"\n2 Locatie livrari";
                                            cout<<"\n3 Inapoi\n";
                                            int comanda3;
                                            cin>>comanda3;
                                            switch(comanda3)
                                            {
                                            case 1:
                                                {
                                                    Locatie_Restaurant* aux;
                                                    aux = new Locatie_Restaurant();
                                                    cin.get();
                                                    cin>>*aux;
                                                    Lista_Locatii.push_back(aux);
                                                    int nr_ang_aux = aux->get_numar_angajati();
                                                    Angajat* aux2;
                                                    aux2 = new Angajat[nr_ang_aux];
                                                    aux2 = aux->get_angajati();
                                                    for(int i=0;i<nr_ang_aux;i++)
                                                    {
                                                        vector_ang.push_back(&aux2[i]);
                                                        Map_ang_locatie[aux2[i].get_cnp()] = aux;
                                                    }
                                                    vector_ang.push_back(aux->get_manager());
                                                    Map_ang_locatie[aux->get_manager()->get_cnp()] = aux;
                                                    break;

                                                }
                                            case 2:
                                                {
                                                        Locatie_Livrari* aux;
                                                        aux = new Locatie_Livrari();
                                                        cin.get();
                                                        cin>>*aux;
                                                        Lista_Locatii.push_back(aux);
                                                        int nr_ang_aux = aux->get_numar_angajati();
                                                        Angajat* aux2;
                                                        aux2 = new Angajat[nr_ang_aux];
                                                        aux2 = aux ->get_angajati();
                                                        for(int i=0; i<nr_ang_aux; i++)
                                                        {
                                                            vector_ang.push_back(&aux2[i]);
                                                            Map_ang_locatie[aux2[i].get_cnp()] = aux;
                                                        }
                                                        break;
                                                }
                                            case 3:
                                                {
                                                    k3 =0;
                                                    break;
                                                }

                                            }
                                        }
                                        break;
                                    }
                                    case 8:
                                    {
                                        int k3 =1;
                                        while(k3 == 1)
                                        {
                                            cout<<"\nCe fel de Topping doriti sa adugati?";
                                            cout<<"\n1 Topping comun ";
                                            cout<<"\n2 Topping Special ";
                                            cout<<"\n3 Inapoi\n";
                                            int comanda3;
                                            cin>>comanda3;
                                            switch(comanda3)
                                            {
                                            case 1:
                                                {
                                                    Topping_Comun* aux;
                                                    aux = new Topping_Comun();
                                                    cin.get();
                                                    cin>>*aux;
                                                    vector_topping.push_back(aux);
                                                    break;

                                                }
                                            case 2:
                                                {
                                                        Topping_Special* aux;
                                                        aux = new Topping_Special();
                                                        cin.get();
                                                        cin>>*aux;
                                                        vector_topping.push_back(aux);
                                                        break;
                                                }
                                            case 3:
                                                {
                                                    k3 =0;
                                                    break;
                                                }

                                            }
                                        }
                                        break;
                                    }
                                    case 9:
                                    {
                                            int contor = 0;
                                            cout<<"Meniu Pizza";
                                            for(auto itr= Meniu_Pizza.begin();itr!=Meniu_Pizza.end();itr++)
                                            {
                                                contor++;
                                                cout<<"\nPizza "<<contor<<" :\n";
                                                cout<<*itr;
                                            }
                                            cout<<"Alegeti Pizza dupa indice: ";
                                            int indice;
                                            cin>>indice;
                                            if(indice<=0||indice>contor)
                                            {
                                                cout<<"\nIndice Incorect";
                                                break;
                                            }
                                            else
                                            {
                                                int contor2= 1;
                                                for(auto itr= Meniu_Pizza.begin();itr!=Meniu_Pizza.end();itr++)
                                                {
                                                    if(contor2 == indice)
                                                    {
                                                        Pizza* aux;
                                                        aux = new Pizza();
                                                        *aux = *itr;
                                                        int k3 =1;
                                                        while(k3 == 1)
                                                        {
                                                            cout<<"\n\nCe doriti sa modificati?\n";
                                                            cout<<"\n1 Numele";
                                                            cout<<"\n2 Pretul si dimensiuniile";
                                                            cout<<"\n3 Reducerea";
                                                            cout<<"\n4 Toppinguri Folosite";
                                                            cout<<"\n5 Inapoi\n";
                                                            int comanda3;
                                                            cin>>comanda3;
                                                            switch(comanda3)
                                                            {
                                                            case 1:
                                                                {
                                                                    char aux2[100];
                                                                    cout<<"\nScrieti Noul nume: ";
                                                                    char* aux3;
                                                                    cin.get();
                                                                    cin.get(aux2,100);
                                                                    aux3 = new char[strlen(aux2)+1];
                                                                    strcpy(aux3,aux2);
                                                                    aux->set_nume_pizza(aux3);
                                                                    break;
                                                                }
                                                                case 2:
                                                                {
                                                                        int nr_dim;
                                                                        cout<<"\nCate dimensiuni sunt?\n";
                                                                        cin>>nr_dim;
                                                                        float* dim;
                                                                        dim = new float[nr_dim];
                                                                        float* pret_dim;
                                                                        pret_dim = new float[nr_dim];
                                                                        cout<<"\nScrieti Dimensiunea si pretul ei respectiv\n";
                                                                        for(int i=0;i<nr_dim;i++)
                                                                        {
                                                                            cout<<"\nDimensiune: ";
                                                                            cin>>dim[i];
                                                                            cout<<"\nPret: ";
                                                                            cin>>pret_dim[i];
                                                                        }
                                                                        aux->set_dimensiuni(nr_dim,dim);
                                                                        aux->set_pret_pizza_pe_dimensiune(nr_dim,pret_dim);
                                                                        aux->set_nr_dimensiuni(nr_dim);
                                                                        break;

                                                                }
                                                                case 3:
                                                                {
                                                                    cout<<"\nDoriti sa aiba reducere? [1/da] [0/nu]";
                                                                    bool red;
                                                                    cin>>red;
                                                                    if(red)
                                                                    {
                                                                        cout<<"\nCare este procentul de reducere?";
                                                                        float proc;
                                                                        cin>>proc;
                                                                        aux->set_procent_reducere(proc);
                                                                        aux->set_reducere(red);
                                                                    }
                                                                    else
                                                                    {
                                                                        aux->set_reducere(red);
                                                                        aux->set_procent_reducere(0);
                                                                    }
                                                                    break;
                                                                }
                                                                case 4:
                                                                {

                                                                    cout<<"\nCate Toppinguri sunt?";
                                                                    int nr_top;
                                                                    cin>>nr_top;
                                                                    string t[20];
                                                                    int* can_top;
                                                                    for(auto itr=vector_topping.begin(); itr!=vector_topping.end(); itr++)
                                                                    {
                                                                        Topping* aux2;
                                                                        aux2 = *itr;
                                                                        cout<<"\n"<<aux2->get_nume_topping();
                                                                    }

                                                                    can_top = new int[nr_top];
                                                                    for(int i=0;i<nr_top;i++)
                                                                    {
                                                                        cout<<"\nTopping: ";
                                                                        char aux[100];
                                                                        cin.get();
                                                                        cin.get(aux,100);
                                                                        cin.get();
                                                                        t[i] = aux;
                                                                        cout<<"\nCantitate: ";
                                                                        cin>>can_top[i];
                                                                    }
                                                                    aux->set_topinguri_folosite(nr_top,t);
                                                                    aux->set_cantitate_per_topping(nr_top,can_top);
                                                                    aux->set_nr_topping(nr_top);
                                                                    break;
                                                                }
                                                                case 5:
                                                                {
                                                                    Meniu_Pizza.insert(*aux);
                                                                    Meniu_Pizza.erase(itr);
                                                                    k3 = 0;
                                                                    break;
                                                                }
                                                            }
                                                        }
                                                    break;
                                                    }
                                                    else
                                                        contor2++;
                                                }
                                                break;
                                            }
                                    }
                                    case 10:
                                    {
                                         int contor = 0;
                                            for(auto itr=vector_ang.begin();itr!=vector_ang.end();itr++)
                                            {
                                                contor++;
                                                cout<<"\nAngajatul "<<contor<<" :\n";
                                                cout<<*(*itr);
                                            }
                                            cout<<"Alegeti angajat dupa indice: ";
                                            int indice;
                                            cin>>indice;
                                            if(indice<=0||indice>contor)
                                            {
                                                cout<<"Indice incorect";
                                                break;
                                            }
                                            else
                                            {
                                                int contor2 =1;
                                                for(auto itr=vector_ang.begin();itr!=vector_ang.end();itr++)
                                                {
                                                    if(contor2 == indice)
                                                    {
                                                        Angajat* aux;
                                                        aux = *itr;
                                                        int k3=1;
                                                        while(k3 == 1)
                                                        {
                                                            cout<<"\nCe doriti sa modificati?\n";
                                                            cout<<"\n1 Salariu";
                                                            cout<<"\n2 Functie";
                                                            cout<<"\n3 Inapoi";
                                                            int comanda3;
                                                            cin>>comanda3;
                                                            switch(comanda3)
                                                            {
                                                                case 1:
                                                                {
                                                                    cout<<"\nScrieti noul Salariu:";
                                                                    float sal;
                                                                    cin>>sal;
                                                                    aux->set_salariu(sal);
                                                                    break;
                                                                }
                                                                case 2:
                                                                {
                                                                    cout<<"\nScrieti noua functie pe care o va avea angajatul:";
                                                                    string aux2;
                                                                    char a[100];
                                                                    cin.get();
                                                                    cin.get(a,100);
                                                                    cin.get();
                                                                    aux2 = a;
                                                                    aux->set_functie(aux2);
                                                                    break;
                                                                }
                                                                case 3:
                                                                {
                                                                    k3=0;
                                                                    break;
                                                                }
                                                            }

                                                        }
                                                    }
                                                    else
                                                        contor2++;
                                                }
                                                break;
                                            }
                                    }
                                    case 11:
                                    {
                                        int contor = 0;
                                            for(auto itr=Lista_Locatii.begin(); itr!=Lista_Locatii.end(); itr++)
                                            {
                                                contor++;
                                                cout<<"\nLocatia "<<contor<<" :\n";
                                                cout<<*(*itr);
                                            }
                                            cout<<"Alegeti Locatie dupa indice: ";
                                            int indice;
                                            cin>>indice;
                                            if(indice<=0||indice>contor)
                                            {
                                                cout<<"Indice incorect";
                                                break;
                                            }
                                            else
                                            {
                                                int contor2=1;
                                                for(auto itr=Lista_Locatii.begin(); itr!=Lista_Locatii.end(); itr++)
                                                {
                                                    if(contor2==indice)
                                                    {
                                                        Locatie_Livrari* aux = dynamic_cast<Locatie_Livrari*> (*itr);
                                                        if(aux!=NULL)
                                                        {
                                                            int k3 =1;
                                                            while(k3 ==1)
                                                            {
                                                                cout<<"\n\n1 Modifica Pretul intretinerii pe luna:";
                                                                cout<<"\n2 Modifica Numarul de telefon";
                                                                cout<<"\n3 Modifica numarul de curieri";
                                                                cout<<"\n4 Inapoi";
                                                                int comanda3;
                                                                cin>>comanda3;
                                                                switch(comanda3)
                                                                {
                                                                case 1:
                                                                    {
                                                                        cout<<"\nNoul pret de intretinere pe luna: ";
                                                                        double pret;
                                                                        cin>>pret;
                                                                        aux->set_pret_intretinere_pe_luna(pret);
                                                                        break;
                                                                    }
                                                                case 2:
                                                                    {
                                                                        cout<<"\nNoul numar de telefon: ";
                                                                        char aux2[100];
                                                                        cin>>aux2;
                                                                        char* a;
                                                                        a = new char[strlen(aux2)+1];
                                                                        strcpy(a,aux2);
                                                                        aux->set_numar_telefon(a);
                                                                        break;
                                                                    }
                                                                case 3:
                                                                    {
                                                                        cout<<"\nNoul numar de curieri: ";
                                                                        int nr_curieri;
                                                                        cin>>nr_curieri;
                                                                        aux->set_numar_curieri(nr_curieri);
                                                                        break;
                                                                    }
                                                                case 4:
                                                                    {
                                                                        k3 = 0;
                                                                        break;
                                                                    }
                                                                }

                                                            }

                                                        break;
                                                        }
                                                        else
                                                        {
                                                            Locatie_Restaurant* aux2 = dynamic_cast<Locatie_Restaurant*> (*itr);
                                                            if(aux2!=NULL)
                                                            {
                                                                int k3 =1;
                                                                while(k3 ==1)
                                                                {
                                                                    cout<<"\n\n1 Modifica Pretul intretinerii pe luna:";
                                                                    cout<<"\n2 Modifica Numarul de locuri";
                                                                    cout<<"\n3 Inapoi";
                                                                    int comanda3;
                                                                    cin>>comanda3;
                                                                    switch(comanda3)
                                                                    {
                                                                    case 1:
                                                                        {
                                                                            cout<<"\nNoul pret de intretinere pe luna: ";
                                                                            double pret;
                                                                            cin>>pret;
                                                                            aux2->set_pret_intretinere_pe_luna(pret);
                                                                            break;
                                                                        }
                                                                    case 2:
                                                                        {
                                                                            cout<<"\nNoul numar de locuri: ";
                                                                            int aux3;
                                                                            cin>>aux3;
                                                                            aux2->set_nr_locuri(aux3);
                                                                            break;
                                                                        }
                                                                    case 3:
                                                                        {
                                                                            k3 = 0;
                                                                            break;
                                                                        }
                                                                    }

                                                                }
                                                                break;
                                                            }


                                                    }

                                                }
                                                else
                                                    contor2++;
                                            }


                                                break;
                                            }
                                    }
                                    case 12:
                                    {
                                             int contor = 0;
                                            cout<<"Toate Toppingurile";
                                            for(auto itr= vector_topping.begin();itr!=vector_topping.end();itr++)
                                            {
                                                contor++;
                                                cout<<"\nTopping "<<contor<<" :\n";
                                                cout<<*(*itr);
                                            }
                                            cout<<"\n\nAlegeti Toppingul dupa indice: ";
                                            int indice;
                                            cin>>indice;
                                            if(indice<=0||indice>contor)
                                            {
                                                cout<<"\nIndice Incorect";
                                                break;
                                            }
                                            else
                                            {
                                                int contor2= 1;
                                                for(auto itr= vector_topping.begin();itr!=vector_topping.end();itr++)
                                                {
                                                    if(contor2 == indice)
                                                    {
                                                        Topping_Comun* aux = dynamic_cast<Topping_Comun*> (*itr);
                                                        if(aux!=NULL)
                                                        {
                                                            int k3 = 1;
                                                            while(k3 == 1)
                                                            {
                                                                cout<<"\n1 Modifica pretul toppingului";
                                                                cout<<"\n2 Modifica cantitatea totala de topping";
                                                                cout<<"\n3 Modifica cantitatea per portie de topping";
                                                                cout<<"\n4 Modifica ziua de aprovizionare";
                                                                cout<<"\n5 Inapoi\n";
                                                                int comanda3;
                                                                cin>>comanda3;
                                                                switch(comanda3)
                                                                {
                                                                    case 1:
                                                                    {
                                                                        cout<<"\nNoul Pret al toppingului: ";
                                                                        float aux2;
                                                                        cin>>aux2;
                                                                        aux->set_pret_topping(aux2);
                                                                        break;
                                                                    }
                                                                    case 2:
                                                                    {
                                                                        cout<<"\nNoua cantitate totala de topping: ";
                                                                        double aux2;
                                                                        cin>>aux2;
                                                                        aux->set_cantitate_totala_topping(aux2);
                                                                        break;
                                                                    }
                                                                    case 3:
                                                                    {
                                                                        cout<<"\nNoua cantitate per portie de topping: ";
                                                                        float aux2;
                                                                        cin>>aux2;
                                                                        aux->set_cantitate_per_portie(aux2);
                                                                        break;
                                                                    }
                                                                    case 4:
                                                                    {
                                                                        cout<<"\nNoua zi de aprovizionare: ";
                                                                        string aux2;
                                                                        cin>>aux2;
                                                                        aux->set_zi_aprovizionare(aux2);
                                                                        break;
                                                                    }
                                                                    case 5:
                                                                    {
                                                                        k3 = 0;
                                                                        break;
                                                                    }

                                                                }
                                                            }
                                                        }
                                                        else
                                                        {
                                                            Topping_Special* aux3 = dynamic_cast<Topping_Special*> (*itr);
                                                            int k3 = 1;
                                                            while(k3 == 1)
                                                            {
                                                                cout<<"\n1 Modifica pretul toppingului";
                                                                cout<<"\n2 Modifica cantitatea totala de topping";
                                                                cout<<"\n3 Modifica cantitatea per portie de topping";
                                                                cout<<"\n4 Modifica lista de alergeni";
                                                                cout<<"\n5 Modifica numarul de zile de valabilitate";
                                                                cout<<"\n6 Inapoi\n";
                                                                int comanda3;
                                                                cin>>comanda3;
                                                                switch(comanda3)
                                                                {
                                                                    case 1:
                                                                    {
                                                                        cout<<"\nNoul Pret al toppingului: ";
                                                                        float aux2;
                                                                        cin>>aux2;
                                                                        aux3->set_pret_topping(aux2);
                                                                        break;
                                                                    }
                                                                    case 2:
                                                                    {
                                                                        cout<<"\nNoua cantitate totala de topping: ";
                                                                        double aux2;
                                                                        cin>>aux2;
                                                                        aux3->set_cantitate_totala_topping(aux2);
                                                                        break;
                                                                    }
                                                                    case 3:
                                                                    {
                                                                        cout<<"\nNoua cantitate per portie de topping: ";
                                                                        float aux2;
                                                                        cin>>aux2;
                                                                        aux3->set_cantitate_per_portie(aux2);
                                                                        break;
                                                                    }
                                                                    case 4:
                                                                    {
                                                                        cout<<"\nNoul numar de alergeni: ";
                                                                        int aux2;
                                                                        cin>>aux2;
                                                                        aux3->set_numar_alergeni(aux2);
                                                                        string* aux4;
                                                                        aux4 = new string[aux2];
                                                                        cin.get();
                                                                        for(int i =0;i<aux2;i++)
                                                                        {
                                                                            cout<<"\nAlergen: ";
                                                                            cin>>aux4[i];
                                                                        }
                                                                        aux3->set_lista_alergeni(aux4,aux2);
                                                                        break;
                                                                    }
                                                                    case 5:
                                                                    {
                                                                        cout<<"\nNoul numar de zile: ";
                                                                        int nr;
                                                                        cin>>nr;
                                                                        aux3->set_durata_valabil_zile(nr);
                                                                        break;
                                                                    }
                                                                    case 6:
                                                                    {
                                                                        k3 = 0;
                                                                        break;
                                                                    }
                                                                }
                                                        }

                                                    }
                                                    break;

                                                    }
                                                    else
                                                        contor2++;

                                                }
                                                break;
                                            }
                                    }
                                    case 13:
                                    {
                                        cout<<"\nMeniu Pizza:\n";
                                        for(auto itr=Meniu_Pizza.begin();itr!=Meniu_Pizza.end();itr++)
                                            cout<<*itr;
                                        break;
                                    }
                                    case 14:
                                    {
                                        cout<<"\nToti Angajatii:\n";
                                        for(auto itr=vector_ang.begin();itr!=vector_ang.end();itr++)
                                            cout<<*(*itr);
                                        break;
                                    }
                                    case 15:
                                    {
                                        cout<<"\nToate Toppingurile:\n";
                                        for(auto itr=vector_topping.begin();itr!=vector_topping.end();itr++)
                                            cout<<*(*itr);
                                        break;
                                    }
                                    case 16:
                                    {
                                        cout<<"\nToate Locatiile:\n";
                                        for(auto itr=Lista_Locatii.begin();itr!=Lista_Locatii.end();itr++)
                                        {
                                            cout<<*(*itr);
                                        }
                                        break;
                                    }
                                    case 17:
                                    {
                                        k2 =0;
                                        break;
                                    }


                                    }


                                }
                                break;
                            }
                            else
                            {
                                cout<<"Parola incorecta";
                                break;
                            }

                        }
                    case 2:
                        {
                            k1= 0;
                            break;
                        }
                    }
                }
                break;

            }
            case 3:
                {
                    k = 0;
                    break;
                }




        }


    }



    //Aici este o alta exemplificare a virtualizarii
    /*string* tipuri;
    tipuri = new string[3];
    tipuri[0] = "penne";
    tipuri[1] = "spaghete";
    tipuri[2] = "fusili";
    Paste_Bolognese pas1(3,tipuri,30,30);
    Paste_Carbonara pas2(3,tipuri,30,30);
    Paste* Test_Virtualizare[2];
    Test_Virtualizare[0] = new Paste_Bolognese();
    static_cast<Paste_Bolognese&>(*Test_Virtualizare[0]) = pas1;
    Test_Virtualizare[1] = new Paste_Carbonara();
    static_cast<Paste_Carbonara&>(*Test_Virtualizare[1]) = pas2;
    //desi ambele obiecte au exact aceleasi date introduse, se observa faptul ca metoda virtuala calculeaza_pret() este diferita pentru fiecare in parte
    cout<<"\nPretul pentru paste Bolognese: "<<Test_Virtualizare[0] -> calculeaza_pret();
    cout<<"\nPretul pentru paste Carbonara: "<<Test_Virtualizare[1] -> calculeaza_pret();
    */
    return 0;
}



