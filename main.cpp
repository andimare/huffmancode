#include <iostream>
#include <fstream>
#include <string>
#include <queue>
#include <unordered_map>
#include "Tree.h"
using namespace std;


//namespace for trimming and capitalizing
namespace andis{
	string trimSpace(string text){
		//creating the space trimming functionality
		unordered_map<char, int>freq;
	
		//counting the number of the specific charater(space)
		for(char ch: text){
			freq[ch]++;
		}
	
		//looping through the string to rip of the unwanted charater(space)
		for(int i = 0; i < freq[' ']; i++){
			text.erase(text.find(' '),1);
		}
		return text;
	}
	
	string toUpperTrim(string text){
		//Convertng the string to upper
		for(int i = 0;i < text.length();i++){
			int dec = text[i];
			
			//Checking if it's already in caps
			if(dec > 64 && dec < 91)continue;
			//Trimming out Non-alpha
			else if(!(dec > 96) || !(dec < 223)){
				text.erase(i,1);
			i--;
			}
			//converssion to uppercase
			else text[i] -= 32;
		}
		
		return text;
	}
}

int main()
{
	//Name of the file with the Original message
	string fileName;
	string text;
	
	cout<<"enter text file name :";cin>>fileName;
	
	fstream file;	
	file.open(fileName, ios::in);
	
	if(file.is_open()){
		//Reading from the file
		getline(file,text,'*');
		//text ="the cats down in an";
		
		cout<<text<<"  closing input file"<<endl;
		text = andis::toUpperTrim(andis::trimSpace(text));
		buildHuffmanTree(text);
		
		file.close();
	}else{
		cout<<"Boy, ooh, boy something is a miss."<<endl;
	}
	
	int andrew;
	cin>>andrew;
	
	return 0;
}
