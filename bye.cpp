#include <iostream>
#include <string>
#include <vector>
#include <conio.h> 
using namespace std;

class User {
    string username;
    string password;
    long long int phone;
    string email;
    bool isCreated = false;
public:
    void create() {
        cout << "Enter Your Name:" << endl;
        cin >> username;   
        while (true) {
            cout << "Enter Phone Number: ";
            cin >> phone;
            if (to_string(phone).length() == 10) {
                break;
            } else {
                cout << "Invalid phone number! Please enter a 10-digit number." << endl;
            }
        }
        cout << "Enter Your E-Mail: ";
        cin >> email;
        cout << "Enter Password:" << endl;
        cin >> password;
        isCreated = true;
    }
    
    string getusername() { return username; }
    string getemail() { return email; }
    string getpassword() { return password; }
    long long int getphone() { return phone; }
    bool accountCreated() { return isCreated; } 
};

class ShoppingPay {
    double balance;
public:
    ShoppingPay() : balance(0) {}

    void addMoney(double amount) {
        balance += amount;
        cout << "Money added successfully. Current balance: $" << balance << endl;
    }

    bool deductMoney(double amount) {
        if (balance >= amount) {
            balance -= amount;
            cout << "Purchase successful! Amount deducted: $" << amount << endl;
            cout << "Remaining balance: $" << balance << endl;
            return true;
        } else {
            cout << "Insufficient balance. Please add more money." << endl;
            return false;
        }
    }

    double getBalance() {
        return balance;
    }
};

class Men {
public:
    void displayItems() {
        cout << "Men's Clothing:" << endl;
        cout << "1. T-Shirt" << endl;
        cout << "2. Jeans" << endl;
        cout << "3. Jacket" << endl;
    }
};

class Women {
public:
    void displayItems() {
        cout << "Women's Clothing:" << endl;
        cout << "1. Dress" << endl;
        cout << "2. Skirt" << endl;
        cout << "3. Blouse" << endl;
    }
};

class Kids {
public:
    void displayItems() {
        cout << "Kids' Clothing:" << endl;
        cout << "1. T-Shirt" << endl;
        cout << "2. Shorts" << endl;
        cout << "3. Jacket" << endl;
    }
};

class Accessories {
public:
    class Electronics {
    public:
        void displayItems() {
            cout << "Electronics Accessories:" << endl;
            cout << "1. Phone Case" << endl;
            cout << "2. Headphones" << endl;
        }
    };

    class Fashioning {
    public:
        void displayItems() {
            cout << "Fashion Accessories:" << endl;
            cout << "1. Watch" << endl;
            cout << "2. Sunglasses" << endl;
        }
    };
};

class Groceries {
public:
    class Staples {
    public:
        void displayItems() {
            cout << "Staples:" << endl;
            cout << "1. Rice" << endl;
            cout << "2. Flour" << endl;
        }
    };

    class Snacks_Beverages {
    public:
        void displayItems() {
            cout << "Snacks and Beverages:" << endl;
            cout << "1. Chips" << endl;
            cout << "2. Juice" << endl;
        }
    };
};

class Ordered {
    vector<string> orders;
    string username;
public:
    Ordered(string user) : username(user) {}

    void addOrder(string& item) {
        orders.push_back(item);
    }

    void showOrders() {
        if (orders.empty()) {
            cout << "No orders yet." << endl;
        } else {
            cout << "Order history for " << username << ":\n";
            for (const auto& order : orders) {
                cout << "- " << order << endl;
            }
        }
    }
};

class Cart {
    vector<string> items;
public:
    void addItem(const string& item) {
        items.push_back(item);
        cout << item << " added to cart." << endl;
    }

    void viewCart() const {
        if (items.empty()) {
            cout << "Cart is empty." << endl;
        } else {
            cout << "Items in cart:\n";
            for (const auto& item : items) {
                cout << "- " << item << endl;
            }
        }
    }

    bool isEmpty() const {
        return items.empty();
    }

    vector<string> checkout() {
        vector<string> purchasedItems = items;
        items.clear();
        return purchasedItems;
    }
};

