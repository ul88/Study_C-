#include<iostream>
using namespace std;

/*
��ӹ��� Ŭ���� : �ڽ� Ŭ����, �Ļ� Ŭ����, ���� Ŭ����
������ִ� Ŭ���� : �θ� Ŭ����, �⺻ Ŭ����, ���� Ŭ����

�Լ� �ñ״�ó : �Լ��� �̸�, �Ű����� ����, ��ȯ ������ �ƿ츣�� ���


�ڽ� Ŭ������ �θ� Ŭ������ ��ü�� �� �־���Ѵ�.
��, �θ� Ŭ������ �ڽ� Ŭ������ ġȯ�� �� �־���Ѵ�.
����, �θ� �ܺη� ������ �Լ��� �ñ״�ó�� �״�� ����ؾ��Ѵ�.

�� ġȯ�ؾ��Ѵٴ� ���� �θ� Ŭ������ ��� ���� ���װ� ���� ����� �״�� �����ؾ��Ѵٴ� ���̴�.
�̸� '�������� ġȯ ��Ģ'�̶�� �Ѵ�.

���� ����� ������ ��, 
class monster_a : public monster, character {}; �� ���� ����ϸ�
monster�� public���� ��ӹް�, character�� private�� ��� �޴´�.
��, ���������ڸ� �����ϸ� private�̴�.

*�̴� Ŭ������ �������� ����ü�� ���� ���� �⺻���� public�̴�.*

�ڽ� Ŭ������ �������̵��� �Լ��� ���ӽ����̽��� �̿��� �θ� Ŭ������ �Լ��� ����� �� �ִ�.

�θ� Ŭ������ ���۷����� ����ϰų� �ڽ� Ŭ������ ���۷����� ����ϰų�
�⺻�����δ� ���۷����޴� Ŭ������ ��������, virtual�� �ٿ� ���� �Լ��� Ȱ���ϸ�
�׻� ���������� �������̵��� �Լ��� ȣ���Ѵ�.

*/

class character {
public:
	character() : hp(100), power(100) {};
protected:
	int hp;
	int power;
};

class player : public character {
public:
	player() {};
};

class monster {
public:
	monster() {};
	void get_damage(int _damage) {};
	void attack(player target_player) {};
	virtual void attack_special(player target_player); // ���� �Լ� ����
};

void monster::attack_special(player target_player) {
	cout << "�⺻ ���� : ������ - 10hp" << endl;
}

class monster_a : public monster, character {
public:
	void attack_special(player target_player);
};

void monster_a::attack_special(player target_player) {
	cout << "���ޱ� ���� : ������ -15hp" << endl;
}

class monster_b : public monster, character {
public:
	void attack_special(player target_player);
};

void monster_b::attack_special(player target_player) {
	cout << "���� ���� : ������ -0hp" << endl;
}

class monster_c : public monster, character {
public:
	void attack_special(player target_player);
};

void monster_c::attack_special(player target_player) {
	cout << "���� ���� ���� : ������ -100hp" << endl;
}

class monster_d : public monster, character {

};

int main()
{
	player player_1;

	monster basic_monster;
	monster_a forest_monster;
	monster_b tutorial_monster;
	monster_c boss_monster;
	monster_d dummy_monster;

	cout << "���� �� ����" << endl;
	basic_monster.attack_special(player_1);
	dummy_monster.attack_special(player_1);
	forest_monster.attack_special(player_1);
	tutorial_monster.attack_special(player_1);
	boss_monster.attack_special(player_1);

	cout << "�⺻(monster Ŭ����) ����" << endl;
	forest_monster.monster::attack_special(player_1);
	tutorial_monster.monster::attack_special(player_1);
	boss_monster.monster::attack_special(player_1);

	monster& mon = forest_monster;
	monster_a& mon_a = forest_monster;

	cout << endl << "�θ� Ŭ���� ���۷����� ����" << endl;
	mon.attack_special(player_1);
	cout << endl << "�ڽ� Ŭ���� ���۷����� ����" << endl;
	mon_a.attack_special(player_1);
	return 0;
}