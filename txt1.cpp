#include <iostream>
#include <string>
#include<iomanip>
using namespace std;

void inputItems(string equiment[], int quantities[], int size, string search[]){
    for (int i = 0; i < size; i++) {
        cout <<"Enter name of equiment " << i + 1 << ": ";
        cin >> equiment[i];
        cout <<"Enter quantity of " << equiment[i] << ": ";
        cin >> quantities[i];
        cout <<"Enter referenceid"<<":";
        cin >> search[i];
    }
}


void displayItems(string equiment[], int quantities[], int size,string search[]){
    cout << left << setw(15) << "Equiment Name"
         << setw(10) << "Quantities"
         << setw(15)<<" ReferenceId"<<endl;
       

    for (int i = 0; i < size; i++) {
    cout << left << setw(15) << equiment[i]
         << setw(10) << quantities[i]
         << setw(15) << search[i]<<endl;
         
    }
}

int main() {
    int n;
    string search[n];
    cout << "Enter the number of equiment:";
    cin >> n; 
    string equiment[n];
    int quantities[n];
    inputItems(equiment, quantities, n,search);
    displayItems(equiment, quantities, n,search);

    return 0;
}
