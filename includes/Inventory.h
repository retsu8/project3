/*
 * =====================================================================================
 *
 *       Filename:  inventory.h
 *    Description: Inventory H file
 *        Version:  1.0
 *        Created:  08/05/2025 11:49:20 PM
 *       Revision:  1.0.0
 *       Compiler:  g++
 *
 *         Author:  William Paddock, 
 *   Organization:  Southern New Hampshire University CS 210 Project Three
 *
 * =====================================================================================
 */
#ifndef INVENTORY_H
#define INVENTORY_H

#include <iostream>
#include <string>
#include <bits/stdc++.h>

using namespace std;

class Inventory {
	private:
		// Setting this to max inventory size
		map<string, int> product;
		std::string name = "";
	public:
		Inventory();
		Inventory(std::string name);
		void SetStoreName(std::string name) {};
		int GetInventory(string name);
		void UpdateInventory(string name, int qty) {};
		std::string InputFile(std::string inventory_file);

};

#endif
