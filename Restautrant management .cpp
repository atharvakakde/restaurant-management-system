#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <cstdlib>
using namespace std;

// Base class for menu items
class MenuItem {
protected:
    int id;
    string name;
    float price;

public:
    MenuItem(int id, string name, float price)
        : id(id), name(name), price(price) {}

    virtual void display() const {
        cout << left << setw(5) << id << setw(20) << name << "Rs. "
             << fixed << setprecision(2) << price << endl;
    }

    virtual float getPrice() const { return price; }
    virtual int getId() const { return id; }
    string getName() const { return name; }

    virtual ~MenuItem() {}
};

// Derived class for special items
class SpecialItem : public MenuItem {
    string specialNote;

public:
    SpecialItem(int id, string name, float price, string note)
        : MenuItem(id, name, price), specialNote(note) {}

    void display() const {
        cout << left << setw(5) << id << setw(20) << name << "Rs. "
             << fixed << setprecision(2) << price
             << "  (" << specialNote << ")" << endl;
    }
};

// Restaurant class managing menu and ordering
class Restaurant {
    vector<MenuItem*> menu;

public:
    ~Restaurant() {
        for (size_t i = 0; i < menu.size(); i++) {
            delete menu[i];
        }
    }

    void addItem(MenuItem* item) {
        menu.push_back(item);
    }

    void showMenu() const {
        cout << "\n================= RESTAURANT MENU =================\n";

        showSection("--- Snacks ---", 1, 5);
        showSection("--- Main Course ---", 6, 13);
        showSection("--- Sides ---", 14, 17);
        showSection("--- Desserts ---", 18, 20);
        showSection("--- Breads ---", 21, 22);

        cout << "==================================================\n";
    }

    const MenuItem* getItem(int id) const {
        for (size_t i = 0; i < menu.size(); i++) {
            if (menu[i]->getId() == id)
                return menu[i];
        }
        return NULL;
    }

private:
    void showSection(const string& title, int startId, int endId) const {
        cout << "\n" << title << "\n";
        for (size_t i = 0; i < menu.size(); i++) {
            if (menu[i]->getId() >= startId && menu[i]->getId() <= endId)
                menu[i]->display();
        }
    }
};

// Employee Management
class Employee {
public:
    string name;
    string role;
    int id;

    Employee(int id, string name, string role) : id(id), name(name), role(role) {}

    void display() const {
        cout << left << setw(5) << id << setw(20) << name << setw(15) << role << endl;
    }
};

class StaffManagement {
    vector<Employee> employees;
    int nextId;

public:
    StaffManagement() : nextId(1) {}

    void addEmployee(const string& name, const string& role) {
        employees.push_back(Employee(nextId++, name, role));
        cout << "Employee added successfully!\n";
    }

    void viewEmployees() const {
        cout << "\n============= STAFF LIST =============\n";
        cout << left << setw(5) << "ID" << setw(20) << "Name" << setw(15) << "Role" << endl;
        for (size_t i = 0; i < employees.size(); i++) {
            employees[i].display();
        }
        cout << "=======================================\n";
    }
};

// Reservation Management
class Reservation {
public:
    string customerName;
    int tableNumber;
    string time;

    Reservation(string name, int table, string time)
        : customerName(name), tableNumber(table), time(time) {}

    void display() const {
        cout << left << setw(20) << customerName << setw(10) << tableNumber << setw(10) << time << endl;
    }
};

class ReservationSystem {
    vector<Reservation> reservations;

public:
    void addReservation(const string& name, int table, const string& time) {
        reservations.push_back(Reservation(name, table, time));
        cout << "Reservation added successfully!\n";
    }

    void viewReservations() const {
        cout << "\n============= RESERVATIONS =============\n";
        cout << left << setw(20) << "Customer" << setw(10) << "Table" << setw(10) << "Time" << endl;
        for (size_t i = 0; i < reservations.size(); i++) {
            reservations[i].display();
        }
        cout << "=======================================\n";
    }
};

// Raw Material Management
class RawMaterial {
public:
    string name;
    int quantity;
    string supplier;

    RawMaterial(string n, int q, string s) : name(n), quantity(q), supplier(s) {}

    void display() const {
        cout << left << setw(20) << name << setw(10) << quantity << setw(20) << supplier << endl;
    }
};

class RawMaterialSystem {
    vector<RawMaterial> materials;

public:
    void addMaterial(const string& name, int quantity, const string& supplier) {
        materials.push_back(RawMaterial(name, quantity, supplier));
        cout << "Raw material added successfully!\n";
    }

    void viewMaterials() const {
        cout << "\n============= RAW MATERIALS =============\n";
        cout << left << setw(20) << "Material" << setw(10) << "Quantity" << setw(20) << "Supplier" << endl;
        for (size_t i = 0; i < materials.size(); i++) {
            materials[i].display();
        }
        cout << "==========================================\n";
    }
};

// Order details structure
struct OrderDetail {
    string itemName;
    float price;
    int quantity;
};

