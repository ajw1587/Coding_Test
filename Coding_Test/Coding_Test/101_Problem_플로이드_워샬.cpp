#include <iostream>
#include <chrono>
#include <vector>

using namespace std;
using namespace chrono;

// �÷��̵� ����
int No101()
{
	system_clock::time_point start = system_clock::now();



	system_clock::time_point end = system_clock::now();
	microseconds micro = duration_cast<microseconds>(end - start);
	cout << "�ҿ� �ð� : " << micro.count() << endl;
	return 0;
}

int main()
{
	No101();

	return 0;
}