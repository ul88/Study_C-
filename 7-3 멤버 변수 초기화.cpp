#include<iostream>
using namespace std;

/*
-�Ϲ� ��� ���� �ʱ�ȭ-
���� �ʱ�ȭ : �ʱ�ȭ ����� �̿��Ͽ� �ʱ�ȭ�ϴ� ��
���� �ʱ�ȭ : ���� ������ �̿��ؼ� �ʱ�ȭ�ϴ� ��
���� �ʱ�ȭ�� ���� ������ �̿��ϹǷ� �����Ͱ� ����Ǿ� ����.
����, �޸� ������ �߰��� �ʿ��ϹǷ� ���ɿ� �̼��� ���̰� �����.
�Ϲ� ������ ū ���̰� ������, Ŭ���� ������ ���� �ʱ�ȭ�� ���� �ʱ�ȭ ���̿� ���̰� �����Ѵ�.

-���۷��� ��� ������ ��� ��� ���� �ʱ�ȭ-
���۷��� ������ ��� ������ ����� ���ÿ� ���� ���������Ѵ�.
����, Ŭ������ ����� ������ ���۷��� ������ ��� ������ �����ڿ���
�ʱ�ȭ ����̳� ���� ������ ���� �ݵ�� �ʱ�ȭ �ؾ��Ѵ�.
��� ��� ������ ����� ���ÿ� ���� �����ص��ȴ�.

-���� ��� ���� �ʱ�ȭ-
Ŭ���� ��� ������ static���� �����ϸ� �ش� Ŭ������ �����ϴ� ��� ��ü���� ������ �����ϴ�.
����, Ŭ������ ������ ���� ������ ���� �������� �ʱ�ȭ�ؾ��Ѵ�.
���� ��� ������ ���� �������� �ʱ�ȭ�ǹǷ� � Ŭ������ ���� ������� �� �� �ֵ���
���ӽ����̽��� �߰��ؾ��Ѵ�.
*/

class character {
public:
	character() {
		cout << "character Ŭ���� ������" << endl;
	};
};

class player : public character {
public:
	player() {};
};

class monster {
public:
	monster() {
		cout << "monster Ŭ���� ������" << endl;
	};
};

class monster_b : private monster, character {
public:
	//�ʱ�ȭ ��Ͽ����� �ʱ갪�� �Ұ�ȣ�� ���Ѵ�.
	monster_b(player& attack_target)
		: monster_type("�Ϲ�"), // ���� �ʱ�ȭ : ��� ������ ���� ���� �����ϴ� ���.
		location{ 0,0 }, // ������ �ʱ�ȭ : �迭 ������ ��� ������ �ʱ�ȭ�ϴ� ���.
		unique_id(++total_count), // ��� ��� ���� �ʱ�ȭ : ��� ��� ������ ������ �� �����Ƿ� �����ڷ� �ʱ�ȭ�ؾ��Ѵ�.
		target(attack_target) { // ���۷��� ��� ���� �ʱ�ȭ : ���۷��� ��� ������ ������ �� �����Ƿ� �����ڿ��� �ʱ�ȭ�ؾ��Ѵ�.
		difficult_level = 10; // ���� �ʱ�ȭ : ���Ǻο��� ��� ������ ���� ���� �����Ѵ�.
		quiz = new char[1024]; // ���� �޸� �Ҵ� : ������ ������ �޸𸮴� �ʿ信 ���� �����ڿ��� �ʱ�ȭ �� �� �ִ�.
		
		cout << "monster_type : " << monster_type << endl;
		cout << "location : " << location[0] << " " << location[1] << endl;
		cout << "unique_id : " << unique_id << endl;
		cout << "difficult_level : " << difficult_level << endl;
		cout << "sizeof(quiz) : " << sizeof(quiz) << endl;
	};
	~monster_b() {
		cout << "�Ҹ��� ����" << endl;

		delete[]quiz;
	};
private:
	string monster_type;
	int location[2];
	static int total_count;
	const int unique_id;
	player& target;
	int difficult_level;
	char* quiz;
};

int monster_b::total_count = 0; //���� ���� �ʱ�ȭ

int main() {

	player player_1;
	monster_b monster(player_1);
	return 0;
}