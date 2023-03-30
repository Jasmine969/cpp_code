#include <iostream>
#include <ostream>
#include <fstream>
#include <ctime>
#include <cmath>
#include <vector>
#include <array>
#include <climits>
#include <cctype>
#include <fstream>
#include <cstdlib>
#include <complex>
#include <ctype.h>
#include <cstring>
// class cubicEOS
// {
//   private:
//   double R;
//   double p,V,T,Tr,Tc,pc;
//   double alphaT;
//   double sigma,epsilon;
//   double zc;
//   double Omega_a,Omega_b;
//   double Omega_SRK,Omega_PR;
//   double a,b;
//   public:
//   cubicEOS();
//   ~cubicEOS();
//   cubicEOS(double p_,double T_);

//   double error(double p_,double T_,double b_,double V_,double alphaT_,double epsilon_,double sigma_ );

// };
/*van de wall equation*/
// static double alphaT=1.0;
// static double omega_a=0.421875,omega_b=0.125;
// static double zc=0.375;
// static const double R=8.314;
// double w_a(const double & Tc,const double & pc)
// {
//     double aa=(pow(R,2)*pow(Tc,2))/pc;
//     return omega_a*aa;

// }
// double w_b(const double & Tc,const double & pc)
// {
//     double bb=(R*Tc)/pc;
//     return omega_b*bb;
// }
// void V(const double & a,const double & b,const double & T,const double & p)
// {
//    double Vol;
//    double error;
//    double v0;
//    v0=(R*T)/p;
//    Vol=((R*T)/p)-(a*(v0-b))/(p*pow(v0,2)+b);
//    error=(Vol-v0)/v0>0? (Vol-v0)/v0:-(Vol-v0)/v0;
//    std::cout<<"v0= "<<v0<<std::endl;
//    std::cout<<"Vol= "<<Vol<<" error= "<<error<<std::endl;
//    while(error>0.0001)
//    {
//      v0=Vol;
//      Vol=((R*T)/p)-(a*(v0-b))/(p*pow(v0,2)+b);
//      error=(Vol-v0)/v0>0? (Vol-v0)/v0:-(Vol-v0)/v0;
//      std::cout<<"Vol= "<<Vol<<" error= "<<error<<std::endl;
//    }
//    return;
// }
// int main()
// {
//   double Tc=408.1,pc=3.648e6,Treal=300.0,p=3.704e5;
// //   std::cout<<"Tc(K)= ";
// //   std::cin>>Tc;
// //   std::cout<<"pc(Pa)= ";
// //   std::cin>>pc;
// //   std::cout<<"Treal(K)= ";
// //   std::cin>>Treal;
// //   std::cout<<"p(Pa)= ";
// //   std::cin>>p;
//   double a=w_a(Tc,pc);
//   double b=w_b(Tc,pc);
//   V(a,b,Treal,p);
//   return 0;
// }
/*RK*/
// static double omega_a=0.42748,omega_b=0.08664;
// // static double zc=0.33333;
// static const double R=8.314;
// double w_a(const double & Tc,const double & pc)
// {
//     double aa=(pow(R,2)*pow(Tc,2.5))/pc;
//     return omega_a*aa;

// }
// double w_b(const double & Tc,const double & pc)
// {
//     double bb=(R*Tc)/pc;
//     return omega_b*bb;
// }
// void V(const double & a,const double & b,const double & T,const double & p)
// {
//    double Vol;
//    long double error;
//    double v0=(R*T)/p;
//    Vol=(R*T)/p-(a*(v0-b))/(pow(T,0.5)*p*v0*(v0+b))+b;
//    error=fabs((Vol-v0)/v0);
//    std::cout<<"Vol= "<<Vol<<" error="<<error<<std::endl;
//    while(error>0.0001)
//    {
//      v0=Vol;
//      Vol=((R*T)/p)-(a*(v0-b))/((pow(T,0.5)*p*v0*(v0+b))+b);
//      error=fabs((Vol-v0)/v0);
//      std::cout<<"Vol= "<<Vol<<" error= "<<error<<std::endl;
//    }
//    return;
// }
// int main()
// {
//   double Tc=408.1,pc=3.648e6,Treal=300.0,p=3.704e5;
// //   std::cout<<"Tc(K)= ";
// //   std::cin>>Tc;
// //   std::cout<<"pc(Pa)= ";
// //   std::cin>>pc;
// //   std::cout<<"Treal(K)= ";
// //   std::cin>>Treal;
// //   std::cout<<"p(Pa)= ";
// //   std::cin>>p;
//   double a=w_a(Tc,pc);
//   double b=w_b(Tc,pc);
//   V(a,b,Treal,p);
//   return 0;
// }

