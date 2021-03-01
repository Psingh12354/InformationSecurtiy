#include <iostream>
#include <cctype> 
#include <cstring>
#include <vector> 
using namespace std;
void HillCipherEncryption(string message, string key){
	int keyMatrix[3][3];
	int k = 0,x,j,i;
	for ( i = 0; i < 3; i++)
	{
		for ( j = 0; j < 3; j++)
		{
			keyMatrix[i][j] = (key[k]) % 65;
			k++;
		}
	}
	int messageVector[3][1];
	for ( i = 0; i < 3; i++)
		messageVector[i][0] = (message[i]) % 65;
		int cipherMatrix[3][1];
		for (i = 0; i < 3; i++)
		{
			for (j = 0; j < 1; j++)
			{
				cipherMatrix[i][j] = 0;
				for (x = 0; x < 3; x++)
				{
					cipherMatrix[i][j] += keyMatrix[i][x]* messageVector[x][j];
				}
			cipherMatrix[i][j] = cipherMatrix[i][j] % 26;
		}
	}
	string CipherText;
	for (int i = 0; i < 3; i++)
		CipherText += cipherMatrix[i][0] + 65;
		cout << "\nCiphertext:" << CipherText;
	}
void HillCipherDecryption(string message, string key){
	int keyMatrix[3][3];
	int k = 0,x,j,i;
	int mat[3][3];
	float determinant = 0;
	for ( i = 0; i < 3; i++)
	{
		for ( j = 0; j < 3; j++)
		{
			keyMatrix[i][j] = (key[k]) % 65;
			mat[i][j]= keyMatrix[i][j];
			k++;
		}
	}
	int messageVector[3][1];
	for ( i = 0; i < 3; i++)
		messageVector[i][0] = (message[i]) % 65;
		for(i = 0; i < 3; i++)
			determinant = determinant + (mat[0][i] * (mat[1][(i+1)%3]* mat[2][(i+2)%3] - mat[1][(i+2)%3] * mat[2][(i+1)%3]));
	 	cout<<"\n\ndeterminant: "<<determinant;
	int a=determinant;
	int r;
	for(int i=0;i<=25;i++)
	{
		r=(a*i)%26;
		if(r==1)
	 	{
	 		r=i;
	 		break;
	 	}
	}
	int mat1[3][3];
	cout<<"\nMultiplicative inverse:"<<r;
	cout<<"\n\nInverse of matrix is: \n";
	for(i = 0; i < 3; i++){
	 	for(j = 0; j < 3; j++)
	 	{
	 		mat1[i][j]=((mat[(j+1)%3][(i+1)%3] *mat[(j+2)%3][(i+2)%3]) - (mat[(j+1)%3][(i+2)%3] *mat[(j+2)%3][(i+1)%3]));
	 		cout<<mat1[i][j]<<"\t";
	 	}
	cout<<"\n";
	}
	cout<<"\n POSITIVE VALUES\n";
	for(int i = 0; i < 3; i++){
	 	for(int j = 0; j < 3; j++)
	 	{
	 		while(mat1[i][j]<0)
		 	{
		 		int z=1;
	 			mat1[i][j]=mat1[i][j]+26*z;
	 		}
	 	cout<<mat1[i][j]<<"\t";
		}
	cout<<"\n";
	}
	cout<<"after multiplication with multiplicative inverse\n";
	for(int i = 0; i < 3; i++){
	 	for(int j = 0; j < 3; j++)
	 	{
	 		keyMatrix[i][j]=(r*mat1[i][j])%26;
	 		cout<<keyMatrix[i][j]<<"\t";
	 	}
	cout<<"\n";
	}
	int plainMatrix[3][1];
	for(i = 0; i < 3; i++)
	{
		for(j = 0; j < 1; j++)
		{
			plainMatrix[i][j] = 0;
			for(x = 0; x < 3; x++)
			{	
				plainMatrix[i][j] += keyMatrix[i][x]* messageVector[x][j];
			}
		plainMatrix[i][j] = plainMatrix[i][j] % 26;
		}
	}
	string PlainText;
	for (int i = 0; i < 3; i++)
		PlainText += plainMatrix[i][0] + 65;
		cout << "\nPlain text:" << PlainText;
	}
	int main()
	{
	string message,key;
	int option;
	cout<<"Enter message (in uppercase):";
	cin>>message;
	cout<<"Enter KEY (in uppercase):";
	cin>>key;
	cout<<"Enter your option:\n 1. Encryption \n 2. Decryption\n";
	cin>>option;
	if(option==1)
	{
		HillCipherEncryption(message, key);
	}
	else{
		HillCipherDecryption(message, key);
	}
}
