#include<iostream>
#include<set>
#include<map>
using namespace std;
/*
	���� �����̳ʵ��� �˻� �۾��� �ð����⵵�� O(logN) �Ǵ� O(1)�� ������.
*/

int main() {
	//��Ƽ ��
	multiset<int> myMultiset;

	myMultiset.insert(5);
	myMultiset.insert(2);
	myMultiset.insert(5);

	int count = myMultiset.count(5);
	cout << "����Ǿ� �ִ� 5�� ����: " << count << endl;

	for (auto iter : myMultiset) {
		cout << iter << " ";
	}
	cout << endl;

	//��Ƽ��
	multimap<string, int> scores;
	scores.insert({ "Bob", 85 });
	scores.insert({ "Jane", 90 });
	scores.insert({ "Tom", 70 });
	scores.insert({ "Bob", 100 });

	cout << "multimap ũ�� : " << scores.size() << endl;

	count = scores.count("Bob");
	cout << "����Ǿ� �ִ� Bob ������ ����: " << count << endl;

	auto range = scores.equal_range("Bob");
	if (range.first != scores.end()) {
		cout << "Bob�� ��� ����: ";
		for (auto iter = range.first; iter != range.second; iter++) {
			cout << iter->second << " ";
		}
		cout << endl;
	}
	else {
		cout << "Bob�� ������ ���� X" << endl;
	}

	scores.erase("Bob");

	cout << "��Ƽ�� ���� ���" << endl;
	for (auto iter : scores) {
		cout << iter.first << " " << iter.second << "\n";
	}
}