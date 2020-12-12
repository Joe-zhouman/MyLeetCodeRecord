// Joe
// 周漫
// 2020071423:45


#pragma once
#include <algorithm>
#include <vector>
using namespace std;

namespace product_of_numbers {
    class ProductOfNumbers {
        vector<int>_product = { 1 };
    public:
        ProductOfNumbers() {
        };

        void add(int num) {
        	if(num == 0) {
                _product = { 1 };
        	}
        	else {
                _product.push_back(num * _product.back());
        	}          
        }

        int getProduct(int k) {
            return k < _product.size() ? _product.back() / _product[_product.size() - k - 1] : 0;
        }
    };
}
