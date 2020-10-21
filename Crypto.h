//
//  Crypto.hpp
//  CS331_HW04
//
//  Created by Chenyu Wang on 11/14/19.
//  Copyright © 2019 chenyu wang. All rights reserved.
//

#ifndef Crypto_h_
#define Crypto_h_

#include <QString>
#include <QVector>

class Crypto{
public:
    Crypto(ushort key, QString opseq, ushort charsiz);
    QString encrypt(const QString& str);
    QString decrypt(const QString& str);
private:
    ushort m_Key;
    QString m_OpSequence;
    ushort m_CharSetSize;
    QVector<int> m_Perm;
    QString shift(const QString& str);
    QString unshift(const QString& str);
    QString permute(const QString& str);
    QString unpermute(const QString& str);
    static int limitedRand(int max);
    QVector<int> randomPerm(int n);
};

#endif /* Crypto_hpp */