/*SRK*/
// static double omega_a=0.42748,omega_b=0.08664;
// // static double zc=0.33333;
// static const double R=8.314;
// double w_a(const double & Tc,const double & pc)
// {
//     double aa=(pow(R,2)*pow(Tc,2))/pc;
//     return omega_a*aa;

// }
// double w_b(const double & Tc,const double & pc)
// {
//     double bb=(R*Tc)/pc;
//     return omega_b*bb;
// }
// double alphaT(const double & om,const double & Tc,const double & T)
// {

//     double m,Tr;
//     m=0.480+1.574*om-0.176*pow(om,2);
//     Tr=T/Tc;
//     return pow((1+m*(1-pow(Tr,0.5))),2);
// }
// void V(const double & b,const double & T,const double & p,const double & aT)
// {
//    double Vol;
//    long double error;
//    double v0=(R*T)/p;
//    Vol=(R*T)/p-(aT*(v0-b))/(p*v0*(v0+b))+b;
//    error=fabs((Vol-v0)/v0);
//    std::cout<<"Vol= "<<Vol<<" error="<<error<<std::endl;
//    while(error>0.0001)
//    {
//      v0=Vol;
//      Vol=(R*T)/p-(aT*(v0-b))/(p*v0*(v0+b))+b;
//      error=fabs((Vol-v0)/v0);
//      std::cout<<"Vol= "<<Vol<<" error= "<<error<<std::endl;
//    }
//    return;
// }
// int main()
// {
//   // double Tc=408.1,pc=3.648e6,Treal=300.0,p=3.704e5,w=0.176;
//      double Tc=405.6,pc=11.28e6,Treal=477.0,p=2.3e6,w=0.250;
// //   std::cout<<"Tc(K)= ";
// //   std::cin>>Tc;
// //   std::cout<<"pc(Pa)= ";
// //   std::cin>>pc;
// //   std::cout<<"Treal(K)= ";
// //   std::cin>>Treal;
// //   std::cout<<"p(Pa)= ";
// //   std::cin>>p;
//   double a=w_a(Tc,pc);
//   double b=w_b(Tc,pc);
//   double aT=alphaT(w,Tc,Treal)*a;
//   V(b,Treal,p,aT);
//   return 0;
// }
/*PR*/
// static double omega_a=0.45724,omega_b=0.07780;
// // static double zc=0.33333;
// static const double R=8.314;
// double w_a(const double & Tc,const double & pc)
// {
//     double aa=(pow(R,2)*pow(Tc,2))/pc;
//     return omega_a*aa;

// }
// double w_b(const double & Tc,const double & pc)
// {
//     double bb=(R*Tc)/pc;
//     return omega_b*bb;
// }
// double alphaT(const double & om,const double & Tc,const double & T)
// {

