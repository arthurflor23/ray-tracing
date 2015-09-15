
#include "headers/RayTracing.hpp"
#include "headers/Object.hpp"
#include "headers/Ambient.hpp"
#include "headers/Light.hpp"
#include "headers/Reader.hpp"
#include "headers/NoArvore.hpp"
#include "headers/NVertex.hpp"
#include "headers/Writer.hpp"
#include <vector>
#include <cstdlib>
#include <armadillo>
#include <iostream>

using namespace arma;
using namespace std;

int RayTracing::inicio(const char *config, const char *saida) {
    
    NoArvore * No = NULL;  
    vector<Object *> objetos;
    vector<Light> luz;
    NVertex normal_boladona;
    Ambient ambiente;
    mat keye;
    int cont_tri=0;
    unsigned int porc;
   
    Reader(config, objetos, luz, ambiente, keye, cont_tri);

    if (objetos.size() == 0){
        cout << "Nenhum objeto encontrado" << endl; 
        return 1; 
    }

    else{
        if (objetos.size() >= 100) porc=objetos.size() * 0.003;
        else porc=5;

        normal_boladona.N(objetos, cont_tri);
        No = NoArvore::construirArvore(objetos, porc);
        Writer(saida, luz, keye, ambiente, No); 
    }

    cout << "Triângulo: " << cont_tri << endl;
    cout << "Esfera: " << objetos.size()-cont_tri << endl;
    
  return 0; 
}



