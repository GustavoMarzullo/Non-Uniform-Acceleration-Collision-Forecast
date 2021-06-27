//Euler's method to solve second order differential equation

#pragma once

#include <vector>

typedef std::vector<double> vecdouble;

double solve(double(*a)(double x),double x0, double v0, double t,double t0=0.0, double delta=0.001){ 
    /*
    Solves d²x/dt²=a(x) for x with initial position x0 and initial velocity v0
    */
    double T=t0,x1=x0,v1=v0,x2,v2;
    while(T<t){
        v2=v1+delta*a(x0);
        x2=x1+delta*v2;
        T+=delta;
        v1=v2;
        x1=x2;           
    }
    return x1;
}

vecdouble solve1(double(*a)(double t),double x0, double v0, double t,double t0, double delta_t=1e-6){ 
    /*
    Solves d²x/dt²=a(t) for x with initial position x0, initial velocity v0 and initial time t0
    */
    static vecdouble array(2); //this array doesn't need to be created thousands of times throughout the loop of RunTest
    double x1=x0,v1=v0,x2,v2;   
    while(t0<t){
        v2=v1+delta_t*a(x0);
        x2=x1+delta_t*v2;
        t0+=delta_t;
        v1=v2;
        x1=x2;        
    }
    array[0]=x1;
    array[1]=v1;
    return array;
}