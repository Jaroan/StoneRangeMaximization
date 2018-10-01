#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)

const double g=9.8;
const double zeroLiftDragCoeff=0.055; // Denoted bt CD0
const double mass=600;
const double surfaceArea=1.028;
const double liftInducedDragCoeff=0.08; //denoted by K
const double beta=0.000138888888888;

double range,height,velocity, pathangle,density;
double drange,dheight,dvelocity, dpathangle;

double load,loadMax; //referred to as n in the paper
double CDrag,CLift;

double DragInduced,LiftInduced,intialLift;
double angleOfAttack;

void initialize();

int main()
{
    fastio;
    initialize();
    cout<<density<<" "<<loadMax<<endl;
}

void initialize()
{
    intialLift=0;

    height=10000;
    velocity=250;
    pathangle=-0.1; //radians
    density=1.225*exp(-beta*height);
    loadMax=density*velocity*velocity*surfaceArea*sqrt(zeroLiftDragCoeff/liftInducedDragCoeff)/(2*mass*g);
}