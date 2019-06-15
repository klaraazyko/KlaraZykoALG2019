#include <iostream>
#include <string>
#include <fstream>
#include <time.h>
using namespace std;
typedef struct nyje{
	int celes;
	string fjala;
	struct nyje *m;
	struct nyje*d;
}nyje;
int i=1;
        void kerko_shto(nyje *rrenja, string s){
            nyje *tmp = rrenja;
            
            while(tmp!=NULL){
                if(tmp->fjala == s) return;
                if(s<tmp->fjala) {
                    if (tmp->m == NULL)
                    {
                        tmp->m = new nyje{i,s,NULL,NULL};
                        tmp->celes=i;
                        i++;
                        return;
                    }else tmp =tmp->m;
                    
                }else{
                    if (tmp->d == NULL)
                    {
                        tmp->d= new nyje {i,s,NULL,NULL};
                        tmp->celes=i;
                        i++;
                        return;
                    }else tmp =tmp->d;
                }
            }
            
        }
char toLowChar(char c)
	 {
	 int asci = (int)c;
 	 if (asci>=65 && asci<=90)
  	 asci+=32;
 	 return (char) asci;
 }
void printoPeme (nyje *T){
	if (T!=NULL){
		printoPeme(T->m);
		cout<<T->celes<<" "<<T->fjala<<endl;
		printoPeme(T->d);
	}
}
string toLowString (string st){
	string l = "";
	for (int i=0; i<st.length();i++){
		l+=toLowChar(st.at(i)); 
	}
	return l;}
	
	void krijoPemen (){
	nyje *T = new nyje;

	T->m=NULL;
	T->d=NULL;
	T->fjala="fjal";
	T->celes=0;
	
	ifstream in;
	in.open("dictionary.txt");
	if (!in){
		cout<<"File could not be found;"<<endl;
		return ;
	}
	else{
		int count=1;
		while (!in.eof()){
			string s;
			in>>s;
			s = toLowString(s);
			count++;
			kerko_shto(T,s);
			}
		in.close();
	}
	printoPeme(T);
}
int main (){
	clock_t start, end;
    double cpu_time_used;	
    start = clock();
    
    krijoPemen();
		
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    
    cout<<endl;
    cout<<"Koha exe: "<<cpu_time_used*1000<<" milisekonda"<<endl;
	
	return 0;
}
