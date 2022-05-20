#include<iostream>
#include<fstream>
#include<windows.h>
using namespace std;
int main()
{
//	ios_base::sync_with_stdio(0);
	cin.tie(0);
	long long k;
	fstream fs;
	fs.open("k.txt");
	fs>>k;
	fs.close();
	while(1)
	{
		fs.open("清單.txt",ios::in);
		char ch[100];
		for(int q=0;q<k;q++) fs.getline(ch,sizeof(ch));
		while(fs.getline(ch,sizeof(ch)))
		{
			k++;
			cout<<ch<<'\n';
		}
		cout<<'\n';	
		fs.close();
//		cout<<"是否開始？ (y/n) ";
		system("pause");
		fs.open("k.txt");
		fs<<k;
		fs.close();
		system("cls");
		Sleep(500);
	}
	
 } 
