
//  Created by Wei-Hsuan Lien on 2018/5/2.
//  Copyright © 2018年 Wei-Hsuan Lien. All rights reserved.


#include <iostream>
#include <istream>
#include <ctime>
#include <string>
#include <iomanip>
#include "bignum.h"
#define LEN 100
using namespace std;

ostream &operator<<(ostream& output, const BigNUM& x)
{
    int firstdigit = 1;
    for (int i = (x.newSize-1); i >= 0; i--){
        if (x.Array[i] != 0){
            for (; i >= 0; i--){
                if (firstdigit == 1)
                    output << x.Array[i] << " ";
                else if (x.Array[i] >= 0)
                    output << setw(3) << setfill('0') << x.Array[i] << " ";
                else if (x.Array[i] < 0)
                    output << setw(3) << setfill('0') << -(x.Array[i]) << " ";
                
                firstdigit++;
            }
        }   
    }
    return output;
}

BigNUM::BigNUM (int Rank)
{
    int temp = Rank;
    rank = Rank;
    Array = new int [100000]();
    for (int i = 0; i < 100000; i++){
        Array[i] = (temp%1000);
        temp /= 1000;
    }
    CountDigit();
}

BigNUM::BigNUM()
{
    Array = new int[100000]();
}

istream &operator >>(istream &input, BigNUM& x)
{
    string str;
    input >> str;
    int convert = atoi(str.c_str());
    x.rank = convert;
    int temp = x.rank;
    x.Array = new int [100000]();
    for (int i = 0; i < 100000; i++){
        x.Array[i] = (temp%1000);
        temp /= 1000;
    }
    x.CountDigit();
    return input;
}

BigNUM::BigNUM(const BigNUM& copy)
{
    CountSize = copy.CountSize;
    newSize = copy.newSize;
    rank = copy.rank;
    plus = copy.plus;
    a = copy.a;
    b = copy.b;
    Array = new int [100000]();
    for (int i = 0; i < 100000; i++){
        Array[i] = copy.Array[i];
    }
}

int BigNUM::getSize()
{
    CountSize = 0;
    int firstdigit = 1;
    for (int i = (newSize-1); i >= 0; i--){
        if (Array[i] != 0 || firstdigit > 1){
            CountSize++;
        }   
    }
    return (CountSize);
}

int BigNUM::CountDigit()
{
    newSize = 0;
    for (int i = 0; i < sizeof(Array); i++){
        newSize++;
    }
    
    newSize = LEN*LEN*(newSize);
    return newSize;
}

BigNUM BigNUM::operator+(const BigNUM& x)
{
    BigNUM temp;
    temp.Array = new int [x.newSize]();
    
    for (int i = 0; i < x.newSize; i++)
        temp.Array[i] = Array[i] + x.Array[i];
    
    for (int j = 0; j < x.newSize; j++){
        int tmp = 0;
        if (temp.Array[j] >= 1000){
            tmp = temp.Array[j]/1000;
            temp.Array[j] %= 1000;
            temp.Array[j+1] += tmp;
        }
    }
    return temp;
}

BigNUM BigNUM::operator-(const BigNUM& x)
{
    BigNUM temp;
    temp.Array = new int [x.newSize]();
    for (int i = 0; i < x.newSize; i++)
        temp.Array[i] = Array[i] - x.Array[i];
 
    return temp;
}

BigNUM BigNUM::operator*=(const BigNUM& x)
{
    this->CountDigit();
    for (int i = 0; i <= CountSize; i++){
        for (int j = 0; j <= newSize; j++){
            Array[j] *= x.rank;
        }
        
        for (int j = 0; j < newSize; j++){
            int tmp = 0;
            if (Array[j] >= 1000){
                tmp = Array[j]/1000;
                Array[j] %= 1000;
                Array[j+1] += tmp;
            }
            
            else if (Array[j] <= -1000){
                tmp = Array[j]/1000;
                Array[j] %= 1000;
                Array[j+1] += tmp;
            }
        }
    }   
    
    CountDigit();
    return *this;
}


BigNUM BigNUM::operator++()
{
    a++;
    if (a < 1000)
        Array[0] = a;
    else if (a >= 1000 && a < 1000000)
        Array[1] = Array[0] + (a/1000);
    if (a >= 1000000)
        Array[2] = Array[0] + Array[1] + (a/1000000);
    
    return *this;
}


bool BigNUM::operator==(const BigNUM& x)
{
    if (Array[0] == x.Array[0])
        return true;
    else 
        return false;
}

BigNUM BigNUM::operator=(const BigNUM& x)
{
    BigNUM temp;
    if (newSize <= x.newSize){
        temp.Array = new int [x.newSize]();
        
        for (int i = 0; i < x.newSize; i++){
            temp.Array[i] = x.Array[i];
            Array[i] = x.Array[i];
        }
    }
    else if (newSize > x.newSize){
        temp.Array = new int [newSize]();
        
        for (int i = 0; i < newSize; i++){
            temp.Array[i] = x.Array[i];
            Array[i] = x.Array[i];
        }
    }
    return temp;
}

bool BigNUM::operator<(const BigNUM& x)
{
    b = x.Array[0] + 1000*x.Array[1] + 1000000*x.Array[2];
    
    if (a < b){
        return true;
    }
    else
        return false;
}

BigNUM::~BigNUM()
{
    delete[] Array;
}
