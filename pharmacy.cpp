#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

struct Pharmacy
{
    char id;
    string medName;
    int quantity;
    int price;
};
void viewMedicine()
{
    ifstream read("medFile.txt");
    if (!read)
    {
        cout << "Error opening file!" << endl;
        exit(1);
    }

    Pharmacy phar;
    while (read >> phar.id)
    {
        read.ignore();
        getline(read, phar.medName);
        read >> phar.quantity;
        read >> phar.price;

        cout << "ID: " << phar.id << endl;
        cout << "Medicine Name: " << phar.medName << endl;
        cout << "Quantity: " << phar.quantity << endl;
        cout << "Price: " << phar.price << endl;
        cout << endl;
    }

    read.close();
}
void updateMedicine()
{
    string s;
    cout << "Enter a name to update the Medicine" << endl;
    cin.ignore();
    getline(cin, s);
    Pharmacy phar;
    ifstream read;
    ofstream write;

    read.open("medFile.txt", ios::in);
    write.open("tempFile.txt", ios::out);

    if (!read || !write)
    {
        cout << "File could not be opened";
        exit(1);
    }

    bool medicineFound = false;

    while (read >> phar.id)
    {
        read.ignore();
        getline(read, phar.medName);
        read >> phar.quantity;
        read >> phar.price;

        if (s == phar.medName)
        {
            medicineFound = true;
            cout << "Update Medicine ID: ";
            cin >> phar.id;
            cout << "Update Medicine Name: ";
            cin.ignore();
            getline(cin, phar.medName);
            cout << "Update Medicine Quantity: ";
            cin >> phar.quantity;
            cout << "Update Medicine Price: ";
            cin >> phar.price;
        }

        write << phar.id << endl;
        write << phar.medName << endl;
        write << phar.quantity << endl;
        write << phar.price << endl;
    }

    read.close();
    write.close();

    if (!medicineFound)
    {
        cout << "Medicine not found!" << endl;
        remove("tempFile.txt");
        return;
    }

    remove("medFile.txt");
    rename("tempFile.txt", "medFile.txt");

    cout << "Medicine updated successfully!" << endl;
}
void addMedicine()
{
    int choice;
    do
    {
        Pharmacy phar;
        cout << "id :", cin >> phar.id;
        cin.ignore();
        cout << "medName :", getline(cin, phar.medName);
        cout << endl;
        cout << "quantity :", cin >> phar.quantity;
        cout << endl;
        cout << " price :", cin >> phar.price;
        cout << endl;
        ofstream write;
        write.open("medFile.txt", ios::app);
        write << phar.id << endl;
        write << phar.medName << endl;
        write << phar.quantity << endl;
        write << phar.price << endl;
        cout << " medicine have saved" << endl;
        cout << "enter '0' for exit or '1' for continue  " << endl;
        cin >> choice;
        write.close();

    } while (choice != 0);
}
void deleteMedicine()
{
    string s;
    cout << "Enter a name to delete the Medicine" << endl;
    cin.ignore();
    getline(cin, s);
    Pharmacy phar;
    ifstream read;
    read.open("medFile.txt");
    ofstream temfile;
    temfile.open("temFile.txt");
    if (!read || !temfile)
    {
        cout << "File could not be opened";
        exit(1);
    }
    bool medicineFound = false;
    while (read >> phar.id)
    {
        read.ignore();
        getline(read, phar.medName);
        read >> phar.quantity;
        read >> phar.price;

        if (s != phar.medName)
        {
            medicineFound = true;
            temfile << phar.id << endl;
            temfile << phar.medName << endl;
            temfile << phar.quantity << endl;
            temfile << phar.price << endl;
        }
    }
    read.close();
    temfile.close();

    if (!medicineFound)
    {
        cout << "Medicine not found!" << endl;
        remove("tempFile.txt");
        return;
    }

    remove("medFile.txt");
    rename("tempFile.txt", "medFile.txt");

    cout << "Medicine updated successfully!" << endl;
}
void searchMedicine()
{
    string s;
    cout << "Enter a name to search the Medicine" << endl;
    cin.ignore();
    getline(cin, s);
    Pharmacy phar;
    ifstream read;
    read.open("medFile.txt", ios::in);
    if (!read)
    {
        cout << "File could not be opened";
        exit(1);
    }

    bool medicineFound = false;
    while (read >> phar.id)
    {
        read.ignore();
        getline(read, phar.medName);
        read >> phar.quantity;
        read >> phar.price;

        if (s == phar.medName)
        {
            cout << "   MedicineID :  " << phar.id << endl;
            cout << "   MedicineName :  " << phar.medName << endl;
            cout << "   MedicineQuantity : " << phar.quantity << endl;
            cout << "   MedicinePrice :  " << phar.price << endl;
            medicineFound = true;
        }
    }

    read.close();

    if (!medicineFound)
    {
        cout << "Medicine not found!" << endl;
    }
}
void purchaseMedicine()
{
    string customerName;
    cout << "Enter your Name again: ";
    cin.ignore();
    getline(cin, customerName);

    string currentDate;
    cout << "Enter date: ";
    getline(cin, currentDate);

    string s;
    cout << "Enter the name of the medicine you want to purchase: ";
    getline(cin, s);
    int quantityToPurchase;
    cout << "Enter the quantity you want to purchase: ";
    cin >> quantityToPurchase;

    Pharmacy phar;
    ifstream read;
    read.open("medFile.txt");
    ofstream tempFile;
    tempFile.open("tempFile.txt");
    ofstream historyFile;
    historyFile.open("historyFile.txt", ios::app);
    if (!read || !tempFile || !historyFile)
    {
        cout << "File could not be opened";
        exit(1);
    }

    bool medicineFound = false;
    float totalPrice = 0;

    while (read >> phar.id)
    {
        read.ignore();
        getline(read, phar.medName);
        read >> phar.quantity;
        read >> phar.price;

        if (s == phar.medName)
        {
            if (phar.quantity >= quantityToPurchase)
            {
                medicineFound = true;
                phar.quantity -= quantityToPurchase;
                totalPrice = phar.price * quantityToPurchase;

                // Write purchase history to file
                historyFile << "Customer Name: " << customerName << endl;
                historyFile << "Date: " << currentDate << endl;
                historyFile << "Medicine Name: " << phar.medName << endl;
                historyFile << "Quantity Purchased: " << quantityToPurchase << endl;
                historyFile << "Total Price: $" << totalPrice << endl;
                historyFile << "---------------------------" << endl;
            }
            else
            {
                cout << "Insufficient quantity available. Purchase failed." << endl;
                tempFile << phar.id << endl;
                tempFile << phar.medName << endl;
                tempFile << phar.quantity << endl;
                tempFile << phar.price << endl;
            }
        }

        tempFile << phar.id << endl;
        tempFile << phar.medName << endl;
        tempFile << phar.quantity << endl;
        tempFile << phar.price << endl;
    }

    read.close();
    tempFile.close();

    remove("medFile.txt");
    rename("tempFile.txt", "medFile.txt");

    if (medicineFound)
    {
        cout << "Purchase successful. " << endl;
        cout << "Total price:" << totalPrice << " Rupees" << endl;
        cout << "Please pay the amount." << endl;
    }
    else
    {
        cout << "Medicine not found. Purchase failed." << endl;
    }
}
void purchaseRecord()
{
    string date;
    cout << "Enter the date (DD/MM/YYYY): ";
    cin.ignore();
    getline(cin, date);

    ifstream historyFile;
    historyFile.open("historyFile.txt");

    if (!historyFile)
    {
        cout << "File could not be opened";
        exit(1);
    }

    string line;
    bool purchaseFound = false;
    string previousLine;
    float grandTotal = 0;

    while (getline(historyFile, line))
    {
        if (line.find("Date: " + date) != string::npos)
        {
            purchaseFound = true;
            cout << previousLine << endl; // Print the previous line (customer name)
            cout << line << endl;         // Print the current line (date)
            for (int i = 0; i < 4; i++)
            {
                getline(historyFile, line);
                cout << line << endl; // Print the next three lines (medicine name, quantity purchased, total price)
            }
            cout << "---------------------------" << endl;

            // Extract total price from the line
            size_t pricePos = line.find("Total Price: $");
            string priceStr = line.substr(pricePos + 14);
            float price = stof(priceStr);
            grandTotal += price;
        }

        previousLine = line; // Store the current line as the previous line for the next iteration
    }

    historyFile.close();

    if (!purchaseFound)
    {
        cout << "No purchase history found for date: " << date << endl;
    }
    else
    {
        cout << "Grand Total: " << grandTotal << " Rupees" << endl;
    }
}
void showCustomers()
{
    ifstream read;
    read.open("customers.txt");

    if (!read)
    {
        cout << "File could not be opened";
        exit(1);
    }

    string line;
    while (getline(read, line))
    {
        stringstream ss(line);
        string name, password;

        getline(ss, name, ',');
        getline(ss, password);

        cout << "Name: " << name << ", Password: " << password << endl;
    }

    read.close();
}
void orderHistory()
{
    string customerName;
    cout << "Enter your name: ";
    cin.ignore();
    getline(cin, customerName);

    ifstream historyFile;
    historyFile.open("historyFile.txt");

    if (!historyFile)
    {
        cout << "File could not be opened";
        exit(1);
    }

    string line;
    bool purchaseFound = false;

    while (getline(historyFile, line))
    {
        if (line.find("Customer Name: " + customerName) != string::npos)
        {
            purchaseFound = true;
            cout << line << endl;
            for (int i = 0; i < 5; i++)
            {
                getline(historyFile, line);
                cout << line << endl;
            }
            cout << "---------------------------" << endl;
        }
    }

    historyFile.close();

    if (!purchaseFound)
    {
        cout << "No purchase history found for customer: " << customerName << endl;
    }
}
bool login()
{
    string name = "Admin";
    int password = 12345;

    cout << "Please confirm your Name and Password to login" << endl;
    cout << "Enter your Name:" << endl;
    cin >> name;
    cout << "Enter your Password:" << endl;
    cin >> password;
    if (name == "Admin" && password == 12345)
    {
        cout << "***** You are able to perform Admin activities *****" << endl;
        return true;
    }
    cout << "You entered the wrong name or password" << endl;
    cout << "You can't perform Admin activities" << endl;

    return false;
}
void registerCustomer()
{

    string name, password;
    cout << "Enter your name: ";
    cin.ignore();
    getline(cin, name);
    cout << "Choose a password: ";
    cin >> password;

    ofstream write;
    write.open("customers.txt", ios::app);
    write << name << "," << password << endl;
    write.close();

    cout << "Registration successful!" << endl;
}
void getFeedback()
{
    string feedback;

    cout << "Please provide your feedback about the pharmacy's overall experience: ";
    cin.ignore();
    getline(cin, feedback);

    ofstream feedbackFile("feedback.txt", ios::app);

    if (!feedbackFile)
    {
        cout << "File could not be opened";
        exit(1);
    }

    feedbackFile << feedback << endl;

    feedbackFile.close();

    cout << "Thank you for your feedback!" << endl;
}
void checkFeedback()
{
    ifstream feedbackFile("feedback.txt");

    if (!feedbackFile)
    {
        cout << "File could not be opened";
        exit(1);
    }

    string feedback;

    cout << "Feedback from customers:" << endl;
    while (getline(feedbackFile, feedback))
    {
        cout << feedback << endl;
    }

    feedbackFile.close();
}
bool loginCustomer()
{
    string name, password;
    cout << "Enter your name (ID): ";
    cin.ignore();
    getline(cin, name);
    cout << "Enter your password: ";
    cin >> password;

    ifstream read("customers.txt");
    string line;
    while (getline(read, line))
    {
        size_t pos = line.find(",");
        string storedName = line.substr(0, pos);
        string storedPassword = line.substr(pos + 1);

        if (name == storedName && password == storedPassword)
        {
            read.close();
            cout << "Login successful!" << endl;
            return true;
        }
    }
    return false;
}
int main()
{
    int choice;

    do
    {
        cout << "******************Pharmacy Management System***************" << endl;
        cout << "************************ Welcome***************************" << endl;
        cout << "1. Admin" << endl;
        cout << "2. Customer" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            // Handle admin functions
            if (login())
            {
                int choice;

                do
                {

                    cout << "1. Medicin Mangment" << endl;
                    cout << "2. Customer Mangment" << endl;
                    cout << "3. Pharchase Records" << endl;
                    cout << "4. view feed back" << endl;
                    cout << "5. exit" << endl;
                    cout << "Enter your choice: ";
                    cin >> choice;

                    switch (choice)
                    {
                    case 1:
                        cout << "Handle Medicine:" << endl;
                        cout << "****************" << endl;
                        int choice;

                        do
                        {
                            cout << " 1.Add Medicine" << endl;
                            cout << "2. View Medicine" << endl;
                            cout << "3. Search Medicine " << endl;
                            cout << "4. delete Medicine " << endl;
                            cout << "5. update Medicine " << endl;
                            cout << "6. Exit" << endl;
                            cout << "Enter your choice: ";
                            cin >> choice;

                            switch (choice)
                            {
                            case 1:
                                // add medicine
                                addMedicine();
                                break;
                            case 2:
                                // view medicine
                                viewMedicine();

                                break;
                            case 3:
                                // search Medicine
                                searchMedicine();

                                break;
                            case 4:
                                //   delete medicine
                                deleteMedicine();

                                break;
                            case 5:
                                // update medicine
                                updateMedicine();
                                break;
                            case 6:
                                cout << "you have done  Medicine Mengement" << endl;
                                break;
                            default:
                                cout << "Invalid choice. Please try again." << endl;
                            }
                        } while (choice != 6);

                        break;
                    case 2:
                        showCustomers();
                        break;
                    case 3:
                        // purchaseRecord
                        purchaseRecord();
                        break;
                    case 4:
                        checkFeedback();
                        break;
                    case 5:
                        cout << "you have done Admin Activities!" << endl;
                        break;
                    default:
                        cout << "Invalid choice. Please try again." << endl;
                    }
                } while (choice != 5);
            }
            break;
        case 2:
            int n;
            do
            {
                // Handle customer functionsint choice;
                cout << " firstly rigister yourself by pressing 1,If you are  a new Customer ";
                cout << " otherwise press 2  for login" << endl;
                cout << "press 3 for exit" << endl;

                cin >> n;

                switch (n)
                {
                case 1:
                    registerCustomer();
                    break;
                case 2:
                    if (loginCustomer())
                    {
                        int choice;
                        do
                        {

                            cout << "1. purchase Opreation" << endl;
                            cout << "2. Order History" << endl;
                            cout << "3. Feed back" << endl;
                            cout << "4. Exit" << endl;
                            cout << "Enter your choice: ";
                            cin >> choice;

                            switch (choice)
                            {
                            case 1:
                                // purchase opreation
                                int choice;
                                do
                                {

                                    cout << "1. Search Medicine" << endl;
                                    cout << "2.  Veiw Avaliable Medicine " << endl;
                                    cout << "3.  Purchase Medicine" << endl;
                                    cout << "4. Exit" << endl;
                                    cout << "Enter your choice: ";
                                    cin >> choice;

                                    switch (choice)
                                    {
                                    case 1:
                                        //  Search Medicine
                                        searchMedicine();
                                        break;
                                    case 2:
                                        //   Veiw Avaliable Medicine
                                        viewMedicine();
                                        break;
                                    case 3:
                                        // Purchase Medicine
                                        purchaseMedicine();

                                        break;
                                    case 4:
                                        cout << "you have exit from  the purchase opreations" << endl;
                                        break;
                                    default:
                                        cout << "Invalid choice. Please try again." << endl;
                                    }
                                } while (choice != 4);
                                break;
                            case 2:
                                //  order history
                                orderHistory();
                                break;
                            case 3:
                                // feed back
                                getFeedback();
                                break;
                            case 4:
                                cout << "you have exit the program";
                                break;
                            default:
                                cout << "Invalid choice. Please try again." << endl;
                            }
                        } while (choice != 4);
                    }

                case 3:
                    cout << "customer have exit. " << endl;
                    break;
                default:
                    cout << "Invalid choice. Please try again." << endl;
                }
            } while (n != 3);
            break;
        case 3:
            cout << "Exiting the program. Goodbye!" << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 3);

    return 0;
}
