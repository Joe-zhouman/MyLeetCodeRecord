// Administrator
// LeetCode
// 0051_NQueens
// 2020-12-13-19:59
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
#include <vector>
#include <algorithm>
#include <string>

#include "Queen.h"
class Solution {
public:
	std::vector<std::vector<std::string>> solveNQueens(int n) {
		std::vector<Queen> queens_;
		std::vector<std::vector<std::string>> ans;
		Queen q(n, 0, 0);
		do {
			if (n <= queens_.size() || n <= q.x_) {
				q = queens_.back();
				queens_.pop_back();
				q.x_++;
			}
			else {
				while (q.x_ < n && std::find(queens_.begin(), queens_.end(), q) != queens_.end()) { q.x_++; }
				if (q.x_ < n) {
					queens_.push_back(q);
					if (n <= queens_.size()) {
						std::vector<std::string> temp;
						auto queens = queens_;
						while (!queens.empty()) {
							temp.push_back(queens.back().ToString());
							queens.pop_back();
						}
						ans.push_back(temp);
					}
					q.y_++;
					q.x_ = 0;
				}
			}
		} while (0 < q.y_ || q.x_ < n);
		return ans;
	}
};
class EightQueens {
private:
	std::vector<Queen> queens_;
	int size_;
	int n_sln_;

public:
	EightQueens(int n);
	void PlaceQueens();
	void ShowQueens();
	bool HasSolution() { return 0 < n_sln_; }
};

EightQueens::EightQueens(int n) { size_ = n; }

void EightQueens::PlaceQueens() {
	Queen q(size_, 0, 0);
	do {
		if (size_ <= queens_.size() || size_ <= q.x_) {
			q = queens_.back();
			queens_.pop_back();
			q.x_++;
		}
		else {
			while (q.x_ < size_ && std::find(queens_.begin(), queens_.end(), q) != queens_.end()) { q.x_++; }
			if (q.x_ < size_) {
				queens_.push_back(q);
				if (size_ <= queens_.size()) {
					n_sln_++;
					ShowQueens();
				}
				q.y_++;
				q.x_ = 0;
			}
		}
	}
	while (0 < q.y_ || q.x_ < size_);
}

//void EightQueens::ShowQueens() {
//    auto queens = queens_;
//    std::cout << "Solution " << n_sln_ << " :" << std::endl << std::endl;
//    while (!(queens.empty())) {
//        queens.pop().Dispaly();
//    }
//    std::cout << "  ";
//    for (size_t i = 0; i < size_; i++) {
//        std::cout << " ";
//    }
//    std::cout << std::endl;
//    std::cout << "  ";
//    for (size_t i = 0; i < size_; i++) {
//        std::cout << static_cast<char>(('A' + i));
//    }
//    std::cout << std::endl << std::endl;
}