int main() {
    Restaurant r;
    StaffManagement staff;
    ReservationSystem resSystem;
    RawMaterialSystem rawSystem;

    string password = "admin123";

    int mode;
    cout << "Welcome to the Restaurant System!\n";
    cout << "1. Customer Side\n";
    cout << "2. Staff Side\n";
    cout << "Enter your choice: ";
    cin >> mode;

    if (mode == 1) {
        // Customer Side - Initialize menu

        // Snacks
        r.addItem(new MenuItem(1, "Vada Pav", 20.0));
        r.addItem(new MenuItem(2, "Misal Pav", 50.0));
        r.addItem(new MenuItem(3, "Poha", 30.0));
        r.addItem(new MenuItem(4, "Kanda Bhaji", 35.0));
        r.addItem(new MenuItem(5, "Sabudana Vada", 45.0));

        // Main Course
        r.addItem(new MenuItem(6, "Zunka Bhakri", 60.0));
        r.addItem(new MenuItem(7, "Pithla Bhakri", 55.0));
        r.addItem(new MenuItem(8, "Bharli Vangi", 75.0));
        r.addItem(new MenuItem(9, "Kolambi Bhaat", 120.0));
        r.addItem(new MenuItem(10, "Chicken Sukka", 150.0));
        r.addItem(new MenuItem(11, "Mutton Rassa", 180.0));
        r.addItem(new MenuItem(12, "Tambda Rassa", 160.0));
        r.addItem(new MenuItem(13, "Pandhra Rassa", 150.0));

        // Sides
        r.addItem(new MenuItem(14, "Usal", 45.0));
        r.addItem(new MenuItem(15, "Batata Bhaji", 35.0));
        r.addItem(new MenuItem(16, "Amti Dal", 40.0));
        r.addItem(new MenuItem(17, "Kothimbir Vadi", 40.0));

        // Desserts
        r.addItem(new MenuItem(18, "Shrikhand", 70.0));
        r.addItem(new MenuItem(19, "Puran Poli", 40.0));
        r.addItem(new MenuItem(20, "Basundi", 65.0));

        // Breads
        r.addItem(new MenuItem(21, "Bhakri", 20.0));
        r.addItem(new MenuItem(22, "Chapati", 15.0));

        int choice, quantity;
        char moreOrder;
        float total = 0;

        vector<OrderDetail> orderDetails;

        do {
            r.showMenu();

            cout << "Enter the ID of the item you want to order: ";
            cin >> choice;
            cout << "Enter quantity: ";
            cin >> quantity;

            const MenuItem* item = r.getItem(choice);
            if (item) {
                float itemTotal = item->getPrice() * quantity;
                total += itemTotal;
                
                OrderDetail od;
                od.itemName = item->getName();
                od.price = item->getPrice();
                od.quantity = quantity;
                orderDetails.push_back(od);

                cout << "Added to bill: Rs. " << fixed << setprecision(2)
                     << item->getPrice() << " x " << quantity
                     << " = Rs. " << itemTotal << endl;
            } else {
                cout << "Invalid choice! Please try again.\n";
            }

            cout << "Do you want to order more? (y/n): ";
            cin >> moreOrder;

        } while (moreOrder == 'y' || moreOrder == 'Y');

        cout << "\n****************************************\n";
        cout << "*            FINAL BILL                *\n";
        cout << "****************************************\n";
        for (size_t i = 0; i < orderDetails.size(); i++) {
            cout << left << setw(30) << orderDetails[i].itemName
                 << orderDetails[i].quantity << " x Rs. " << fixed << setprecision(2)
                 << orderDetails[i].price << " = Rs. " 
                 << orderDetails[i].price * orderDetails[i].quantity << endl;
        }
        cout << left << setw(30) << "Total Amount" << ": Rs. " 
             << fixed << setprecision(2) << total << endl;
        cout << "****************************************\n";
        cout << "Thank you for dining with us! Have a great day!\n";

    } else if (mode == 2) {
        string pass;
        cout << "Enter Staff Password: ";
        cin >> pass;

        if (pass == password) {
            int staffChoice;
            do {
                cout << "\n==== Staff Management Menu ====\n";
                cout << "1. Add Employee\n";
                cout << "2. View Employees\n";
                cout << "3. Add Reservation\n";
                cout << "4. View Reservations\n";
                cout << "5. Add Raw Material\n";
                cout << "6. View Raw Materials\n";
                cout << "7. Exit\n";
                cout << "Enter your choice: ";
                cin >> staffChoice;

                if (staffChoice == 1) {
                    string name, role;
                    cout << "Enter Employee Name: ";
                    cin.ignore();
                    getline(cin, name);
                    cout << "Enter Role (e.g., Chef, Manager): ";
                    getline(cin, role);
                    staff.addEmployee(name, role);
                } else if (staffChoice == 2) {
                    staff.viewEmployees();
                } else if (staffChoice == 3) {
                    string name, time;
                    int table;
                    cout << "Enter Customer Name: ";
                    cin.ignore();
                    getline(cin, name);
                    cout << "Enter Table Number: ";
                    cin >> table;
                    cout << "Enter Time (e.g., 7PM): ";
                    cin.ignore();
                    getline(cin, time);
                    resSystem.addReservation(name, table, time);
                } else if (staffChoice == 4) {
                    resSystem.viewReservations();
                } else if (staffChoice == 5) {
                    string material, supplier;
                    int quantity;
                    cout << "Enter Raw Material Name: ";
                    cin.ignore();
                    getline(cin, material);
                    cout << "Enter Quantity: ";
                    cin >> quantity;
                    cout << "Enter Supplier Name: ";
                    cin.ignore();
                    getline(cin, supplier);
                    rawSystem.addMaterial(material, quantity, supplier);
                } else if (staffChoice == 6) {
                    rawSystem.viewMaterials();
                }
            } while (staffChoice != 7);
        } else {
            cout << "Incorrect Password! Access Denied.\n";
        }
    } else {
        cout << "Invalid option selected. Exiting.\n";
    }

    return 0;
}
