#include<iostream>
using namespace std;
/*
�Ҹ��� : �����ڿ� �ݴ� ������ �ϸ�, �Ҹ��ڴ� ��ü�� �Ҹ��� �� ����ȴ�.
�Ҹ��ڿ����� ��ü�� �Ҹ��� �� �ʿ��� �޸� ������ �ܺ� ȯ���� ��ü ���� ���� ���·�
�����ϴ� ���� ���� �����Ѵ�.
*/

class character {
public:
	character() {
		cout << "character Ŭ���� ������" << endl;
	}
	virtual ~character() {
		cout << "charactor Ŭ���� �Ҹ���" << endl;
	}
};

class monster {
public:
	monster() {
		cout << "monster Ŭ���� ������" << endl;
	}
	virtual ~monster() {
		cout << "monster Ŭ���� �Ҹ���" << endl;
	}
};

class monster_a : public monster, character {
public:
	monster_a() {
		cout << "monster_a Ŭ���� ������" << endl;
	}
	virtual ~monster_a() {
		cout << "monster_a Ŭ���� �Ҹ���" << endl;
	}
};

int main()
{
	// �Ҹ����� ȣ�� ������ �������� �����̴�.
	//monster_a forest_monster;

	//�������� ġȯ ��Ģ ����
	monster* forest_monster = new monster_a();
	/*
	�Ҹ��ڿ� virtual�� ������ ���� ��, monster Ŭ������ �ش��ϴ� �Ҹ��ڸ� ����ȴ�.
	�Ҹ��ڿ� virtual�� ���� ��, monster_a forest_monster�� �������� ���� �Ȱ���, ��� �Ҹ��ڰ� ����ȴ�.
	*/
	delete forest_monster;
	return 0;
}