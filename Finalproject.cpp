#include <iostream>
#include <string>
using namespace std;

class EquipmentManager {
    string categories[5];
    string items[5][10]; // Fixed array size for items
    int quantities[5][10]; // Quantities for items
    int ampleThresholds[5][10]; // Ample thresholds for items
    int itemCounts[5]; // Count of items in each category

public:
    // Initialize categories and items
    EquipmentManager() {
        categories[0] = "TOOLS";
        categories[1] = "SPARES";
        categories[2] = "MEDICINES";
        categories[3] = "CONSUMABLES";
        categories[4] = "MANUALS";

        itemCounts[0] = 3;
        items[0][0] = "Mechanical Tool"; quantities[0][0] = 10; ampleThresholds[0][0] = 5;
        items[0][1] = "Electrical Tool"; quantities[0][1] = 8; ampleThresholds[0][1] = 4;
        items[0][2] = "Diagnostic Tool"; quantities[0][2] = 5; ampleThresholds[0][2] = 3;

        itemCounts[1] = 2;
        items[1][0] = "Electrical Part"; quantities[1][0] = 20; ampleThresholds[1][0] = 10;
        items[1][1] = "Mechanical Part"; quantities[1][1] = 15; ampleThresholds[1][1] = 8;

        itemCounts[2] = 2;
        items[2][0] = "Adaptation Med"; quantities[2][0] = 10; ampleThresholds[2][0] = 5;
        items[2][1] = "Environmental Med"; quantities[2][1] = 8; ampleThresholds[2][1] = 4;

        itemCounts[3] = 2;
        items[3][0] = "Food Pack"; quantities[3][0] = 30; ampleThresholds[3][0] = 15;
        items[3][1] = "Drink Pack"; quantities[3][1] = 25; ampleThresholds[3][1] = 12;

        itemCounts[4] = 2;
        items[4][0] = "Operational Manual"; quantities[4][0] = 5; ampleThresholds[4][0] = 2;
        items[4][1] = "Maintenance Manual"; quantities[4][1] = 4; ampleThresholds[4][1] = 2;
    }

    // Display categories
    void showCategories() const {
        cout << "Select a category:" << endl;
        for (int i = 0; i < 5; ++i) {
            cout << i + 1 << ". " << categories[i] << endl;
        }
    }

    // Display items in a category
    void showItems(int cat) const {
        cout << "-- " << categories[cat] << " --" << endl;
        for (int i = 0; i < itemCounts[cat]; ++i) {
            cout << i + 1 << ". " << items[cat][i] << " (Qty: " << quantities[cat][i];
            if (quantities[cat][i] >= ampleThresholds[cat][i])
                cout << " [Ample]";
            cout << ")" << endl;
        }
    }

    // Add stock
    void feedItem(int cat, int idx, int amt) {
        if (quantities[cat][idx] >= ampleThresholds[cat][idx]) {
            cout << "Notice: " << items[cat][idx] << " is already ample (" << quantities[cat][idx] << ")." << endl;
        }
        quantities[cat][idx] += amt;
        cout << "Added " << amt << " to " << items[cat][idx] << ". New qty: " << quantities[cat][idx];
        if (quantities[cat][idx] >= ampleThresholds[cat][idx])
            cout << " [Ample now]";
        cout << endl;
    }

    // Remove stock
    void dispenseItem(int cat, int idx, int amt) {
        if (quantities[cat][idx] < amt) {
            cout << "Error: only " << quantities[cat][idx] << " available for " << items[cat][idx] << "." << endl;
        } else {
            quantities[cat][idx] -= amt;
            cout << "Dispensed " << amt << " of " << items[cat][idx] << ". Remaining: " << quantities[cat][idx];
            if (quantities[cat][idx] < ampleThresholds[cat][idx])
                cout << " [Warning: low stock]";
            cout << endl;
        }
    }
};

int main() {
    EquipmentManager manager;
    manager.showCategories();
    manager.showItems(0); // Example: Display items in the first category
    manager.feedItem(0, 0, 5); // Example: Add stock to the first item in the first category
    manager.dispenseItem(0, 0, 3); // Example: Dispense stock from the first item in the first category

    return 0;
}
