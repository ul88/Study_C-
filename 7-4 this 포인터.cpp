#include<iostream>
using namespace std;
/*
this : ��ü ���ο��� ��ü �ڽ��� ����Ű�� Ű����
*/

class bank {
private:
	int safe;
	string bank_name;
public:
	bank(string name) : bank_name(name) { safe = 0; }
	~bank() {}
	int get_safe() { return safe; };
	void use_counter(int _in, int _out);
	void transfer_account(int safe);
	void reset_account();
};

void bank::use_counter(int _in, int _out) {
	safe += _in;
	safe -= _out;
	cout << bank_name << " ó�� - �Ա�: " << _in << ", ���: " << _out << endl;
}

/* �� �Լ��� �������� �ϸ� �Ʒ��� ���� �ڵ�� �ٲ��.
void bank::use_counter(bank *const this, int _in, int _out){
	this->safe += _in;
	this->safe -= _out;
}
*/

void bank::transfer_account(int safe) {
	this->safe = safe;
	cout << bank_name << "�� ���� �̵�: " << safe << endl;
}

void bank::reset_account() {
	safe = 0;
	cout << bank_name << " ���°� �ʱ�ȭ �Ǿ����ϴ�.";
}

int main()
{
	bank rich_bank("������ ����"), global_bank("������ ����");
	rich_bank.use_counter(50, 10);
	global_bank.transfer_account(rich_bank.get_safe());
	rich_bank.reset_account();
	return 0;
}