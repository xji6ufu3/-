#include<iostream>
#include<sstream>
#include<fstream>
#include<string.h>
#include<stdio.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	//cin.tie(0);
	string a;
	int s,number,kka;
	bool kk;
	int price[12]={35,30,40,20,25,35,25,60,90,50,50,100},ops[12]={};
	char c;
	string kc;
	float cc,total,sumfir,sumsc,sum; 
	cout<<"���O�G\n\"stop\"����{��\n\"clear\"�M������x��X\n";
	fstream ofs;
	ofs.open("total.txt");
	ofs>>total;
	ofs.close();
//	string good[12]={"���ű��߲ʤg����(������)","�תջĦ����ζ���(������)","�������ΥثͶ�(�Q�p��)  ","�Y���������Y(��K�Y)    ","�j�������J����(������)  ","�ſ}����J��(�A���T)    ","�������`(������)        ","���j�M�\\(C+E)           ","�����j�M�\\(A+C+D)       ","�M�n�Ĥ@��(D+F)         ","�M�n�ĤG��(B+G)         ","�j����(B+C+D+E)        "};
	string good[12]={"������","������","�Q�p��","��K�Y","������","�A���T","������","�Q�p�� + ������","������ + �Q�p�� + ��K�Y","��K�Y + �A���T","������ + ������","������ + ������ + ��K�Y + �Q�p��"};
	while(cout<<"-------------------------------------\n\n�\\�I�s���G " , cin>>a){
		bool kb=0;
		kk=1;
		ofs.open("�s��.txt");
		ofs>>number;
		ofs.close();
		ofs.open("�M��.txt",ios::app); // �Ϥ�󤣾D���л\�A�i�q���ݷs�W��� 
		if(a=="stop" or a=="Stop") break;
		else if(a=="clear" or a=="Clear"){
			system("cls");
			cout<<"���O�G\n\"stop\"����{��\n\"clear\"�M������x��X\n";
			continue;
		}
		stringstream ss(a);
		int k=0;
		sum=0;
		sumfir=0;
		sumsc=0;
		kka=0;
		cout<<"����G";
		cc=10;
		cin>>kc;
		kka=0;
		if(kc == "8" or kc == "9") cc=(int)kc[0]-'1';
		else if(kc == "0" or kc == "n" or kc == "N") cc = 10;
		else if(kc=="10" ) kka=10;
		else if(kc=="20") kka=20;
		else{
			cout<<"��J���~\n";
			ofs<<"��J���~\n-------------------------------------\n";
			ofs.close();
			kk=0;
		}
		cout<<"�O�_��J���T�H(y/n) ";
		cin>>kc;
		if(kc=="N" or kc=="n"){
			ofs<<"��J���~\n-------------------------------------\n";
			ofs.close();
			kk=0;
		}
		if(kk){
		cout<<"-------------------------------------\n���ӡG\n";
		ofs<<"���ӡG\n";
		cout<<"�I�\\���G "<<number<<"\n\n";
		ofs<<"�I�\\���G "<<number<<"\n\n";
		number++;
		ofs.close();
		ofs.open("�s��.txt");
		ofs<<number;
		ofs.close();
		ofs.open("�M��.txt",ios::app);
		for(int q=0;q<a.size();q++){
			c=a[q];
			if(c>='A' and c<='L') s=(int)(c-'A');
			else if(c>='a' and c<='l') s=(int)(c-'a');
			else if((c>'L' and c<='Z') or (c>'l' and c<='z')){
				cout<<"��J�榡���~�A�N���� A~H �� a~h (�����j�p�g)\n";
				ofs<<"��J�榡���~\n-------------------------------------\n";
				sum = sumfir+sumsc;
				total-=sum;
				ofs.close();
				kk=0;
			}
			else{
				cout<<"��J�榡���~�A�ȯ��J�r��\n";
				ofs<<"��J�榡���~*\n-------------------------------------\n";
				sum = sumfir+sumsc;
				total-=sum;
				ofs.close();
				kk=0;
			}
			if(kk){
			k++;
			ops[s]++;
			}	
		}
		if(kk){
		while(1){
			if(ops[1] and ops[2] and ops[3] and ops[4]){
				ops[1]--;
				ops[2]--;
				ops[3]--;
				ops[4]--;
				ops[11]++;//L
				kb=1;
			}
			else if(ops[0] and ops[2] and ops[3]){
				ops[0]--;
				ops[2]--;
				ops[3]--;
				ops[8]++;//I
				kb=1;
			}
			else if(ops[2] and ops[4]){
				ops[2]--;
				ops[4]--;
				ops[7]++;//H
				kb=1;
			}
			else if(ops[3] and ops[5]){
				ops[3]--;
				ops[5]--;
				ops[9]++;//J
				kb=1;
			}
			else if(ops[1] and ops[6]){
				ops[3]--;
				ops[5]--;
				ops[10]++;//K
				kb=1;
			}
			else break;
		}
		for(int q=5;q<7;q++) kka+=ops[q]*5;
		for(int q=0;q<12;q++){
			if(q>6) sumsc=sumsc+price[q]*ops[q];
			else sumfir=sumfir+price[q]*ops[q];
		}
		sum = sumfir+sumsc;
		if(sum < 50) cc = 10; 
		if(cc==8.0 or cc==9.0) sumfir = sumfir * cc / 10;
		sum = sumfir+sumsc-kka;
		total+=sum;
		int nt=1;
		for(int q=0;q<12;q++){
			if(ops[q]){
				if(q<=6){
					cout<<nt<<". "<<good[q]<<" * "<<ops[q]<<"��  �@�G"<<(int)(price[q] * cc * ops[q] / 10.0)<<"��\n";
					ofs<<nt<<". "<<good[q]<<" * "<<ops[q]<<"��  �@�G"<<(int)(price[q] * cc * ops[q] / 10.0)<<"��\n";
				}
				else{
					cout<<nt<<". "<<good[q]<<" * "<<ops[q]<<"��  �@�G"<<price[q] * ops[q]<<"��\n";
					ofs<<nt<<". "<<good[q]<<" * "<<ops[q]<<"��  �@�G"<<price[q] * ops[q]<<"��\n";
				}
				nt++;
			}
		}
		}
		if(kk){
		cout<<"\n�`�p "<<(int)sum<<" ��\n�`��~�B�G "<<(int)total<<" ��\n";
		ofs<<"\n�`�p "<<(int)sum<<" ��\n�`��~�B�G "<<(int)total<<" ��\n-------------------------------------\n";
		ofs.close();
		}
		}
		if(kk){ 
		ofs.open("total.txt");
		ofs<<total;
		ofs.close();
		ofs.open("�`��.txt");
		string str[12];
		int num[12];
		for(int q=0;q<12;q++){
			ofs>>str[q]>>num[q];
		}
		ofs.close();
		ofs.open("�`��.txt",std::ios::out | std::ios::trunc);
		for(int q=0;q<12;q++){
			ofs<<str[q]<<" "<<num[q]+ops[q]<<'\n';
		}
		ofs.close();
		}
		memset(ops,0,sizeof(ops));
	}
}
