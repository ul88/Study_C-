#include<iostream>
#include<vector>
using namespace std;
/*
	�����̳� : ���� Ÿ���� ���� ��ü�� ������ �� �ִ� ���� ������ ������ ����

	�ݺ��� : ��ü���� ���α׷��ֿ��� �����̳��� ���� ���ҵ��� ��ȸ�ϴ� ��ü
*/

int main()
{
	//begin() : ���� ��ġ
	//end() : ������ ��� ���� ��ġ
	vector<int> v {0,1,2,3,4};

	vector<int>::iterator it = v.begin();

	cout << *it << endl;
	cout << *(it + 1) << endl;
	cout << *(it + 2) << endl;
	cout << *(it + 3) << endl;
	cout << *(it + 4) << endl;

	for (vector<int>::iterator it = v.begin();it != v.end();it++) {
		cout << *it << " ";
	}
	return 0;
}