//     double m,Tr;
//     m=0.3746+1.54226*om-0.26992*pow(om,2);
//     Tr=T/Tc;
//     return pow((1+m*(1-pow(Tr,0.5))),2);
// }
// void V(const double & b,const double & T,const double & p,const double & aT)
// {
//    double Vol;
//    long double error;
//    double v0=(R*T)/p;
//    Vol=(R*T)/p-(aT*(v0-b))/(p*(v0*(v0+b)+b*(v0-b)))+b;
//    error=fabs((Vol-v0)/v0);
//    std::cout<<"Vol= "<<Vol<<" error="<<error<<std::endl;
//    while(error>0.0001)
//    {
//      v0=Vol;
//      Vol=(R*T)/p-(aT*(v0-b))/(p*(v0*(v0+b)+b*(v0-b)))+b;;
//      error=fabs((Vol-v0)/v0);
//      std::cout<<"Vol= "<<Vol<<" error= "<<error<<std::endl;
//    }
//    return;
// }
// int main()
// {
//   double Tc=408.1,pc=3.648e6,Treal=300.0,p=3.704e5,w=0.176;
// //   std::cout<<"Tc(K)= ";
// //   std::cin>>Tc;
// //   std::cout<<"pc(Pa)= ";
// //   std::cin>>pc;
// //   std::cout<<"Treal(K)= ";
// //   std::cin>>Treal;
// //   std::cout<<"p(Pa)= ";
// //   std::cin>>p;
//   double a=w_a(Tc,pc);
//   double b=w_b(Tc,pc);
//   double aT=alphaT(w,Tc,Treal)*a;
//   V(b,Treal,p,aT);
//   return 0;
// }

// p31 2-1
/*RK*/
// static double omega_a=0.42748,omega_b=0.08664;
// // static double zc=0.33333;
// static const double R=8.314;
// double w_a(const double & Tc,const double & pc)
// {
//     double aa=(pow(R,2)*pow(Tc,2.5))/pc;
//     return omega_a*aa;

// }
// double w_b(const double & Tc,const double & pc)
// {
//     double bb=(R*Tc)/pc;
//     return omega_b*bb;
// }
// int main()
// {
//   double Tc=190.6,pc=4.6e6,Treal=323.15,p0=21562.4;
// //   std::cout<<"Tc(K)= ";
// //   std::cin>>Tc;
// //   std::cout<<"pc(Pa)= ";
// //   std::cin>>pc;
// //   std::cout<<"Treal(K)= ";
// //   std::cin>>Treal;
// //   std::cout<<"p(Pa)= ";
// //   std::cin>>p;
//    double a=w_a(Tc,pc);
//    double b=w_b(Tc,pc);
// //    P(a,b,Treal,p0);
//     /*idea gas EOS*/
//       double vmol=0.1246;
//       double p;
//    p=(8.314*323.15)/vmol;//21562.4
//     //   p=(R*Treal)/(vmol-b)-a/(pow(Treal,0.5)*vmol*(vmol+b));//21556
//       std::cout<<p<<'\n';
//     double error=fabs(21556-21562.4)/21562.4;
//     std::cout<<error;
//   return 0;
// }
// p31 2-4 van der waals EQ
// static double omega_a=0.421875,omega_b=0.125;
// static double zc=0.375;
// static const double R=8.314;
// double w_a(const double & Tc,const double & pc)
// {
//     double aa=(pow(R,2)*pow(Tc,2))/pc;
//     return omega_a*aa;

