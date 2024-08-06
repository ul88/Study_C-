#include<iostream>
using namespace std;
/*
	Ŭ���� ���ø��� ������ Ŭ������ �Լ��� ���� �� �ִ�.

	Ŭ���� ���ø��� ������� �ν��Ͻ�ȭ ������ ������ ��Ģ�� �ؼ��ؾ��ϹǷ� �����ؾ��� ���� �ִ�.
*/

template<typename U>
class caller {
public:
	caller() : object(nullptr) {}
	void set_object(U* obj_pointer) { object = obj_pointer; }
	void print_out_frined_object() {
		cout << "(friend Ŭ���� ���ø� ȣ��) ���ø� �Ű����� �� : "
			<< object->first << endl;
	}
private:
	U* object;
};

template<typename T = int>
class data_package {
public:
	data_package(T first) : first(first) {}
	friend caller<data_package>;
private:
	T first;
};

int main()
{
	caller<data_package<>> caller_int_obj;
	caller<data_package<string>> caller_string_obj;

	data_package<> template_inst1(5);
	data_package<string> template_inst2("Ŭ���� ���ø� �⺻���� �ƴ� string��");

	caller_int_obj.set_object(&template_inst1);
	caller_string_obj.set_object(&template_inst2);
	caller_int_obj.print_out_frined_object();
	caller_string_obj.print_out_frined_object();
	return 0;
}