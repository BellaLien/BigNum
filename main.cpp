
//  Created by Wei-Hsuan Lien on 2018/5/2.
//  Copyright © 2018年 Wei-Hsuan Lien. All rights reserved.


#include<iostream>
#include<time.h>
#include "bignum.h"

using namespace std;

int main(int argc, char *argv[]) {
    
    cout << "Hello, I'm driver program for Midterm." << endl;
    cout << "Here is the 1st part (Big Fibonacci number):\n";
    //F(0) = 0, F(1) = 1, F(2) = 1, ... F(n) = F(n-1) + F(n-2)
    
    //*Option 1 of Task 1 (without user input)
//    BigNUM tN(123456), tFirst(0), tSecond(1), tFNumber(0);
//    cout << "input tN (calculate nth Fib#) : " << tN;
//    cout << endl;

    //*Option 2 of Task 1 (with user input)
    BigNUM tN, tFirst(0), tSecond(1), tFNumber(0);
    cout << "input tN (calculate nth Fib#) : ";
    cin >> tN;
    cout << "tN : " << tN << endl;
    
    clock_t Start_t1 = clock();
    if (tN == 0)
        tFNumber = 0;
    else if (tN == 1)
        tFNumber = 1;
    else
    {
        tFNumber = 0;
        tFirst = 0;
        tSecond = 1;
        for (BigNUM i = 0; i < tN - 1; ++i) {
            tFNumber = tSecond + tFirst;
            tFirst = tSecond;
            tSecond = tFNumber;
        }
    }
    cout << "the " << tN << "th Fibonacci number is : " << tFNumber << " (" << tFNumber.getSize() << ")" << endl;
    cout << "Clock:" << (clock() - Start_t1) * 1.0 / CLOCKS_PER_SEC << " sec." << endl;
    
//    ---------------------------------------------------------------------------------------------
    
    cout << "Here is the 2nd part (BIGGGGG N^M)\n";
    
    //*Option 1 of Task 2 (without user input)
//    BigNUM tA(12345),tB(54321),tC(1);
    
    //*Option 2 of Task 1 (with user input)
    BigNUM tA,tB,tC(1);
    cout << "input tA : ";
    cin >> tA;
    cout << "input tB : ";
    cin >> tB;
    
    cout << "tA : " << tA << endl;
    cout << "tB : " << tB << endl;
    
    clock_t Start_t = clock();
    
    for(BigNUM tF = 0; tF < tB; ++tF){
        tC *= tA;
//        cout << tC << " " << endl;
    }
    cout << "tC = " << tC << " (" << tC.getSize() << ")" << endl;
    cout << "Clock:" << (clock() - Start_t) * 1.0 / CLOCKS_PER_SEC << " sec." << endl;
    
    //--THE END--
    int x;
    cout << "input any integer : ";
    cin >> x;
    return 0;
}

