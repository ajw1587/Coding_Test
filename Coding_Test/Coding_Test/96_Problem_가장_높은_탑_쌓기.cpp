#include <iostream>
#include <chrono>
#include <vector>

using namespace std;
using namespace chrono;

// ���� ���� �� �ױ�
// �ظ��� ���簢���� ������ü �������� ����Ͽ� ž�� �װ��� �Ѵ�.
// ž�� ������ �� ���� �Ʒ����� ���� �����鼭 ����� ����.
// �Ʒ��� ������ �����ϸ鼭 ���� ���� ž�� ���� �� �ִ� ���α׷��� �ۼ��Ͻÿ�.
// 
// (����1)������ ȸ����ų �� ����.��, ������ �ظ����� ����� �� ����.
// (����2)�ظ��� ���̰� ���� ������ ������, ���� ���԰� ���� ������ ����.
// (����3)�������� ���̴� ���� ���� �ִ�.
// (����4)ž�� ���� �� �ظ��� ���� ���� ���� �ظ��� ���� ������ ���� �� ����.
// (����5)���԰� ���ſ� ������ ���԰� ������ ���� ���� ���� �� ����.

int No96()
{
	system_clock::time_point start = system_clock::now();



	system_clock::time_point end = system_clock::now();
	microseconds micro = duration_cast<microseconds>(end - start);
	cout << "�ҿ� �ð� : " << micro.count() << endl;
	return 0;
}

int main()
{
	No96();

	return 0;
}