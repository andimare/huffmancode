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
	
	string toUpper(string text){
		//Convertng the string to upper
		for(int i = 0;i < text.length();i++){
			int dec = text[i];
			//Checking if it's already in caps
			if(dec > 64 && dec < 91)continue;
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
		text = andis::toUpper(andis::trimSpace(text));
		buildHuffmanTree(text);
		
		file.close();
	}else{
		cout<<"Boy, ooh, boy something is a miss."<<endl;
	}
	
	int andrew;
	cin>>andrew;
	
	return 0;
}
/*
Huffman Codes are :

c 11111
h 111100
f 11101
r 11100
t 11011
p 110101
i 1100
g 0011
l 00101
a 010
o 000
d 10011
H 00100
. 111101
s 0110
m 0111
e 110100
  101
n 1000
u 10010

Original string was :
Huffman coding is a data compression algorithm.

Encoded string is :
00100100101110111101011101010001011111100010011110010000011101110001101010101011001101011011010101111110000111110101111001101000110011011000001000101010001010011000111001100110111111000111111101

Decoded string is: 
Huffman coding is a data compression algorithm.
*/
