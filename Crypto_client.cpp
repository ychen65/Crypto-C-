// 
// Programer: Chenyu Wang
//  main.cpp
//  CS331_HW04
//  Brief Description: it is a program about encryption and decryption. Using shift, unshift, permute, and unpermute.
//
//  Created by Chenyu Wang on 11/14/19.
//  Last modification on 11/16/19.
//  Copyright © 2019 chenyu wang. All rights reserved.
//

#include <QTextStream>
#include "Crypto.h"

int main(){
    QTextStream cout(stdout);
    QString str1("asdfghjkl;QWERTYUIOP{}}|123456&*()_+zxcvnm,,, ./?");
    QString str2;
    
    cout << "Original string: " << str1 << endl;
    cout << "length: " << str1.length() << endl;
    QString seqstr("pspsp");
    ushort key(12579);
    Crypto crypt(key, seqstr, 128);
    str2 = crypt.encrypt(str1);
    cout << "Encrypted string: " << str2 << endl;
    cout << "Recovered string: " << crypt.decrypt(str2) << endl;
    
}
