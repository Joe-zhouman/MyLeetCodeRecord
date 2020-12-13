// Administrator
// LeetCode
// 0051_NQueens
// 2020-12-13-18:34
// *Author*    : Joe, Zhou Man 
// *Email*     : man.man.man.man.a@gmail.com 
// *Email*     : joe_zhouman@foxmail.com 
// *QQ*        : 1592020915 
// *Weibo*     : @zhouman_LFC 
// *Twitter*   : @zhouman_LFC 
// *Website*   : www.joezhouman.com 
// *Github*    : https://github.com/Joe-zhouman 
// *LeetCode*  : https://leetcode-cn.com/u/joe_zm/

#pragma once
#include <iostream>
class Queen {
    int size_;

public:
    int x_;
    int y_;
    Queen(int size, int x = 0, int y = 0) :size_(size), x_(x), y_(y) {};
    bool operator==(Queen const& q) const {
        if (x_ == q.x_) return true;
        if (x_ - q.x_ == y_ - q.y_) return true;
        if (x_ - q.y_ == q.x_ - y_) return true;
        if (y_ == q.y_) return true;
        return false;
    }
    bool operator!=(Queen const& q) const { return !(*this == q); }
	std::string ToString() const {
        std::string queen_str;
        for (auto i = 0; i < x_; i++) {
            queen_str += '.';
        }
        queen_str += 'Q';
        for (auto i = x_ + 1; i < size_; i++) {
            queen_str += '.';
        }
        return queen_str;
    	
    }
    /*void Dispaly() {
        std::cout << y_ << " ";
        for (auto i = 0; i < x_; i++) std::cout << 'O';
        std::cout << 'X';
        for (auto i = x_ + 1; i < size_; i++) std::cout << 'O';
        std::cout << std::endl;
    }*/
	
};
