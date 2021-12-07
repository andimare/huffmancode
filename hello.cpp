//Testing on, the saving of file names into variable
#include<iostream>
#include<fstream>
#include<string>
#include <queue>
#include <unordered_map>
using namespace std;

int main(){
	//Lexicography
	/*string str1 = "f", str2 = "b";
	char ch ='a';
	int y = ch;
	cout<<y<<endl;
	
	if(str1 > str2){
		cout<<"Lexicography states that 'f' is greater than 'b' "<<endl;
	}else{
		cout<<"Let's assume the opposite for now"<<endl;
	}
	*/
	
	string str3 = "huffIn.txt";
	fstream file;
	
	cout<<str3<<endl;
	
	file.open(str3, ios::in);
	
	if(file.is_open()){
		cout<<"File successisfully opened, and the name passed as a variable"<<endl;
		string text;
		
		getline(file,text);
		cout<<text<<endl;
		
		file.close();
	}else{
		cout<<"Boy, ooh, boy something is a miss."<<endl;
	}
	
	/*
	unordered_map <char, int> freq;
	
	for(char ch: "nyabwanga"){
		freq[ch]++;
		cout<<ch<<endl; 
	}
	
	char chr = 'a';
	
	for(int i =0; i < 26; i++){
	//	cout<<chr<<" "<<freq[chr]<<endl;
		chr++;
	}*/
	
	/*
	//creating the space trimming functionality
	string text = "nyabwanga";
	unordered_map<char, int>freq;
	
	//counting the number of the specific charater(space)
	for(char ch: text){
		freq[ch]++;
	}
	
	//looping through the string to rip of the unwanted charater(space)
	for(int i = 0; i < freq['a']; i++){
		text.erase(text.find('a'),1);
		cout<<text<<endl;
	}
	
	
	//Convertng the string to upper
	for(int i = 0;i < text.length();i++){
		text[i] -= 32;
	}
	
	//Finding the respective decimal numbers
	//To get the difference between them
	char ch1[2] = {'a','A'};
	for(int i = 0;i < 2;i++){
		int b = ch1[i];
		//cout<<b<<endl;
	}
	
	cout<<text<<endl;
	*/

	return 0;
}



































