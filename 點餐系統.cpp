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
	cout<<"指令：\n\"stop\"停止程式\n\"clear\"清除控制台輸出\n";
	fstream ofs;
	ofs.open("total.txt");
	ofs>>total;
	ofs.close();
//	string good[12]={"高溫殺菌粗土豆條(粗薯條)","脂肪酸佐食用塊莖(細薯條)","鳥綱雞形目屍塊(鹽酥雞)  ","頭足綱墨魚丸(花枝丸)    ","大豆分離蛋白鏈(甜不辣)  ","乳糖膠原蛋白(鮮奶酪)    ","茶紅素胜(紅茶凍)        ","盛大套餐\(C+E)           ","極盛大套餐\(A+C+D)       ","清爽第一式(D+F)         ","清爽第二式(B+G)         ","大滿足(B+C+D+E)        "};
	string good[12]={"粗薯條","細薯條","鹽酥雞","花枝丸","甜不辣","鮮奶酪","紅茶凍","鹽酥雞 + 甜不辣","粗薯條 + 鹽酥雞 + 花枝丸","花枝丸 + 鮮奶酪","細薯條 + 紅茶凍","細薯條 + 甜不辣 + 花枝丸 + 鹽酥雞"};
	while(cout<<"-------------------------------------\n\n餐\點編號： " , cin>>a){
		bool kb=0;
		kk=1;
		ofs.open("叫號.txt");
		ofs>>number;
		ofs.close();
		ofs.open("清單.txt",ios::app); // 使文件不遭到覆蓋，可從尾端新增資料 
		if(a=="stop" or a=="Stop") break;
		else if(a=="clear" or a=="Clear"){
			system("cls");
			cout<<"指令：\n\"stop\"停止程式\n\"clear\"清除控制台輸出\n";
			continue;
		}
		stringstream ss(a);
		int k=0;
		sum=0;
		sumfir=0;
		sumsc=0;
		kka=0;
		cout<<"打折：";
		cc=10;
		cin>>kc;
		kka=0;
		if(kc == "8" or kc == "9") cc=(int)kc[0]-'1';
		else if(kc == "0" or kc == "n" or kc == "N") cc = 10;
		else if(kc=="10" ) kka=10;
		else if(kc=="20") kka=20;
		else{
			cout<<"輸入錯誤\n";
			ofs<<"輸入錯誤\n-------------------------------------\n";
			ofs.close();
			kk=0;
		}
		cout<<"是否輸入正確？(y/n) ";
		cin>>kc;
		if(kc=="N" or kc=="n"){
			ofs<<"輸入錯誤\n-------------------------------------\n";
			ofs.close();
			kk=0;
		}
		if(kk){
		cout<<"-------------------------------------\n明細：\n";
		ofs<<"明細：\n";
		cout<<"點餐\號： "<<number<<"\n\n";
		ofs<<"點餐\號： "<<number<<"\n\n";
		number++;
		ofs.close();
		ofs.open("叫號.txt");
		ofs<<number;
		ofs.close();
		ofs.open("清單.txt",ios::app);
		for(int q=0;q<a.size();q++){
			c=a[q];
			if(c>='A' and c<='L') s=(int)(c-'A');
			else if(c>='a' and c<='l') s=(int)(c-'a');
			else if((c>'L' and c<='Z') or (c>'l' and c<='z')){
				cout<<"輸入格式錯誤，代號為 A~H 或 a~h (不分大小寫)\n";
				ofs<<"輸入格式錯誤\n-------------------------------------\n";
				sum = sumfir+sumsc;
				total-=sum;
				ofs.close();
				kk=0;
			}
			else{
				cout<<"輸入格式錯誤，僅能輸入字母\n";
				ofs<<"輸入格式錯誤*\n-------------------------------------\n";
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
					cout<<nt<<". "<<good[q]<<" * "<<ops[q]<<"個  共："<<(int)(price[q] * cc * ops[q] / 10.0)<<"元\n";
					ofs<<nt<<". "<<good[q]<<" * "<<ops[q]<<"個  共："<<(int)(price[q] * cc * ops[q] / 10.0)<<"元\n";
				}
				else{
					cout<<nt<<". "<<good[q]<<" * "<<ops[q]<<"個  共："<<price[q] * ops[q]<<"元\n";
					ofs<<nt<<". "<<good[q]<<" * "<<ops[q]<<"個  共："<<price[q] * ops[q]<<"元\n";
				}
				nt++;
			}
		}
		}
		if(kk){
		cout<<"\n總計 "<<(int)sum<<" 元\n總營業額： "<<(int)total<<" 元\n";
		ofs<<"\n總計 "<<(int)sum<<" 元\n總營業額： "<<(int)total<<" 元\n-------------------------------------\n";
		ofs.close();
		}
		}
		if(kk){ 
		ofs.open("total.txt");
		ofs<<total;
		ofs.close();
		ofs.open("總數.txt");
		string str[12];
		int num[12];
		for(int q=0;q<12;q++){
			ofs>>str[q]>>num[q];
		}
		ofs.close();
		ofs.open("總數.txt",std::ios::out | std::ios::trunc);
		for(int q=0;q<12;q++){
			ofs<<str[q]<<" "<<num[q]+ops[q]<<'\n';
		}
		ofs.close();
		}
		memset(ops,0,sizeof(ops));
	}
}
