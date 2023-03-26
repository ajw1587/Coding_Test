#include <iostream>
#include <chrono>
#include <vector>

using namespace std;
using namespace chrono;

// �۾��� ã�� (BFS : ����Ʈ�� Ž��)
// ������ �۾����� �Ҿ���ȴ�. ������ �۾������� ��ġ�����Ⱑ �޷� �ִ�. 
// ������ ��ġ�� �۾����� ��ġ�� �������� ��ǥ ������ �־�����
// ������ ���� ��ġ���� �۾����� ��ġ���� ������ ���� ������� �̵��Ѵ�.
// ������ ��ī�� ������ Ÿ�� ���µ� �� ���� ������ 
// ������ 1, �ڷ� 1, ������ 5�� �̵��� �� �ִ�.
// �ּ� �� ���� ������ ������ �۾����� ��ġ���� �� �� �ִ��� 
// ���ϴ� ���α׷��� �ۼ��ϼ���.
//
// ex) 
// �Է� : S(������ ��ġ) = 5, E(�۾����� ��ġ) = 14
// ��� : 3
int No71()
{
	system_clock::time_point start = system_clock::now();

	int S = 5, E = 14;
	vector<int> dis(10001, 0);



	system_clock::time_point end = system_clock::now();
	microseconds micro = duration_cast<microseconds>(end - start);
	cout << "�ҿ� �ð� : " << micro.count() << endl;
	return 0;
}

int main()
{
	No71();

	return 0;
}