#include <iostream>
#include <string>
using namespace std;

class Dispenser {
public:
    string object_name;
    int input;
    
    int initial() {
        int N;
        cout << "Select group of objects by number:" << endl;
        cout << "1. TOOLS" << endl;
        cout << "2. SPARES" << endl;
        cout << "3. MEDICINES" << endl;
        cout << "4. CONSUMEABLES" << endl;
        cout << "5. MANNUALS" << endl;
        cin >> N;
        return N;
    }
    
    int dispense() {
        cout << "Enter the name of the required object:" << endl;
        cin >> object_name;
        cout << "Enter the number of objects required:" << endl;
        cin >> input;
        return input;
    }
};

class TOOLS {
public:
    int n;
    int tool() {
        cout << "Which tool do you want:" << endl;
        cout << "11. Mechanical" << endl;
        cout << "12. Electrical" << endl;
        cout << "13. Diagnostic Tools" << endl;
        cout << "14. Robotic Tools" << endl;
        cout << "15. Emergency Tools" << endl;
        cout << "16. Extravehicular Activity (EVA) Tools" << endl;
        cin >> n;
        return n;
    }
};

class SPARES {
public:
    int n;
    int spares() {
        cout << "Which component do you want:" << endl;
        cout << "21. Electrical parts" << endl;
        cout << "22. Mechanical Parts" << endl;
        cout << "23. Life Support Systems" << endl;
        cout << "24. Propulsion Systems" << endl;
        cout << "25. Communication Systems" << endl;
        cout << "26. Thermal Control Systems" << endl;
        cout << "27. Structural Components" << endl;
        cout << "28. Scientific Instruments" << endl;
        cout << "29. Miscellaneous" << endl;
        cin >> n;
        return n;
    }
};

class MEDICINES {
public:
    int n;
    int medicine() {
        cout << "Which ailment's medicine do you want:" << endl;
        cout << "31. Physical Adaptation Ailments" << endl;
        cout << "32. Environmental Ailments" << endl;
        cout << "33. Psychological Ailments" << endl;
        cout << "34. Infectious or Minor Injuries" << endl;
        cout << "35. Cardiovascular and Respiratory Issues" << endl;
        cout << "36. Hygiene Requirements" << endl;
        cin >> n;
        return n;
    }
};

class CONSUMEABLES {
public:
    int n;
    int consumeables() {
        cout << "What do you want for consuming:" << endl;
        cout << "41. Food" << endl;
        cout << "42. Drinks" << endl;
        cout << "43. Supplements" << endl;
        cout << "44. Emergency Rations" << endl;
        cin >> n;
        return n;
    }
};

class MANNUALS {
public:
    int n;
    int mannuals() {
        cout << "Which manuals do you want:" << endl;
        cout << "51. Operational Manuals" << endl;
        cout << "52. Maintenance Manuals" << endl;
        cout << "53. Emergency Manuals" << endl;
        cout << "54. Scientific Experiment Manuals" << endl;
        cout << "55. Extravehicular Activity (EVA) Manuals" << endl;
        cout << "56. Training and Reference Materials" << endl;
        cin >> n;
        return n;
    }
};

int main() {
    Dispenser disp;
    int choice = disp.initial();
    
    switch(choice) {
        case 1: {
            TOOLS toolMenu;
            int toolChoice = toolMenu.tool();
            cout << "You selected tool option: " << toolChoice << endl;
            cout << "Your item will be dispensed out shortly"<<endl;
            break;
        }
        case 2: {
            SPARES spareMenu;
            int spareChoice = spareMenu.spares();
            cout << "You selected spares option: " << spareChoice << endl;
            cout << "Your item will be dispensed out shortly"<<endl;
            break;
        }
        case 3: {
            MEDICINES medMenu;
            int medChoice = medMenu.medicine();
            cout << "You selected medicines option: " << medChoice << endl;
            cout << "Your item will be dispensed out shortly"<<endl;
            break;
        }
        case 4: {
            CONSUMEABLES consMenu;
            int consChoice = consMenu.consumeables();
            cout << "You selected consumeables option: " << consChoice << endl;
            cout << "Your item will be dispensed out shortly"<<endl;
            break;
        }
        case 5: {
            MANNUALS manualMenu;
            int manualChoice = manualMenu.mannuals();
            cout << "You selected manuals option: " << manualChoice << endl;
            cout << "Your item will be dispensed out shortly"<<endl;
            break;
        }
        default:
            cout << "Invalid choice. Please run the program again and select a valid option." << endl;
            break;
    }
    
    return 0;
}
