#include <iostream>
#include <string>
#include <fstream>
#include <time.h>
using namespace std;
typedef struct node{
	int celes;
	string fjala;
	struct node *m;
	struct node *d;
}node;
int i=1;
        void kerko_shto(node *rrenja, string s){
            node *tmp = rrenja;
            
            while(tmp!=NULL){
                if(tmp->fjala == s) return;
                if(s<tmp->fjala) {
                    if (tmp->m == NULL)
                    {
                        tmp->m = new node{i,s,NULL,NULL};
                        tmp->celes=i;
                        i++;
                        return;
                    }else tmp =tmp->m;
                    
                }else{
                    if (tmp->d == NULL)
                    {
                        tmp->d= new node {i,s,NULL,NULL};
                        tmp->celes=i;
                        i++;
                        return;
                    }else tmp =tmp->d;
                }
            }
            
        }
char toLowChar(char c)
	 {
	 int asciiValue = (int)c;
 	 if (asciiValue>=65 && asciiValue<=90)
  	 asciiValue+=32;
 	 return (char) asciiValue;
 }
void printTree (node *T){
	if (T!=NULL){
		printTree(T->m);
		cout<<T->celes<<" "<<T->fjala<<endl;
		printTree(T->d);
	}
}
string toLowString (string st){
	string l = "";
	for (int i=0; i<st.length();i++){
		l+=toLowChar(st.at(i)); 
	}
	return l;}
	
	void krijoPemen (){
	node *T = new node;

	T->m=NULL;
	T->d=NULL;
	T->fjala="fjal";
	T->celes=0;
	
	ifstream in;
	in.open("fjalor.txt");
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
	printTree(T);
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
