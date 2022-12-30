#include <iostream>
#include "BigDicimalInt.h"
#include <stdlib.h>
using namespace std;

int main()
{
    string input1;
    int answer;
    string input2;
    cout<<"Please , enter first number : ";
    getline(cin,input1);
    cout<<"Please, enter the second number : ";
    getline(cin,input2);
    cout<<"Please , enter the number of the operator :\n";
    cout<<"1. + \n2. -\n3. compare\n";
    cin>>answer;
   BigDecimalInt num1 (input1);
   BigDecimalInt num2 (input2);
   if(answer ==1){
          BigDecimalInt sum(num1 + num2 );
          cout<<input1<<" + "<<input2<<" = "<<sum;
   }
   else if (answer==2){
       BigDecimalInt diff(num1 - num2);
       cout<<input1<<" - "<<input2<<" = "<<diff;
   }
   else if (answer==3){
    if(num1>num2)
        cout<<"First number"<<" > "<<"Second number\n";
    else if(num1<num2)
        cout<<"First number"<<" < "<<"Second number\n";
    else if(num1==num2)
        cout<<"The two numbers are equal\n";
   }
}
