
//
//  Created by Wei-Hsuan Lien on 2018/5/2.
//  Copyright © 2018年 Wei-Hsuan Lien. All rights reserved.
//

#ifndef bignum_h
#define bignum_h

#include <iostream>
#include <string>
using namespace std;

class BigNUM {
    
friend ostream &operator<<(ostream &output, const BigNUM &X);
friend istream &operator>>(istream &input, BigNUM &X);
    
public:
    BigNUM(int);
    BigNUM(const BigNUM&);
    BigNUM();
    int getSize();
    int CountDigit();
    BigNUM operator+(const BigNUM&);
    BigNUM operator-(const BigNUM&);
    BigNUM operator=(const BigNUM&);
    BigNUM operator*=(const BigNUM&);
    BigNUM operator++();
    bool operator==(const BigNUM&);
    bool operator<(const BigNUM&);
    ~BigNUM();
private:
    int *Array;
    int CountSize = 0;
    int newSize = 100;
    int rank = 0;
    int plus = 1;
    int a = 0, b = 0;
    
};

#endif /* s1042701_bignumV3_h */
