
#include "headers/Sphere.hpp"
#include "headers/Object.hpp"
#include "headers/Hittable.hpp"
#include <armadillo>
#include <vector>

using namespace arma;
using namespace std;

Sphere::Sphere() {
}

Sphere::Sphere(vec esfera){
    
    mat transf;
    vec kd, ks;
    
    transf << esfera(11) << esfera(12) << esfera(13) << esfera(14) << endr
	   << esfera(15) << esfera(16) << esfera(17) << esfera(18) << endr 
           << esfera(19) << esfera(20) << esfera(21) << esfera(22) << endr
           << 0 << 0 << 0 << 1;
	
    setTransf(transf);
    
    this->centro << esfera(0) << esfera(1) << esfera(2) << 1;
    this->centro = transf * centro;
    this->centro.shed_row(3);
	
    this->raio = esfera(3);	
    
    kd << esfera(4) << esfera(5) << esfera(6);
    ks << esfera(7) << esfera(8) << esfera(9);
    
    setKd(kd);
    setKs(ks);
        
    setP(esfera(10));
	
    this->min = this->centro - this->raio;
    this->max = this->centro + this->raio;
        
    setTipo(0);
}

bool Sphere::colide(const vec &d, double &T, const vec &origem){
    double a, b, c, delta, x, xx;
	
    a = dot(origem-d,origem-d);
    b = 2*dot(origem-d, this->centro - origem);
    c = dot(this->centro - origem, this->centro - origem) - (this->raio * this->raio);
	
    delta = (b*b) - (4 * a * c);

    if (delta>=0){
	x  = (-b + sqrt(delta)) / (2 * a);
	xx = (-b - sqrt(delta)) / (2 * a);
	    
	if (x < xx) { 
            T=x; 
        }
	
        else { 
            T=xx; 
        } 
	    
        return true;
    }
	  
    else { 
        return false; 
    }
}  

