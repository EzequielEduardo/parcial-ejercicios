#ifndef VIDEO_H
#define VIDEO_H
#include "Fecha.h"

class Video
{
    public:
        Video();
        int getID();
        void setID(int);
        char* getTitulo();
        void setTitulo(const char *);
        bool getContenidoNinios();
        void setContenidoNinios(bool);
        Fecha getFecha();
        void setFecha(Fecha);
        int getDuracion();
        void setDuracion(int);
        int getVisualizaciones();
        void setVisualizaciones(int);
        void mostrar();
		void mostrar2();
        bool leerDeDisco(int);
        bool grabarEnDisco();

    private:
        int _id;
        char _titulo[100];
        bool _ninios;
        Fecha _fecha;
        int _duracion;
        int _visualizaciones;
};

#endif // VIDEO_H
