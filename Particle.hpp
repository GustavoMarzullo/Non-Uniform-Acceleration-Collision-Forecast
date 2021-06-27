//this archive defines the classes and structures to describe the motion and positon of a particle at a determined time

#pragma once 

#include <iostream>
#include "euler_method.hpp"

using std::cout; using std::endl;

struct position{
    double x;
    double y;
    position() {}; //default constructor
    position(double X, double Y){ //constructor
        x=X;
        y=Y;
    }
};

struct velocity{
    double x;
    double y;
    velocity() {}; //default constructor
    velocity(double X, double Y){ //constructor
        x=X;
        y=Y;
    }
};

struct acceleration{
    double (*x)(double);
    double (*y)(double);
    acceleration() {}; //default constructor
    acceleration(double (*X)(double), double (*Y)(double)){ //constructor
        x=X;
        y=Y;
    }
};

class particle{
private:
    position s0;         //initial position
    velocity v0;         //initial velocity
    acceleration a;      //acceleration
    double time;         //actual time (zero by default)
    position s;          //actual position   
    velocity v;          //actual velocity

public:
    particle () {}; //default constructor
    particle(position initial_pos, velocity initial_vel, acceleration A, double TIME=0.0){ //class constructor
        s0 = initial_pos;
        v0 = initial_vel;
        a = A;
        time = TIME;
        s = s0;
        v = v0;
    }

    double xpos(double t){
        double x;
        x=solve(a.x,s0.x,v0.x,t); //calculation of the x position
        return x;
    }

    double ypos(double t){
        double y;
        y=solve(a.y,s0.y,v0.y,t); //calculation of the y position
        return y;
    }

    position pos(double t){
        double x,y;
        position S;
        x=solve(a.x,s0.x,v0.x,t);
        y=solve(a.y,s0.y,v0.y,t);
        S.x=x;
        S.y=y;
        return S;
    }

    void updatepos(double t){ //changes the actual position, velocity and time of the particle
        static vecdouble x;
        static vecdouble y;

        //calculating the new x and y positions
        x=solve1(a.x,s.x,v.x,t,time);
        y=solve1(a.y,s.y,v.y,t,time);

        //updating the particle parameters
        time=t;
        s.x= x[0];
        s.y= y[0];
        v.x= x[1];
        v.y= y[1];
    }

    void print(){
        cout<<"Time = "<<time<<endl;
        cout<<"Position: "<<"("<<s.x<<","<<s.y<<")"<<endl;
        cout<<"Velocity: "<<"("<<v.x<<","<<v.y<<")"<<endl;
    }

    double actual_time(){ //returns the actual time
        return time;
    }

    position actual_pos(){ //returns the actual position
        return s;
    }

    velocity actual_vel(){
        return v;
    }
};
