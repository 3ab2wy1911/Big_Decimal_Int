# Big_Decimal_Int
## The idea of the code
* Different variations of types int and float exist in C++ and other languages. 
* They are limited by minimum and maximum values depending on the number of bytes used to store the number.
* So We developed Big_Decimal_Int a C++ type (class) that can hold unlimited decimal integer values and performs arithmetic operations on them "like BigInteger and BigDecimal classes in Java". 
## Some features and functions of the class
* BigDecimalInt (string decStr); // Initializes from string & rejects bad input
* BigDecimalInt (int decInt); // Initialize from integer
* BigDecimalInt operator+ (BigDecimalInt anotherDec); // member fn
* BigDecimalInt operator- (BigDecimalInt anotherDec); // member fn
* bool operator< (BigDecimalInt anotherDec); // member fn
* bool operator> (BigDecimalInt anotherDec); // member fn
* bool operator==(BigDecimalInt anotherDec); // member fn
* BigDecimalInt operator= (BigDecimalInt anotherDec); // member fn
* int size(); // member fn
* int sign(); // member fn
* friend ostream& operator << (ostream& out, BigDecimalInt b)
