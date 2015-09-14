
#ifndef HITTABLE_HPP
#define	HITTABLE_HPP
#include <armadillo>

using namespace arma;
using namespace std;

class Hittable{
    
public:
    virtual vec getMin(); 
    virtual vec getMax();
    virtual vec getCentro();
    
};


#endif	/* HITTABLE_HPP */

