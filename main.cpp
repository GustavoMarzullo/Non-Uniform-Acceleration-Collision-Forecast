#include <iostream>
#include "Particle.hpp"
#include "TestCollision.hpp"

using std::cout; using std::endl;

//-------------------------------------Defining the acceleration functions-----------------------
double a1(double t){
    return 1.0;
}

double a3(double t){
    return 3.0;
}

double aminus3(double t){
    return -3.0;
}

double a0(double t){
    return 0.0;
}

//----------------------------------------------------End---------------------------------------

void test_update(){
    position pos1(1,0);
    velocity vel1(3,0);
    acceleration acel1(a1,a0);
    particle P1(pos1,vel1,acel1);
    P1.print();
    P1.updatepos(5);
    printf("\n");
    P1.print();
    P1.updatepos(10);
    printf("\n");
    P1.print();
}

void testcollision(){
    cout<<"First test"<<endl;
    cout<<"Two particles are running along the x-axis."<<endl;
    cout<<"P1(0,0) is running at constant speed at 5m/s and P2(10,0) at constant speed at -3m/s."<<endl<<endl;
    //defining the particles
    position pos1(0,0),pos2(10,0);
    velocity vel1(5,0),vel2(-3,0);
    acceleration acel1(a0,a0),acel2(a0,a0);
    particle P1(pos1,vel1,acel1);
    particle P2(pos2,vel2,acel2);
    double hitbox = 0.01; //1 cm
    double duration = 60;
    RunTest(P1,P2,duration,hitbox);

    cout<<"\n----------------------------------------------------------------------------"<<endl;

    cout<<"\nSecond test"<<endl;
    cout<<"Two particles are running along the x-axis."<<endl;
    cout<<"P5(0,0) at 5m/s and accelerating at 3 m/s² is running after P6(15,0) at 10m/s and accelerating at 1 m/s².\n"<<endl<<endl;
    //defining the particles
    position pos5(0,0),pos6(15,0);
    velocity vel5(5,0),vel6(10,0);
    acceleration acel5(a3,a0),acel6(a1,a0);
    particle P5(pos5,vel5,acel5);
    particle P6(pos6,vel6,acel6);
    hitbox = 0.01; //1cm
    duration = 60;
    RunTest(P5,P6,duration,hitbox);

    cout<<"\n----------------------------------------------------------------------------"<<endl;

    cout<<"\nThird test"<<endl;
    cout<<"P7(1,1) is with velocity (2,2)m/s and acceleration (1,1)m/s² and P8 stands still at (10,10).\n"<<endl;
    //defining the particles
    position pos7(1,1),pos8(10,10);
    velocity vel7(2,2),vel8(0,0);
    acceleration acel7(a1,a1),acel8(a0,a0);
    particle P7(pos7,vel7,acel7);
    particle P8(pos8,vel8,acel8);
    hitbox = 0.01; //1cm
    duration = 60;
    RunTest(P7,P8,duration,hitbox); 
}

int main(){
    testcollision();
    return 0;
}