#include<iostream>
#include <string>
#include<vector>
using namespace std;
int main() {
 char
arr[5][5]={{'M','O','N','A','R'},{'C','H','Y','B','D'},{'E','F','G','I','K'},{'L','P','Q','S','T'},{'U','V','W','X','Z'}};
 char pt[100];
 int i, j, length;
 cout<<"Playfair Keymatrix\n==================\n";
 for(i=0; i<5; i++)
 {
 for(j=0; j<5; j++)
 cout<<arr[i][j]<<" ";
 cout<<"\n";
 }
 cout<<"Enter the message:\n";
 cin.getline(pt,100);
	for(int i=0;i<100;i++)
	{
		pt[i]=toupper(pt[i]);
	
	}
//	char c;
//	for(int i=0;i<100;i++){
//		char a=pt[i];
//		char b=pt[i+1];
//		
//		if(a==b){
//			c=b;
//			pt[i+1]='X';
//			pt[i+2]=c;
//		}
//	}
 int r1=0, r2=0, c1=0, c2=0;
 cout<<"Cipher text:";
 int k=0;
 while(pt[k] != '\0')
 {
 for(i=0; i<5; i++)
 {
 for(j=0; j<5; j++)
 {
 if(arr[i][j] == pt[k])
 {
 r1=i; c1=j;
 }
 if(arr[i][j] == pt[k+1])
 {
 r2=i; c2=j;
 }
 }
 }
 if(r1==r2) 
 {
 if(c2==4)
 cout<< arr[r1][c1+1]<< arr[r2][0];
 else if (c1==4)
 cout<< arr[r1][0]<< arr[r2][c2+1];
 else
 cout<< arr[r1][c1+1]<< arr[r2][c2+1];
 }
if(c1==c2)
 {
 if(r2==4)
 cout<< arr[r1+1][c1]<< arr[0][c2];
 else if (r1==4)
 cout<< arr[0][c1]<< arr[r2+1][c2];
 else
 cout<< arr[r1+1][c1]<< arr[r2+1][c2];
 }
 if(r1 != r2 && c1 != c2)
 {
 cout<< arr[r1][c2]<< arr[r2][c1];
 }
 k=k+2;
 }
}

