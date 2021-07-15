#include <iostream>
#include <vector>
using namespace std;
class Stack{
	public:
	vector <int> elements;
    void push(int a){
    	elements.push_back(a);
	}
    void pop(){
    	if(elements.size()==0){
    		cout<<"Stack is empty"<<endl;
		}
		else{	
        int a=elements.size();
    	cout<<"Deleted value is " <<elements[a-1]<<endl;
    	elements.erase(elements.begin()+a-1);
    }
	}
	void display(){
		int i;
		for(i=0; i<(int)elements.size();i++){
		cout<<elements[i]<<" ";
	}
	cout<<endl;
	}
    
};


int main(){
   cout<<"1. push"<<endl;
   cout<<"2. pop"<<endl;
   cout<<"3. display"<<endl;
   Stack s;
   int a;
   while(1){
   	cout<<"Enter your choice:"<<endl;
   	cin>>a;
   	cout<<a<<endl;
   	if(a==1){
   		int b;
   		cout<<"Enter an integer element to push: "<<endl;
   		cin>>b;
   		cout<<b<<endl;
   		s.push(b);
   		char c;
   		cout<<"Do you want to continue? (y/n)"<<endl;
   		cin>>c;
   		cout<<c<<endl;
   		if(c=='n'){
   			break;
		   }
	   }
	else if(a==2){
		s.pop();
		char c;
   		cout<<"Do you want to continue? (y/n)"<<endl;
   		cin>>c;
   		cout<<c<<endl;
   		if(c=='n'){
   			break;
		   }
	}
	else if(a==3){
		s.display();
		char c;
   		cout<<"Do you want to continue? (y/n)"<<endl;
   		cin>>c;
   		cout<<c<<endl;
   		if(c=='n'){
   			break;
		   }
	}   
   }
}
