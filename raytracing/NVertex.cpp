
#include "headers/NVertex.hpp"
#include <armadillo>
#include <vector>
#include <omp.h>

using namespace arma;
using namespace std;

NVertex::NVertex() {
}

int NVertex::N(vector <Object *> &objetos, const int &cont_tri){
    
    mat aux;
    aux.zeros(cont_tri,3);
	
    #pragma omp parallel for
    for (unsigned int w=0;w<objetos.size();w++){
	if (objetos[w]->getTipo() == 1){
            
            vec turnA = objetos[w]->getA();
            vec turnB = objetos[w]->getB();
            vec turnC = objetos[w]->getC();
		
            for (unsigned int j=w+1;j<objetos.size();j++){
                if (objetos[j]->getTipo() == 1){

                    vec compareA = objetos[j]->getA();
                    vec compareB = objetos[j]->getB();
                    vec compareC = objetos[j]->getC();
		      
                    if ((turnA(0) == compareA(0)) && (turnA(1) == compareA(1)) && (turnA(2) == compareA(2))){ 
                        
			    aux.row(w) = aux.row(w) + objetos[j]->getNormal().t();
			    aux.row(j) = aux.row(j) + objetos[w]->getNormal().t();
                    }
			
                    if ((turnA(0) == compareB(0)) && (turnA(1) == compareB(1)) && (turnA(2) == compareB(2))){ 
                        
			    aux.row(w) = aux.row(w) + objetos[j]->getNormal().t();
			    aux.row(j) = aux.row(j) + objetos[w]->getNormal().t();
                    }
			
                    if ((turnA(0) == compareC(0)) && (turnA(1) == compareC(1)) && (turnA(2) == compareC(2))){
                        
			aux.row(w) = aux.row(w) + objetos[j]->getNormal().t();
			aux.row(j) = aux.row(j) + objetos[w]->getNormal().t();
                    }
			
                    if ((turnB(0) == compareA(0)) && (turnB(1) == compareA(1)) && (turnB(2) == compareA(2))){
                        
			aux.row(w) = aux.row(w) + objetos[j]->getNormal().t();
			aux.row(j) = aux.row(j) + objetos[w]->getNormal().t();
                    }
			
                    if ((turnB(0) == compareB(0)) && (turnB(1) == compareB(1)) && (turnB(2) == compareB(2))){
                        
			aux.row(w) = aux.row(w) + objetos[j]->getNormal().t();
			aux.row(j) = aux.row(j) + objetos[w]->getNormal().t();
                    }
			
                    if ((turnB(0) == compareC(0)) && (turnB(1) == compareC(1)) && (turnB(2) == compareC(2))){ 

                        aux.row(w) = aux.row(w) + objetos[j]->getNormal().t();
			aux.row(j) = aux.row(j) + objetos[w]->getNormal().t();
                    }
			
                    if ((turnC(0) == compareA(0)) && (turnC(1) == compareA(1)) && (turnC(2) == compareA(2))){
                        
			aux.row(w) = aux.row(w) + objetos[j]->getNormal().t();
			aux.row(j) = aux.row(j) + objetos[w]->getNormal().t();
                    }
			  
                    if ((turnC(0) == compareB(0)) && (turnC(1) == compareB(1)) && (turnC(2) == compareB(2))){ 
			    
                        aux.row(w) = aux.row(w) + objetos[j]->getNormal().t();
			aux.row(j) = aux.row(j) + objetos[w]->getNormal().t();
                    }
			
                    if ((turnC(0) == compareC(0)) && (turnC(1) == compareC(1)) && (turnC(2) == compareC(2))){
                        
			aux.row(w) = aux.row(w) + objetos[j]->getNormal().t();
			aux.row(j) = aux.row(j) + objetos[w]->getNormal().t();
                    }
		}
            }
            
            if ( !((aux(w,0) == 0) && (aux(w,1) == 0) && (aux(w,2) == 0))) { 
                objetos[w]->setNormal(aux.row(w).t()); 
            }
        }
    }
    
    return 0;    
}

