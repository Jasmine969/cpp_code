#include <iostream>
#include <cmath>
#include <climits>
#include <cstring>
#include <string>
#include <vector>
#include <array>
struct WW
{
     std::string name;
     float dia;
     double wei;
};
int main()
{
    using namespace std;
    WW *pin=new WW;
    cout<<"Please enter the name of Pizza's company: ";
    // getline(cin,pin->name);
    cout<<"Please enter the diameter of the Pizza: ";
    cin>>(pin->dia);
    cout<<"Please enter the weight of the Pizza: ";
    cin>>pin->wei;
    cout<<"The name of the Pizza's company is: "<<pin->name<<endl;
    cout<<"The diameter of the Pizza is: "<<pin->dia<<endl;
    cout<<"The weight of the Pizza is: "<<pin->wei<<endl;
    cin.get();

    return 0;
}