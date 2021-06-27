//this archive defines the functions needed to test if two particles collide

#pragma once

#include "Particle.hpp"
#include <math.h>
#include <iostream>

using std::cout; using std::endl;
using std::max; using std::abs;

bool collision(particle P1, particle P2, double d){
    /*
    Tests if P1 and P2 collide. The variable d is the threshold.
    The distance between P1 and P2 is calculated by the Pythagoras' theorem.
    If P1 and P2 are closer than d the particles have collided then the function returns true.
    */
   double distance;
   static position pos_p1, pos_p2; //holds the position of P1 and P2 at instant t
   pos_p1=P1.actual_pos();
   pos_p2=P2.actual_pos();
   distance = pow(pow(pos_p2.x-pos_p1.x,2)+pow(pos_p2.y-pos_p1.y,2),0.5); //Pythagoras' theorem
   return (distance<d); //if distance<d so the particles have collided 
}

void RunTest(particle P1, particle P2, double duration, double d, double start_time=0.0){
    /*
    Runs the test for time "duration". If the particles collide then the tests stops.
    The test is ran by deltax intervals of time
    */
   double actual_time = start_time; //just an alias
   static velocity v1=P1.actual_vel(), v2=P2.actual_vel();
   double v_max = max(max(abs(v1.x),abs(v2.x)),max(abs(v1.y),abs(v2.y))); //getting the max absolute velocity
   double delta_t=d/(10.0*v_max); //the delta_t is one tenth of the time that the fastest object passes the hitbox
   bool collided=false;
   while(actual_time<=duration){
       P1.updatepos(actual_time); 
       P2.updatepos(actual_time);
       if(collision(P1,P2,d)){
           position pos = P1.actual_pos();
           cout<<"The particles have collided after "<<actual_time<<" seconds."<<endl;
           cout<<"x position = "<<pos.x<<endl;
           cout<<"y position = "<<pos.y<<endl;
           collided=true;
           break;
       }
        else{
            actual_time+=delta_t;
        }
   }
   if(not collided){
       cout<<"The particles have not collided after "<<duration<<" seconds."<<endl;
   }
}
