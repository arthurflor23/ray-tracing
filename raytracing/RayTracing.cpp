
#include "headers/RayTracing.hpp"
#include "headers/Object.hpp"
#include "headers/Ambient.hpp"
#include "headers/Light.hpp"
#include <vector>
#include <cstdlib>
#include <armadillo>
#include <string>
#include <iostream>

using namespace arma;
using namespace std;

void RayTracing::inicio(string config, string saida) {
    
    cout << config << endl << saida << endl;

//    NoArvore * No = NULL;  
    vector<Object *> objetos;
    vector<Light> luz;
//    NVertex normal_boladona;
    Ambient ambiente;
    mat keye;
//    int cont_tri=0;
//    unsigned int porc;
//    
//    Read(config, objetos, luz, ambiente, keye, cont_tri);
//
//    if (objetos.size() == 0){
//        cout << "Nenhum objeto encontrado" << endl; 
//        return 1; 
//    }
//
//    else{
//        if (objetos.size() >= 100) porc=objetos.size() * 0.003;
//        else porc=5;
//
//        normal_boladona.N(objetos, cont_tri);
//        No = NoArvore::construirArvore(objetos, porc);
//        Write(saida, luz, keye, ambiente, No); 
//    }
//
//    cout << "Triângulo: " << cont_tri << endl;
//    cout << "Esfera: " << objetos.size()-cont_tri << endl;
    
    
}



