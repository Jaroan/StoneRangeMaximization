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
double zeroLiftDrag,liftInducedDrag;
double angleOfAttack;


void initialize();
void obtainIncrements();

int main()
{
    fastio;
    initialize();
    cout<<density<<" "<<loadMax<<endl;
    
    load=loadMax;

    while(height>=0)
    {
        obtainIncrements();
        
        range+=drange;
        height+=dheight;
        velocity+=dvelocity;
        pathangle+=dpathangle;
        
        cout<<"Range:"<<range<<"||"<<"Height:"<<height<<"||"<<"Velocity:"<<velocity<<"||"<<"Path Angle:"<<pathangle<<"||"<<"Height:"<<height<<"||"<<"Velocity:"<<velocity<<"||"<<"Density:"<<density<<endl;
    }

    cout<<endl<<endl<<endl<<"Computations for various values of load"<<endl<<endl;
    for(load=-1;load<=2;load+=0.01)
    {
        initialize();
        while(height>=0)
        {
            obtainIncrements();
            
            range+=drange;
            height+=dheight;
            velocity+=dvelocity;
            pathangle+=dpathangle;
        }

        cout<<"load:"<<load<<"   range:"<<range<<endl;
    }

    
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

void obtainIncrements()
{
    drange=velocity*cos(pathangle);
    dheight=velocity*sin(pathangle);
    dpathangle=g*(load-cos(pathangle))/velocity;

    density=1.225*exp(-beta*height);
    zeroLiftDrag=density*velocity*velocity*surfaceArea*zeroLiftDragCoeff/2;
    liftInducedDrag=2*(mass*g)*(mass*g)*liftInducedDragCoeff/(density*velocity*velocity*surfaceArea);

    dvelocity=-(zeroLiftDrag+liftInducedDrag*load*load)/mass - g*sin(pathangle);

    if(dheight>0)
        dheight*=-1;
    if(drange<0)
        drange*=-1;
}