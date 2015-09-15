
#ifndef WRITE_HPP
#define	WRITE_HPP

#include "NoArvore.hpp"
#include "Pixels.hpp"
#include <vector>

using namespace arma;
using namespace std;

class Write {
    
public:
    
    Write(const char *txt, const vector<Light> luz, const mat keye, const Ambient ambiente, NoArvore * No);

};

#endif	/* WRITE_HPP */

