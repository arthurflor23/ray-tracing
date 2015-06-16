
#include "headers/Triangle.hpp"
#include "headers/Object.hpp"
#include "headers/Hittable.hpp"
#include <armadillo>
#include <vector>

using namespace arma;
using namespace std;

Triangle::Triangle() {
}

Triangle::Triangle (vec triangulo){
    
    mat transf;
    vec kd, ks;
    
    transf << triangulo(16) << triangulo(17) << triangulo(18) << triangulo(19) << endr
	   << triangulo(20) << triangulo(21) << triangulo(22) << triangulo(23) << endr 
           << triangulo(24) << triangulo(25) << triangulo(26) << triangulo(27) << endr
           << 0 << 0 << 0 << 1;

    setTransf(transf);
    
    this->A << triangulo(0) << triangulo(1) << triangulo(2) << 1;
    this->A = transf * A;
    this->A.shed_row(3);
	
    this->B << triangulo(3) << triangulo(4) << triangulo(5) << 1;
    this->B = transf * B;
    this->B.shed_row(3);
	
    this->C << triangulo(6) << triangulo(7) << triangulo(8) << 1;
    this->C = transf * C;
    this->C.shed_row(3);
	
    kd << triangulo(9) << triangulo(10) << triangulo(11);
    ks << triangulo(12) << triangulo(13) << triangulo(14);
    
    setKd(kd);
    setKs(ks);
        
    setP(triangulo(15));
    
    setTipo(1);
	
    this->baricentro = (this->A + this->B + this->C)/3;
    
    setNormal(cross(this->B - this->A, this->C - this->A));
}

bool Triangle::colide(const vec &d, double &T, const vec &origem){
    
    vec tuv;
    mat matriz1, matriz2;

    matriz1.insert_cols(0, origem-d);
    matriz1.insert_cols(1, this->B - this->A);
    matriz1.insert_cols(2, this->C - this->A);
	      
    if ((det(matriz1)>0.000001) || (det(matriz1)<-0.000001)){
        
        matriz2 = origem - this->A;
  
	tuv = matriz1.i() * matriz2;

	if ((tuv(1)>=0) && (tuv(1)<=1) && (tuv(2)>=0) && (tuv(2)<=1) && (tuv(1)+tuv(2)<=1)){
            
            T=tuv(0); 
            setNormal(normalise(getNormal()));
            
            return true;
	}
    }
    
    return false;
}


