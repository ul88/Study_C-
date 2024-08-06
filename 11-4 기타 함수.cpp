#include<iostream>
#include<random> // ���� ����
#include<chrono> // �õ尪 ����
using namespace std;
int main()
{
	//�õ尪 ���
	auto curTime = chrono::system_clock::now();
	auto duration = curTime.time_since_epoch();
	auto millis = chrono::duration_cast<chrono::milliseconds>(duration).count();

	//mt19937 : 32bit ����
	//mt19937_64 : 64bit ����
	//rand, srand �Լ��� ���� ������ �� �ִ� ���� ũ�Ⱑ �� ŭ
	mt19937_64 mt_rand(millis);

	for (int i = 0;i < 10;i++) {
		cout << mt_rand() << endl;
	}

	/*
		�����Լ�
		���� ���� : �ּڰ��� ����
		���� ���� : ���� ���� ���ο� �޸� ������ ����
	*/
	return 0;
}