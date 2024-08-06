#include<iostream>
#include<vector>
using namespace std;
template<typename T>
void pinrt_vector_all(vector<T>& v) {
	cout << "���� �� ���� ���� : " << v.size() << endl;
	for (auto iter : v) {
		cout << iter << " ";
	}
	cout << endl << "-----------" << endl;
}
int main()
{
	vector<int> v = { 0,10,20,30,40 };

	cout << "����" << endl;
	pinrt_vector_all(v);

	v.insert(v.begin() + 3, 25);
	cout << "insert ���" << endl;
	pinrt_vector_all(v);

	v.erase(v.begin() + 3);
	cout << "erase ���" << endl;
	pinrt_vector_all(v);


	//vector<int>::const_iterator : ���� �ݺ��ڷ� �ݺ��ڰ� ����Ű�� ���ڰ��� ������ �� ����.

	vector<int>::const_iterator const_it = v.cbegin();
	cout << *const_it << endl;

	++const_it;
	cout << *const_it << endl;
	
	const_it = v.cend();
	--const_it;
	cout << *const_it << endl;


	cout << "������ �ݺ��� ���" << endl;
	for (auto it = v.rbegin();it != v.rend();it++) {
		cout << *it << endl;
	}
	return 0;
}