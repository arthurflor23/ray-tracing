
#include <vector>
#include <armadillo>
#include "Ray.hpp"
#ifndef BOX_HPP
#define	BOX_HPP

using namespace arma;
using namespace std;

class Box {
    
private:
    vector <vec> bounds;
    
public:
    Box();
    
    Box(vec min, vec max){
	this->bounds.push_back(min);
	this->bounds.push_back(max);
      }
    
    vec getMin() { 
        return bounds[0]; 
    }
    
    vec getMax() { 
        return bounds[1]; 
    }
   
    static bool intersect(vector <vec> &bounds, Ray &r);  
    
};

#endif	/* BOX_HPP */

