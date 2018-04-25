#include<bits/stdc++.h>
using namespace std;

struct HeapNode
{
	char data;
	int frequency;
	HeapNode* left;
	HeapNode* right;
	HeapNode(char c,int d)
	{
		data = c;
		frequency = d;
		left = NULL;
		right = NULL;
	}
};

void buildMinHeap(vector<HeapNode*> &roots);
void minHeapify(int index,int n,vector<HeapNode*> &roots);
void buildHuffmanTree(vector<HeapNode*> &roots);
void generateCodes(HeapNode* root,string code);
void showHuffManTree(HeapNode* root);

int main()
{
	int numberOfInputs;
	cout<<"Enter the number of characters : ";
	cin>>numberOfInputs;

	vector<HeapNode*> roots(numberOfInputs);

	cout<<"Enter the character and its frequency space seperated for all "<<numberOfInputs<<" characters.\n";

	for(int i=0;i<numberOfInputs;i++)
	{
		int d;
		char c;
		cin>>c>>d;
		roots[i] = new HeapNode(c,d);
	}

	buildMinHeap(roots);
	buildHuffmanTree(roots);
	//showHuffManTree(roots[0]);
	cout<<"\n\n\nHuffman Codes for given characters are as below.\n";
	generateCodes(roots[0],"");

	return 0;
}

void buildMinHeap(vector<HeapNode*> &roots)
{
	for(int i=roots.size()/2-1;i>=0;i--)
		minHeapify(i,roots.size(),roots);
	return ;
}

void minHeapify(int index,int n,vector<HeapNode*> &roots)
{
	int smallestIndex = index;
	int leftIndex = 2*index+1;
	int rightIndex = 2*index+2;

	if(leftIndex<n && roots[leftIndex]->frequency<roots[smallestIndex]->frequency)
		smallestIndex = leftIndex;
	if(rightIndex<n && roots[rightIndex]->frequency<roots[smallestIndex]->frequency)
		smallestIndex = rightIndex;

	if(smallestIndex != index)
	{
		HeapNode* tempNode = roots[smallestIndex];
		roots[smallestIndex] = roots[index];
		roots[index] = tempNode;

		minHeapify(smallestIndex,n,roots);
	}
	return ;
}

void buildHuffmanTree(vector<HeapNode*> &roots)
{
	if(roots.size()>1)
	{
		HeapNode* node1 = roots[0];
		roots.erase(roots.begin(),roots.begin()+1);
		minHeapify(0,roots.size(),roots);
		HeapNode* node2 = roots[0];
		roots.erase(roots.begin(),roots.begin()+1);
		//minHeapify(0,roots.size(),roots);
		HeapNode* newNode = new HeapNode('-',node1->frequency + node2->frequency);
		newNode->left = node1;
		newNode->right = node2;
		cout<<node1->frequency<<"  "<<node2->frequency<<endl;
		roots.push_back(newNode);
		minHeapify(0,roots.size(),roots);
		buildHuffmanTree(roots);
	}
}

void generateCodes(HeapNode* root,string code)
{
	if(root==NULL)
		return;
	if(root->left==NULL && root->right==NULL)
	{
		cout<<root->data<<"   "<<code<<endl;
		return;
	}

	generateCodes(root->left,code+"0");
	generateCodes(root->right,code+"1");
}

void showHuffManTree(HeapNode* root)
{
	if(root!=NULL)
	{
		showHuffManTree(root->left);
		cout<<root->data<<" "<<root->frequency<<endl;
		showHuffManTree(root->right);
	}
}

/*
Input:
6
a 5
b 9
c 12
d 13
e 16
f 45

Output:
f   0
c   100
d   101
a   1100
b   1101
e   111
*/