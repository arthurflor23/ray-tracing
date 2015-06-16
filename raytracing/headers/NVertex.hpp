
#ifndef NVERTEX_HPP
#define	NVERTEX_HPP

#include "Object.hpp"
#include <vector>

using namespace std;

class NVertex {
    
public:
    
    NVertex();
    
    int N(vector <Object *> &objetos, const int &cont_tri);
   

};

#endif	/* NVERTEX_HPP */

