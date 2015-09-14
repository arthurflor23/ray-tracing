/* 
 * File:   Read.hpp
 * Author: arthur
 *
 * Created on 11 de Setembro de 2015, 10:54
 */

#ifndef READ_HPP
#define	READ_HPP

#include "Object.hpp"
#include "Hittable.hpp"
#include <vector>

using namespace arma;
using namespace std;

class Read {
    
public:
    
    static int leitura(const char* txt, vector<Object *> &objetos, vector<Light> &luz, Ambient &ambiente, mat &keye, int &cont_tri);

};

#endif	/* READ_HPP */