int main() {
    int choice = 0, choice1 = 0, choice2 = 0, choice3 = 0, choice4 = 0;
    User u;
    ShoppingPay paySystem;
    Ordered* order = nullptr; 
    Cart cart;

    while (true) {
        cout << "1. Login" << endl;
        cout << "2. Sign Up" << endl;
        cout << "3. Exit" << endl;
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1: {
                if (!u.accountCreated()) {
                    cout << "Please Sign Up before trying to Login!" << endl;
                    break;
                }

                string username, password;
                cout << "Enter the UserName" << endl;
                cin >> username;
                cout << "Enter the Password" << endl;

                char ch;
                password.clear();
                while ((ch = _getch()) != '\r') { 
                    if (ch == '\b') {  
                        if (!password.empty()) {
                            password.pop_back();
                            cout << "\b \b"; 
                        }
                    } else {
                        password += ch;
                        cout << '*';  
                    }
                }
                cout << endl;

                if (u.getusername() == username && u.getpassword() == password) {
                    if (order == nullptr) {
                        order = new Ordered(u.getusername());
                    }

                    while (true) {
                        cout << "1. Buy" << endl;
                        cout << "2. Cart" << endl;
                        cout << "3. View Profile" << endl;
                        cout << "4. Add Money" << endl;
                        cout << "5. View Orders" << endl;
                        cout << "6. Log Out" << endl;
                        cin >> choice1;

                        switch (choice1) {
                            case 1: {
                                while (true) {
                                    cout << "1. Accessories" << endl;
                                    cout << "2. Groceries" << endl;
                                    cout << "3. Men" << endl;
                                    cout << "4. Women" << endl;
                                    cout << "5. Kids" << endl;
                                    cout << "6. Exit" << endl;
                                    cin >> choice2;
                                    switch (choice2) {
                                        case 1: {
                                            Accessories::Electronics electronics;
                                            electronics.displayItems();
                                            cart.addItem("Electronics Accessory");
                                            break;
                                        }
                                        case 2: {
                                            Groceries::Staples staples;
                                            staples.displayItems();
                                            cart.addItem("Staples");
                                            break;
                                        }
                                        case 3: {
                                            Men men;
                                            men.displayItems();
                                            cart.addItem("Men's Clothing");
                                            break;
                                        }
                                        case 4: {
                                            Women women;
                                            women.displayItems();
                                            cart.addItem("Women's Clothing");
                                            break;
                                        }
                                        case 5: {
                                            Kids kids;
                                            kids.displayItems();
                                            cart.addItem("Kids' Clothing");
                                            break;
                                        }
                                        case 6:
                                            goto exit_inner1; 
                                        default:
                                            cout << "Invalid choice!" << endl;
                                    }
                                }
                            exit_inner1:;
                            break;
                            }
                            case 2:
                                cart.viewCart();
                                if (!cart.isEmpty()) {
                                    cout << "Do you want to checkout? (1 for Yes, 2 for No): ";
                                    int checkoutChoice;
                                    cin >> checkoutChoice;
                                    if (checkoutChoice == 1) {
                                        double totalPrice = 100;  // Simplified total price for example
                                        if (paySystem.deductMoney(totalPrice)) {
                                            auto purchasedItems = cart.checkout();
                                            for (const auto& item : purchasedItems) {
                                                order->addOrder(item);
                                            }
                                            cout << "Items purchased successfully." << endl;
                                        }
                                    }
                                }
                                break;
                            case 3:
                                cout << "Your Name: " << u.getusername() << endl;
                                cout << "Your Phone: " << u.getphone() << endl;
                                cout << "Your Email: " << u.getemail() << endl;
                                break;
                            case 4:
                                double amount;
                                cout << "Enter amount to add to ShoppingPay: ";
                                cin >> amount;
                                paySystem.addMoney(amount);
                                break;
                            case 5:
                                if (order) {
                                    order->showOrders();
                                }
                                break;
                            case 6:
                                goto exit_main;
                            default:
                                cout << "Enter Valid Data!" << endl;
                        }
                    }
                } else {
                    cout << "Invalid login details!" << endl;
                }
                break;
            }
            case 2:
                u.create();
                cout << "Account Created Successfully!" << endl;
                break;
            case 3:
                if (order) delete order;  
                return 0;
            default:
                cout << "Enter Valid Data!" << endl;
        }
    }
exit_main:;
    return 0;
}
