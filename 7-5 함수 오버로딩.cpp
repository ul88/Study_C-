#include<iostream>
using namespace std;

/*
 ** �������̵� : � ��Ģ�̳� �Ƿ¿� �ռ��ų� �����Ѵ� **
��, �θ� Ŭ������ �Լ��� �������̵��Ѵٴ� ���� �θ��� ���Ǹ� �����ϰų� �׿� �ռ�
�ڽ� Ŭ������ ���ǵ� �Լ��� �켱���ϰڴٴ� ���̴�.

 ** �����ε� : ����ȭ �Ǵ� ���� ��, ���� ����ؼ� �״´ٴ� �ǹ�**
�̹� ���ǵ� �Լ��� ���� �̸��� ���������, �Ű����� ������ ������ ���鼭 ���ο� ���Ǹ�
��� �״� �ǹ̷� ������ �� �ִ�.

	�Լ��� �̸� ���� -> ���ο� �Լ�
	�̸��� �Ű����� ������ �״���ε� ��ȯ ���ĸ� �ٲ� �Լ� -> �����ε� X ���� �߻�
*/

class character {
public:
	character() : location{0, 0} {}

	void move(int x, int y) {
		location[0] = x;
		location[1] = y;
		cout << location[0] << ", " << location[1] << "�� �̵�" << endl;
	}

	void move(int x[], int y[], int spot_count) {
		for (int i = 0;i < spot_count;i++) {
			location[0] = x[i];
			location[1] = y[i];
			cout << i + 1 << "��°: " << location[0] << ", " << location[1] << "�� �̵�" << endl;
		}
	}

protected:
	int location[2];
};

int main()
{
	character character_obj;
	int x_list[3] = { 10,15,20 };
	int y_list[3] = { 10,15,20 };

	character_obj.move(10, 10);
	cout << endl;
	character_obj.move(x_list, y_list, 3);
	return 0;
	return 0;
}