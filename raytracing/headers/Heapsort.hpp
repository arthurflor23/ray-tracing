
#ifndef HEAPSORT_HPP
#define	HEAPSORT_HPP

#include "Object.hpp"
#include <vector>

using namespace std;

class Heapsort {
    
public:
    Heapsort();
    static vector<Object*> heapsort(vector <Object *> &objetos, int n, int eixo);

};

#endif	/* HEAPSORT_HPP */