// }
// double w_b(const double & Tc,const double & pc)
// {
//     double bb=(R*Tc)/pc;
//     return omega_b*bb;
// }
// void V(const double & a,const double & b,const double & T,const double & p)
// {
//    double Vol;
//    double error;
//    double v0;
//    v0=(R*T)/p;
//    Vol=((R*T)/p)-(a*(v0-b))/(p*pow(v0,2)+b);
//    error=(Vol-v0)/v0>0? (Vol-v0)/v0:-(Vol-v0)/v0;
//    std::cout<<"v0= "<<v0<<std::endl;
//    std::cout<<"Vol= "<<Vol<<" error= "<<error<<std::endl;
//    while(error>0.0001)
//    {
//      v0=Vol;
//      Vol=((R*T)/p)-(a*(v0-b))/(p*pow(v0,2)+b);
//      error=(Vol-v0)/v0>0? (Vol-v0)/v0:-(Vol-v0)/v0;
//      std::cout<<"Vol= "<<Vol<<" error= "<<error<<std::endl;
//    }
//    return;
// }
// int main()
// {
//   double Tc=405.6,pc=11.28e6,Treal=477.0,p=2.03e6,T=448.6;
//   double a=w_a(Tc,pc);
//   double b=w_b(Tc,pc);
//   V(a,b,Treal,p);//T=477k,p=2.03e6Pa,vmol=0.001842
//   // double pre;
//   // double vmol=0.142/1536.3735;
//   // pre=(R*T)/(vmol-b)-a/pow(vmol,2);
//   // std::cout<<pre<<'\n';//pre=1.7956e7Pa
//   return 0;
// }
// p31 2-4 RK EQ
// static double omega_a=0.42748,omega_b=0.08664;
// // static double zc=0.33333;
// static const double R=8.314;
// double w_a(const double & Tc,const double & pc)
// {
//     double aa=(pow(R,2)*pow(Tc,2.5))/pc;
//     return omega_a*aa;

