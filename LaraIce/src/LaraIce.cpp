#include "LaraIce.h"
#include <iostream>

using namespace std;



            void LaraIce::llenar(int cc){

                if(encendida==true){
                 if(deposito==2000){cout<<"El deposito esta lleno;"<<endl;}
                 if(deposito<2000){
                        if(deposito+cc<=2000){
                                deposito+=cc;
                  }else{ cout<<"El deposito excede su capacidad, ingrese menos agua;"<<endl;}

                  }
                }else{cout<<"Antes debe encender la maquina"<<endl;}
                  }

            int LaraIce::getHielo(int tam){

            if(encendida==true){

                switch(tam){
                    case 1:
                        if(deposito>=15){

                          hieloChico++;
                          deposito-=15;
                            return 1;

                        }else return 0;
                        break;
                    case 2:
                         if(deposito>=25){

                          HieloGrande++;
                          deposito-=25;
                            return 2;
                            }else return 0;

                        break;
                    default:
                        cout<<"Opcion Incorrecta"<<endl;
                        break;
                }


            }

            }
            void LaraIce::vaciar(){ deposito=0; }

            LaraIce::LaraIce(bool b){encendida = b;}

            void LaraIce::encender(){
            encendida=true;
            hieloChico=HieloGrande=0;
            }


            void LaraIce::apagar(){

            cout<<"Hielos chicos: "<<hieloChico<<endl;
            cout<<"Hielos grandes: "<<HieloGrande<<endl;

            }
