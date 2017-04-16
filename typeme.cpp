#include <iostream>
#include<fstream>
#include<stdlib.h>
#include<ctime>
#include<cstring>
#include<conio.h>
using namespace std;
char ch;
int score;
int t;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
void welcomepage()
{
	int i;
    for(i=0;i<200;i++)
    {
    	cout<<"*";
	}
		cout<<endl<<endl;
	for(i=0;i<30;i++)
	{
		cout<<" ";
	}
	cout<<"WELCOME TO TYPE ME";
	cout<<endl<<endl;
	for(i=0;i<200;i++)
    {
    	cout<<"*";
	}
	cout<<endl<<"press enter to proceed"<<endl;
	cout<<"press esc to exit "; i=_getch();
	if(i==13)
		system("CLS");
	else
		exit(1);
}

   	string username;
   	string pass;
void level(int pos)
{
	int i=1;
	int count=0;
	int s=score;
	ifstream f("typingdata.txt");
	string str;
	string ustr;
	while(i<pos+1)
	{
    	getline(f,str);
    	i++;
}
	s:
	cout<<endl<<str;
	cout<<endl;
	cout<<"type above sentence";
	cout<<endl<<endl;
	i=0;
	int start_s=clock();
	 while(1)
	{
		if(i==0)
	    	ustr="";
		 ch=_getche();
		 if(ch==13)
		 	break;
		 if(ch==8)
		 {
		 	  if(i!=0)
		 {
	          ustr.erase(ustr.begin()+i-1);
	          i=i-1;
	          cout<<" \b";
	          count++;
		 }
	}
		 else
		 {
		  	  ustr.insert(ustr.begin()+i,ch);
		 	  i=i+1;
		 }
	}
	    int stop_s=clock();
	    cout <<endl<< "time: " << (stop_s-start_s)/double(CLOCKS_PER_SEC)*1000 << endl;
	    int time=(float(1000)/float((stop_s-start_s)/double(CLOCKS_PER_SEC)*1000))*1000;
	    if((str.length()/2)>ustr.length())
	    {
	    	 cout<<"sory type sentence correctly";
	    	  ustr="";
	 	    count=0;
	 	     score=s;
	 	 	cout<<endl;
	 	 	goto s;  	 
		}
		if(str.length()>=ustr.length())
		{
			for(i=0;i<ustr.length();i++)
	   {
	 		if(str[i]!=ustr[i])
	 			count++;
		 }
		 		}
		else
		{
			for(i=0;i<str.length();i++)
	 	{
	 		if(str[i]!=ustr[i])
	 			count++;
		 }
		   if(i!=ustr.length())
		   	count++;
		}
		cout<<endl<<count;
		float acur=1-(float(count)/float(str.length()));	
		cout<<endl<<"your accuracy is "<<acur*1000<<"%";
	  score=score+(acur*100)+time;
	 cout<<endl<<"your score is "<<score;
	 cout<<endl<<"press 1 to retype "<<endl<<"press 2 to prceed and 3 to exit and 4 to see your position";char p=_getch();
	 if(p=='1')
	 {
	 	 ustr="";
	 	 count=0;
	 	 score=s;
	 	 cout<<endl;
	 	 goto s;
	 }
	  ofstream u(username.c_str());
	   u<<username<<endl;
	  u<<pos+1<<endl<<score;
	  u.close();
	  f.close();
	 if(p=='3')
	 	exit(1);
	if(p=='4')
	{
		cout<<"hi";
		ifstream fin("users.txt");
		string g,pa;
		int sc;int count=1;
		getline(fin,g);
		getline(fin,pa);
		while(fin)
		{
			getline(fin,g);
			getline(fin,pa);
			if(username!=g)
			{
				ifstream f(g.c_str());
				getline(f,g);
				if(g!="")
				{
					fin>>sc;
					fin>>sc;
				}
				if(score<sc)
					count++;
			}
	
	}
	         cout<<"your position in my users"<<count<<endl;
	         fin.close();
	         f.close();
	         system("PAUSE");
		}
	}

