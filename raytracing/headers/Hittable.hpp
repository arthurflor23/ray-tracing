
#ifndef HITTABLE_HPP
#define	HITTABLE_HPP
#include <armadillo>

using namespace arma;
using namespace std;

class Hittable{
    
public:
    virtual vec getMin() = 0; 
    virtual vec getMax() = 0;
    virtual vec getCentro() = 0;
    
};


#endif	/* HITTABLE_HPP */

