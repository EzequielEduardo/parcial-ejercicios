#include <iostream>
using namespace std;
#include <cstring>
#include "Video.h"

Video::Video()
{
    //ctor
}

int Video::getID() { return _id; }
void Video::setID(int val) { _id = val; }
char* Video::getTitulo() { return _titulo; }
void Video::setTitulo(const char *val) { strcpy(_titulo, val); }
bool Video::getContenidoNinios() { return _ninios; }
void Video::setContenidoNinios(bool val) { _ninios = val; }
Fecha Video::getFecha() { return _fecha; }
void Video::setFecha(Fecha val) { _fecha = val; }
int Video::getDuracion() { return _duracion; }
void Video::setDuracion(int val) { _duracion = val; }
int Video::getVisualizaciones() { return _visualizaciones; }
void Video::setVisualizaciones(int val) { _visualizaciones = val; }

void Video::mostrar(){
    cout << _id << "," << _titulo << "," << _ninios << "," << _fecha.getDia();
    cout << "/" << _fecha.getMes() << "/" << _fecha.getAnio() << ",";
    cout << _duracion << "," << _visualizaciones << endl;
}

bool Video::leerDeDisco(int pos){
    FILE *p;
    p = fopen("videos.dat", "rb");
    if (p == NULL){
        return false;
    }
    bool ok;
    fseek(p, sizeof(Video) * pos , 0);
    ok = fread(this, sizeof(Video), 1, p);
    fclose(p);
    return ok;
}
/*
void Video::leerDeDisco(int* vid,int*vmax){
    FILE *p;
    int pos=0;
    p = fopen("videos.dat", "rb");
    if (p == NULL){
        return false;
    }
    bool ok;

    fseek(p, sizeof(Video) * pos , 0);
    ok = fread(this, sizeof(Video), 1, p);
    fclose(p);
    return ok;
}
*/
bool Video::grabarEnDisco(){
    FILE *p;
    p = fopen("videos.dat", "ab");
    if (p == NULL){
        return false;
    }
    bool ok;
    ok = fwrite(this, sizeof(Video), 1, p);
    fclose(p);
    return ok;
}

int cantidadRegistros(){

int cont=0;


}

bool Video::vizualizarVideo(int id){
    FILE *p;
     bool ok;
     Video reg;
    p = fopen("videos.dat", "rb+");
    if (p == NULL){
        return false;
    }
    while(fread(&reg, sizeof(Video), 1, p)==1){

        if(getID()==reg.getID()){

                reg.mostrar();

                int a=reg.getVisualizaciones()+1;
            reg.setVisualizaciones(a);
            fseek(p, ftell(p)-sizeof reg , 0);
            ok = fwrite(&reg, sizeof(Video), 1, p);

        }
    }

    fclose(p);
    return ok;
}



 void Video::ranking(){
    int cantidad=cantidadRegistros();
    int  *vid;
    int *vmax;



 }


 }