void level3(int pos)
{
	ifstream f("typingdata.txt");
	int count=0;
	int s=score;
	string str[4];
	string ustr;
	int t=0,i=1;
	while(i<=pos)
	{
		getline(f,str[0]);
		i++;
	}
	for(t=1;t<4;t++)
		getline(f,str[t]);
	s:
	t=0;
	cout<<endl<<endl;
	for(i=0;i<4;i++)
		cout<<str[i]<<endl;
	i=0;
	cout<<endl<<"type the above paragraph"<<endl;
	int start_s=clock();
	 while(1)
	{
		lb:
		if(i==0)
	    	ustr="";
		 ch=_getche();
		 if(ch==13)
		 {
		      if(t<4)
		      {
		      	if(str[t].length()>=ustr.length())
		{
			for(i=0;i<ustr.length();i++)
	   {
	 		if(str[t][i]!=ustr[i])
	 			count++;
		 }
		 		}
		else
		{
			for(i=0;i<str[t].length();i++)
	 	{
	 		if(str[t][i]!=ustr[i])
	 			count++;
		 }
		   if(i!=ustr.length())
		   {
		   		count++;
		   		i++;
		}
	}
	         t++;
	         if(t==4)
	         	break;
	         i=0;
	         cout<<endl;
	         goto lb;
			  }
		 }
		 if(ch==8)
		 {
		 	  if(i!=0)
		 {
	          ustr.erase(ustr.begin()+i-1);
	          i=i-1;
	          cout<<" \b";
	          count++;
		 }
	}
		 else if(ch!=13)
		 {
		 	  ustr.insert(ustr.begin()+i,ch);
		 	  i=i+1;
		 }
	}
	   int stop_s=clock();
	   cout <<endl<< "time: " << (stop_s-start_s)/double(CLOCKS_PER_SEC)*1000 << endl;
	  int time=(float(1000)/float((stop_s-start_s)/double(CLOCKS_PER_SEC)*1000))*1000;
	  float acur=1-(float(count)/float(str[0].length()+str[1].length()+str[2].length()+str[3].length()));		
	  cout<<endl<<"your accuracy is "<<acur*100<<"%";
	  score=score+(acur*1000)+time;
	 cout<<endl<<"your score is "<<score;
	 cout<<endl<<"press 1 to retype "<<endl<<"press 2 to prceed and 3 to exit";char p=_getch();
	 if(p=='1')
	 {
	 	 ustr="";
	 	 count=0;
	 	 score=s;
	 	 cout<<endl;
	 	 goto s;
	 }
	  ofstream u(username.c_str());
	   u<<username<<endl;
	  u<<pos+4<<endl<<score;
	  u.close();
	  f.close();
	 if(p=='3')
	 	exit(1);
}
     int reg()
{
	 int i=0;int ch;
	 string g,pa;
	  h:
	cout<<endl<<"enter username ";cin>>username;
	 ifstream f("users.txt");
	 while(f)
	 {
	 	getline(f,g);
	 	getline(f,pa);
	 	if(g==username)
	 	{
	 		cout<<endl<<"this username already exists iam sorry rename your name";
	 		f.close();
	 		goto h;
		 }
	 }
	 f.close();
	lb:
	cout<<"enter password atmost(8)";
	while(1)
	{
		if(i==0)
	    	pass="";
		 ch=_getch();
		 if(ch==13)
		 	break;
		 if(ch==8)
		 {
		 	  if(i!=0)
		 {
	          pass.erase(pass.begin()+i-1);
	          i=i-1;
	          cout<<"\b \b";
		 }
	}
		 else
		 {
		 	  pass.insert(pass.begin()+i,ch);
		 	  cout<<"*";
		 	  i=i+1;
		 }
	}
	if(i>8)
	{
		 cout<<endl<<"invalid password";
		  cout<<" try again"<<endl;
		  pass="";
		  i=0;
		  goto lb;
	}
	
	ofstream fout;
	fout.open("users.txt",ios::app);
	fout<<username<<endl;fout<<pass<<endl;fout.close();cout<<endl<<"you registered"<<endl;
	cout<<"press 1 to show password and 2 to continue";cin>>ch;
	if(ch==1)
	{
		cout<<pass<<endl;
		system("PAUSE");
}
	return 1;
	
}
 int login()
 {
 	 string user;
 	 string password;int i=0;int ch;
 	 la:
 	 cout<<"enter your username ";cin>>user;
 	 lb:
 	  cout<<"enter password almost(8)";
 	  while(1)
	{
		if(i==0)
	    	password="";
		 ch=_getch();
		 if(ch==13)
		 	break;
		 if(ch==8)
		 {
		 	  if(i!=0)
		 {
	          password.erase(password.begin()+i-1);
	          i=i-1;
	          cout<<"\b \b";
		 }
	}
		 else
		 {
		 	  password.insert(password.begin()+i,ch);
		 	  cout<<"*";
		 	  i=i+1;
		 }
	}
	if(i>8)
	{
		 cout<<endl<<"invalid password";
		  cout<<" try again"<<endl;
		  password="";
		  i=0;
		  goto lb;
	}
	
 	ifstream fin("users.txt");
 	if(!fin)
        {
            cout<<"cannot open file\n";
        }
    else
    {
    	while(fin)
    	{
    		getline(fin,username);
    		getline(fin,pass);
    		if(user==username && password==pass)
    		{
    			 break;
			}
		}
		if(fin)
			return 1;
		else
			return 0;
}
 fin.close();
}



