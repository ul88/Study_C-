#include<iostream>
using namespace std;
/*
	is-a ���� : ���Ͱ� �������� �⺻ �Ӽ��� ������ ��ӹ޾Ƽ� 
	���ο� ���͸� ����� �ش� ���Ϳ��� Ưȭ�� ������ �����ϴ� �Ͱ� ���� �����,
	�ڽ� Ŭ������ ������ �θ� Ŭ������ ��ü�� �� �ִ�.
	
	���� ����� ���� : 
		1. Ŭ������ Ŀ����.
			*�����ڰ� �����ؾ��� ����
			Ŭ������ Ŀ���� �׸�ŭ �Ӽ��� ����� �������Ƿ� ����� ��Ʊ� ����
			����, �θ� Ŭ���� �� �Ϻΰ� ����Ǹ� ��ӹ��� ��� Ŭ������ 
			�ٽ� �������ؾ��Ѵ�.
			����̳� ��� ����� ���� �������� �������� ���յ��� ���ٰ� ���Ѵ�.
			�ҽ� �ڵ�� ���յ��� �������� ���������� �����ϴ�.
			�̷� �Ŵ� Ŭ������ ���յ��� �������Ƿ� �����ؾ��Ѵ�.

		2. ������ �ð� ����
			Ŭ���� ������ ���ʰ���� �� �� �ȿ� �������� ��������,
			���¼ҽ�ó�� Ŭ���� ������ ���� ����� �� �ð��� �ɸ� ���� �ִ�.
			���� ��ȭ�� ������ ���ٸ�, �ݺ� �������� �ϸ� �����ص� ������ ������,
			��� ���谡 �����ϰ� ���� ����� �����ϰ� ���������� 
			�����Ͽ� ���� �ð��� �ҿ�Ǿ� ���߿� �δ��� �� �� �ִ�.

	���� ����� �����:
		������ �Ӽ��� ����� ������ Ŭ������ �и��ϰ�
		�� Ŭ������ ��� ������ �����ϴ� ������, ���� ����� ���Ѵ�.

		Ŭ������ �и��Ͽ� �����ϴ� ������δ�
		'��������'�� '��׸����̼�'�� �����Ѵ�.

		���������� �и��� Ŭ������ ����(part-of)�ϴ� �����̰�,
		��׸����̼��� ���(has-a)�ϴ� �����̴�.

	���� �ֱ� : ��ü�� �����Ǿ� �Ҹ��ϴ� ������ �ǹ�
	���� �ֱⰡ ���� : �ٸ� ��ü�� ������ �� �Բ� �����ǰų�,
	�ٸ� ��ü�� ���ؼ� �����ǰų�,
	�ٸ� ��ü�� ���ؼ� �Ҹ�Ǵ� ��츦 ���Ѵ�.

	*�� �����ֱⰡ ���� ���� �������ǰ� ��׸����̼��� �����ϴ� ù��° ������ �ȴ�.
	 
	
	��������(part-of) : Ŭ������ ��ӹ޴� ���� �ƴ϶� ��� ������ �����ϴ� ����
		�����ֱⰡ �����ϴ�.
		�ڽ� Ŭ������ �θ� Ŭ������ ������ ��ü�� �� �ִ� ������ ��������
		��Ӻ��� ���������� ����

	��׸����̼�(has-a) : �������ǰ� ���������, 
	��׸����̼��� ��ü�� �����ͳ� ���۷��� ������ �����Ѵ�.
		���� �и��� Ŭ������ �̸� �����ϴ� Ŭ������ �����ֱⰡ �ٸ���.
			* ���۷��� ������ ����Ѵٸ� �ݵ�� �����ڿ��� �ʱ�ȭ�ؾ��Ѵ�.
		�������ǰ� �޸� �и��� Ŭ������ �̸� ����ϴ� Ŭ������ ������ ���踦 ������.
		�������� ġȯ ��Ģ�� ���� �и��� Ŭ������ ���� ������ ���� �ְ�,
		�ش� Ŭ������ ��ӹ��� �ڽ� Ŭ������ ������ ���� �ִ�.


*/
class character {
public:
	character() : hp(100), power(100) {};
protected:
	int hp;
	int power;
};

class player {
public:
	player() {};
};

class monster {
public:
	monster() {};
	void get_damage(int _damage) {};
	virtual void attack(player target_player) {
		cout << " ���� : ������ - 10hp" << endl;
	}
};

class monster_2nd_gen : public monster {
public:
	virtual void attack(player target_plaer) override {
		cout << " ���ο� ���� : ������ - 30 hp" << endl;
	}
};

class monster_a { // ��������
public:
	void attack(player target_player) {
		main_role.attack(target_player);
	}
private:
	character main_body;
	monster main_role;
};

class monster_b { // ��׸����̼�
public:
	monster_b(character& ref_character, monster& ref_monster)
		: main_body(ref_character), main_role(ref_monster) {};
	void attack(player target_player) {
		main_role.attack(target_player);
	}
private:
	character& main_body;
	monster& main_role;
};

int main()
{
	player player_1;
	character character_obj;
	monster monster_obj;
	monster_2nd_gen monster_new_obj;

	monster_a forest_monster;

	monster_b tutorial_monster(character_obj, monster_obj);
	monster_b urban_monster(character_obj, monster_new_obj);

	cout << "���� A ����" << endl;
	forest_monster.attack(player_1);

	cout << endl << "���� B ����" << endl;
	tutorial_monster.attack(player_1);
	urban_monster.attack(player_1);

	return 0;
}