# include<bits/stdc++.h>
using namespace std;
class Node {
public:
	int prn;
	Node* next;
	Node* prev;

	Node()
	{
		prn = 0;
		next = NULL;
		prev = NULL;
	}
	Node(int prn)
	{
		this->prn = prn;
		this->next = NULL;
		this->prev = NULL;
	}
	
};

class Linkedlist {
	Node* head;

public:

	Linkedlist() { head = NULL; }
	void insertNode(int);

	void printList();
	int count();
	void concat();
	void deleteNode(int);


};

void Linkedlist::deleteNode(int key)
{
	Node *head_ref = head;
	Node *temp = head_ref->next;
	Node *prev1 = NULL;
	if (head_ref->prn==key)
	{
		delete head_ref;
		head = temp;
		
		
	}
	else
   
	{
		Node *temp1 = head;
		while(temp1->next!=NULL && temp1->prn != key)
		{
			prev1 = temp1;
			temp1 = temp1->next;
			
		}
		if (temp1==NULL)
		{
			cout<<key<<" Not found"<<endl;
		}
		prev1->next = temp1->next;
		delete temp1;
	}
}
void Linkedlist::concat()
{
	
	int n1;
	int data1;
	cout<<"Enter how many elements you want to enter in linked list 2: ";
	cin>>n1;
	for (int i= 0; i<n1; i++)
	{
		cout<<"Enter Element: ";
		cin>>data1;
		Linkedlist::insertNode(data1);
	}
	
	
}
int Linkedlist::count()
{
	int cnt = 0;
	Node* temp = head;
	if (head == NULL) {
		
		return cnt;
	}

	while (temp != NULL) {
		cnt += 1;
		temp = temp->next;
	}
	return cnt;
}

void Linkedlist::insertNode(int prn)
{
	Node* newNode = new Node(prn);
	if (head == NULL) {
		head = newNode;
		return;
	}

	Node* temp = head;
	while (temp->next != NULL) {

		temp = temp->next;
	}

	temp->next = newNode;
	newNode->prev = temp;
	cout<<"Previous element: "<<newNode->prev->prn<<endl;
	
}


void Linkedlist::printList()
{
	Node* temp = head;
	if (head == NULL) {
		cout << "List empty" << endl;
		return;
	}

	while (temp != NULL) {
		cout << temp->prn << "->";
		temp = temp->next;
	}
	if (temp==NULL)
	{
		cout<<"NULL";
	}
}

int main()
{
	Linkedlist list;
	int prn;
	string name1;
	string yesNO;
    while (1)
    {

    		cout<<"Enter PRN No.: ";
	    	cin>>prn;
	    	list.insertNode(prn);
	    	cout<<"DO you want to continue press y otherwise press n: ";
	    	cin>>yesNO;
	    	if (yesNO=="y")
	    	continue;
	    	else
	    	break;
		
    
    	
		
			
	}


	cout << "------------------------Elements of the list are ----------------------------\n";
	
	list.printList();
	
	cout<<"\nCount of element in linked list is: "<<list.count()<<endl;
	cout << endl;

	list.concat();
	cout<<"Concatenated link list: ";
	list.printList();
	cout<<"\nCount of element in concatenated linked list is: "<<list.count()<<endl;
	int key;
	cout<<"Enter which element you want to delete:";
	cin>>key;
	list.deleteNode(key);
	list.printList();
	cout << endl;
	return 0;
}