// }
// double w_b(const double & Tc,const double & pc)
// {
//     double bb=(R*Tc)/pc;
//     return omega_b*bb;
// }
// void V(const double & a,const double & b,const double & T,const double & p)
// {
//    double Vol;
//    long double error;
//    double v0=(R*T)/p;
//    Vol=(R*T)/p-(a*(v0-b))/(pow(T,0.5)*p*v0*(v0+b))+b;
//    error=fabs((Vol-v0)/v0);
//    std::cout<<"Vol= "<<Vol<<" error="<<error<<std::endl;
//    while(error>0.0001)
//    {
//      v0=Vol;
//      Vol=((R*T)/p)-(a*(v0-b))/((pow(T,0.5)*p*v0*(v0+b))+b);
//      error=fabs((Vol-v0)/v0);
//      std::cout<<"Vol= "<<Vol<<" error= "<<error<<std::endl;
//    }
//    return;
// }
// int main()
// {
//   double Tc=405.6,pc=11.28e6,Treal=477.0,p=2.03e6,T=448.6;
//   double a=w_a(Tc,pc);
//   double b=w_b(Tc,pc);
//   // V(a,b,Treal,p);//T=477k,p=2.03e6Pa,vmol=0.001851
//   double pre;
//   double vmol=0.142/1528.9033;
//   pre=(R*T)/(vmol-b)-a/(pow(T,0.5)*vmol*(vmol+b));
//   std::cout<<pre<<'\n';//pre=1.85418e7Pa
//   return 0;
// }
/*PR*/
static double omega_a = 0.45724, omega_b = 0.07780;
static const double R = 8.314;
double w_a(const double &Tc, const double &pc)
{
  double aa = (pow(R, 2) * pow(Tc, 2)) / pc;
  std::cout << omega_a << ' ' << R << ' '
            << Tc << ' ' << pc << '\n';
  double nums[]{pow(R, 2), pow(Tc, 2), pow(R, 2) * pow(Tc, 2),
   (pow(R,2)*pow(Tc,2))/pc, omega_a * (pow(R,2)*pow(Tc,2))/pc};
  return omega_a * aa;
}
double w_b(const double &Tc, const double &pc)
{
  double bb = (R * Tc) / pc;
  return omega_b * bb;
}
double alphaT(const double &om, const double &Tc, const double &T)
{

  double m, Tr, at;
  m = 0.3746 + 1.54226 * om - 0.26992 * pow(om, 2);
  Tr = T / Tc;
  at = pow((1 + m * (1 - pow(Tr, 0.5))), 2);
  return at;
}
double V(const double &b, const double &T, const double &p, const double &aT)
{
  double Vol;
  long double error;
  double v0 = (R * T) / p;
  Vol = (R * T) / p - (aT * (v0 - b)) / (p * (v0 * (v0 + b) + b * (v0 - b))) + b;
  error = fabs((Vol - v0) / v0);
  std::cout << "Vol= " << Vol << " error=" << error << std::endl;
  while (error > 0.0001)
  {
    v0 = Vol;
    Vol = (R * T) / p - (aT * (v0 - b)) / (p * (v0 * (v0 + b) + b * (v0 - b))) + b;
    ;
    error = fabs((Vol - v0) / v0);
    std::cout << "Vol= " << Vol << " error= " << error << std::endl;
  }
  return Vol;
}
int main()
{
  double Tc = 405.6, pc = 11.28e6, Treal = 477.0, p = 2.03e6, w = 0.250, T = 448.6;
  double a = w_a(Tc, pc);
  double b = w_b(Tc, pc);
  double aT = alphaT(w, Tc, Treal) * a;
  double aTP = alphaT(w, Tc, T) * a;
  double v = V(b, Treal, p, aT);
  //   double vmol=0.142/(2.83/v);
  //   double pre=(R*T)/(vmol-b)-aTP/(vmol*(vmol+b)+b*(vmol-b));;
  // std::cout<<pre<<'\n';//pre=1.90704e7Pa
  return 0;
}
// enum Equation{Vdw,RK,SRK,PR};
// double V(const double & Treal,const double & preal,const double & pc,const double & Tc,const double & w)
// {
//     double Vol,error,delta,epsilon,aT,b,Tr,m,at;
//     double omega_a[3]{0.421875,0.42748,0.45724};
//     double omega_b[3]{0.125,0.08664,0.07779};
//     double v0=(R*Treal)/preal;
//     double n=(R*Tc)/pc;
//     int eq;
//     while (eq>=Vdw && eq<=PR)
//    {
//     switch (eq)
//     {
//      case Vdw:
//       delta=epsilon=0;
//       aT=omega_a[0]*(pow(R,2)*pow(Tc,2))/pc;
//       b=omega_b[0]*n;
//       Tr=1;
//       break;
//      case RK:
//       delta=1;
//       epsilon=0;
//       aT=omega_a[1]*(pow(R,2)*pow(Tc,2.5))/pc;
//       b=omega_b[1]*n;
//       Tr=pow(Treal,0.5);
//      break;
//      case SRK:
//       delta=1;
//       epsilon=0;
//       m=0.480+1.574*w-0.176*pow(w,2);
//       at=pow((1+m*(1-pow((Treal/Tc),0.5))),2);
//       aT=omega_a[1]*(pow(R,2)*pow(Tc,2))/pc*at;
//       b=omega_b[1]*n;
//       Tr=1;
//      break;
//      case PR:
//       delta=2.4142;
//       epsilon=2.4142;
//       m=0.3746+1.54226*w-0.26992*pow(w,2);
//       at=pow((1+m*(1-pow((Treal/Tc),0.5))),2);
//       aT=omega_a[2]*(pow(R,2)*pow(Tc,2))/pc*at;
//       b=omega_b[2]*n;
//       Tr=1;
//      break;
//     }
//     if(!(std::cin>>eq)){break;}
//    }
//     Vol=v0-(aT*(v0-b))/(Tr*preal*(v0+epsilon*b)*(v0+delta*b))+b;
//     error=fabs((Vol-v0)/v0);
//     while (error>0.0001)
//     {
//       v0=Vol;
//       Vol=(R*Treal)/preal-(aT*(v0-b))/(Tr*preal*(v0+epsilon*b)*(v0+delta*b))+b;
//       error=fabs((Vol-v0)/v0);
//       std::cout<<"Vol ="<<Vol<<" ,error="<<error<<std::endl;
//     }
//     return Vol;
// }
// int main()
// {
//   // double Tc=408.1,pc=3.648e6,Treal=300.0,p=3.704e5,w=0.176;
//   //  double Tc=405.6,pc=11.28e6,Treal=477.0,p=2.03e6,w=0.250,T=448.6;
//   double v=V(477.0,2.03e6,11.28e6,405.6,0.250);
//   std::cout<<v;
//   return 0;
// }
