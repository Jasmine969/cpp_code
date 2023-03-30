#include <iostream>
#include <cmath>
static const double R=8.314;
enum Equation{Vdw,RK,SRK,PR};
double V(const double & Treal,const double & preal,const double & pc,const double & Tc,const double & w)
{
    double Vol,error,delta,epsilon,aT,b,Tr,m,at;
    double omega_a[3]{0.421875,0.42748,0.45724};
    double omega_b[3]{0.125,0.08664,0.07779};
    double v0=(R*Treal)/preal;
    double n=(R*Tc)/pc;
    int eq;
    while (eq>=Vdw && eq<=PR)
   { 
    switch (eq)
    {
     case Vdw:
      delta=epsilon=0;
      aT=omega_a[0]*(pow(R,2)*pow(Tc,2))/pc;
      b=omega_b[0]*n;
      Tr=1;
      break;
     case RK:
      delta=1;
      epsilon=0;
      aT=omega_a[1]*(pow(R,2)*pow(Tc,2.5))/pc;
      b=omega_b[1]*n;
      Tr=pow(Treal,0.5);
     break;
     case SRK:
      delta=1;
      epsilon=0;
      m=0.480+1.574*w-0.176*pow(w,2);
      at=pow((1+m*(1-pow((Treal/Tc),0.5))),2);
      aT=omega_a[1]*(pow(R,2)*pow(Tc,2))/pc*at;
      b=omega_b[1]*n;
      Tr=1;
     break;
     case PR:
      delta=2.4142;
      epsilon=2.4142;
      m=0.3746+1.54226*w-0.26992*pow(w,2);
      at=pow((1+m*(1-pow((Treal/Tc),0.5))),2);
      std::cout << omega_a[2] << ' ' << R << ' '
      << Tc << ' ' << pc << '\n';
      double a=omega_a[2]*(pow(R,2)*pow(Tc,2))/pc;
      double nums[]{pow(R, 2), pow(Tc, 2), pow(R, 2) * pow(Tc, 2),
       (pow(R,2)*pow(Tc,2))/pc, omega_a[2]*(pow(R,2)*pow(Tc,2))/pc};
      aT=omega_a[2]*(pow(R,2)*pow(Tc,2))/pc*at;
      b=omega_b[2]*n;
      Tr=1;
     break;
    }
    if(!(std::cin>>eq)){break;}
   } 
    Vol=v0-(aT*(v0-b))/(Tr*preal*(v0+epsilon*b)*(v0+delta*b))+b;
    error=fabs((Vol-v0)/v0);
    while (error>0.0001)
    {
      v0=Vol;
      Vol=(R*Treal)/preal-(aT*(v0-b))/(Tr*preal*(v0+epsilon*b)*(v0+delta*b))+b;
      error=fabs((Vol-v0)/v0);
      std::cout<<"Vol ="<<Vol<<" ,error="<<error<<std::endl;
    }
    return Vol;
}
int main()
{
  // double Tc=408.1,pc=3.648e6,Treal=300.0,p=3.704e5,w=0.176;
  //  double Tc=405.6,pc=11.28e6,Treal=477.0,p=2.03e6,w=0.250,T=448.6;
  double v=V(477.0,2.03e6,11.28e6,405.6,0.250);
  std::cout<<v;
  return 0;
}
