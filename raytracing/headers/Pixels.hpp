
#ifndef PIXELS_HPP
#define	PIXELS_HPP
#include <armadillo>

using namespace arma;
using namespace std;

class Pixels {
   
private:
    int r, g, b;
    vec xy; 
    
public:
    Pixels();
    
    Pixels(int x, int y){
	this->xy << x << y;
    }
    
    int color(vec rgb){
	this->r = (int)rgb(0);
	this->g = (int)rgb(1);
	this->b = (int)rgb(2);
        
        return 0;
    }
      
    vec getXY() { 
        return this->xy; 
    }
    
    int getR() { 
        return this->r; 
    }
    
    int getG() { 
        return this->g; 
    }
    
    int getB() { 
        return this->b; 
    }

};

#endif	/* PIXELS_HPP */