int main(int argc, char** argv) {
	welcomepage();	 
	cout<<"press 1 to register"<<endl<<"press 2 to login ";
	 char r;r=_getch();int p=0;int pos;
	switch(r)
	{
	  case '1':
			p=reg();
			break;
	   case '2':
	 		t=login();
	 		la:
			if(t)
				cout<<endl<<"login sucessfull";
			else
			{
				cout<<endl<<"not successfull login try again";
				cout<<endl<<"press 1 to try again 2.you want to register";
				int ch;cin>>ch;
				if(ch==1)
				{
		 			t=login();
		 	 		goto la;
				}
	  			else if(ch==2)
	   			{		
	   	  			p=reg();
	   			}		
				}
}
  cout<<endl;
    if(p==1)
    {
    	score=0;
    	pos=1;
    	ofstream ft(username.c_str());
 	     ft.close();
 	     system("cls");cout<<endl<<endl;
 	    cout<<"hi welcome "<<username<<endl;
	}
	if(t)
	{
		ifstream ft(username.c_str());
		string user;
		getline(ft,user);
		if(user==username)
		{
		cout<<endl<<"hi "<<username;
		cout<<endl<<"welcome back";
		ft>>pos;
		ft>>score;
		ft.close();
	}
	else if(user=="")
	{
		score=0;
		pos=1;
		cout<<endl<<"hi "<<username;
		cout<<endl<<"welcome back";
		
	}
	else
		cout<<"invalid file";
}
	cout<<endl<<endl;
 	    cout<<"press enter to start typing or esc to exist"; char ch=_getch();
 	    if(ch==27)
 	    	exit(1);
 	    l:
 	      system("cls");
 	    while(pos<4)
 	    {
 	    		cout<<endl<<"you are in level 1";
 	        	level(pos);
 	        	system("cls");
 	      	pos++;
 	  }
 	    if(score>=3800 && pos<8 )
 	    {
 	   		cout<<endl<<"you sucessfully entered to level 2";
 	   		cout<<endl<<"press enter to proceed and esc to exit";ch=_getch();
 	    	if(ch==27)
 	    		exit(1);
 	   		pos=4;
 	   		ls:
 	   		system("cls");
 	   		while(pos<8)
 	   {
 	   	      cout<<endl<<"you are in level 2";
 	   	      level(pos);
 	   	      system("cls");
 	   	      pos++;   
		}
	}
	else if(pos<8)
	 {
	 	cout<<endl<<"sorry your score is not enough to go to level 2";
	 	cout<<endl<<"press 1 to goto level 1 again else 2 to exit";
	 	ch=_getch();
	 	if(ch=='1')
	 		{
	 			pos=1;
	 			score=0;
	 			goto l;
			 }
		else
			exit(1);
	 }
	 if(score>8000)
	 {
	 	 cout<<endl<<"you sucessfully entered to level 3";
	 	 
	 		cout<<endl<<"press enter to proceed and esc to exit";ch=_getch();
 	    	if(ch==27)
 	    		exit(1);
 	   		system("cls");
 	   		while(pos<19)
 	   {
 	   	      system("cls");
 	   	      cout<<endl<<"you are in level 3";
 	   	      level3(pos);
 	   	      system("cls");
 	   	      pos=pos+4;
				     
		}	 
	 }
	 else
	 {
	 	cout<<endl<<"sorry your score is not enough to enter in level 3"<<endl;
	 	cout<<"your default score is 3000 and start level 2 again";
	 	score=300;
	 	cout<<endl<<"press 1 to level 2"<<"press 2 to exist";ch=_getch();
	 	if(ch=='1')
	 	{
	 		pos=4;
	 		goto ls;
		 }
	 }
	 cout<<endl<<"your completed my all tasks"<<endl;
	 cout<<"BYE thanks for TYPING me"<<endl;
   system("PAUSE");
   
	return 0;
}

