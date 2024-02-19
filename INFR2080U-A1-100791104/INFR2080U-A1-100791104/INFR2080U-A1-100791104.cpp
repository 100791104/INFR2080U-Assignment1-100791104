// Nishaanth Murali, 100791104, Assignment 1 - INFR 2080U

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

int main()
{
    ifstream theFile("product_data.txt");

    int const capacity = 100; // The maximum number of products the online shopping platform contains. Based on the given text file, we can only insert another 50 products.

    int id[capacity];
    string name[capacity];
    double price[capacity];
    string category[capacity];

    string temp_id;
    string temp_name;
    string temp_price;
    string temp_category;
    string line;
    int counter = 0;

// Data Load

    while (getline(theFile, line)) 
    {
        stringstream ss(line);
        getline(ss, temp_id, ',');
        getline(ss, temp_name, ',');
        getline(ss, temp_price, ',');
        getline(ss, temp_category, ',');
        id[counter] = stoi(temp_id);
        name[counter] = temp_name;
        price[counter] = stod(temp_price);
        category[counter] = temp_category;
        counter++;
    }
    
    theFile.close();

// Data Manipulation Operations (Insert, Update, Delete, Search, Sort)

    bool OnOff = true;
    int input1;
    int input2 = 0;
    int input3;

    while (OnOff == true) 
    {
        cout << "Enter (1) to Insert, (2) to Update, (3) to Delete, (4) to Search, (5) to Sort, or (6) to Exit the Program." << endl;
        cin >> input1;

        if (counter >= capacity || input2 > capacity)
        {
            cout << "ERROR: Insufficient Storage! Exiting the Program." << endl;
            exit(0);
        }

        if (input1 == 1)
        {
            cout << "Input Confirmed: Insert" << endl;

            cout << "Enter the Product ID: ";
            cin >> id[counter];
            cout << "Enter the Product Name: ";
            cin >> name[counter];
            cout << "Enter the Product Price: ";
            cin >> price[counter];
            cout << "Enter the Product Category: ";
            cin >> category[counter];
            counter++;
        }
        else if (input1 == 2)
        {
            cout << "Input Confirmed: Update" << endl;

            cout << "Enter the Product's Row, ranging from 0 to the determined capacity (e.g. 0): ";
            cin >> input2;
            cout << "Update the Product's ID (e.g. 57353): ";
            cin >> id[input2];
            cout << "Update the Product's Name (e.g. Camera SBBHC): ";
            cin >> name[input2];
            cout << "Update the Product's Price (e.g. 546.88): ";
            cin >> price[input2];
            cout << "Update the Product's Category (e.g. Electronics): ";
            cin >> category[input2];
        }
        else if (input1 == 3)
        {
            cout << "Input Confirmed: Delete" << endl;

            cout << "Enter the Product's Row, ranging from 0 to the determined capacity (e.g. 0): ";
            cin >> input2;
            id[input2] = 0;
            name[input2] = 'null';
            price[input2] = 0.00;
            category[input2] = 'null';
        }
        else if (input1 == 4)
        {
            cout << "Input Confirmed: Search" << endl;

            cout << "Select the Attribute you wish to Search:\n Enter (1) for ID\n Enter (2) for Name\n Enter (3) for Price\n Enter (4) for Category\n\n";
            cin >> input3;

            if (input3 == 1) {
                int temp_id2;
                cout << "ID Search: ";
                cin >> temp_id2;
                for (int i = 0; i < capacity; i++) {
                    if (id[i] == temp_id2) {
                        cout << id[i] << " " << name[i] << " " << price[i] << " " << category[i] << endl;
                    }
                }
            }
            else if (input3 == 2) {
                cout << "Name Search: ";
                cin >> temp_name;
                for (int i = 0; i < capacity; i++) {
                    if (name[i].find(temp_name, 0) != string::npos) {
                        cout << id[i] << " " << name[i] << " " << price[i] << " " << category[i] << endl;
                    }
                }
            }
            else if (input3 == 3) {
                double temp_price2;
                cout << "Price Search: ";
                cin >> temp_price2;
                for (int i = 0; i < capacity; i++) {
                    if (price[i] == temp_price2) {
                        cout << id[i] << " " << name[i] << " " << price[i] << " " << category[i] << endl;
                    }
                }
            }
            else if (input3 == 4) {
                cout << "Category Search: ";
                cin >> temp_category;
                for (int i = 0; i < capacity; i++) {
                    if (category[i].find(temp_category, 0) != string::npos) {
                        cout << id[i] << " " << name[i] << " " << price[i] << " " << category[i] << endl;
                    }
                }
            }
        }
        else if (input1 == 5)
        {
            cout << "Input Confirmed: Sort" << endl;

            cout << "The product data will be listed by price (least to greatest) using the bubble sort method." << endl;

            double temp_price3[capacity];
            for (int i = 0; i < capacity; i++) {
                temp_price3[i] = price[i];
            }

            for (int i = 0; i < capacity; i++) {
                for (int j = 0; j < capacity - 1; j++) {
                    if (temp_price3[j] > temp_price3[j + 1]) {
                        double temp = temp_price3[j];
                        temp_price3[j] = temp_price3[j + 1];
                        temp_price3[j + 1] = temp;
                    }
                }
            }

            for (int i = 0; i < capacity; i++) {
                for (int j = 0; j < capacity; j++) {
                    if (temp_price3[i] == price[j]) {
                        cout << id[j] << ", " << name[j] << ", " << price[j] << ", " << category[j] << endl;
                    }
                }
            }

        }
        else if (input1 == 6)
        {
            cout << "Input Confirmed: Exit the Program" << endl;
            OnOff = false;
        }
        else 
        {
            cout << "ERROR: Unrecognized Input!" << endl;
            OnOff = false;
        }

    }

    return 0;
}