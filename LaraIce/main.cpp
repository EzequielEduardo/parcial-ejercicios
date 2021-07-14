#include <iostream>
#include "LaraIce.h"
using namespace std;


void opciones(){

    cout << "LARAHICE" << endl;
    cout<<endl;
    cout<<"1-Llenar"<<endl;
    cout<<"2-getHielo"<<endl;
    cout<<"3-vaciar"<<endl;
    cout<<"4-encender"<<endl;
    cout<<"5-apagar"<<endl<<endl;
    cout<<"0-salir del programa"<<endl;
    cout<<"opcion: ";

}


int main()
{
    LaraIce obj(false);
    int opc,tam;

    opciones();
    cin>>opc;
    cout<<endl;

    while(opc!=0){

          switch(opc){
          case 1:
                cout<<"Indique cantidad de Centimetros Cubicos a llenar: ";
                cin>>tam;
                obj.llenar(tam);
                system("pause");
                system("cls");
            break;
            case 2:
                int valor;
                cout<<"Indique el Tamaño: "<<endl;
                cout<<"1-chico."<<endl;
                cout<<"2-Grande."<<endl;
                cin>>tam;
                valor=obj.getHielo(tam);
               if( valor==1) cout<<"preparando hielo chico "<<endl;
               if( valor==2) cout<<"preparando hielo grande "<<endl;
               if( valor==0) cout<<"No se pudo preparar el hielo"<<endl;
                system("pause");
                system("cls");
            break;
            case 3:
                obj.vaciar();
                system("pause");
                system("cls");
            break;
            case 4:
                obj.encender();
                system("pause");
                system("cls");
            break;
            case 5:
                obj.apagar();
                system("pause");
                system("cls");
            break;
            case 0:
                cout<<"Fin del programa"<<endl;
                return 0;
            break;
            default:
            break;


          }



         opciones();
        cin>>opc;
        cout<<endl;
    }

    cout<<"Fin del programa"<<endl;
    return 0;
}
