/*
 * =====================================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description: Grocery Store Handle 
 *
 *        Version:  1.0
 *        Created:  08/05/2025 11:49:20 PM
 *       Revision:  1.0.0
 *       Compiler:  gcc
 *
 *         Author:  William Paddock, 
 *   Organization:  Southern New Hampshire University CS 210 Project Three
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include <iostream>
#include <string>
#include <bits/stdc++.h>

using namespace std;

class Inventory {
	public:
		Inventory();
		Inventory(std::string name);
		int InputFile(std::string inventory_file);
		void SetStoreName(std::string name);
		void PrintMenu(int choice);
		int GetInventory(string name);
		void UpdateInventory(string name);
		void SearchInput();
		int GetInput();
		void PrintInventory();
		void PrintFrequency();
		void ToLower(std::string& lowerMe);
		void RemoveWhiteSpace(std::string& cleanMe);
		void InitializeInventory(std::string line);
		void SaveFile();
	private:
		// Setting this to max inventory size
		map<string, int> product;
		std::string name;
};

Inventory::Inventory(){
	map<string, int> product = {};
	string name = "";
}

Inventory::Inventory(std::string name){
	this -> name = name;
}

void Inventory::PrintMenu(int choice){
	// Menu to print user input
	switch(choice){
		case 0:
			cout <<  "Which item are you searching for?" << endl;
			break;
		case 1:
			cout << "Choose from the following menu" << endl;
			cout << "1. Search" << endl;
			cout << "2. Inventory" << endl;
			cout << "3. Frequency" << endl;
			cout << "4. Exit" << endl;
		}
}
void Inventory::PrintInventory(){
	// Iter through the map printing all the values in inventory
	map<string,int>::iterator it; 
	for (it=this->product.begin();it!=this->product.end();++it) {
		string capital = it->first;
		capital[0] = toupper(capital[0]);
	    cout << it->second << " " << capital << endl;
	}
}

void Inventory::SetStoreName(std::string name){
	// Set the store name
	this -> name = name;
}
int Inventory::GetInventory(string name){
	// Return the product inventory
	return this -> product[name];
}

void Inventory::ToLower(std::string& lowerMe) {
	// Lowercase the string
	for (size_t i = 0; i < lowerMe.length(); ++i) {
        lowerMe[i] = tolower(lowerMe[i]);
    }
}

void Inventory::UpdateInventory(std::string name){
	// refernce the product
	map<string, int> local = this -> product;
	ToLower(name);
	RemoveWhiteSpace(name);
	try{
		// Update if exists
		local[name] = local[name] + 1;
	} catch (int e) {
		// if not add a new one.
		local.insert({name, 1});
	}

	this -> product = local;
}

void Inventory::InitializeInventory(std::string line){
	// Get the space between the .dat file lines
	auto pos = line.find(' ');

	// Sprit the line appart using key
	string key = line.substr(0, pos);

	// Set the qty
	int qty = strtol(line.substr(pos, line.size()));

	// Remove whitespace
	key = RemoveWhiteSpace(key);

	// Save the key
	this -> product[key] = qty;
}

void Inventory::SaveFile(){
	std::ofstream saveFS (this -> name + ".dat");
	map<string,int>::iterator it; 
	for (it=this->product.begin();it!=this->product.end();++it) {
		saveFS << it -> first << " " << it -> second << endl;
	}
	saveFS.close();
}
int Inventory::InputFile(std::string inventory_file){
	// Open the file input stream
	ifstream saveFS;
	saveFS.open(this -> name + ".dat");
	if(!saveFS.is_open()){
		// if file not found create a saavefile
		std::ofstream saveFS (this -> name + ".dat");
	} else {
		// Add the saved inventory to the file
		string line;
	   	while (getline(saveFS, line)) {
	        // Process each line as needed
	    	InitializeInventory(line);
	    }
	}
	ifstream inFS;
	inFS.open(inventory_file);
	if (!inFS.is_open()) {
      return 1; // 1 indicates error
   	}
   	string line;
   	while (getline(inFS, line)) {
        // Process each line as needed
    	cout << "checking file: " << line << endl;
    	UpdateInventory(line);
    }
	inFS.close();
	return 0;

}

void Inventory::RemoveWhiteSpace(std::string& cleanMe){
	// Clean the whitespace from the strings
	cleanMe.erase(std::remove_if(cleanMe.begin(), cleanMe.end(),
        [](char c) {
            return (c == ' ' || c == '\n' || c == '\r' ||
                    c == '\t' || c == '\v' || c == '\f');
        }),
        cleanMe.end());
}
void Inventory::SearchInput(){
	// Clear out the buffer
    std::cin.clear(); // clear error state
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 

	// Ask for input
	cout << "What would you like to search?" << endl;
	string query;

	// Get the input
	getline(cin, query);
	ToLower(query);
	RemoveWhiteSpace(name);
	map<string, int> local = this -> product;

	// Search the key
    auto it = local.find(query);

    // Checking if key present or not
    if (it != local.end()){
        cout << it->first << ": " << it->second << endl;
    }else {
		cout << "That item is not in the inventory" << endl;
	}
}

int Inventory::GetInput(){
	// Get the users input for menu
	int i = 0;
	cin >> i;
	while(!cin && (i < 0 || i >4)) // or if(cin.fail())
	{
	    cout << "Invalid Input; only enter a number between1 1 and 4";
	    // user didn't input a number
	    cin.clear(); // reset failbit
	    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //skip bad input
	    // next, request user reinput
		cin >> i;
	}
	// Return the response if valid
	return i;
}

void Inventory::PrintFrequency(){
	// Printing the histogram
	map<string,int>::iterator it; 
	for (it=this->product.begin();it!=this->product.end();++it) {
		string capital = it->first;
		capital[0] = toupper(capital[0]);
	    cout << capital;
	    for(int i = 0; i< it->second; i++){
	    	cout << "%";
	    }
	    cout << endl;
	}
}

int GroceryHandle(){
	// Grovery store handler
	string store_name = "Corner Grocer";
	Inventory* grocer;
	grocer = new Inventory(store_name);
	grocer -> InputFile("CS210_Project_Three_Input_File.txt");
	int input = 0;
	while(input != 4){
		grocer -> PrintMenu(1);
		input = grocer -> GetInput();
		switch(input) {
			case 1:
				grocer -> SearchInput();
				break;
			case 2:
				grocer -> PrintInventory();
				break;
			case 3:
				grocer -> PrintFrequency();
				break;
			case 4:
				return 0;
			default:
				cout << "Invalid input" << endl;
			}
	}
	grocer -> PrintInventory();
	return 0;
}

int main(){
	// Main function for store handling
	GroceryHandle();
	return 0;
}
