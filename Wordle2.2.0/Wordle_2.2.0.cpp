#include<bits/stdc++.h>
#include<windows.h>
#include<conio.h>
using namespace std;
const int sye=0xE0,sgre=0xA0,sgra=0x08,swh=0x0F,sli=0xF0;
int yellow=0xE0,green=0xA0,gray=0x08,white=0x0F,light=0xF0;
const int N=10,maxguess=101,maxlen=25;
string version="Wordle 2.2.0";
void scbc(char put,int color){
	if(color==-1) return;
	HANDLE handle=GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(handle,color==0?white:color);
	cout<<put<<" ";
	SetConsoleTextAttribute(handle,white);
}
void scbc(string put,int color){
	HANDLE handle=GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(handle,color==0?white:color);
	cout<<put;
	SetConsoleTextAttribute(handle,white);
}
namespace cc{
	int ye,gre,gra,wh,li,mcs;
	void print(){
		system("cls");
		cout<<version<<endl;
		cout<<"[COLOR SETTING Page]"<<endl<<endl;
		scbc("YELLOW",(mcs==1?light:white));cout<<"   ";scbc('Y',ye);cout<<ye<<endl;
		scbc("GREEN",(mcs==2?light:white));cout<<"    ";scbc('G',gre);cout<<gre<<endl;
		scbc("GRAY",(mcs==3?light:white));cout<<"     ";scbc('G',gra);cout<<gra<<endl;
		scbc("WHITE",(mcs==4?light:white));cout<<"    ";scbc('W',wh);cout<<wh<<endl;
		scbc("LIGHT",(mcs==5?light:white));cout<<"    ";scbc('L',li);cout<<li<<endl<<endl;
		scbc("USING STANDARD COLOR",(mcs==6?light:white));cout<<endl<<endl;
		scbc("SAVE AND EXIT",(mcs==7?light:white));cout<<endl;
		scbc("EXIT WITHOUT SAVING",(mcs==8?light:white));cout<<endl<<endl;
		scbc("COLOR HELP",(mcs==9?light:white));
	}
	void main(){
		ye=yellow,gre=green,gra=gray,wh=white,li=light;
		mcs=1;print();
		while(1){print();
			while(1){
				if(kbhit()){
					char ch=getch();
					if(ch==72 and mcs!=1){mcs--;}
					if(ch==80 and mcs!=9){mcs++;}
					if(ch==13){
						if(mcs==1){
							cout<<"Input Color >>";cin>>ye;
						}
						if(mcs==2){
							cout<<"Input Color >>";cin>>gre;
						}
						if(mcs==3){
							cout<<"Input Color >>";cin>>gra;
						}
						if(mcs==4){
							cout<<"Input Color >>";cin>>wh;
						}
						if(mcs==5){
							cout<<"Input Color >>";cin>>li;
						}
						if(mcs==6){
							ye=sye;
							gre=sgre;
							gra=sgra;
							wh=swh;
							li=sli;
						}
						if(mcs==7){
							yellow=ye;green=gre;
							gray=gra;white=wh;light=li;
							return;
						}
						if(mcs==8){
							return;
						}
						if(mcs==9){
							system("cls");
							system("color help");
							system("cls");
						}
						break;
					}
					print();
				}
			}
		}
	}
}
namespace sett{
	int mcs;
	bool simpl;
	bool lastr;
	bool rands;
	bool aexit;
	string aexitw;
	bool paus;
	void print(){
		system("cls");
		cout<<version<<endl;
		cout<<"[SETTING Page]"<<endl<<endl;
		scbc("SINPLE MODE",(mcs==1?light:white));cout<<"   "<<(simpl?"ON":"OFF")<<endl;
		scbc("RANDOM START PLAYER",(mcs==2?light:white));cout<<"   "<<(rands?"ON":"OFF")<<endl;
		scbc("JUST SHOW LAST RESULT",(mcs==3?light:white));cout<<"   "<<(lastr?"ON":"OFF")<<endl;
		scbc("ACCEPT EXIT WHILE PLAYING",(mcs==4?light:white));cout<<"   "<<(aexit?"ON":"OFF")<<endl;
		scbc("PAUSE WHEN WRONG LENGTH",(mcs==5?light:white));cout<<"   "<<(paus?"ON":"OFF")<<endl<<endl;
		scbc("COLOR SETTING",(mcs==6?light:white));cout<<endl<<endl;
		scbc("EXIT",(mcs==7?light:white));cout<<endl;
	}
	void main(){
		mcs=1;print();
		while(1){print();
		while(1){
			if(kbhit()){
				char ch=getch();
				if(ch==72 and mcs!=1){mcs--;}
				if(ch==80 and mcs!=7){mcs++;}
				if(ch==13){
					if(mcs==1){ system("cls");simpl^=1;}
					if(mcs==2){ system("cls");rands^=1;}
					if(mcs==3){ system("cls");lastr^=1;}
					if(mcs==4){ system("cls");aexit^=1;
					if(aexit){
						system("cls");cout<<"Setting Exit Word >>";cin>>aexitw;
					}
					}
					if(mcs==5){ system("cls");paus^=1;}
					if(mcs==6){ system("cls");cc::main();}
					if(mcs==7){return;}
					break;
				}
				print();
			}
		}
	}
	}
}
int pause(){
	system("cls");
	cout<<"'R' Restart the Game"<<endl;
	cout<<"'H' Return to Home Page"<<endl;
	while(1){
		if(kbhit()){
			char ch=getch();
			if(ch=='r') return 1;
			else return 0;
		}
	}
}
struct state{
	string ans;
	int times,tottimes;
	int judge[maxguess][maxlen];
	string hans[maxguess];
	int guessed[256];
	bool win;
	bool ac[maxlen];
	void clear(string aans,int ttimes){
		tottimes=ttimes;
		ans=aans;
		memset(judge,0,sizeof judge);
		memset(ac,0,sizeof ac);
		win=false;
		memset(guessed,0,sizeof guessed);
		for(int i=1;i<=ttimes;++i) hans[i].clear();
		times=0;
	}
};
vector<string>word;
void readvocabulary(){
	word.clear();
	cout<<"[READ Mode]"<<endl;
	cout<<"Open File Name (If you don't know how to do, just input '0')>>";
	char rea[201];cin>>rea;ifstream f;
	if(rea[0]!='0'){ f.open(rea);}
	else{ f.open("StandardVocabulary.wordle");}
	while(1){
		string in;f>>in;
		if(in=="0") break;
		if(in.empty()) break;
		word.push_back(in);
	}
	if(word.empty()){
		system("cls");
		cout<<"Read File Error"<<endl;
		readvocabulary();
		return;
	}
	cout<<"Read "<<word.size()<<" words."<<endl;
	system("pause");
	system("cls");
}
int check(state &x){
	bool flag=false;
	if(x.hans[x.times].length()!=x.ans.length()) return -1;
	for(char i:x.hans[x.times]) if(!x.guessed[i])x.guessed[i]=gray;
	for(int i=0;i<=x.hans[x.times].length()-1;++i){
		if(x.hans[x.times][i]!=x.ans[i]){
			flag=true;
		}
		else{
			x.ac[i]=true;
			x.judge[x.times][i]=green;
			x.guessed[x.hans[x.times][i]]=green;
		}
	}
	if(flag==false){x.win=true;return 2;}
	for(int i=0;i<=x.hans[x.times].length()-1;++i){
		for(int j=0;j<=x.hans[x.times].length()-1;++j){
			if(x.hans[x.times][j]==x.ans[i]){
				if(x.judge[x.times][j]==0){
					x.judge[x.times][j]=yellow;
					if(x.guessed[x.hans[x.times][j]]!=green)x.guessed[x.hans[x.times][j]]=yellow;
				}
			}
		}
	}
	return 1;
}
void print(state x){
	system("cls");
	if(!sett::simpl){
		cout<<"Rule"<<endl;
		scbc(' ',yellow);
		cout<<" Yellow means the string has this letter,but it isn't in the correct place."<<endl;
		scbc(' ',green);
		cout<<" Green means the string has this letter,and it is in the correct place."<<endl;
	}
	cout<<"The Length of Word: "<<x.ans.length()<<endl;
	cout<<"Answer: ";
	for(int i=0;i<=x.ans.length()-1;++i){
		if(x.ac[i]==true){ scbc(x.ans[i],green);}
		else cout<<"* ";
	}
	cout<<endl<<endl;
	for(int i=max(1,(sett::lastr?x.times:1));i<=x.times;++i){
		for(int j=0;j<=x.ans.length()-1;++j){
			scbc(x.hans[i][j],x.judge[i][j]);
		}
		cout<<endl;
	}
	cout<<endl;cout<<"Remain Letters "<<endl;
	for(int i='a';i<='z';++i){
		scbc(i,x.guessed[i]);
	}
	cout<<endl<<endl;
	if(x.win){
		cout<<"You Win"<<endl;
		cout<<"Total Times: "<<x.times<<endl;
	}
	else if(x.tottimes==x.times){
		cout<<"You lost"<<endl;
		cout<<"The answer is: "<<x.ans<<endl;
	}
	else{
		if(!sett::simpl)cout<<"You have "<<x.tottimes-x.times<<" chance remain"<<endl;
		else cout<<"Remains: "<<x.tottimes-x.times<<endl;
	}
}
namespace _1p{
	state p;
	void main(){
		p.clear(word[rand()%word.size()],5);
		while(1){
			print(p);
			p.times++;
			if(!sett::simpl)cout<<"Guess a Word >>";
			else cout<<">>";
			cin>>p.hans[p.times];
			if(sett::aexit and p.hans[p.times]==sett::aexitw) return;
			if(0);
			else{
				int res=check(p);
				if(res==-1){
					cout<<"Wrong Length"<<endl;
					if(sett::paus)system("pause");
					p.times--;continue;
				}
				print(p);
				if((res==1 and p.times==p.tottimes) or res==2){
					break;
				}
			}
		}
		system("pause");
		if(pause()){
			_1p::main();
		}
	}
}
namespace _2pc{
	state p;
	void main(){
		string in;int tt;
		cout<<"Input a Word to Guess >>";
		cin>>in;
		cout<<"Input the total time of Guess >>";
		cin>>tt;
		p.clear(in,tt);
		while(1){
			print(p);
			p.times++;
			if(!sett::simpl)cout<<"Guess a Word >>";
			else cout<<">>";
			cin>>p.hans[p.times];
			if(sett::aexit and p.hans[p.times]==sett::aexitw) return;
			if(0);
			else{
				int res=check(p);
				if(res==-1){
					cout<<"Wrong Length"<<endl;
					if(sett::paus)system("pause");
					p.times--;continue;
				}
				print(p);
				if((res==1 and p.times==p.tottimes) or res==2){
					break;
				}
			}
		}
		system("pause");
		if(pause()){
			_2pc::main();
		}
	}
}
namespace _2pb{
	state p[2];int nowp=0;
	void main(){
		if(sett::rands){
			nowp=rand()%2;
		}
		else nowp=1;
		p[0].clear(word[rand()%word.size()],maxguess-1);
		p[1].clear(word[rand()%word.size()],maxguess-1);
		while(1){
			print(p[nowp]);
			cout<<"Now Player :";
			scbc(nowp+1+'0',light);
			cout<<endl;
			p[nowp].times++;
			if(!sett::simpl)cout<<"Guess a Word >>";
			else cout<<">>";
			cin>>p[nowp].hans[p[nowp].times];
			if(sett::aexit and p[nowp].hans[p[nowp].times]==sett::aexitw) return;
			if(0);
			else{
				int res=check(p[nowp]);
				if(res==-1){
					cout<<"Wrong Length"<<endl;
					if(sett::paus)system("pause");
					p[nowp].times--;continue;
				}
				print(p[nowp]);
				if(res==2){
					break;
				}
			}
			if(p[0].times==p[0].tottimes and p[1].times==p[1].tottimes) break;
			nowp=1-nowp;
		}
		cout<<"Player "<<nowp<<" Win"<<endl;
		cout<<"Game over. 1P Answer: "<<p[0].ans<<"  2P Answer: "<<p[1].ans<<endl;		
		system("pause");
		if(pause()){
			_2pb::main();
		}
	}
}
namespace _2pco{
	state p;int nowp=0;
	void main(){
		if(sett::rands){
			nowp=rand()%2;
		}
		else nowp=1;
		p.clear(word[rand()%word.size()],maxguess-1);
		while(1){
			print(p);
			cout<<"Now Player :";
			scbc(nowp+1+'0',light);
			cout<<endl;
			p.times++;
			if(!sett::simpl)cout<<"Guess a Word >>";
			else cout<<">>";
			cin>>p.hans[p.times];
			if(sett::aexit and p.hans[p.times]==sett::aexitw) return;
			if(0);
			else{
				int res=check(p);
				if(res==-1){
					cout<<"Wrong Length"<<endl;
					if(sett::paus)system("pause");
					p.times--;continue;
				}
				print(p);
				if((res==1 and p.times==p.tottimes) or res==2){
					break;
				}
			}
			nowp=1-nowp;
		}
		cout<<"Game over. Player "<<1-nowp<<" Win. The Answer is: "<<p.ans<<endl;		
		system("pause");
		if(pause()){
			_2pco::main();
		}
	}
}
namespace np{
	state p[101];int nowp,totp;
	void main(){
		cin>>totp;nowp=1;
		for(int i=1;i<=totp;++i) p[i].clear(word[rand()%word.size()],maxguess-1);
		while(1){
			print(p[nowp]);
			cout<<"Now Player :";
			scbc(nowp+1+'0',light);
			cout<<endl;
			p[nowp].times++;
			if(!sett::simpl)cout<<"Guess a Word >>";
			else cout<<">>";
			cin>>p[nowp].hans[p[nowp].times];
			if(sett::aexit and p[nowp].hans[p[nowp].times]==sett::aexitw) return;
			if(0);
			else{
				int res=check(p[nowp]);
				if(res==-1){
					cout<<"Wrong Length"<<endl;
					if(sett::paus)system("pause");
					p[nowp].times--;continue;
				}
				print(p[nowp]);
				if(res==2){
					break;
				}
			}
			nowp++;if(nowp>totp) nowp-=totp;
		}
	}
}
int mcs;
void printmain(){
	system("cls");
	cout<<version<<endl;
	cout<<"[MAIN Page]"<<endl;
	cout<<"Choose Mode"<<endl<<endl;
	scbc("1P",(mcs==1?light:white));cout<<endl;
	scbc("2P CREATOR",(mcs==2?light:white));cout<<endl;
	scbc("2P BATTLE",(mcs==3?light:white));cout<<endl;
	scbc("2P COOPERATION",(mcs==4?light:white));cout<<endl;
	scbc("NP (Creating)",(mcs==5?light:white));cout<<endl<<endl;
	scbc("Read File",(mcs==6?light:white));cout<<endl;
	scbc("Setting",(mcs==7?light:white));cout<<endl;
	scbc("Exit",(mcs==8?light:white));cout<<endl;
}
int main(){
	if(CLOCKS_PER_SEC!=1000){
		cout<<"[WARNING] This Programme Jus For Windows OS"<<endl<<endl;
	}
	srand(time(0));
	readvocabulary();
	mcs=1;
	while(1){
		printmain();
		while(1){
			if(kbhit()){
				char ch=getch();
				if(ch==72 and mcs!=1){mcs--;}
				if(ch==80 and mcs!=8){mcs++;}
				if(ch==13){
					if(mcs==1){ system("cls");_1p::main();}
					if(mcs==2){ system("cls");_2pc::main();}
					if(mcs==3){ system("cls");_2pb::main();}
					if(mcs==4){ system("cls");_2pco::main();}
					if(mcs==6){ system("cls");readvocabulary();}
					if(mcs==7){ sett::main();}
					if(mcs==8){ return 0;}
					break;
				}
				printmain();
			}
		}
	}
}


