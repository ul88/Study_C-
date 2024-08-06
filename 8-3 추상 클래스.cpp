#include<iostream>
#include<list>
using namespace std;
/*
	�߻� Ŭ���� : Ŭ������ ���� ���� �Լ��� �ִ� Ŭ����
		�߻� Ŭ������ ���Ǵ� �Ϲ� Ŭ������ ���� Ŭ������� �Ѵ�.

	C++���� �߻� Ŭ������ �Ϲ� Ŭ������ �޸� ��ü�� ���� ������ �� ������,
	�߻� Ŭ������ ��ӹ��� �ڽ� Ŭ�������� ��ü�� �����Ѵ�.

	�ڽ� Ŭ���������� ���� ���� �Լ��� �ݵ�� �������̵��ؾ��Ѵ�.

	�߻� Ŭ������ ��ü���� ��Ģ�� �������� ������ �� ����Ѵ�.
	�߻� Ŭ�������� Ư�� ������ ����� �Լ��� ���� �س���, ���� �ڽ� Ŭ��������
	���� �ٸ� �˰������� �����ϵ��� ������ �� �ִ�.
*/
class character {
public:
	character() : hp(100), power(100) {}
protected:
	int hp;
	int power;
};

class player : public character {
public:
	player() {}
};

class monster {
public:
	monster() {
		cout << "Monster �θ� Ŭ���� ������"<<endl;
	}
	virtual ~monster() {
		cout << "Monster �θ� Ŭ���� �Ҹ���" << endl;
	}
	virtual void find_route() = 0;
	virtual void attack_special(player target_plater) = 0;
};

class monster_a : public monster {
public:
	virtual void attack_special(player target_player) override {
		cout << "���ޱ� ���� : ������ - 15 hp" << endl;
	}
	virtual void find_route() override {
		cout << "���� �켱 Ž��(DFS)" << endl;
	}
};

class monster_b : public monster, character {
public:
	virtual void attack_special(player target_player) override {
		cout << "���� ���� : ������ - 0 hp" << endl;
	}
	virtual void find_route() override {
		cout << "�ʺ� �켱 Ž��(BFS)" << endl;
	}
};

class monster_c : public monster, character {
public:
	virtual void attack_special(player target_player) override {
		cout << "���� ���� ���� : ������ - 100 hp" << endl;
	}
	virtual void find_route() override {
		cout << "���ͽ�Ʈ�� �ִ� ��� �˰���" << endl;
	}
};

void monster_routine(monster* mon, player target_plater) {
	mon->find_route();
	mon->attack_special(target_plater);
}

int main() {
	list<monster*> mon_list;
	player target_player;
	monster_a first_monster;
	mon_list.push_back(&first_monster);

	monster_b second_monster;
	mon_list.push_back(&second_monster);

	monster_c third_monster;
	mon_list.push_back(&third_monster);

	for (auto item : mon_list) {
		monster_routine(item, target_player);
	}
	return 0;
}