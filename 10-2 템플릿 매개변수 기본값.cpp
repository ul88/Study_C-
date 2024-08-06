#include<iostream>
using namespace std;
/*
	C++�� �Լ��� �⺻������ �����ϵ��� ���� �� �ִ�.
	��, �Ű������� �⺻���� ������ ������ �Լ��� ȣ���� �� ���� �������� �ʾƵ� �ȴ�.

	���ø� �Ű������� �⺻���� �����ؼ� ����� �� �ִ�.
	�ٸ�, ���ø� �Ű������� ������ ������ ��Ÿ���Ƿ�, �⺻ ������ ������ �ǹ��Ѵ�.
*/

template<typename T = int>
class data_package {
public:
	data_package(T first) : first(first){}
	void print_out_element() {
		cout << "���ø� �Ű����� �� : " << first << endl;
	}
private:
	T first;
};

int main()
{
	data_package<> template_inst1(5);
	data_package<string> template_inst2("Ŭ���� ���ø� �⺻���� �ƴ� string��");

	template_inst1.print_out_element();
	template_inst2.print_out_element();
	return 0;
}