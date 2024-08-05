#include<iostream>
using namespace std;

/*
Ŭ�������� ���� ���縦 �����ϴ� ���� �����ڰ� �⺻���� ���ǵǾ� ������,
�ʿ��� �� ���� �����ڸ� �������̵��ؼ� ����ؾ��Ѵ�.
���� �����ڴ� �Ű����� ������ �����Ƿ� �̹� ���ǵ� �Լ��� �������̵��Ѵ�.

����� �������� ��ü���� ���ϴ� ������ �̹� ���ǵ� ���ϱ� ���꿡��
�ǿ����ڸ� �����ϴ� ���̴�.
��, int + int, string + stringó�� ���ǵ� ���ϱ� ���꿡�� int,string ��ſ� ��ü�� ����ϴ� ���̴�.
�̰��� �ٷ� ������ �����ε��̴�.

	��ȯ_���� operator������_��ȣ(�Ű�����)

�� ����Ѵ�.
*/

class character {
public:
	character() : hp(100), level(1) {};
protected:
	int hp;
	int level;
};

class player : public character {
public:
	player() {};
	int get_hp() { return hp; }
};

class monster {
public:
	monster() {};
};

class monster_c : public monster, public character {
public:
	void attack_special(player target_player);
	monster_c operator+(monster_c& operand);
	monster_c operator+(player& operand);
	void set_level(int level_value) { level = level_value; }
	void set_hp(int hp_value) { hp = hp_value; }
	int get_level() { return level; }
	int get_hp() { return hp; }
};

monster_c monster_c::operator+(monster_c& operand) {
	monster_c result_monster;
	result_monster.set_level(level + operand.get_level());
	return result_monster;
}

monster_c monster_c::operator+(player& operand) {
	monster_c result_monster;
	result_monster.set_hp(hp + operand.get_hp());
	return result_monster;
}

int main()
{
	monster_c monster_c_obj1, monster_c_obj2;
	monster_c_obj2.set_level(2);
	monster_c new_monster_c_obj = monster_c_obj1 + monster_c_obj2;
	cout << "��ü �� ���� C #1 Level[" << monster_c_obj1.get_level()
		<< "], ���� C #2 Level[" << monster_c_obj2.get_level()
		<< "]" << endl;

	cout << "��ü �� ���� C Level[" << new_monster_c_obj.get_level()
		<< "]" << endl;

	monster_c monster_c_obj3, monster_c_obj4;
	monster_c_obj4.set_level(2);
	player player1;

	new_monster_c_obj = monster_c_obj1 + monster_c_obj2;

	cout << "Player ��ü �� ���� C HP[" << new_monster_c_obj.get_hp() << "]" << endl;

	new_monster_c_obj = new_monster_c_obj + player1;
	
	cout << "Player ��ü �� ���� C HP[" << new_monster_c_obj.get_hp() << "]" << endl;
	return 0;
}