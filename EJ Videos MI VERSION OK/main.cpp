#include <iostream>
using namespace std;
#include "Video.h"

//-------------------------------------------------------------------------------------------
//prototypes
void Punto1();
void ordenarClase(Video *vec, int tam);
int contarRegVideos();
void leeryllenarVectordeObjetos(Video *vec, int tam);
void Ranking();
void MostrarPorcentaje();

//-------------------------------------------------------------------------------------------

int calculaPorcentajeVideosdeAdulto(int anio){
Video obj;
int pos=0, cont=0;
while(obj.leerDeDisco(pos++)){
	if(obj.getFecha().getAnio()==anio && obj.getContenidoNinios()==false){
	cont++;
	}
}
return cont;
//return (cont/contarRegVideos())*100;
}


int calculaPorcentajeVideosdeNinio(int anio){
Video obj;
int pos=0, cont=0;
while(obj.leerDeDisco(pos++)){
	if(obj.getFecha().getAnio()==anio && obj.getContenidoNinios()==true){
	cont++;
	}
}
cout<<"cant de vides de ninio: "<<cont;
return cont;
//return (cont/contarRegVideos())*100;
}

void MostrarPorcentaje(){
int anioIni, anioFin;
Video obj;
cout<<"Ingrese año de inicio: "<<endl;
cin>>anioIni;
cout<<"ingrese año de fin: "<<endl;
cin>>anioFin;


for(int i=0;i<((anioFin-anioIni))+1;i++)
{
	cout<<"año: "<<anioIni+i<<"\t";
	cout<<"% VideodeNinios: "<<calculaPorcentajeVideosdeNinio(anioIni+i)<<"\t";
	cout<<"% Video para adultos: "<<calculaPorcentajeVideosdeAdulto(anioIni+i)<<endl;
}




}

int main()
{
   // Punto1();
  // Ranking();

  MostrarPorcentaje();



  //  reg.leerDeDisco(0);
    //reg.mostrar();




    return 0;
}


//-------------------------------------------------------------------------------------------
//funciones globales
void Punto1(){
Video obj;
int ID;
cout<<"ingrese el Id: "<<endl;
cin>>ID;

int pos=0;

while(obj.leerDeDisco(pos++)){
	if(ID==obj.getID())	{
		//cout<<"id: "<<obj.getID();
		cout<<"TITULO: "<<obj.getTitulo()<<endl;
		cout<<"DURACION: "<<obj.getDuracion()<<endl;
		cout<<"VISUALIZACIONES: "<<obj.getVisualizaciones()<<endl;
		cout<<"FECHA DE CREACION: ";obj.getFecha().mostrar();

		obj.setVisualizaciones(obj.getVisualizaciones());
		}
	}
}

//-------------------------------------------------------------------------------------------

void ordenarClase(Video *vec, int tam){
    int i, j, posMax;
    for(i=0; i<tam-1; i++){
        posMax = i;
        for(j=i+1; j<tam; j++){
            if (vec[j].getVisualizaciones() > vec[posMax].getVisualizaciones()){
                posMax = j;
            }
        }
        Video aux = vec[i];
        vec[i] = vec[posMax];
        vec[posMax] = aux;
    }
}

int contarRegVideos(){
    int bytes, cr;
    FILE *p;
    p = fopen("videos.dat", "rb");
    if (p == NULL){ return 0; }
    fseek(p, 0, SEEK_END);
    bytes = ftell(p);
    cr = bytes / sizeof(Video);
    fclose(p);
    return cr;
}

void leeryllenarVectordeObjetos(Video *vec, int tam){
    for(int i=0; i<tam; i++){
        vec[i].leerDeDisco(i);
    }
}

void Ranking(){
int cant= contarRegVideos();
Video *vec;
if(cant ==0) return;
vec=new Video[cant];
leeryllenarVectordeObjetos(vec,cant);

ordenarClase(vec,cant);

for(int i=0;i<10;i++)
{
	vec[i].mostrar2();


}


delete vec;
}

