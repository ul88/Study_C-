#include<iostream>
#include<list>
using namespace std;
int main()
{
	list<int> myList;

	myList.push_back(2);
	myList.push_back(3);
	myList.push_back(4);

	myList.push_front(1);
	myList.push_front(0);

	cout << "����Ʈ ���:" << endl;
	for (auto iter : myList) {
		cout << iter << " ";
	}

	myList.pop_front();
	myList.pop_back();

	cout << "����Ʈ ���:" << endl;
	for (auto iter : myList) {
		cout << iter << " ";
	}
	return 0;
}