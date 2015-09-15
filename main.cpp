/* 
 * File:   main.cpp
 * Author: arthur
 * 
 * g++ -fopenmp main.cpp raytracing/*.cpp -O3 -o example -llapack -larmadillo && time ./example
 * 
 * Created on 9 de Junho de 2015, 21:35
 */

#include <cstdlib>
#include "raytracing/headers/RayTracing.hpp"
#include <iostream>
#include <string>

using namespace std;

int main(int argc, char *argv[]) { 
    
//    if (argc != 3){
//      cout << "Argumentos inválidos" << endl;
//      return 1;
//    }
//    
//    RayTracing::inicio(argv[1], argv[2]);
    
    RayTracing::inicio("config.txt", "saida.ppm");
    
    return 0;
}

