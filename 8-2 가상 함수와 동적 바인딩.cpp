#include<iostream>
using namespace std;
/*
	C++���� �������� ������ �� ��� �Լ� ��� �ڽ� Ŭ�������� �������̵��ؾ� �ϴ� �Լ���
	�����Լ��� �����ؾ��Ѵ�.

	�Ϲ� ��� ������ ��ĳ���õ� �θ� Ŭ������ ������ �Լ��� ȣ�������,
	���� �Լ��� �ڽ� Ŭ�������� �������̵��� �Լ��� ȣ��ȴ�.

	*���� �Լ� ��� ���� : ������ ����

	�������� ġȯ ��Ģ�� ���� �ڽ� Ŭ������ �θ� Ŭ������ ��ü�ϴ���(��ĳ����) �θ� Ŭ������
	��� �Լ��� �ƴ� �ڽ� ũ������ �������̵��� �Լ��� ȣ��ž� �������� �����ȴ�.

	���ε� : ���α׷��� �����ϸ� �Լ� ȣ���̳� ���� ������ �ش� �ڵ�� ����Ǵ� ��

	���� ���ε� : �������� �� �����Ǿ� ���α׷��� ����Ǵ� ���� �״�� �����ȴ�.
		auto ���� �ܿ��� ���� �߷��� ���� �����Ƿ�, �Ϲ� ������ �Լ�, Ŭ����, ���� ��� �Լ�,
		���ø� �� ��κ��� �������� ���ε��Ѵ�.
	���� ���ε� : ����� ���� ������ �����Ǹ� ����� �� �ִ�.

	���� �Լ� ���̺� : �޸𸮿� _vfptr �̶�� ���� �Լ� ���̺��� ����Ű�� �����Ͱ� �ڵ����� �����,
	��ü�� ���� �Լ��� ȣ�� �� �� _vfptr�� ����Ѵ�.

	�����Լ� ���̺��� Ŭ������ ���� �������� �ֻ��� Ŭ�������� �����Ѵ�.
		�ڽ� Ŭ������ �θ� Ŭ������ ���� �Լ� ���̺��� ��ӹ�����, ���� �Լ��� �������̵� �� ��
		�ش� �Լ��� �ּҸ� ���� �Լ� ���̺� ����Ѵ�.



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
	virtual void attack_special(player target_player);
};

void monster::attack_special(player target_plater) {
	cout << "�⺻ ���� : ������ - 10 hp" << endl;
}

class monster_a : public monster, character {
public:
	virtual void attack_special(player target_player) override {
		cout << "����Ŭ ���� : ������ - 15 hp" << endl;
	}
};

int main() {
	player player_1;

	monster mother_monster;
	monster_a forest_monster;

	mother_monster.attack_special(player_1);

	monster* mon = &forest_monster;
	cout << endl << "�θ� Ŭ������ ��ĳ���� �� ����" << endl;
	mon->attack_special(player_1);

	mon = &mother_monster;
	cout << endl << "�θ� Ŭ������ ����" << endl;
		mon->attack_special(player_1);
}
