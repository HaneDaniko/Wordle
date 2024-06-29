#include<bits/stdc++.h>
#include<windows.h>
#define Kw "114514"
#define Save "0"
using namespace std;
int len;
int ansid,times;
vector<string> wst;
string in;
char rea[201];
int jg[6][8];
bool zc[8];
string ans[6];
int guessed['z'+1];
void clear(){  //reset the game
	len=0;
	ansid=0;
	times=0;
	for(int i=0;i<=5;++i){
		for(int j=0;j<=7;++j){
			jg[i][j]=0;
		}
		ans[i].clear();
	}
	for(int i=0;i<=7;++i){
		zc[i]=false;
	}
	for(int i='a';i<='z';++i){
		guessed[i]=0;
	}
}
void scbc(char put,int type){  //colorful change the word result
	HANDLE handle=GetStdHandle(STD_OUTPUT_HANDLE);
	if(type==1){
		SetConsoleTextAttribute(handle,0xE0);
		cout<<put<<" ";
		SetConsoleTextAttribute(handle,0x0F);
	}
	if(type==2){
		SetConsoleTextAttribute(handle,0xA0);
		cout<<put<<" ";
		SetConsoleTextAttribute(handle,0x0F);
	}
	if(type==0){
		cout<<put<<" ";
	}
}
void scbc(string put,int color){  //colorful change the word result
	HANDLE handle=GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(handle,color);
	cout<<put<<" ";
	SetConsoleTextAttribute(handle,0x0F);
}
int check(int time,string x){  //check the input changes what
	bool flag=false;
	if(x.length()!=wst[ansid].length()){
		return -1;
	}
	for(int i=0;i<=x.length()-1;++i){
		guessed[x[i]]=1;
	}
	for(int i=0;i<=x.length()-1;++i){
		if(x[i]!=wst[ansid][i]){
			flag=true;
			break;
		}
		jg[time][i]=2;
		zc[i]=true;
	}
	if(flag==false){
		return 2;
	}
	for(int i=0;i<=x.length()-1;++i){
		for(int j=0;j<=x.length()-1;++j){
			if(x[j]==wst[ansid][i]){
				if(jg[time][j]==0){
					guessed[x[j]]=2;
					jg[time][j]=1;
				}
				if(i==j){
					guessed[x[j]]=3;
					jg[time][j]=2;
					zc[j]=true;
				}
			}
		}
	}
	return 1;
}
void sc(int times){    //print the result
	system("cls");
	cout<<"Rule"<<endl;
	scbc(' ',1);
	cout<<" Yellow means the string has this letter,but it isn't in the correct place."<<endl;
	scbc(' ',2);
	cout<<" Green means the string has this letter,and it is in the correct place."<<endl;
	cout<<"There's a string has "<<len<<" letters."<<endl<<"Answer : ";
	for(int i=0;i<=len-1;++i){
		if(zc[i]){
			scbc(wst[ansid][i],2);
		}
		else{
			cout<<"* ";
		}
	}
	cout<<endl<<endl;
	for(int i=0;i<=times;++i){
		for(int j=0;j<=len-1;++j){
			scbc(ans[i][j],jg[i][j]);
		}
		cout<<endl;
	}
	cout<<endl;
	cout<<"Remain Letters"<<endl;
	for(int i='a';i<='z';++i){
		string x;x.push_back(i);
		if(guessed[i]==0){
			scbc(x,0x0F);
		}
		if(guessed[i]==1){
			scbc(x,0x08);
		}
		if(guessed[i]==2){
			scbc(x,0xE0);
		}
		if(guessed[i]==3){
			scbc(x,0xA0);
		}
		x.clear();
	}
	cout<<endl<<endl;
}
void rd(){
	cout<<"Read Mode"<<endl<<"Please open a file (Putin 0 to read 'StandardVocabulary.wordle') >>";
	cin>>rea;
	if(rea[0]!='0'){
		freopen(rea,"r",stdin);
	}
	else{
		freopen("StandardVocabulary.wordle","r",stdin);
	}
	while(1){
		cin>>in;
		if(in=="0"){
			break;
		}
		wst.push_back(in);
	}
	cout<<"Read "<<wst.size()<<" Words."<<endl;
	cin.clear();
	freopen("CON","r",stdin);
	cout<<endl;
	system("pause");
	system("cls");
}
int main(){
	system("title Read // WordleGame 1.2.0 version // Made By HaneDaniko");
	rd();
	srand(time(NULL));
	while(1){
		ansid=rand()%wst.size();
		len=wst[ansid].length();
		cout<<"There's a string has "<<len<<" letters."<<endl<<"Answer : ";
		for(int i=0;i<=len-1;++i){
			cout<<"* ";
		}
		cout<<endl<<endl;
		system("title Guess // WordleGame 1.2.0 version // Made By HaneDaniko");
		while(1){
			cout<<"You have 5 chance in totle to guess."<<endl;
			cout<<"Guess a word >>";
			cin>>ans[times];
			if(ans[times]==Kw){
				ans[times].clear();
				system("cls");
				cout<<"Creator Mode"<<endl;
				string com;
				while(1){
					cout<<"Command >>";
					cin>>com;
					if(com=="/exit"){
						system("cls");
						break;
					}
					else if(com=="/answer"){
						cout<<wst[ansid];
					}
					else if(com=="/system"){
						char sys[101];
						cout<<"System >>";
						cin>>sys;
						system(sys);
						cout<<"Has Done it.";
					}
					else{
						cout<<"Wrong Command.";
					}
					cout<<endl;
				}
				continue;
			}
			else if(ans[times]==Save){
				int sav;
				ans[times].clear();
				system("cls");
				system("color 07");
				system("title C:/Users/hzoi/Desktop/Untitled1.cpp");
				cout<<"100 7 1 "<<endl<<"101 1 2"<<endl<<"1 2 2 "<<endl<<"2 3 2 "<<endl<<"3 3 1 "<<endl<<"1 3 2 "<<endl<<"3 1 1 "<<endl<<"5 5 0"<<endl<<"Yes"<<endl<<"No"<<endl;
				cout<<"--------------------------------"<<endl<<"Process exited after 2.797 seconds with return value 0"<<endl<<"请按任意键继续. . .";
				cin>>sav;
				system("cls");
				system("title Guess // WordleGame 1.2.0 version // Made By HaneDaniko");
				continue;
			}
			else{
				int a=check(times,ans[times]);
				if(a==-1){
					cout<<"Wrong Length."<<endl<<endl;
					continue;
				}
				else if(a==1){
					for(int i=0;i<=len-1;++i){
						cout<<jg[times][i]<<" ";
					}
					cout<<endl;
					sc(times);
					times++;
					if(times==5){
						system("title Just SO EASY! Are you CLEVER ?");
						cout<<"You lost."<<endl;
						cout<<"The Answer is '"<<wst[ansid]<<"'."<<endl;
						break;
					}
					cout<<"You have "<<5-times<<" times remain."<<endl;
				}
				else{
					system("title Win // WordleGame 1.2.0 version // Made By HaneDaniko");
					sc(times);
					times++;
					cout<<"You Win."<<endl;
					cout<<"Total Times : "<<times<<endl;
					break;
				}
			}
		}
		system("pause");
		system("cls");
		system("title Next // WordleGame 1.2.0 version // Made By HaneDaniko");
		cout<<"Moving on to the next round"<<endl;
		system("pause");
		system("cls");
		clear();
	}
	return 0;
}

