#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Represents an item in the space vending feeder/dispenser
struct Item {
    string name;
    int quantity;
    int ampleThreshold;
};

class Dispenser {
    vector<vector<Item>> categories;
    vector<string> categoryNames;

public:
    Dispenser() {
        categoryNames = {"TOOLS","SPARES","MEDICINES","CONSUMABLES","MANUALS"};
        categories.resize(categoryNames.size());

        // Initialize categories
        categories[0] = { {"Mechanical Tool",10,5}, {"Electrical Tool",8,4}, {"Diagnostic Tool",5,3}, {"Robotic Tool",2,1}, {"Emergency Tool",3,2}, {"EVA Tool",4,2} };
        categories[1] = { {"Electrical Part",20,10}, {"Mechanical Part",15,8}, {"Life Support System",5,2}, {"Propulsion System",3,1}, {"Communication System",4,2}, {"Thermal Control System",3,1}, {"Structural Component",6,3}, {"Scientific Instrument",2,1}, {"Miscellaneous",10,5} };
        categories[2] = { {"Adaptation Med",10,5}, {"Environmental Med",8,4}, {"Psychological Med",6,3}, {"Injury Med",7,3}, {"Cardio/Resp Med",5,2}, {"Hygiene Supply",12,6} };
        categories[3] = { {"Food Pack",30,15}, {"Drink Pack",25,12}, {"Supplement",20,10}, {"Emergency Ration",10,5} };
        categories[4] = { {"Operational Manual",5,2}, {"Maintenance Manual",4,2}, {"Emergency Manual",3,1}, {"Experiment Manual",6,3}, {"EVA Manual",4,2}, {"Training Material",10,5} };
    }

    // Show main category menu
    void showCategories() const {
        cout << "Select a category by number:" << endl;
        for (int i = 0; i < categoryNames.size(); ++i) {
            cout << i+1 << ". " << categoryNames[i] << endl;
        }
    }

    // Show items in chosen category
    void showItems(int cat) const {
        cout << "-- " << categoryNames[cat] << " --" << endl;
        for (int i = 0; i < categories[cat].size(); ++i) {
            const Item& it = categories[cat][i];
            cout << i+1 << ". " << it.name << " (Qty: " << it.quantity;
            if (it.quantity >= it.ampleThreshold)
                cout << " [Ample]";
            cout << ")" << endl;
        }
    }

    // Dispense selected item
    void dispenseItem(int cat, int idx, int amt) {
        if (idx < 0 || idx >= categories[cat].size()) {
            cout << "Invalid item selection." << endl;
            return;
        }
        Item& it = categories[cat][idx];
        if (it.quantity >= amt) {
            it.quantity -= amt;
            cout << "Dispensed " << amt << " x " << it.name << ". Remaining: " << it.quantity << endl;
            if (it.quantity < it.ampleThreshold) {
                cout << "Alert: " << it.name << " stock is low!" << endl;
            }
        } else {
            cout << "Error: Only " << it.quantity << " available." << endl;
        }
    }
};

int main() {
    Dispenser disp;
    cout << "=== ISRO Space Vending Feeder & Dispenser ===" << endl;

    disp.showCategories();
    int categoryChoice;
    cin >> categoryChoice;
    if (categoryChoice < 1 || categoryChoice > disp.categoryNames.size()) {
        cout << "Invalid category. Exiting." << endl;
        return 0;
    }

    int catIndex = categoryChoice - 1;
    disp.showItems(catIndex);

    cout << "Enter item number to dispense: ";
    int itemChoice;
    cin >> itemChoice;

    cout << "Enter quantity to dispense: ";
    int quantity;
    cin >> quantity;

    disp.dispenseItem(catIndex, itemChoice - 1, quantity);
    cout << "Shutdown complete. Have a safe mission!" << endl;
    return 0;
}
