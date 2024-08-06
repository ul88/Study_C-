#include<iostream>
#include<string>
using namespace std;
int main()
{
	string str1("Hello"); // ������ ȣ��� �ʱ�ȭ
	string str2 = "Hello"; // ���� �������� �ʱ�ȭ
	
	cout << endl << "length, size" << endl;

	cout << str1.length() << endl; // ���ڿ��� ���� ��ȯ
	cout << str1.size() << endl; // ��ü�� �޸� ũ�� ��ȯ
	// ���� ���ڿ��� ���̰� �ʿ��� �� length�� ����ؾ���

	cout << endl << "empty" << endl;

	cout << std::boolalpha; // bool�� ����� ��, true �Ǵ� false�� �߰� ��
	cout << str1.empty() << endl;
	cout << std::noboolalpha; // bool�� ����� ��, 1 �Ǵ� 0���� �߰� ��
	cout << str1.empty() << endl;

	/*
		���ڿ�.append("�߰���_���ڿ�", ���ڿ�_����_�ε���, ����_����);
	*/
	cout << endl << "append" << endl;

	str1.append(" World!"); // ���� ���ڿ��� ���� �߰��� ����
	cout << str1 << endl;

	str2.append(" World!", 6, 1); // �߰��� ���ڿ����� 6��° �ε����� !���� 1���� �߰��� ����
	cout << str2 << endl;

	/*
		���ڿ�.find(ã��_���ڿ�);
		���ڿ�.find(ã��_����);
		���ڿ�.find(ã��_���ڿ�, ����_��ġ);
		���� ��ġ�� ����ٸ� ������ ó�� ���� ��ġ���� Ž���� �����Ѵ�.

		���ڿ��� ã�µ� �����ϸ� �ش� ���ڿ��� ���� ��ġ�� ��ȯ�Ѵ�.
		���� ã�� ���ϸ� ���� Ÿ���� string::npos�� ��ȯ�Ѵ�.

		string::npos ����
			static const size_t npos = -1;
	*/

	cout << endl << "find" << endl;

	cout << str1.find("Hello") << endl;
	cout << str1.find("World") << endl;
	cout << (str1.find("NO FIND") == string::npos ? "false" : "true") << endl;

	/*
		���_���ڿ�.compare(����_���ڿ�);

		0 : �� ���ڿ��� ����
		��� : ��� ���ڿ��� �� ��ų� ��ġ���� �ʴ� ù ��° ���ڰ� �� ŭ
		���� : ��� ���ڿ��� �� ª�ų� ��ġ���� �ʴ� ù ��° ���ڰ� �� ����
	*/

	cout << endl << "compare" << endl;

	cout << str1.compare("Hello World!") << endl;
	cout << str1.compare("Hello") << endl;
	cout << str1.compare("Hello World! not compare") << endl;
	cout << str1.compare("Hella World!") << endl;
	cout << str1.compare("Hellz World!") << endl;

	// compare���� ������ ����Ϸ��� ���� �����ڸ� ����ϸ� �ȴ�.
	cout << endl << "compare ��� ���Կ����ڷ� ��" << endl;
	cout << (str1 == "Hello World!" ? "true" : "false") << endl;
	cout << (str1 != "Hello World!" ? "true" : "false") << endl;

	/*
		replace ����
	*/

	/*
		wstring : ���̵� ���ڿ� -> �����ڵ� ���ڿ��� ó���� �� ���
	*/
	cout << endl << "wstring" << endl;

	setlocale(LC_ALL, ""); // ���α׷��� ���� ����

	wstring korString = L"�ȳ��ϼ���"; // L�� ���ڿ� ���ͷ��� ���̵� ���ڿ����� ��Ÿ��

	wcout << korString << endl; // ���̵� ��� ��Ʈ�� wcout ���

	return 0;
}