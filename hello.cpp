//Testing on, the saving of file names into variable
#include<iostream>
#include<fstream>
#include<string>
#include <queue>
#include <unordered_map>
using namespace std;

int main(){
    //cout<<"Hello world"<<endl;

	/*string str1 = "f", str2 = "b";
	char ch ='a';
	int y = ch;
	cout<<y<<endl;
	
	if(str1 > str2){
		cout<<"Lexicography states that 'f' is greater than 'b' "<<endl;
	}else{
		cout<<"Let's assume the opposite for now"<<endl;
	}
	
	
	string str3 = "omare.txt";
	fstream file;
	
	cout<<str3<<endl;
	
	file.open(str3, ios::in | ios::out | ios::trunc);
	
	if(file.is_open()){
		cout<<"File successisfully opened, and the name passed as a variable"<<endl;
	}else{
		cout<<"Boy, ooh, boy something is a miss."<<endl;
	}
	*/
	
	unordered_map <char, int> freq;
	
	for(char ch: "nyabwanga"){
		freq[ch]++;
		cout<<ch<<endl; 
	}
	
	char chr = 'a';
	
	for(int i =0; i < 26; i++){
	//	cout<<chr<<" "<<freq[chr]<<endl;
		chr++;
	}
	
    int andrew;
    cin>>andrew;
}



































