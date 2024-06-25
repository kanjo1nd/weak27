#include <iostream>
using namespace std;

/*
   �������� � ����� "����������� ������" ��������� ������� :
	  �������� �������� �� �������� �������,
	  �������� ���������� ��������,
	  ����� ��������� ��������(������� ���������� ������� ���������� �������� � ������ ������ ��� NULL � ������ �������).
*/
struct Element
{
	// ������
	char data;
	// ����� ���������� �������� ������
	Element* Next;
};

// ����������� ������
class List
{
	// ����� ��������� �������� ������
	Element* Head;
	// ����� ��������� �������� ������
	Element* Tail;
	// ���������� ��������� ������
	int Count;

public:
	// �����������
	List();
	// ����������
	~List();

	// ���������� �������� � ������
	// (����� ������� ���������� ���������)
	void Add(char data);

	// �������� �������� ������
	// (��������� �������� �������)
	void Del();
	// �������� ����� ������
	void DelAll();

	// ���������� ����������� ������
	// (���������� ���������� � ��������� ��������)
	void Print();

	// ��������� ���������� ���������, ����������� � ������
	int GetCount();

	void AddIndex(char data, int index)// Z, 2
	{
		Element* temp = Head;
		int i = 1;
		while (i < index)
		{
			temp = temp->Next;
			i++;
		}
		Element* NewNode = new Element;
		NewNode->data = data;

		// ��������� ������
		NewNode->Next = temp->Next;
		temp->Next = NewNode;
	}

	// ����� ��������� ��������
	int Search(char c) {
		Element* temp = Head;
		int i = 0;
		while (temp != nullptr) {
			if (temp->data == c) {
				return i;
			}
			i++;
			temp = temp->Next;
		}
		return NULL;
	}
};

List::List()
{
	// ���������� ������ ����
	Head = Tail = NULL;
	Count = 0;
}

List::~List()
{
	// ����� ������� ��������
	DelAll();
}

int List::GetCount()
{
	// ���������� ���������� ���������
	return Count;
}

void List::Add(char data)
{
	// �������� ������ ��������
	Element* temp = new Element;

	// ���������� �������
	temp->data = data;
	// ��������� ������� �����������
	temp->Next = NULL;
	// ����� ������� ���������� ��������� ��������� ������
	// ���� �� �� ������ �����������
	if (Head != NULL) {
		Tail->Next = temp;
		Tail = temp;
	}
	// ����� ������� ���������� ������������
	// ���� �� ������ �����������
	else {
		Head = Tail = temp;
	}
}

void List::Del()
{
	// ���������� ����� ��������� ��������
	Element* temp = Head;
	// ������������� ������ �� ��������� �������
	Head = Head->Next;
	// ������� ������ �������� �������
	delete temp;
}

void List::DelAll()
{
	// ���� ��� ���� ��������
	while (Head != 0)
		// ������� �������� �� ������
		Del();
}

void List::Print()
{
	// ���������� ����� ��������� ��������
	Element* temp = Head;
	// ���� ��� ���� ��������
	while (temp != 0)
	{
		// ������� ������
		cout << temp->data << " ";
		// ��������� �� ��������� �������
		temp = temp->Next;
	}

	cout << "\n\n";
}

// �������� ������
void main()
{
	// ������� ������ ������ List
	List lst;
	lst.Add('A');
	lst.Add('B');
	lst.Add('C');
	lst.Add('D');
	lst.Add('E');
	lst.Add('F');
	lst.Print();

	lst.AddIndex('Z', 2);
	lst.Print();

	cout << lst.Search('E') << endl;
}