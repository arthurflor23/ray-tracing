
#ifndef TRIANGLE_HPP
#define	TRIANGLE_HPP

#include "Object.hpp"
#include <armadillo>
#include <vector>

using namespace arma;
using namespace std;

class Triangle :public Object {

private:
    vec A, B, C, baricentro;
    
public:
    
    Triangle(vec triangulo);

    bool colide(const vec &d, double &T, const vec &origem);
    
    void setCentro(vec baricentro) {
        this->baricentro = baricentro;
    }

    vec getCentro() {
        return baricentro;
    }

    void setC(vec C) {
        this->C = C;
    }

    vec getC() {
        return C;
    }

    void setB(vec B) {
        this->B = B;
    }

    vec getB() {
        return B;
    }

    void setA(vec A) {
        this->A = A;
    }

    vec getA() {
        return A;
    }
    
    vec getMin(){ 
        double tmp[3];
	vec aux;
	  
	for (int i=0;i<3;i++){
	      if ((this->A(i) <= this->B(i)) && (this->A(i) <= this->C(i))) { 
                  tmp[i]=A(i); 
              }
              
	      else if ((this->B(i) <= this->A(i)) && (this->B(i) <= this->C(i))) { 
                  tmp[i]=B(i); 
              }
              
	      else if ((this->C(i) <= this->A(i)) && (this->C(i) <= this->B(i))) { 
                  tmp[i]=C(i); 
              }
	}
	    
	aux << tmp[0] << tmp[1] << tmp[2]; 
        
	return aux; 
    }
    
    vec getMax(){ 
	double tmp[3];
	vec aux;
	  
	for (int i=0;i<3;i++){
	    if ((this->A(i) >= this->B(i)) && (this->A(i) >= this->C(i))) { 
                tmp[i]=A(i); 
            }
            
	    else if ((this->B(i) >= this->A(i)) && (this->B(i) >= this->C(i))) { 
                tmp[i]=B(i); 
            }
	    
            else if ((this->C(i) >= this->A(i)) && (this->C(i) >= this->B(i))) { 
                tmp[i]=C(i); 
            }
	}
	    
	aux << tmp[0] << tmp[1] << tmp[2]; 
	return aux; 
    }

};

#endif	/* TRIANGLE_HPP */

