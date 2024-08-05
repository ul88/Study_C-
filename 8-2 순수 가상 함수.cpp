#include<iostream>
#include<list>
using namespace std;
/*
	���� ���� �Լ� : �θ� Ŭ���������� ���� �Լ��� ���� �ϰ� �ڽ� Ŭ�������� �����ϵ���
	�����ϴ� ���� �Լ�
		�θ� Ŭ���������� �������� ������, �ڽ� Ŭ������ ����� �̸� �����ϰ� ���� �� ���

	���� ���� �Լ� ����
		virtual void attack_special(player_target) = 0;
	
	���� ���� �Լ��� ������ �Ŀ��� �� Ŭ������ ��ӹ޴� �ڽ� Ŭ�������� �ݵ�� �����ؾ��Ѵ�.
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
	monster() {}
	void get_damage(int _damage) {}
	void attack(player target_player) {}
	virtual void attack_special(player target_player) {
		cout << "�⺻ ���� : ������ - 10 hp" << endl;
	}
	virtual void attack_at_dawn() = 0;
};

class monster_a : public monster, character {
public:
	virtual void attack_special(player target_player) override {
		cout << "���ޱ� ���� : ������ - 15 hp" << endl;
	}
	virtual void attack_at_dawn() override {
		cout << "���ʿ��� ���!" << endl;
	}
};

class monster_b : public monster, character {
public:
	virtual void attack_special(player target_player) override {
		cout << "���� ���� : ������ - 0 hp" << endl;
	}
	virtual void attack_at_dawn() override {
		cout << "������ ������ ħ���Ͽ� ��ȭ!" << endl;
	}
};

class monster_c : public monster, character {
public:
	virtual void attack_special(player target_player) override {
		cout << "���� ���� ���� : ������ - 100 hp" << endl;
	}
	virtual void attack_at_dawn() override {
		cout << "���ʿ��� ������ ���� ���� �߻�!" << endl;
	}
};

int main() {
	list<monster*> mon_list;

	monster_a first_monster;
	mon_list.push_back(&first_monster);

	monster_b second_monster;
	mon_list.push_back(&second_monster);

	monster_c third_monster;
	mon_list.push_back(&third_monster);

	for (auto item : mon_list) {
		item->attack_at_dawn();
	}
	return 0;
}