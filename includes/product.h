/*
 * =====================================================================================
 *
 *       Filename:  product.h
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

#ifndef PRODUCT_H
#define PRODUCT_H

using namespace std;

class Product{
        public:
                int GetCount();
                string GetName();
                void SetCount(int count);
                void SetName(string name);
        private:
                int quantity = 0;
                string name = "";
};

#endif
