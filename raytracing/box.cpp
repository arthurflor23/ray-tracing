
#include "box.hpp"
#include "raytracer/ray.hpp"

bool Box::intersect(Ray &r) {
    
    double tmin, tmax, tymin, tymax, tzmin, tzmax;

    tmin = (bounds[r.GetSign()[0]](0) - r.GetOrigem()(0)) * r.GetInv_d()(0);
    tmax = (bounds[1-r.GetSign()[0]](0) - r.GetOrigem()(0)) * r.GetInv_d()(0);

    tymin = (bounds[r.GetSign()[1]](1) - r.GetOrigem()(1)) * r.GetInv_d()(1);
    tymax = (bounds[1-r.GetSign()[1]](1) - r.GetOrigem()(1)) * r.GetInv_d()(1);

    if (tmin > tymax || tymin > tmax) { 
        return false; 
    }
    
    if (tymin > tmin) { 
        tmin = tymin; 
    }
    
    if (tymax < tmax) { 
        tmax = tymax; 
    }

    tzmin = (bounds[r.GetSign()[2]](2) - r.GetOrigem()(2)) * r.GetInv_d()(2);
    tzmax = (bounds[1-r.GetSign()[2]](2) - r.GetOrigem()(2)) * r.GetInv_d()(2);

    if (tmin > tzmax || tzmin > tmax) { 
        return false; 
    }
    
    if (tzmin > tmin) { 
        tmin = tzmin; 
    }
    
    if (tzmax < tmax) { 
        tmax = tzmax; 
    }

    if (tmin > r.GetTmin()) { 
        r.SetTmin(tmin); 
    }
    
    if (tmax < r.GetTmax()) { 
        r.SetTmax(tmax);  
    }

    return true;
}

