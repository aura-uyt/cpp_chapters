#include<iostream>
using namespace std;
int main(){
    float rate,amount,SI,a,b,time ;
    cout<<"Enter the Amount: ";
    cin>>amount;
    cout<<"Enter the Rate(% pa): ";
    cin>>rate;
    cout<<"Enter the Time period(in yrs.): ";
    cin>>time;

    SI=(amount*(rate+100)*time)/100;

    cout<<"Your total amount is: "<<SI;
    cout<<"\n";

    cout<<"\n";
    return 0;
}