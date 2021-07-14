#ifndef LARAICE_H
#define LARAICE_H


class LaraIce
{
        private:
            bool encendida;
            int hieloChico,HieloGrande;
            int deposito;
       public:
            LaraIce(bool);
            void llenar(int);
            int getHielo(int);
            void vaciar();
            void encender();
            void apagar();

};

#endif // LARAICE_H
