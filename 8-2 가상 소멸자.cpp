#include<iostream>
using namespace std;
/*
	�����ڴ� �θ� -> �ڽ� ������ ȣ��ǰ�
	�Ҹ��ڴ� �ڽ� -> �θ� ������ ȣ��ȴ�.

	�׷��� �θ�Ŭ������ ��ĳ������ �� ����,
	�����ڴ� ����� �θ� -> �ڽ� ������ ȣ�������,
	�ڽ� Ŭ������ �Ҹ��ڴ� ȣ����� �ʴ´�.
	�̷��� �Ǹ� �ڽ� Ŭ������ �ִ� �Ҹ��ڰ� ������� �����Ƿ�, �ڵ忡 ����
	�޸� ������ �߻��� �� �ִ�.

	���� �Ҹ��� : �Ҹ��ڸ� ���� �Լ��� �����ϴ� ��

	���� �Ҹ��ڸ� ����ϸ� ��ĳ���õ� monster_a�� �Ҹ��ڰ� ȣ��� �Ŀ� ��� ������ ����
	�θ� Ŭ������ �ö󰡸鼭 ȣ��ȴ�.
*/

class monster {
public:
	monster() {
		cout << "monster() ������ ȣ��" << endl;
		dummy = new int;
	}
	virtual ~monster() {
		cout << "~monster() �Ҹ��� ȣ��" << endl;
		delete dummy;
	}
private:
	int* dummy;
};

class monster_a : public monster {
public:
	monster_a() {
		cout << "monster_a() ������ ȣ��" << endl;
		dummy_a = new int;
	}
	~monster_a() {
		cout << "~monster_a() �Ҹ��� ȣ��" << endl;
		delete dummy_a;
	}
private:
	int* dummy_a;
};

int main()
{
	monster* mon = new monster_a();
	delete mon;
	return 0;
}