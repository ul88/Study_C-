#include<iostream>
using namespace std;
/*
	Ŭ���� ���� ��ø�� Ŭ������ ���� �� �ִ� ��ó��
	Ŭ���� ���ø��� ��ø�� �� �ִ�.
		1. ���� Ŭ������ ��� ����ó�� ����ϴ� ���
			��� �����̹Ƿ� �ٱ��� Ŭ�������� ���� Ŭ������ ��� ������ �����ϰ�
			�ʿ��ϸ� �ʱ�ȭ�� �����Ѵ�.
		2. ���� Ŭ������ ������ ��ü�� �����ؼ� ����ϴ� ���
			���� : ���ø��� ��ø�� �����̹Ƿ� �ٱ��� Ŭ������ ���ø� �Ű������� ��� �Է��ؾ���.
*/

template<typename Type1, typename Type2>
class data_package { // �ٱ��� Ŭ����
public:
	template <typename Type3>
	class nested_class_data_package { // ���� Ŭ����
	public:
		nested_class_data_package(Type3 data) : nested_class_data(data) {}
		Type3 get_element() { return nested_class_data; }
		Type3 nested_class_data;
	};

	template<typename Type4>
	class nested_class {
	public:
		nested_class(Type4 data) : nested_class_data(data) {}
		void print_out_element() {
			cout << "��ø Ŭ���� ������: " << nested_class_data << endl;
		}
	private:
		Type4 nested_class_data;
	};

	data_package(Type1 first, Type2 second) : first(first), second(second),
		internal_data(second) {}

	void print_out_element() {
		cout << "ù ��° ���: " << first << ", �� ��° ���: " << second << endl;
		cout << "��ø Ŭ���� ���: " << internal_data.get_element() << endl;
	}

private:
	Type1 first;
	Type2 second;
	nested_class_data_package<Type2> internal_data;
};

int main()
{
	data_package<string, int> template_inst1("���ڿ�", 10);
	data_package<string, int>::nested_class<int> template_inst2(500);

	cout << "��ø Ŭ���� ù ��° ����" << endl;
	template_inst1.print_out_element();

	// �� ��° ���ʷ� ����� ����� �Ϲ����� Ŭ���� ���ø��� Ȱ���̴�.
	cout << endl << "��ø Ŭ���� �� ��° ����" << endl;
	template_inst2.print_out_element();
	return 0;
}