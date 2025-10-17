🚀 Space Station Vending Machine – Embedded Equipment Manager
📘 Overview

This project simulates the inventory management logic of an embedded vending system designed for space stations.
It efficiently tracks, replenishes, and dispenses items (such as tools, medicines, and consumables) — ensuring astronauts always have critical supplies available with proper stock alerts.

This is a C++ simulation prototype representing the core logic that would be integrated into a real embedded hardware system.

🧩 Features

✅ Categorizes items into five key types:

Tools

Spares

Medicines

Consumables

Manuals

✅ Monitors and displays quantity levels of each item
✅ Displays “Ample” status when stock is sufficient
✅ Displays “Low stock warning” when inventory drops below safe threshold
✅ Allows feeding (adding) and dispensing (removing) stock items
✅ Can easily be extended to integrate with sensors, RFID, or display modules in an actual embedded system

🧠 How It Works

The system maintains arrays for:

Categories

Item names

Quantities

Ample thresholds

Each category contains multiple items with predefined starting quantities and safety thresholds.

Example:

Mechanical Tool → Quantity: 10, Ample Threshold: 5

Electrical Tool → Quantity: 8, Ample Threshold: 4

If an item’s stock falls below its threshold, the program warns:

[Warning: low stock]

🧮 Code Summary
Main Components

EquipmentManager Class
Handles all data and operations for managing stock.

Key Methods
Method	Description
showCategories()	Displays all available item categories
showItems(int cat)	Displays items in a specific category with quantity info
feedItem(int cat, int idx, int amt)	Adds stock to an item
dispenseItem(int cat, int idx, int amt)	Removes stock from an item, with low-stock alert
💻 Example Run

Output Example:

Select a category:
1. TOOLS
2. SPARES
3. MEDICINES
4. CONSUMABLES
5. MANUALS

-- TOOLS --
1. Mechanical Tool (Qty: 10 [Ample])
2. Electrical Tool (Qty: 8 [Ample])
3. Diagnostic Tool (Qty: 5 [Ample])

Added 5 to Mechanical Tool. New qty: 15 [Ample now]
Dispensed 3 of Mechanical Tool. Remaining: 12 [Ample]

⚙️ Compilation & Execution
Using g++
g++ equipment_manager.cpp -o vending_system
./vending_system

Using any C++ IDE

Open the file in Code::Blocks, VS Code, or Dev-C++

Compile and run the project normally.

🔩 Embedded System Context

This logic can serve as the software backend of a space station vending/dispensing system.
In a real embedded setup, this C++ code would be connected to:

Microcontrollers (e.g., STM32 / Arduino / ESP32)

RFID or biometric authentication modules

LCD / OLED display screens

Motors / actuators for dispensing items

Example Integration Flow:
Astronaut selects → Category → Item  
↓  
Microcontroller checks stock (via this logic)  
↓  
If ample → Dispense command sent → Motor activates  
↓  
Quantity updates in EEPROM or cloud storage

🧾 Future Enhancements

🔹 Integration with IoT dashboards for live inventory monitoring

🔹 Automatic low-stock alerts to mission control

🔹 Support for floating-point quantities (for liquids, gases, etc.)

🔹 File-based or EEPROM-based persistent storage

🔹 Add security layers for controlled item access


