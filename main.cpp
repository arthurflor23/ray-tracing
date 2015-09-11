/* 
 * File:   main.cpp
 * Author: arthur
 * 
 * g++ -Wall -fopenmp main.cpp raytracing/RayTracing.cpp raytracing/Ambient.cpp raytracing/Read.cpp -O3 -o example -llapack -larmadillo && time ./example
 * 
 * Created on 9 de Junho de 2015, 21:35
 */

#include <cstdlib>
#include "raytracing/headers/RayTracing.hpp"
#include <iostream>
#include <string>

using namespace std;

int main(int argc, char *argv[]) { 
        
    RayTracing::inicio("config.txt", "saida.ppm");
    
    return 0;
}

