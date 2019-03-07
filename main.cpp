/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: ruben
 *
 * Created on 7 de marzo de 2019, 20:34
 */

#include <cstdlib>
#include <iostream>
#include "utilidades.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    
    const int CAPACIDAD = 20;
    Valor array1[CAPACIDAD/2];
    Valor array2[CAPACIDAD/2]; // ={Valor(0, 0, 10), Valor(1, 1, 0.3), Valor(1, 2, 4.3), Valor(2, 2, 1.5), Valor(3, 2, 0.25)};
    Valor resultado1[CAPACIDAD];
    int util1=0, util2=0;

    leerContenido(array1, util1);
    mostrarContenido(array1, util1);
    leerContenido(array2, util2);
    mostrarContenido(array2, util2);
    int utilR = combinarSuma(array1, util1, array2, util2, resultado1);
    cout << " -------------------------------- " << endl;
    mostrarContenido(resultado1, utilR);
    return 0;
}

