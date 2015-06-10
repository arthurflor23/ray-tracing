/* 
 * File:   main.cpp
 * Author: arthur
 * 
 * g++ -Wall -fopenmp final.cpp -O3 -o example -llapack -larmadillo && time ./example config.txt teste.ppm
 * 
 * Created on 9 de Junho de 2015, 21:35
 */

#include <cstdlib>
#include "raytracing/headers/RayTracing.hpp"

int main() { 
    
    
    RayTracing::inicio("config.txt", "saida.ppm");
    
    
    return 0;
}

