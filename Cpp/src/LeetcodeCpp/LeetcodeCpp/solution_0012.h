#pragma once
/*****************************************************************//**
 * \file   solution_0012.h
 * \brief  给你一个整数，将其转为罗马数字。
 * 
 * \author Administrator
 * \date   March 2023
 *********************************************************************/
#include<string>
#include<vector>
const std::vector< std::vector<std::string>> a = {
    {"","M","MM","MMM"},
    {"","C","CC","CCC","CD","D","DC","DCC","DCCC","CM"} ,
    {"","X","XX","XXX","XL","L","LX","LXX","LXXX","XC"},
    {"","I","II","III","IV","V","VI","VII","VIII","IX"}
};
const std::string thousands[] = {"","M","MM","MMM"};
const std::string hundreds[] = {"","C","CC","CCC","CD","D","DC","DCC","DCCC","CM"};
const std::string tens[] = {"","X","XX","XXX","XL","L","LX","LXX","LXXX","XC"};
const std::string ones[] = {"","I","II","III","IV","V","VI","VII","VIII","IX"};
const std::pair<int, std::string> value2sym[]{
    {1000,"M"},
    {900,"CM"},
    {500,"D"},
    {400,"CD"},
    {100,"C"},
    {90,"XC"},
    {50,"L"},
    {40,"XL"},
    {10,"X"},
    {9,"IX"},
    {5,"V"},
    {4,"IV"},
    {1,"I"}
};
class solution_0012 {
public:
    std::string intToRoman(int num) {
        return thousands[num / 1000] + hundreds[num % 1000 / 100] + tens[num % 100 / 10] + ones[num % 10];
    }
    std::string intToRoman2(int num) {
        std::string ans;
        for(const auto& p : value2sym) {
            while(num>=p.first) {
                num -= p.first;
                ans += p.second;
            }
            if(num == 0) {
                break;
            }
        }
        return ans;
    }
};

