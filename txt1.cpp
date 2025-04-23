#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Represents an item in the space feeder
struct Item {
    string name;
    int quantity;
    int ampleThreshold;
};

// Manages categories and items
class Inventory {
    vector<vector<Item>> categories;
    vector<string> categoryNames;

public:
    Inventory() {
        categoryNames = {"TOOLS","SPARES","MEDICINES","CONSUMABLES","MANUALS"};
        categories.resize(categoryNames.size());

        // Populate each category with initial stock and ample thresholds
        categories[0] = { // TOOLS
            {"Mechanical Tool", 10, 5},
            {"Electrical Tool", 8, 4},
            {"Diagnostic Tool", 5, 3},
            {"Robotic Tool", 2, 1},
            {"Emergency Tool", 3, 2},
            {"EVA Tool", 4, 2}
        };
        categories[1] = { // SPARES
            {"Electrical Part", 20, 10},
            {"Mechanical Part", 15, 8},
            {"Life Support Sys", 5, 2},
            {"Propulsion Sys", 3, 1},
            {"Comm Sys", 4, 2},
            {"Thermal Control Sys", 3, 1},
            {"Structural Component", 6, 3},
            {"Scientific Instrument", 2, 1},
            {"Miscellaneous", 10, 5}
        };
        categories[2] = { // MEDICINES
            {"Adaptation Med", 10, 5},
            {"Environmental Med", 8, 4},
            {"Psychological Med", 6, 3},
            {"Injury Med", 7, 3},
            {"Cardio/Resp Med", 5, 2},
            {"Hygiene Supplies", 12, 6}
        };
        categories[3] = { // CONSUMABLES
            {"Food Pack", 30, 15},
            {"Drink Pack", 25, 12},
            {"Supplements", 20, 10},
            {"Emergency Ration", 10, 5}
        };
        categories[4] = { // MANUALS
            {"Operational Manual", 5, 2},
            {"Maintenance Manual", 4, 2},
            {"Emergency Manual", 3, 1},
            {"Experiment Manual", 6, 3},
            {"EVA Manual", 4, 2},
            {"Training Material", 10, 5}
        };
    }

    // Display category menu
    void listCategories() const {
        cout << "Select a group of objects by number:" << endl;
        for (int i = 0; i < categoryNames.size(); ++i) {
            cout << i+1 << ". " << categoryNames[i] << endl;
        }
    }

    // Display items in chosen category
    void listItems(int cat) const {
        cout << "-- " << categoryNames[cat] << " --" << endl;
        for (int i = 0; i < categories[cat].size(); ++i) {
            const Item& it = categories[cat][i];
            cout << i+1 << ". " << it.name
                 << " (Qty: " << it.quantity;
            if (it.quantity >= it.ampleThreshold)
                cout << " [Ample]";
            cout << ")" << endl;
        }
    }

    // Dispense requested amount and alert if low
    void dispense(int cat, int idx, int amt) {
        if (idx < 0 || idx >= categories[cat].size()) {
            cout << "Invalid item selection." << endl;
            return;
        }
        Item& it = categories[cat][idx];
        if (it.quantity >= amt) {
            it.quantity -= amt;
            cout << "Dispensed " << amt << " of " << it.name
                 << ". Remaining: " << it.quantity << endl;
            if (it.quantity < it.ampleThreshold) {
                cout << "Alert: " << it.name << " stock is low!" << endl;
            }
        } else {
            cout << "Error: Only " << it.quantity << " available." << endl;
        }
    }
};

int main() {
    Inventory inv;
    cout << "=== ISRO Space Vending Feeder ===" << endl;

    inv.listCategories();
    int catChoice;
    cin >> catChoice;
    if (catChoice < 1 || catChoice > 5) {
        cout << "Invalid category. Exiting." << endl;
        return 0;
    }

    int cat = catChoice - 1;
    inv.listItems(cat);

    cout << "Enter item number to dispense: ";
    int itemNum;
    cin >> itemNum;

    cout << "Enter quantity to dispense: ";
    int qty;
    cin >> qty;

    inv.dispense(cat, itemNum - 1, qty);
    cout << "Shutting down feeder. Goodbye!" << endl;
    return 0;
}
