//
//  Crypto.cpp
//  CS331_HW04
//
//  Created by Chenyu Wang on 11/14/19.
//  Copyright © 2019 chenyu wang. All rights reserved.
//

#include "Crypto.h"
#include <cstdlib>
#include <QChar>

Crypto::Crypto(ushort key, QString opseq, ushort charsiz){
    m_Key = key;
    m_OpSequence =opseq;
    m_CharSetSize = charsiz;
}

int Crypto::limitedRand(int max){
    return rand()%max;
}

QVector<int> Crypto::randomPerm(int n){
    srandom(m_Key);
    int k;
    m_Perm.clear();
    m_Perm.resize(n);
    for (int i=0; i<n; i++){
        k=limitedRand(n);
        m_Perm[i]=k;
    }
    return m_Perm;
}

QString Crypto::shift(const QString& text){
    srandom(m_Key);
    ushort j;
    ushort shiftText;
    QString s;
    int r=limitedRand(m_CharSetSize);
    for (int i=0;i<text.length();i++){
        j=text[i].toAscii();
        shiftText=(j+r)%m_CharSetSize;
        s+=shiftText;
    }
    return s;
}

QString Crypto::unshift(const QString& text){
    srandom(m_Key);
    ushort j;
    ushort shiftText;
    QString unstring;
    int r=limitedRand(m_CharSetSize);
    for (int i=0;i<text.length();i++){
        shiftText=text[i].toAscii();
        j=m_CharSetSize+shiftText-r;
        unstring+=j;
    }
    return unstring;
}

QString Crypto::permute(const QString& text){
    QString cstirng;
    for (int i=0; i<text.length(); i++){
        int index=m_Perm[i];
        cstirng+=text.at(index);
    }
    return cstirng;
}

QString Crypto::unpermute(const QString& text){
    QString unpermuteS;
    for(int i=0; i<text.length();i++){
        int index=m_Perm[i];
        unpermuteS[index]=text[i];
    }
    return unpermuteS;
}

QString Crypto::encrypt(const QString& text){
    randomPerm(text.length());
    QString OriginalT=text;
    QString cryptoS;
    for(int i=0; i<m_OpSequence.length();i++){
        if(m_OpSequence[i]=='p')
            cryptoS=shift(OriginalT);
        if(m_OpSequence[i]=='s')
            cryptoS=permute(OriginalT);
    }
    return cryptoS;
}

QString Crypto::decrypt(const QString& text){
    randomPerm(text.length());
    QString newS=text;
    QString decryptS;
    for(int i=0; i<m_OpSequence.length();i++){
        if(m_OpSequence[i]=='p')
            decryptS=unshift(newS);
        if(m_OpSequence[i]=='s')
            decryptS=unpermute(newS);
    }
    return decryptS;    
}
