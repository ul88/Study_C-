#include<iostream>
using namespace std;
/*
	���� Ŭ���� ���ø��� ���� �����ϱ⺸�ٴ� ���̺귯������ 
	�̹� ����� ũ���� ���ø��� �̿��� ���� �� ����.

	���ø� ����� Ŭ���� ����
		template <typename Type1, typename Type2>
		class data_package {
		public:
			data_package(Type1 first, Type2 second) : first(first), second(second) {}
		private:
			Type1 first;
			Type2 second;
		};

	�⺻������ Ŭ���� ���ø������� ������ ������ ��������� ���������������
	C++17 ���� �����Ϸ������� Ŭ���� ���ø������� ���� �߷��� ����� �� �ִ�.
*/

template <typename Type1, typename Type2>
class data_package {
public:
	data_package(Type1 first, Type2 second) : first(first), second(second) {}
	void print_out_element() {
		cout << "ù ��° ���: " << first << ", �� ��° ���: " << second << endl;
	}
private:
	Type1 first;
	Type2 second;
};

int main()
{
	/*data_package<int, double> template_inst1(5, 10.5);
	data_package<string, int> template_inst2("���ڿ�", 10);*/

	data_package template_inst1(5, 10.5);
	data_package template_inst2("���ڿ�", 10);

	template_inst1.print_out_element();
	template_inst2.print_out_element();
	return 0;
}