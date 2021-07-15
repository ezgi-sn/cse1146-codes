#include <iostream>
#include <cstring>
#include <string>
using namespace std;
int checkWord(string s){
	int i,j,count=0;
	for(i=0; i<s.length();i++){
		int keyCount=1;
		for(j=i+1; j<s.length();j++){
			if(s[i]==s[j]){
			keyCount++;
			}
		}
		if(keyCount!=1){
			count+=keyCount;
		}
	}
	return count;
}
void findRepetitive(string s){
	int i,maxCount,start,temp,length,j;
	maxCount=0;
	start=0;
	temp=0;
	length=0;
	string word="";
	for(i=0; i<s.length();i++){
		if(s[i]!=' '){
			word+=s[i];
			length++;
		}
		else if(s[i]==' '){
			temp=checkWord(word);
			if(temp>maxCount){
				maxCount=temp;
				start=i-length;
			}
			length=0;
			word="";
		}
		if(i==(int)(s.length())-1){ //son kelimeye denk gelme iht
		temp=checkWord(word);
			if(temp>maxCount){
				maxCount=temp;
				start=i-length+1;
			}
		}
	}
	int k;
	if(maxCount!=0){
	for(k=start;; k++){
		if(s[k]==' ' || s[k]=='\0')
		break;
		else
		cout<<s[k];
	}
}
else
return;
}
int main(){
	string s;
	getline(cin,s);
	findRepetitive(s);

}
