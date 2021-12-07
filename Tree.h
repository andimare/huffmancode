#include <iostream>
#include <fstream>
#include <string>
#include <queue>
#include <unordered_map>
using namespace std;

// A Tree node
struct Node
{
	char ch;
	int freq;
	Node *left, *right;
};

// Function to allocate a new tree node
Node* getNode(char ch, int freq, Node* left, Node* right)
{
	Node* node = new Node();

	node->ch = ch;
	node->freq = freq;
	node->left = left;
	node->right = right;

	return node;
}

// Comparison object to be used to order the heap
struct comp
{
	bool operator()(Node* l, Node* r)
	{
		// highest priority item has lowest frequency
		return l->freq > r->freq;
	}
};

// traverse the Huffman Tree and store Huffman Codes
// in a map.
void encode(Node* root, string str,
			unordered_map<char, string> &huffmanCode)
{
	if (root == nullptr)
		return;

	// found a leaf node
	if (!root->left && !root->right) {
		huffmanCode[root->ch] = str;
	}

	encode(root->left, str + "0", huffmanCode);
	encode(root->right, str + "1", huffmanCode);
}

// traverse the Huffman Tree and decode the encoded string
void decode(Node* root, int &index, string str)
{
	if (root == nullptr) {
		return;
	}

	// found a leaf node
	if (!root->left && !root->right)
	{
		cout << root->ch;
		return;
	}

	index++;

	if (str[index] =='0')
		decode(root->left, index, str);
	else
		decode(root->right, index, str);
}

// Builds Huffman Tree and decode given input text
void buildHuffmanTree(string text)
{
	// count frequency of appearance of each character
	// and store it in a map
	unordered_map<char, int> freq;
	for (char ch: text) {
		freq[ch]++;
	}
	
	//Printing the HuffMan Table
	char ch = 'A';
	cout<<endl;
	cout<<"Printing Huffman Table"<<endl;
	
	for(int i = 0; i < 26; i++){
		cout<<ch<<" "<<freq[ch]<<endl;
		ch += 1;
	}
	
	// Create a priority queue to store live nodes of
	// Huffman tree;
	priority_queue<Node*, vector<Node*>, comp> pq;

	// Create a leaf node for each character and add it
	// to the priority queue.
	for (auto pair: freq) {
		pq.push(getNode(pair.first, pair.second, nullptr, nullptr));
	}

	// do till there is more than one node in the queue
	while (pq.size() != 1)
	{
		// Remove the two nodes of highest priority
		// (lowest frequency) from the queue
		Node *left = pq.top(); pq.pop();
		Node *right = pq.top();	pq.pop();

		// Create a new internal node with these two nodes
		// as children and with frequency equal to the sum
		// of the two nodes' frequencies. Add the new node
		// to the priority queue.
		int sum = left->freq + right->freq;
		pq.push(getNode('\0', sum, left, right));
	}

	// root stores pointer to root of Huffman Tree
	Node* root = pq.top();

	// traverse the Huffman Tree and store Huffman Codes
	// in a map. Also prints them
	unordered_map<char, string> huffmanCode;
	encode(root, "", huffmanCode);

	//cout << "Huffman Codes are :\n" << '\n';
	cout<<endl;
	
	string file2Name;
	cout<<"Creating huffman coding..."<<endl;
	cout<<" enter name of file to store the table :";cin>>file2Name;
	
	ofstream file2;
	file2.open(file2Name, ios::out |ios::app);
	
	if(file2.is_open()){
		for (auto pair: huffmanCode) {
			//cout << pair.first << " " << pair.second << '\n';
			file2<< pair.first << " " << pair.second << '\n';
		}
		file2.close();
	}else{
		cout<<"Error file"<<endl;
	}
	/*for (auto pair: huffmanCode) {
		cout << pair.first << " " << pair.second << '\n';
	}*/

	//cout << "\nOriginal string was :\n" << text << '\n';

	// print encoded string
	string str = "";
	for (char ch: text) {
		str += huffmanCode[ch];
	}

	string file3Name;
	cout<<"enter name of file to hold the encoded msg :";cin>>file3Name;
	ofstream file3;
	file3.open(file3Name, ios::out | ios::trunc);
	
	if(file3.is_open()){
		//cout<<"Success"<<endl;
		file3<< str;
		file3.close();
	}else{
		cout<<"Error file 2"<<endl;
	}
	
	//cout << "\nEncoded string is :\n" << str << '\n';
	
	// traverse the Huffman Tree again and this time
	// decode the encoded string
	
	string file4Name,line;
	cout<<"uncompressing file ..."<<endl;
	cout<<" enter the compressed message file name :";cin>>file4Name;
	
	fstream file4;	
	file4.open(file4Name, ios::in);
	
	if(file4.is_open()){
		//cout<<"Success"<<endl;
		getline(file4,line);
		cout<<line<<endl;
		
		file4.close();
	}else{
		cout<<"Error file 4"<<endl;
	}
	
	int index = -1;
	cout << "\nDecoded string is: \n";
	while (index < (int)line.size() - 2) {
		decode(root, index, line);
	}
}

