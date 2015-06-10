/* 
 * File:   main.cpp
 * Author: arthur
 * 
 * g++ -Wall -fopenmp final.cpp -O3 -o example -llapack -larmadillo && time ./example config.txt teste.ppm
 * 
 * Created on 9 de Junho de 2015, 21:35
 */

#define ARMA_USE_LAPACK
#include <cstdlib>
#include <armadillo>

using namespace arma;
using namespace std;

int main(int argc, char** argv) {

    if (argc != 3){
        
      cout << "Argumentos inválidos" << endl;
      return 1;
    }
    
    NoArvore * No = NULL;  
    vector<Object *> objetos = NULL;
    vector<Light> luz;
    NVertex normal_boladona;
    Ambient ambiente;
    mat keye;
    int cont_tri=0;
    unsigned int porc;
    
    Read(argv[1], objetos, luz, ambiente, keye, cont_tri);

    if (objetos.size() == 0){
        cout << "Nenhum objeto encontrado" << endl; 
        return 1; 
    }

    else{
        if (objetos.size() >= 100) porc=objetos.size() * 0.003;
        else porc=5;

        normal_boladona.N(objetos, cont_tri);
        No = NoArvore::construirArvore(objetos, porc);
        Write(argv[2], luz, keye, ambiente, No); 
      }

    cout << "Triângulo: " << cont_tri << endl;
    cout << "Esfera: " << objetos.size()-cont_tri << endl;
    
    return 0;
}

