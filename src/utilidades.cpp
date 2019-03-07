//
// Created by mgomez on 16/02/17.
// editado by acid on 27/02/19
//hi?

#include "utilidades.h"
using namespace std;

void leerContenido(Valor coleccion[], int & util){
    int fila,columna;
    double valor;
    cout << "Nuevo vector" << endl;
    do{
      cout << "Introduce cuantos: ";
      cin >> util;
    }while (util > CAPACIDAD/2);

    for(int i = 0; i < util; i++){
        cin >> fila;
        cin >> columna;
        cin >> valor;
        coleccion[i]= Valor(fila, columna, valor);
    }

}

void mostrarContenido(Valor const coleccion[], int util){
    cout << util << " ";
    for(int i=0; i < util; i++) {
        coleccion[i].mostrar();
        if(i < (util-1)){
            cout << " -- ";
        }
    }
    cout << endl;
}

int combinarSuma(Valor vec1[], int util1, Valor vec2[], int util2, Valor result[]){
    int util_result=0;
    bool find=false;
    //si los 2 vectores no estan vacios entran
    if(util1>0 && util2>0){
        //recorro cada componente del vector1 y comparo
        for(int i=0;i<util1;i++){
            find=false;
            //recorre el segundo vector hasta que supere el tamaño o haya encontrado una coincidencia
            for(int e=0;e<util2 && !find;e++){
                //si las filas y columnas de los 2 vectores coinciden
                if(vec1[i].fila==vec2[e].fila && vec1[i].columna==vec2[e].columna){
                    //guardo la fila, la columna en resultado y sumo los 2 valores de los 2 vectores
                    result[i].fila=vec1[i].fila;
                    result[i].columna=vec1[i].columna;
                    result[i].valor=vec1[i].valor + vec2[e].valor;

                    find=true;
                    util_result++;
                }
                //cout << vec1[i].fila << " -- " << vec2[e].fila << endl;
            }
            // si no ha encontrado ninguna coincidencia guarda por defecto el del primer vector
            if(!find){
                //guardo la fila, la columna y el valor en result del primer vector
                result[i].fila=vec1[i].fila;
                result[i].columna=vec1[i].columna;
                result[i].valor=vec1[i].valor;

                util_result++;
            }
        }
        //recorro cada componente del vector2 y comparo
        for(int i=0;i<util2;i++){
            find=false;
            //recorre el segundo vector hasta que supere el tamaño o haya encontrado una coincidencia
            for(int e=0;e<util1 && !find;e++){
                //si las filas y columnas de los 2 vectores coinciden cambia a true
                if(vec2[i].fila==vec1[e].fila && vec2[i].columna==vec1[e].columna) find=true;
            }
            // si no ha encontrado ninguna coincidencia guarda por defecto el del segundo vector
            if(!find){
                //guardo la fila, la columna y el valor en result del primer vector
                result[util_result].fila=vec2[i].fila;
                result[util_result].columna=vec2[i].columna;
                result[util_result].valor=vec2[i].valor;

                util_result++;
            }
        }

    //en caso contrario compruebo si el vector 1 o 2 no esta vacio y guardo el vector 1 o 2 en el vector result
    }else if(util1>0){
        util_result=util1;
        for(int i=0;i<util_result;i++){
            result[i]=vec1[i];
        }
    }else if(util2>0){
        util_result=util2;
        for(int i=0;i<util_result;i++){
            result[i]=vec2[i];
        }
    }
    return util_result;
}
