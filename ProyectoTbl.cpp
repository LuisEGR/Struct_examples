#include <stdio.h>
#include <conio.h>
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
char op;
struct ListaAlumnos{
	int nlista;
	string nombre;
	int cal;
	int prom;
	ListaAlumnos* sig;
	ListaAlumnos* ant;
};
ListaAlumnos L,*p,*m,*prin,*fin;
/****************************************/
void crear(ListaAlumnos *registro,ListaAlumnos *fin,ListaAlumnos *anterior)
{
      cout<<"Inserte los datos...";
      cout<<"\nNo. de Lista:";cin>>registro->nlista;
      cout<<"Nombre:";cin>>registro->nombre;
      cout<<"Calificacion:";cin>>registro->cal;
      cout<<"Promedio:";cin>>registro->prom;
      cout<<"Desea agregar otro? s/n: ";cin>>op;
      if(op == 'n' || op == 'N')
      {
            registro->sig=NULL;
            registro->ant=anterior;
            fin=registro;
      }
      else
      {
            registro->sig= new ListaAlumnos;
            registro->ant=anterior;
            crear(registro->sig,fin,registro);
      }
}
void mostrar(ListaAlumnos *pt)
{
      if (pt != NULL)
      {
          cout<<pt->nlista<<"\t"<<pt->nombre<<"\t"<<pt->cal<<"\t\t"<<pt->prom<<endl;
          mostrar(pt->sig);
       }
}
/*****************************************/
int main(){
	prin = new ListaAlumnos;
	fin = new ListaAlumnos;
	crear(prin,fin,NULL);
	cout<<"\nNo.\tNombre\tCalificacion\tPromedio"<<endl;
	mostrar(prin);
  getch();
  return 0;

}
