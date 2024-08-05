#include<iostream>
using namespace std;

/*
������ : ��ü�� ������ ���Ŀ� �ڵ����� ȣ��Ǵ� �Լ�
		Ŭ����_�̸�() ���� �����Ѵ�.
*/

class character {
public:
	character() {
		cout << "character Ŭ���� ������" << endl;
	};
};

class monster {
public:
	monster() {
		cout << "monster Ŭ���� ������" << endl;
	};
};

class monster_a : public monster, character {
public:
	monster_a() : monster_a(10,10) { // ������ ���� �ʱ�ȭ ��Ͽ� �ٸ� ������ ȣ���� �����ϴ�. (C++11����)
		cout << "monster_a Ŭ���� ������" << endl;
	};

	monster_a(int x, int y) : location{ x,y } { 
		// : �ڴ� �ʱ�ȭ ����̶�� �ϸ�, �Ű������� ���޹��� ������ ������ �ʱ�ȭ�Ѵ�.
		cout << "monster_a Ŭ���� ������ (�Ű����� �߰�)" << endl;
	};

	void show_location() {
		cout << "��ġ(" << location[0] << ", " << location[1] << ")" << endl;
	};
private:
	int location[2];
};

int main() {
	character player;

	//��� Ŭ������ ������ ȣ�� ������
	//��ӹ��� ������� monster -> character ������ ȣ��ǰ�
	//���������� �ڽ��� �����ڰ� ȣ��ȴ�.
	//��, monster -> character -> monster_a ���̴�.
	monster_a forest_monster;
	forest_monster.show_location();

	monster_a wood_monster(10, 25);
	wood_monster.show_location();
	return 0;
}