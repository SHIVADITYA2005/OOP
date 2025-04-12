#include <iostream>
#include <string>
using namespace std;
class Dispenser{
    string object_name;
    int input;
    int initial (){
        cout <<"select group of objects"<<endl;
        cout <<"TOOLS"<<endl;
        cout <<"SPARES"<<endl;
        cout <<"MEDICINES"<<endl;
        cout <<"CONSUMEABLES"<<endl;
    }
    int dispense() {
        cout<<"Enter the name of required object"<<endl;
        cin>>object_name;
        cout<<"Enter the number of objects required"<<endl;
        cin>>input;
    }
};