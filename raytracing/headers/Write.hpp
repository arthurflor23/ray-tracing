/* 
 * File:   Write.hpp
 * Author: arthur
 *
 * Created on 11 de Setembro de 2015, 11:05
 */

#ifndef WRITE_HPP
#define	WRITE_HPP

using namespace arma;
using namespace std;

class Write {
    
public:
    
    int Write(const char *txt, const vector<Light> luz, const mat keye, const Ambient ambiente, NoArvore * No);

};

#endif	/* WRITE_HPP */

