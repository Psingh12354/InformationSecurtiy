#include<iostream>
#include<math.h>
using namespace std;
int gcd(int a, int b) {
   int t;
   while(1) {
      t= a%b;
      if(t==0)
      return b;
      a = b;
      b= t;
   }
}
int main(){
	double p,q,n,phi,temp,e=7;
	cout<<"Enter p : ";
	cin>>p;
	cout<<"Enter q : ";
	cin>>q;
	n=p*q;
	phi=(p-1)*(q-1);
	while(e<phi){
		temp=gcd(e,phi);
		if(temp==1){
			break;
		}
		else{
			e++;
		}
	}
	double d1=1/e;
	double d=fmod(d1,phi);
	double message=9;
	double c=pow(message,e);
	double m=pow(c,d);
	c=fmod(c,n); //enc
	m=fmod(m,n); //dec
	cout<<"Enter p : "<<p<<"\n";
	cout<<"Enter q : "<<q<<"\n";
	cout<<"Enter message : "<<message<<"\n";
	cout<<"---------------\n";
	cout<<"Original Message : "<<message<<"\n";
	cout<<"n : "<<n<<"\n";
	cout<<"phi : "<<phi<<"\n";
	cout<<"e : "<<e<<"\n";
	cout<<"d : "<<d<<"\n";
	cout<<"Encrypted Message : "<<c<<"\n";
	cout<<"Decrypted Message : "<<m<<"\n";
}
