#include "BigDicimalInt.h"
#include <stdlib.h>
    BigDecimalInt::BigDecimalInt(string decStr) {
        bool b=true;
        for (int i = 1; i < decStr.size(); i++)
        {
            if (!isdigit(decStr[i])) {
                b=false;
                break;
            }
            else
                b=true;
        }
        if((decStr[0]!='+' and decStr[0]!='-') and !isdigit(decStr[0]))
           b=false;
        if(b)
            num=decStr;
        else{
            cout<<"Bad Input \n";
            exit(3);
        }
    }
    //________________________________________
    BigDecimalInt::BigDecimalInt (int decInt){
        if(decInt<0)
            decInt=0-decInt;
        num= "-"+ to_string(decInt);
    }
    //_________________________________________
   int BigDecimalInt ::  sign()
    {
        if (num[0]=='-')
        {
            return -1;
        }

        else return 0;
    }
    //_____________________________________________________
    int BigDecimalInt::size()
    {
        if(num[0]=='-'||num[0]=='+')
        {
            return num.size()-1;
        }
        else return num.size();
    }
    //___________________________________________________________
    BigDecimalInt BigDecimalInt ::operator -  (BigDecimalInt anotherDec) {
        string s,s2;
        if(size()>anotherDec.size()) {
            int tempint;
            int sizediff = size() - anotherDec.size();
            if (sign() == anotherDec.sign()) {
                if (sign() == -1) {
                    //-325 - -2
                    // subtract 325 - 2 -
                    string str;
                    num.erase(num.begin());
                    anotherDec.num.erase(anotherDec.num.begin());
                    for (int i = 0; i < sizediff; i++)
                    {
                        anotherDec.num = "0" + anotherDec.num;
                    }
                    for (int i = num.size() - 1; i >= 0; i--) {
                        s = num[i];
                        s2 = anotherDec.num[i];
                        if (stoi(s2) <= stoi(s)) {
                            tempint = stoi(s) - stoi(s2);
                        } else {
                            tempint = stoi(s) + 10 - stoi(s2);
                            int c = 1;
                            int check =num[i - c] - '0';
                            while ((check) < 1) {
                                num[i - c] = '9';
                                c++;
                                check = num[i - c] - '0';
                            }
                            s = num[i - c];
                            num[i - c] = (stoi(s) - 1) + 48;
                        }
                        num[i] = (tempint) + 48;
                        str = num;
                        if(stoi(str)!=0)
                          str = "-" + str;
                    }
                    return BigDecimalInt(str);
                }
                else if (sign()==0){
                    // 325589 - 3256
                    //subtract
                    if(num[0]=='+')
                        num.erase(num.begin());
                    if (anotherDec.num[0]=='+')
                        anotherDec.num.erase(anotherDec.num.begin());
                    string str;
                    for (int i = 0; i < sizediff; i++)
                    {
                        anotherDec.num = "0" + anotherDec.num;
                    }
                    for (int i = num.size() - 1; i >= 0; i--) {
                        s = num[i];
                        s2 = anotherDec.num[i];
                        if (stoi(s2) <= stoi(s)) {
                            tempint = stoi(s) - stoi(s2);
                        } else {
                            tempint = stoi(s) + 10 - stoi(s2);
                            int c = 1;
                            int check =num[i - c] - '0';
                            while ((check) < 1) {
                                num[i - c] = '9';
                                c++;
                                check = num[i - c] - '0';
                            }
                            s = num[i - c];
                            num[i - c] = (stoi(s) - 1) + 48;
                        }
                        num[i] = (tempint) + 48;
                    }
                    str = num;
                    return BigDecimalInt(str);
                }
            }
            else if (sign()!=anotherDec.sign()) {
                if (sign() > anotherDec.sign()) {
                    //32563--256
                    //add
                    string str;
                    if (num[0] == '+')
                        num.erase(num.begin());
                    anotherDec.num.erase(anotherDec.num.begin());
                    for (int i = 0; i <= sizediff; i++) {
                        anotherDec.num = "0" + anotherDec.num;
                    }
                    num="0"+num;
                    for (int i = num.size() - 1; i >= 0; i--) {
                        s = num[i];
                        s2 = anotherDec.num[i];
                        if (stoi(s2) + stoi(s) <= 9) {
                            tempint = stoi(s) + stoi(s2);
                        } else {
                            tempint = stoi(s) + stoi(s2) - 10;
                            num[i] = tempint + 48;
                            int c = 1;
                            int check = num[i - c] - '0';
                            while ((check + 1) > 9) {
                                num[i - c] = '0';
                                c++;
                                check = num[i - c] - '0';
                            }
                            num[i - c] += 1;
                        }
                        num[i] = (tempint) + 48;
                    }
                    str = num;
                    return BigDecimalInt(str);
                }
                else if (sign() < anotherDec.sign()) {
                    //-32569
                    //325
                    //add 32569 + 325 -
                    num.erase(num.begin());
                    if (anotherDec.num[0]=='+')
                        anotherDec.num.erase(anotherDec.num.begin());
                    num = "0" + num;
                    for (int i = 0; i <= sizediff; i++) {
                        anotherDec.num = "0" + anotherDec.num;
                    }
                    string str;
                    cout << num << endl << anotherDec.num << endl;
                    for (int i = num.size() - 1; i >= 0; i--) {
                        s = num[i];
                        s2 = anotherDec.num[i];
                        if (stoi(s2) + stoi(s) <= 9) {
                            tempint = stoi(s) + stoi(s2);
                        } else {
                            tempint = stoi(s) + stoi(s2) - 10;
                            num[i] = tempint + 48;
                            int c = 1;
                            int check = num[i - c] - '0';
                            while ((check + 1) > 9) {
                                num[i - c] = '0';
                                c++;
                                check = num[i - c] - '0';
                            }
                            num[i - c] += 1;
                        }
                        num[i] = (tempint) + 48;
                    }
                    str = num;
                    if(stoi(str)!=0)
                        str = "-" + str;
                    return BigDecimalInt(str);

                }
            }
        }
        //*******************************************
        else if (size()<anotherDec.size()){
            if(sign()==anotherDec.sign()){
                if(sign()==0){
                    //32502-3625142
                    //-3625142-32502
                    int tempint;
                    int sizediff = anotherDec.size()-size();
                    if(num[0]=='+')
                        num.erase(num.begin());
                    if (anotherDec.num[0]=='+')
                        anotherDec.num.erase(anotherDec.num.begin());
                    string str;
                    for (int i = 0; i < sizediff; i++)
                    {
                        num = "0" + num;
                    }
                    for (int i = num.size()-1; i >= 0; i--) {
                        s = anotherDec.num[i];
                        s2 = num[i];
                        if (stoi(s2) <= stoi(s))
                        {
                            tempint = stoi(s) - stoi(s2);
                        }
                        else {
                            tempint = stoi(s) + 10 - stoi(s2);
                            int c=1;
                            int check =anotherDec.num[i-c]-'0';
                            while((check)<1)
                            {
                                anotherDec.num[i-c]='9';
                                c++;
                                check =num[i-c]-'0';
                            }
                            s=anotherDec.num[i-c];
                            anotherDec.num[i-c]=(stoi(s) - 1)+48;
                        }
                        anotherDec.num[i] = (tempint)+48 ;
                    }
                    str=anotherDec.num;
                    if(stoi(str)!=0)
                        str = "-" + str;
                    return BigDecimalInt(str);

                }
                else if (sign() ==-1){
                    //-325--362502
                    //362502-325 subtract
                    int tempint;
                    int sizediff = anotherDec.size()-size();
                    num.erase(num.begin());
                    anotherDec.num.erase(anotherDec.num.begin());
                    string str;
                    for (int i = 0; i < sizediff; i++)
                    {
                        num = "0" + num;
                    }
                    for (int i = num.size()-1; i >= 0; i--) {
                        s = anotherDec.num[i];
                        s2 = num[i];
                        if (stoi(s2) <= stoi(s))
                        {
                            tempint = stoi(s) - stoi(s2);
                        }
                        else {
                            tempint = stoi(s) + 10 - stoi(s2);
                            int c=1;
                            int check =anotherDec.num[i-c]-'0';
                            while((check)<1)
                            {
                                anotherDec.num[i-c]='9';
                                c++;
                                check =num[i-c]-'0';
                            }
                            s=anotherDec.num[i-c];
                            anotherDec.num[i-c]=(stoi(s) - 1)+48;
                        }
                        anotherDec.num[i]= (tempint)+48 ;
                    }
                    str=anotherDec.num;
                    return BigDecimalInt(str);
                }
            }
            else if (sign() !=anotherDec.sign()){
                if (sign()>anotherDec.sign()){
                    //325--32263
                    //add +
                    int tempint;
                    if(num[0]=='+')
                        num.erase(num.begin());
                    anotherDec.num.erase(anotherDec.num.begin());
                    int sizediff = anotherDec.size()-size();
                    for (int i = 0; i <= sizediff; i++)
                    {
                        num = "0" + num;
                    }
                    anotherDec.num="0"+anotherDec.num;
                    string str;
                    for (int i = num.size()-1; i >= 0; i--) {
                        s2 = num[i];
                        s = anotherDec.num[i];
                        if (stoi(s2) + stoi(s)<9)
                        {
                            tempint = stoi(s) + stoi(s2);
                        }
                        else {
                            tempint = stoi(s) + stoi(s2) - 10;
                            anotherDec.num[i] = tempint + 48;
                            int c = 1;
                            int check = anotherDec.num[i - c] - '0';
                            while ((check + 1) > 9) {
                                anotherDec.num[i - c] = '0';
                                c++;
                                check = anotherDec.num[i - c] - '0';
                            }
                            anotherDec.num[i - c] += 1;
                        }
                        anotherDec.num[i] = (tempint) + 48;
                    }
                    str=anotherDec.num;
                    return BigDecimalInt(str);
                }
                else if(sign()<anotherDec.sign()){
                    //-325-3026541
                    //add 325 +3026541 -
                    int tempint;
                    if(anotherDec.num[0]=='+')
                        anotherDec.num.erase(anotherDec.num.begin());
                    num.erase(num.begin());
                    int sizediff = anotherDec.size()-size();
                    for (int i = 0; i <= sizediff; i++)
                    {
                        num = "0" + num;
                    }
                    anotherDec.num="0"+anotherDec.num;
                    string str;
                    for (int i = num.size()-1; i >= 0; i--) {
                        s2 = num[i];
                        s = anotherDec.num[i];
                        if (stoi(s2) + stoi(s)<9)
                        {
                            tempint = stoi(s) + stoi(s2);
                        }
                        else {
                            tempint = stoi(s) + stoi(s2) - 10;
                            anotherDec.num[i] = tempint + 48;
                            int c = 1;
                            int check = anotherDec.num[i - c] - '0';
                            while ((check + 1) > 9) {
                                anotherDec.num[i - c] = '0';
                                c++;
                                check = anotherDec.num[i - c] - '0';
                            }
                            anotherDec.num[i - c] += 1;
                        }
                        anotherDec.num[i] = (tempint) + 48;
                    }
                    str=anotherDec.num;
                    if(stoi(str)!=0)
                        str = "-" + str;
                    return BigDecimalInt(str);
                }
            }
        }
        else if (size() == anotherDec.size()) {
            int tempint;
            if (sign() == anotherDec.sign()) {
                if (sign() == 0) {
                    //526-990 /// subtract  -
                    //852 - 325 // subtract +
                    if (num[0] == '+')
                        num.erase(num.begin());
                    if (anotherDec.num[0] == '+')
                        anotherDec.num.erase(anotherDec.num.begin());
                    string str;
                    if (num[0] >= anotherDec.num[0]) {
                        for (int i = num.size() - 1; i >= 0; i--) {
                            s = num[i];
                            s2 = anotherDec.num[i];
                            if (stoi(s2) <= stoi(s)) {
                                tempint = stoi(s) - stoi(s2);
                            } else {
                                tempint = stoi(s) + 10 - stoi(s2);
                                int c = 1;
                                int check = num[i - c] - '0';
                                while ((check) < 1) {
                                    num[i - c] = '9';
                                    c++;
                                    check = num[i - c] - '0';
                                }
                                s = num[i - c];
                                num[i - c] = (stoi(s) - 1) + 48;
                            }
                            num[i] = (tempint) + 48;
                        }
                        str = num;
                    } else if (anotherDec.num[0] > num[0]) {
                        for (int i = num.size() - 1; i >= 0; i--) {
                            s2 = num[i];
                            s = anotherDec.num[i];
                            if (stoi(s2) <= stoi(s)) {
                                tempint = stoi(s) - stoi(s2);
                            } else {
                                tempint = stoi(s) + 10 - stoi(s2);
                                int c = 1;
                                int check = anotherDec.num[i - c] - '0';
                                while ((check) < 1) {
                                    anotherDec.num[i - c] = '9';
                                    c++;
                                    check = anotherDec.num[i - c] - '0';
                                }
                                s = anotherDec.num[i - c];
                                anotherDec.num[i - c] = (stoi(s) - 1) + 48;
                            }
                            anotherDec.num[i] = (tempint) + 48;
                        }
                        str = anotherDec.num;
                        if(stoi(str)!=0)
                            str = "-" + str;
                    }
                    return BigDecimalInt(str);

                }
                else if (sign() == -1) {
                    //-990 - -580   990-580 -
                    //-520 - -982   980 - 520 +
                    num.erase(num.begin());
                    anotherDec.num.erase(anotherDec.num.begin());
                    string str;
                    if (num[0] >= anotherDec.num[0]) {
                        for (int i = num.size() - 1; i >= 0; i--) {
                            s = num[i];
                            s2 = anotherDec.num[i];
                            if (stoi(s2) <= stoi(s)) {
                                tempint = stoi(s) - stoi(s2);
                            } else {
                                tempint = stoi(s) + 10 - stoi(s2);
                                int c = 1;
                                int check = num[i - c] - '0';
                                while ((check) < 1) {
                                    num[i - c] = '9';
                                    c++;
                                    check = num[i - c] - '0';
                                }
                                s = num[i - c];
                                num[i - c] = (stoi(s) - 1) + 48;
                            }
                            num[i] = (tempint) + 48;
                        }
                        str = num;
                        if(stoi(str)!=0)
                            str = "-" + str;
                    }
                    else if (anotherDec.num[0] > num[0]) {
                        for (int i = num.size() - 1; i >= 0; i--) {
                            s2 = num[i];
                            s = anotherDec.num[i];
                            if (stoi(s2) <= stoi(s)) {
                                tempint = stoi(s) - stoi(s2);
                            } else {
                                tempint = stoi(s) + 10 - stoi(s2);
                                int c = 1;
                                int check = anotherDec.num[i - c] - '0';
                                while ((check) < 1) {
                                    anotherDec.num[i - c] = '9';
                                    c++;
                                    check = anotherDec.num[i - c] - '0';
                                }
                                s = anotherDec.num[i - c];
                                anotherDec.num[i - c] = (stoi(s) - 1) + 48;
                            }
                            anotherDec.num[i] = (tempint) + 48;
                        }
                        str = anotherDec.num;
                    }
                    return BigDecimalInt(str);
                }
            }
            else if (sign() != anotherDec.sign()) {
                if (sign() > anotherDec.sign()) {
                    //328--225
                    //add
                    if (num[0] == '+') {
                        num.erase(num.begin());
                    }
                    anotherDec.num.erase(anotherDec.num.begin());
                    anotherDec.num = "0" + anotherDec.num;
                    num = "0" + num;
                    for (int i = anotherDec.num.size() - 1; i >= 0; i--) {
                        s2 = num[i];
                        s = anotherDec.num[i];
                        if (stoi(s2) + stoi(s) <= 9) {
                            tempint = stoi(s) + stoi(s2);
                        } else {
                            tempint = stoi(s) + stoi(s2) - 10;
                            anotherDec.num[i] = tempint + 48;
                            int c = 1;
                            int check = anotherDec.num[i - c] - '0';
                            while ((check + 1) > 9) {
                                anotherDec.num[i - c] = '0';
                                c++;
                                check = anotherDec.num[i - c] - '0';
                            }
                             anotherDec.num[i - c] += 1;
                        }
                        anotherDec.num[i] = (tempint) + 48;
                    }
                    string str;
                    str = anotherDec.num;
                    return BigDecimalInt(str);
                }
                else if (sign() < anotherDec.sign()) {
                    //-65 - 32
                    //-32 - 65
                    // add -
                    if (anotherDec.num[0] == '+') {
                        anotherDec.num.erase(anotherDec.num.begin());
                    }
                    num.erase(num.begin());
                    anotherDec.num = "0" + anotherDec.num;
                    num = "0" + num;
                    for (int i = anotherDec.num.size() - 1; i >= 0; i--) {
                        s2 = num[i];
                        s = anotherDec.num[i];
                        if (stoi(s2) + stoi(s) <= 9) {
                            tempint = stoi(s) + stoi(s2);
                        } else {
                            tempint = stoi(s) + stoi(s2) - 10;
                            anotherDec.num[i] = tempint + 48;
                            int c = 1;
                            int check = anotherDec.num[i - c] - '0';
                            while ((check + 1) > 9) {
                                anotherDec.num[i - c] = '0';
                                c++;
                                check = anotherDec.num[i - c] - '0';
                            }
                            anotherDec.num[i - c] += 1;
                        }
                        anotherDec.num[i] = (tempint) + 48;
                    }
                    string str;
                    str = anotherDec.num;
                    if(stoi(str)!=0)
                        str = "-" + str;
                    return BigDecimalInt(str);
                }
            }
        }
    }
    //___________________________________________________________
    BigDecimalInt BigDecimalInt ::operator + (BigDecimalInt anotherDec) {
        string s, s2;
        if (size() > anotherDec.size()) {
            int tempint = 0;
            int sizediff = size() - anotherDec.size();
            if (sign() == anotherDec.sign()) {
                if (sign() == -1) {
                    // -3625 + -821
                    // add - ...
                    num.erase(num.begin());
                    anotherDec.num.erase(anotherDec.num.begin());
                    num = "0" + num;
                    for (int i = 0; i <= sizediff; i++) {
                        anotherDec.num = "0" + anotherDec.num;
                    }
                    string str;
                    for (int i = num.size() - 1; i >= 0; i--) {
                        s = num[i];
                        s2 = anotherDec.num[i];
                        if (stoi(s2) + stoi(s) <= 9) {
                            tempint = stoi(s) + stoi(s2);
                        } else {
                            tempint = stoi(s) + stoi(s2) - 10;
                            num[i] = tempint + 48;
                            int c = 1;
                            int check = num[i - c] - '0';
                            while ((check + 1) > 9) {
                                num[i - c] = '0';
                                c++;
                                check = num[i - c] - '0';
                            }
                            // s=num[i-c];
                            num[i - c] += 1;
                            // str[i-c+1]=num[i-c];
                        }
                        num[i] = (tempint) + 48;
                    }
                    str = num;
                    str = "-" + num;
                    return BigDecimalInt(str);
                }
                else if (sign() == 0) {
                    //9965 + 326
                    // add
                    if (num[0] == '+')
                        num.erase(num.begin());
                    if (anotherDec.num[0] == '+')
                        anotherDec.num.erase(anotherDec.num.begin());
                    num = "0" + num;
                    for (int i = 0; i <= sizediff; i++) {
                        anotherDec.num = "0" + anotherDec.num;
                    }
                    for (int i = num.size() - 1; i >= 0; i--) {
                        s = num[i];
                        s2 = anotherDec.num[i];
                        if (stoi(s2) + stoi(s) <= 9) {
                            tempint = stoi(s) + stoi(s2);
                        } else {
                            tempint = stoi(s) + stoi(s2) - 10;
                            num[i] = tempint + 48;
                            int c = 1;
                            int check = num[i - c] - '0';
                            while ((check + 1) > 9) {
                                num[i - c] = '0';
                                c++;
                                check = num[i - c] - '0';
                            }
                            // s=num[i-c];
                            num[i - c] += 1;
                            // str[i-c+1]=num[i-c];
                        }
                        num[i] = (tempint) + 48;
                    }
                    string str;
                    str = num;
                    return BigDecimalInt(str);
                }
            }
            else if (sign() != anotherDec.sign()) {
                if (sign() > anotherDec.sign())
                {
                    //32563+-256
                    //subtract 32563 - 256
                    if (num[0] == '+')
                        num.erase(num.begin());
                    anotherDec.num.erase(anotherDec.num.begin());
                    //char str[num.size()];
                    string str;
                    for (int i = 0; i < sizediff; i++) {
                        anotherDec.num = "0" + anotherDec.num;
                    }
                    for (int i = num.size() - 1; i >= 0; i--) {
                        s = num[i];
                        s2 = anotherDec.num[i];
                        if (stoi(s2) <= stoi(s)) {
                            tempint = stoi(s) - stoi(s2);
                        } else {
                            tempint = stoi(s) + 10 - stoi(s2);
                            int c = 1;
                            int check = num[i - c] - '0';
                            while ((check) < 1) {
                                num[i - c] = '9';
                                c++;
                                check = num[i - c] - '0';
                            }
                            s = num[i - c];
                            num[i - c] = (stoi(s) - 1) + 48;
                        }
                        num[i] = (tempint) + 48;
                    }
                    str = num;
                    return BigDecimalInt(str);
                }
                else if (sign() < anotherDec.sign()) {
                    //-32569
                    //325
                    //subtract
                    if (anotherDec.num[0] == '+')
                        anotherDec.num.erase(anotherDec.num.begin());
                    num.erase(num.begin());
                    string str;
                    for (int i = 0; i < sizediff; i++) {
                        anotherDec.num = "0" + anotherDec.num;
                    }
                    for (int i = num.size() - 1; i >= 0; i--) {
                        s = num[i];
                        s2 = anotherDec.num[i];
                        if (stoi(s2) <= stoi(s)) {
                            tempint = stoi(s) - stoi(s2);
                        } else {
                            tempint = stoi(s) + 10 - stoi(s2);
                            int c = 1;
                            int check = num[i - c] - '0';
                            while ((check) < 1) {
                                num[i - c] = '9';
                                c++;
                                check = num[i - c] - '0';
                            }
                            s = num[i - c];
                            num[i - c] = (stoi(s) - 1) + 48;
                        }
                        num[i] = (tempint) + 48;
                    }
                    str = num;
                    str = "-" + str;
                    return BigDecimalInt(str);
                }
            }
        }
            //**************************************************************
        else if (size() < anotherDec.size()) {
            int tempint = 0;
            int sizediff = anotherDec.size() - size();
            if (sign() == anotherDec.sign()) {
                if (sign() == 0) {
                    //32502+3625142
                    //add
                    if (num[0] == '+')
                        num.erase(num.begin());
                    if (anotherDec.num[0] == '+')
                        anotherDec.num.erase(anotherDec.num.begin());
                    anotherDec.num = "0" + anotherDec.num;
                    for (int i = 0; i <= sizediff; i++) {
                        num = "0" + num;
                    }
                    for (int i = anotherDec.num.size() - 1; i >= 0; i--) {
                        s2 = num[i];
                        s = anotherDec.num[i];
                        if (stoi(s2) + stoi(s) <= 9) {
                            tempint = stoi(s) + stoi(s2);
                        } else {
                            tempint = stoi(s) + stoi(s2) - 10;
                            anotherDec.num[i] = tempint + 48;
                            int c = 1;
                            int check = anotherDec.num[i - c] - '0';
                            while ((check + 1) > 9) {
                                anotherDec.num[i - c] = '0';
                                c++;
                                check = anotherDec.num[i - c] - '0';
                            }
                            // s=num[i-c];
                            anotherDec.num[i - c] += 1;
                            // str[i-c+1]=num[i-c];
                        }
                        anotherDec.num[i] = (tempint) + 48;
                    }
                    string str;
                    str = anotherDec.num;
                    return BigDecimalInt(str);

                } else if (sign() == -1) {
                    //-325+-362502
                    //add -
                    num.erase(num.begin());
                    anotherDec.num.erase(anotherDec.num.begin());
                    anotherDec.num = "0" + anotherDec.num;
                    for (int i = 0; i <= sizediff; i++) {
                        num = "0" + num;
                    }
                    for (int i = anotherDec.num.size() - 1; i >= 0; i--) {
                        s2 = num[i];
                        s = anotherDec.num[i];
                        if (stoi(s2) + stoi(s) <= 9) {
                            tempint = stoi(s) + stoi(s2);
                        } else {
                            tempint = stoi(s) + stoi(s2) - 10;
                            anotherDec.num[i] = tempint + 48;
                            int c = 1;
                            int check = anotherDec.num[i - c] - '0';
                            while ((check + 1) > 9) {
                                anotherDec.num[i - c] = '0';
                                c++;
                                check = anotherDec.num[i - c] - '0';
                            }
                            anotherDec.num[i - c] += 1;
                        }
                        anotherDec.num[i] = (tempint) + 48;
                    }
                    string str;
                    str = anotherDec.num;
                    str = "-" + str;
                    return BigDecimalInt(str);
                }
            } else if (sign() != anotherDec.sign()) {
                if (sign() > anotherDec.sign()) {
                    //325+-32263
                    // subs 332263 - 325 -
                    if (num[0] == '+')
                        num.erase(num.begin());
                    anotherDec.num.erase(anotherDec.num.begin());
                    string str;
                    for (int i = 0; i < sizediff; i++) {
                        num = "0" + num;
                    }
                    for (int i = anotherDec.num.size() - 1; i >= 0; i--) {
                        s2 = num[i];
                        s = anotherDec.num[i];
                        if (stoi(s2) <= stoi(s)) {
                            tempint = stoi(s) - stoi(s2);
                        } else {
                            tempint = stoi(s) + 10 - stoi(s2);
                            int c = 1;
                            int check = anotherDec.num[i - c] - '0';
                            while ((check) < 1) {
                                anotherDec.num[i - c] = '9';
                                c++;
                                check = anotherDec.num[i - c] - '0';
                            }
                            s = anotherDec.num[i - c];
                            anotherDec.num[i - c] = (stoi(s) - 1) + 48;
                        }
                        anotherDec.num[i] = (tempint) + 48;
                    }
                    str = anotherDec.num;
                    str = "-" + str;
                    return BigDecimalInt(str);
                } else if (sign() < anotherDec.sign()) {
                    //-325+3026541
                    //3026541 - 325 subtract
                    string str;
                    if (anotherDec.num[0] == '+')
                        anotherDec.num.erase(num.begin());
                    num.erase(num.begin());
                    for (int i = 0; i < sizediff; i++) {
                        num = "0" + num;
                    }
                    for (int i = anotherDec.num.size() - 1; i >= 0; i--) {
                        s2 = num[i];
                        s = anotherDec.num[i];
                        if (stoi(s2) <= stoi(s)) {
                            tempint = stoi(s) - stoi(s2);
                        } else {
                            tempint = stoi(s) + 10 - stoi(s2);
                            int c = 1;
                            int check = anotherDec.num[i - c] - '0';
                            while ((check) < 1) {
                                anotherDec.num[i - c] = '9';
                                c++;
                                check = anotherDec.num[i - c] - '0';
                            }
                            s = anotherDec.num[i - c];
                            anotherDec.num[i - c] = (stoi(s) - 1) + 48;
                        }
                        anotherDec.num[i] = (tempint) + 48;
                    }
                    str = anotherDec.num;
                    return BigDecimalInt(str);
                }
            }
        }
            //******************************************************
        else if (size() == anotherDec.size()) {
            int tempint;
            if (sign() == anotherDec.sign()) {
                if (sign() == 0) {
                    //990+990
                    //add
                    if (num[0] == '+')
                        num.erase(num.begin());
                    if (anotherDec.num[0] == '+')
                        anotherDec.num.erase(anotherDec.num.begin());
                    anotherDec.num = "0" + anotherDec.num;
                    num = "0" + num;
                    for (int i = anotherDec.num.size() - 1; i >= 0; i--) {
                        s2 = num[i];
                        s = anotherDec.num[i];
                        if (stoi(s2) + stoi(s) <= 9) {
                            tempint = stoi(s) + stoi(s2);
                        } else {
                            tempint = stoi(s) + stoi(s2) - 10;
                            anotherDec.num[i] = tempint + 48;
                            int c = 1;
                            int check = anotherDec.num[i - c] - '0';
                            while ((check + 1) > 9) {
                                anotherDec.num[i - c] = '0';
                                c++;
                                check = anotherDec.num[i - c] - '0';
                            }
                            anotherDec.num[i - c] += 1;
                        }
                        anotherDec.num[i] = (tempint) + 48;
                    }
                    string str;
                    str = anotherDec.num;
                    return BigDecimalInt(str);
                }
                else if (sign() == -1) {
                    num.erase(num.begin());
                    anotherDec.num.erase(anotherDec.num.begin());
                    anotherDec.num = "0" + anotherDec.num;
                    num = "0" + num;
                    for (int i = anotherDec.num.size() - 1; i >= 0; i--) {
                        s2 = num[i];
                        s = anotherDec.num[i];
                        if (stoi(s2) + stoi(s) <= 9) {
                            tempint = stoi(s) + stoi(s2);
                        } else {
                            tempint = stoi(s) + stoi(s2) - 10;
                            anotherDec.num[i] = tempint + 48;
                            int c = 1;
                            int check = anotherDec.num[i - c] - '0';
                            while ((check + 1) > 9) {
                                anotherDec.num[i - c] = '0';
                                c++;
                                check = anotherDec.num[i - c] - '0';
                            }
                            anotherDec.num[i - c] += 1;
                        }
                        anotherDec.num[i] = (tempint) + 48;
                    }
                    string str;
                    str = anotherDec.num;
                    if(stoi(str)!=0)
                        str = "-" + str;

                    return BigDecimalInt(str);
                }
            }
            else if (sign() != anotherDec.sign()) {
                if (sign() > anotherDec.sign()) {
                    //328+-225
                    //subtract 328 - 225 +
                    //326+-429
                    //subtract 429 - 326 -
                    if (num[0] == '+') {
                        num.erase(num.begin());
                    }
                    anotherDec.num.erase(anotherDec.num.begin());
                    string str;
                    if (num[0] >= anotherDec.num[0]) {
                        for (int i = num.size() - 1; i >= 0; i--) {
                            s = num[i];
                            s2 = anotherDec.num[i];
                            if (stoi(s2) <= stoi(s)) {
                                tempint = stoi(s) - stoi(s2);
                            } else {
                                tempint = stoi(s) + 10 - stoi(s2);
                                int c = 1;
                                int check = num[i - c] - '0';
                                while ((check) < 1) {
                                    num[i - c] = '9';
                                    c++;
                                    check = num[i - c] - '0';
                                }
                                s = num[i - c];
                                num[i - c] = (stoi(s) - 1) + 48;
                            }
                            num[i] = (tempint) + 48;
                        }
                        str = num;
                    }
                    else if (anotherDec.num[0] > num[0]) {
                        for (int i = num.size() - 1; i >= 0; i--) {
                            s2 = num[i];
                            s = anotherDec.num[i];
                            if (stoi(s2) <= stoi(s)) {
                                tempint = stoi(s) - stoi(s2);
                            } else {
                                tempint = stoi(s) + 10 - stoi(s2);
                                int c = 1;
                                int check = anotherDec.num[i - c] - '0';
                                while ((check) < 1) {
                                    anotherDec.num[i - c] = '9';
                                    c++;
                                    check = anotherDec.num[i - c] - '0';
                                }
                                s = anotherDec.num[i - c];
                                anotherDec.num[i - c] = (stoi(s) - 1) + 48;
                            }
                            anotherDec.num[i] = (tempint) + 48;
                        }
                        str = anotherDec.num;
                        if(stoi(str)!=0)
                            str = "-" + str;
                    }
                    return BigDecimalInt(str);
                }
                else if (sign() < anotherDec.sign()) {
                    if (anotherDec.num[0] == '+') {
                        anotherDec.num.erase(anotherDec.num.begin());
                    }
                    num.erase(num.begin());
                    string str;
                    if (num[0] >= anotherDec.num[0]) {
                        for (int i = num.size() - 1; i >= 0; i--) {
                            s = num[i];
                            s2 = anotherDec.num[i];
                            if (stoi(s2) <= stoi(s)) {
                                tempint = stoi(s) - stoi(s2);
                            } else {
                                tempint = stoi(s) + 10 - stoi(s2);
                                int c = 1;
                                int check = num[i - c] - '0';
                                while ((check) < 1) {
                                    num[i - c] = '9';
                                    c++;
                                    check = num[i - c] - '0';
                                }
                                s = num[i - c];
                                num[i - c] = (stoi(s) - 1) + 48;
                            }
                            num[i] = (tempint) + 48;
                        }
                        str = num;
                        if(stoi(str)!=0)
                            str = "-" + str;
                    }
                    else if (anotherDec.num[0] > num[0]) {
                        for (int i = num.size() - 1; i >= 0; i--) {
                            s2 = num[i];
                            s = anotherDec.num[i];
                            if (stoi(s2) <= stoi(s)) {
                                tempint = stoi(s) - stoi(s2);
                            } else {
                                tempint = stoi(s) + 10 - stoi(s2);
                                int c = 1;
                                int check = anotherDec.num[i - c] - '0';
                                while ((check) < 1) {
                                    anotherDec.num[i - c] = '9';
                                    c++;
                                    check = anotherDec.num[i - c] - '0';
                                }
                                s = anotherDec.num[i - c];
                                anotherDec.num[i - c] = (stoi(s) - 1) + 48;
                            }
                            anotherDec.num[i] = (tempint) + 48;
                        }
                        str = anotherDec.num;
                    }
                    return BigDecimalInt(str);
                }
            }
        }
    }

    //___________________________________________________________
    bool BigDecimalInt::operator> (BigDecimalInt anotherDec){
        bool b = false;
        if(sign()==anotherDec.sign()) {
            if (num[0] == '-') {
                num.erase(num.begin());
                anotherDec.num.erase(anotherDec.num.begin());
                if (size() > anotherDec.size()) {
                    b = false;
                } else if (size() < anotherDec.size()) {
                    b = true;
                }
                else {
                    for (int i = 0; i < size(); i++) {
                        if (num[i] < anotherDec.num[i]) {
                            b = true;
                            break;
                        } else if (num[i] > anotherDec.num[i]) {
                            b = false;
                            break;
                        } else
                            continue;
                    }

                }
            }
            else if (sign()==0) {
                if (size()>anotherDec.size()){
                    b= true;
                }
                else if(size()<anotherDec.size()){
                    b= false;
                }
                else {
                    for (int i = 0; i < size(); i++) {
                        if (num[i] < anotherDec.num[i]) {
                            b = false;
                            break;
                        } else if (num[i] > anotherDec.num[i]) {
                            b = true;
                            break;
                        }
                        else
                            continue;
                    }
                }

            }
        }
        else if (sign()!=anotherDec.sign()){
            if(sign()==-1 && anotherDec.sign()==0) {
                b = false;
            }
            else {
                b = true;
            }
        }
        return b;
    }
    //___________________________________________________________
    bool BigDecimalInt:: operator< (BigDecimalInt anotherDec){
        bool b = false;
        if(sign()==anotherDec.sign()) {
            if (sign()==-1) {
                num.erase(num.begin());
                anotherDec.num.erase(anotherDec.num.begin());
                if (size() < anotherDec.size()) {
                    b = false;
                }
                else if (size() > anotherDec.size()) {
                    b = true;
                }
                else {
                    for (int i = 0; i < size(); i++) {
                        if (num[i] > anotherDec.num[i]) {
                            b = true;
                            break;
                        }
                        else if (num[i] < anotherDec.num[i]) {
                            b = false;
                            break;
                        }
                    }

                }
            }
            else if (sign()==0) {
                if(num[0]=='+')
                    num.erase(num.begin());
                if(anotherDec.num[0]=='+')
                    anotherDec.num.erase(anotherDec.num.begin());
                if (size()<anotherDec.size()){
                    b= true;
                }
                else if(size()>anotherDec.size()){
                    b= false;
                }
                else {
                    for (int i = 0; i < size(); i++) {
                        if (num[i] > anotherDec.num[i]) {
                            b = false;
                            break;
                        } else if (num[i] < anotherDec.num[i]) {
                            b = true;
                            break;
                        }
                    }
                }

            }
        }
        else if (sign()!=anotherDec.sign()){
            if(sign()==-1 && anotherDec.sign()==0) {
                b = true;
            }
            else {
                b = false;
            }
        }
        return b;
    }
    //___________________________________________________________
    bool BigDecimalInt:: operator== (BigDecimalInt anotherDec){
       bool b;
       if((size()!=anotherDec.num.size()) or (sign()!= anotherDec.sign()))
           b=false;
       else {
           for (int i = 0; i < size();i++) {
               if (num[i] == anotherDec.num[i])
                   b=true;
               else {
                   b = false;
                   break;
               }
           }
       }
       return b;
    }
    //______________________________________________________
    BigDecimalInt BigDecimalInt:: operator= (BigDecimalInt anotherDec){
        num=anotherDec.num;
    }
    //_____________________________________________________________________
   ostream& operator<<(ostream & out, BigDecimalInt& b){
        out<<b.num;
    }
   //_______________________________________________________
BigDecimalInt::~BigDecimalInt()
{
    //dtor
}
