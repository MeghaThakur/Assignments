#include <sstream>

#include<iostream>
#include<stdio.h>
 #include<math.h>
#include<string>
#include<stdlib.h>
#include<time.h>

using namespace std;
long int mult(string X, string Y);
int makeEqualLength(string &str1, string &str2);
string addBitStrings( string first, string second );
int multiSingleBit(string a, string b);



int main()
{
	clock_t begin=clock();
    long x=mult("1234", "1050");
    clock_t end=clock();
    printf ("%ld\n",x );

    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
printf("Elapsed time: %.2f.\n",time_spent);
}


int makeEqualLength(string &str1, string &str2)
{
    int len1 = str1.size();
    int len2 = str2.size();
    if (len1 < len2)
    {
        for (int i = 0 ; i < len2 - len1 ; i++)
            str1 = '0' + str1;
        return len2;
    }
    else if (len1 > len2)
    {
        for (int i = 0 ; i < len1 - len2 ; i++)
            str2 = '0' + str2;
    }
    return len1; 
}

string addBitStrings( string first, string second )
{
	int var1 = atoi(first.c_str());
	int var2 = atoi(second.c_str());
	int resultt=var1+var2;
	std::string result = std::to_string(resultt);
    return result;
}
 int multiSingleBit(string a, string b)
{  int var1 = atoi(a.c_str());
	int var2 = atoi(b.c_str());
	int result=var1*var2;
	return result;
    }

long int mult(string X, string Y)
{
    
    int n = makeEqualLength(X, Y);
 
       if (n == 0) return 0;
    if (n == 1) return multiSingleBit(X, Y);
 
    int fh = n/2;   
    int sh = (n-fh); 
 
    string Xl = X.substr(0, fh);
    string Xr = X.substr(fh, sh);
 
    string Yl = Y.substr(0, fh);
    string Yr = Y.substr(fh, sh);
 
   
    long int P1 = mult(Xl, Yl);
    long int P2 = mult(Xr, Yr);
    long int P3 = mult(addBitStrings(Xl, Xr), addBitStrings(Yl, Yr));

    return P1*pow(10,n)+(P3-P1-P2)*pow(10,n/2)+P2;
}
