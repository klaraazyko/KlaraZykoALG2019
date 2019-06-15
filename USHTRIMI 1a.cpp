#include <iostream>
#include <string>
#include <fstream>
#include <time.h>
using namespace std;

typedef struct nyje{
	int celes;
	string fjala;
	struct nyje *pas;
}nyje;

char toLowChar(char c)
	 {
	 int asci = (int)c;
 	 if (asci>=65 && asci<=90)
  	 asci+=32;
 	 return (char) asci;
 }

string toLowString (string str){
	string t = "";
	for (int i=0; i<str.length();i++){
		t+=toLowChar(str.at(i)); 
	}
	return t;
}
int fjala(nyje *koka,string s)
{
	nyje *tmp=koka;
	int c=0;
	while(tmp!=NULL)
	{if(tmp->fjala==s)
		return -1;
		c++;
		tmp=tmp->pas;}
	return c;
	
}
void addInList(nyje *koka,string s)
{
	nyje *tmp=koka;
	int c=0;
	int a=fjala(koka,s);
	if(a!=-1)
	{for (int i=1; i<a; i++){
		tmp = tmp->pas;}		
		nyje *newNode = new nyje;
		newNode->celes=a;
		newNode->fjala=s;
		tmp->pas=newNode;
		newNode->pas=NULL;
	
	}

}
void printoList(nyje *koka)
	{nyje *tmp=koka;
		while(tmp!=NULL)
		{
		cout<<"CELESI="<<tmp->celes<<" , "<<tmp->fjala<<"\n";
		tmp=tmp->pas;}
	}
void Fjalor (){
	nyje *fjalor = new nyje;
	fjalor->celes=0;
	fjalor->fjala="Fjal";
	fjalor->pas=NULL;
	
	ifstream in;
	in.open("dictionary.txt");
	if (!in){
		cout<<"File nuk u gjet;"<<endl;
		return ;
	}
	else{
		while (!in.eof()){
			string s;
			in>>s;
			addInList(fjalor,toLowString(s));
		}
	}
	in.close();	
	printoList(fjalor);	
}

int main (){
	clock_t start, end;
    double cpu_time_used;	
    start = clock();
   	Fjalor();
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    
    cout<<endl;
    cout<<"Koha per ekzekutim: "<<cpu_time_used<<" sekonda ose"<<cpu_time_used*1000<<" milisekonda"<<endl;
	return 0;
}
