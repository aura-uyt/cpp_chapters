#include<iostream>
using namespace std;

int c=55;

int main(){
    int a,b,c;
    cout<<"Enter the value of 'a' "<<endl;
    cin>>a;
    cout<<"Enter the value of 'b' "<<endl;
    cin>>b;

    c=a+b;
    cout<< "The value of 'c' is "<< c <<endl;
    cout<< "The value of GLOBAL 'c' is "<< ::c <<endl;

    return 0;
}