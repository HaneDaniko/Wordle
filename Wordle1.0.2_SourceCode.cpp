#include<bits/stdc++.h>
#include<windows.h>
using namespace std;
int len,maxlen;
int ansid,times,tlen[5];
string wst[5][201],in;//0 4   1 5   2 6
char rea[201];
int jg[6][8];
bool zc[8];
string ans[6];
void clear(){
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
}
void scbc(char put,int type){
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
int check(int time,string x){
	bool flag=false;
	if(x.length()!=wst[len-4][ansid].length()){
		return -1;
	}
	for(int i=0;i<=x.length()-1;++i){
		if(x[i]!=wst[len-4][ansid][i]){
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
			if(x[j]==wst[len-4][ansid][i]){
				if(jg[time][j]==0){
					jg[time][j]=1;
				}
				if(i==j){
					jg[time][j]=2;
					zc[j]=true;
				}
			}
		}
	}
	return 1;
}
void sc(int times){
	system("cls");
	cout<<"Rule"<<endl;
	scbc(' ',1);
	cout<<" Yellow means the string has this letter,but it isn't in the correct place."<<endl;
	scbc(' ',2);
	cout<<" Green means the string has this letter,and it is in the correct place."<<endl;
	cout<<"There's a string has "<<len<<" letters."<<endl<<"Answer : ";
	for(int i=0;i<=len-1;++i){
		if(zc[i]){
			scbc(wst[len-4][ansid][i],2);
//			cout<<wst[len-4][ansid][i]<<" ";
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
	cin>>maxlen;
	for(int i=4;i<=maxlen;++i){
		cin>>tlen[i-4];
		for(int j=0;j<=tlen[i-4]-1;++j){
			cin>>wst[i-4][j];
		}
	}
	freopen("CON","r",stdin);
	cout<<endl;
	system("pause");
	system("cls");
}
int main(){
	system("title Read // WordleGame 1.0.2 version // Made By HaneDaniko");
	rd();
	srand(time(NULL));
	while(1){
		len=rand()%(maxlen-3)+4;
		ansid=rand()%tlen[len-4];
		cout<<"There's a string has "<<len<<" letters."<<endl<<"Answer : ";
		for(int i=0;i<=len-1;++i){
			cout<<"* ";
		}
		cout<<endl<<endl;
		system("title Guess // WordleGame 1.0.2 version // Made By HaneDaniko");
		while(1){
			cout<<"You have 5 chance in totle to guess."<<endl;
			cout<<"Guess a word >>";
			cin>>ans[times];
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
					cout<<"The Answer is '"<<wst[len-4][ansid]<<"'."<<endl;
					break;
				}
				cout<<"You have "<<5-times<<" times remain."<<endl;
			}
			else{
				system("title Win // WordleGame 1.0.2 version // Made By HaneDaniko");
				sc(times);
				times++;
				cout<<"You Win."<<endl;
				cout<<"Total Times : "<<times<<endl;
				break;
			}
		}
		system("pause");
		system("cls");
		system("title Next // WordleGame 1.0.2 version // Made By HaneDaniko");
		cout<<"Moving on to the next round"<<endl;
		system("pause");
		system("cls");
		clear();
	}
	return 0;
}
