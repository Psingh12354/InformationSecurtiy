#include<iostream>
#include<math.h>
using namespace std;
long long int power(long long int a, long long int b,long long int P)
{
 	if (b == 1)
 	return a;
 	else
 	return (((long long int)pow(a, b)) % P);
}
int main()
{
 	long long int P, G, x, a, y, b, ka, kb;
 	P = 32; 
 	cout<<"The value of P : "<<P<<"\n";
 	G = 9;
 	cout<<"The value of G :"<<G<<"\n\n";
 	a = 4; 
 	cout<<"The private key a for Alice : "<< a<<"\n";
 	x = power(G, a, P); 
 	b = 3;
 	cout<<"The private key b for Bob : "<<b<<"\n\n";
 	y = power(G, b, P); 
 	ka = power(y, a, P); 
 	cout<<"Secret key for the Alice is : "<< ka<<"\n";
  	kb = power(x, b, P); 
 	cout<<"Secret Key for the Bob is : "<<kb<<"\n";
	return 0;
}

