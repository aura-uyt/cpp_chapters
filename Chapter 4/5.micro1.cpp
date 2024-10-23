#include <iostream>
using namespace std;

int main(){
    int pass1, pass2, user;
    cout<<"\n\t>>> Welcome to Password Management System <<<"<<endl;
    cout<<"Enter your Username: ";
    cin>>user;
    cout<<"Enter the Password: ";
    cin>>pass1;
    cout<<"Re-enter the Password: ";
    cin>>pass2;
    cout<<endl;
    if (pass1 == pass2)
    {
        cout<<"Congratulations, you're Username and Password has been saved.";
    }
    else{
        cout<<"ERROR: Enter the same Password in both fields.";
    }
    

    cout<<endl;
    return 0;
}