/*
 * =====================================================================================
 *
 *       Filename:  product.cpp
 *
 *    Description: Grocery Store product Handle 
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
#include "product.h"

using namespace std;
int Product::GetCount(){
        return quantity;
}
string Product::GetName(qty){
        return name;
}
void Product::SetName(string name){
        this -> name = name;
}
void Product::SetCount(int qty){
        this -> quantity = this -> quantity + qty;
}