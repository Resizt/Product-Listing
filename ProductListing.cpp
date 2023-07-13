#include <iostream>
#include <iomanip>
#include <unordered_map>
#include <vector>
#include <string>
#include <fstream>
#include <cstdlib>
#include <variant>

using namespace std;

struct product 
{
    string pName;
    int invAmount = 0;

    double pSize = 0;
    double pPrice = 0;
    double pTotal = 0;
};

void menu() 
{
    cout << "---------------" << endl;
    cout << "1. Enter new product" << endl;
    cout << "2. View inventory" << endl;
    cout << "3. Edit Product" << endl;
    cout << "4. Shipping Info" << endl;
    cout << "5. Exit" << endl;
}

int main()
{
    vector<product> pVector;
    product pInfo;
    int option = 0, exit = 0, choice = 0, choice2 = 0;;
    cout << "Welcome to the Product listing" << endl;

    while (option != 5) {
        menu();
        cin >> option;
        switch (option) // Menu selection
        {
        case 1: // Data input
            cout << "Enter the product name:";
            cin.ignore();
            getline(cin, pInfo.pName);
            cout << "Enter the size of the product:";
            cin >> pInfo.pSize;     // Entering the Size of the product
            cout << "Enter the Price of the product:";
            cin >> pInfo.pPrice;    // Entering the Price of the product
            cout << "Inventory count: ";
            cin >> pInfo.invAmount; // Entering the inventory count
            pInfo.pTotal = pInfo.pPrice * pInfo.invAmount;

            pVector.push_back(pInfo); // Adding the entry as a vector
            break;
        case 2: // Printing the data 
            cout << std::left
                << std::setw(30) << "Product Name"
                << std::setw(20) << "Size (.fl)"
                << std::setw(20) << "Price"
                << std::setw(20) << "Inventory Count"
                << std::setw(20) << "Asset Cost" << endl;

            // Print table rows
            for (int i = 0; i < pVector.size(); i++)
            {
                cout << std::setw(30) << pVector[i].pName
                    << std::setw(20) << pVector[i].pSize
                    << std::setw(20) << pVector[i].pPrice
                    << std::setw(20) << pVector[i].invAmount
                    << std::setw(20) << pVector[i].pTotal << endl;
            }
            system("pause");
            break;
        case 3: // Editing function
            cout << "Pick a product you want to adjust" << endl;
            cout << "---------------" << endl;
            for (int i = 0; i < pVector.size(); i++)
                cout << i+1 << " " << pVector[i].pName << endl;
            cin >> choice;

            cout << "What do you want to change?" << endl;
            cout << "1. Change the name\n2. Change the size\n3. Change the price\n4. Inventory Count" << endl;
            cin >> choice2;

            switch (choice2) {
            case 1:
                cout << "Renamed name" << endl;
                cout << "Old Name: " << pVector[choice - 1].pName << endl;
                cout << "New Name: ";
                cin.ignore();
                getline(cin, pVector[choice - 1].pName);
                break;
            case 2:
                cout << "Resize" << endl;
                cout << "Old Size: " << pVector[choice - 1].pSize << endl;
                cout << "New Size: ";
                cin >> pVector[choice - 1].pSize;
                break;
            case 3:
                cout << "Adjust Price" << endl;
                cout << "Old Price: " << pVector[choice - 1].pPrice << endl;
                cout << "New Price: ";
                cin >> pVector[choice - 1].pPrice;
                pVector[choice - 1].pTotal = pVector[choice - 1].pPrice * pVector[choice - 1].invAmount;
                break;
            case 4:
                cout << "Adjust Inventory Count" << endl;
                cout << "Old Count: " << pVector[choice - 1].pTotal << endl;
                cout << "New Count: ";
                cin >> pVector[choice - 1].invAmount;
                pVector[choice - 1].pTotal = pVector[choice - 1].pPrice * pVector[choice - 1].invAmount;
                break;
            }
            break;
        case 4:
            cout << "Shipping level\n1. North America/Canada\n2. International" << endl;
            cin >> choice;
            system("pause");
            break;
        case 5:
            return(0);
            break;
        }
        system("CLS");
    }
}