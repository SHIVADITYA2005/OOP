#include <iostream>
#include <string>
using namespace std;
class Equipment
{
public:
    string name;
    int quantity;
    string referenceId;
};
void inputEquipment(Equipment &eq) 
{
    cout << "Enter item name: ";
    cin >> eq.name;
    cout << "Enter quantity: ";
    cin >> eq.quantity;
    cout << "Enter reference ID: ";
    cin >> eq.referenceId;
}
void addQuantity(Equipment &eq) 
{
    int amount;
    cout << "Enter quantities to add (enter 0 to stop):\n";
    while(true) 
    {
        cout << "Enter amount to add: ";
        cin >> amount;
        if (amount == 0) 
        {
            break; 
        }
        if (amount > 0) 
        {
            eq.quantity += amount;
            cout << "Added " << amount << " to " << eq.name << ". New quantity: " << eq.quantity << endl;
        }
        else 
        {
            cout << "Invalid amount. Please enter a positive number." << endl;
        }
    }
}
void decreaseQuantity(Equipment &eq) 
{
    int amount;
    cout << "Enter quantities to remove (enter 0 to stop):\n";
    while(true)
    {
        cout << "Enter amount to remove: ";
        cin >> amount;
        if(amount == 0) 
        {
            break; 
        }
        if(amount > 0) 
        {
            if(eq.quantity >= amount) 
            {
                eq.quantity -= amount;
                cout << "Removed " << amount << " from " << eq.name << ". New quantity: " << eq.quantity << endl;
            }
            else 
            {
                cout << "Error: Cannot remove more than available quantity. Current quantity: " << eq.quantity << endl;
            }
        }
        else
        {
            cout << "Invalid amount. Please enter a positive number." << endl;
        }
    }
}
void compareEquipment(const Equipment &eq1, const Equipment &eq2)
{
    cout << "--- Comparison Results ---\n";
    if (eq1.name != eq2.name)
        cout << "Names are different: " << eq1.name << " vs " << eq2.name << endl;
    else
        cout << "Names are the same: " << eq1.name << endl;
    if(eq1.quantity != eq2.quantity)
        cout << "Quantities are different: " << eq1.quantity << " vs " << eq2.quantity << endl;
    else
        cout << "Quantities are the same: " << eq1.quantity << endl;
    if(eq1.referenceId != eq2.referenceId)
        cout << "Reference IDs are different: " << eq1.referenceId << " vs " << eq2.referenceId << endl;
    else
        cout << "Reference IDs are the same: " << eq1.referenceId << endl;
}
int main() 
{
    Equipment eq1, eq2;
    int choice;
    cout << "Enter details for Equipment 1:\n";
    inputEquipment(eq1);
    cout << "Enter details for Equipment 2:\n";
    inputEquipment(eq2);
    do {
        cout << "Menu:\n";
        cout << "1. Compare equipment\n";
        cout << "2. Add quantity to Equipment 1\n";
        cout << "3. Decrease quantity from Equipment 1\n";
        cout << "4. Add quantity to Equipment 2\n";
        cout << "5. Decrease quantity from Equipment 2\n";
        cout << "6. Exit\n";
        cout << "Enter choice (1-6): ";
        cin >> choice;
        switch(choice) 
        {
            case 1:
                compareEquipment(eq1, eq2);
                break;
            case 2:
                addQuantity(eq1);
                break;
            case 3:
                decreaseQuantity(eq1);
                break;
            case 4:
                addQuantity(eq2);
                break;
            case 5:
                decreaseQuantity(eq2);
                break;
            case 6:
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } 
    while (choice != 6);
    return 0;
}
