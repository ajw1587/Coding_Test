#include <iostream>
#include <chrono>
#include <vector>

using namespace std;
using namespace chrono;

// k�������� �Ҽ� ���� ���ϱ�
// https://school.programmers.co.kr/learn/courses/30/lessons/92335
int No()
{
    system_clock::time_point start = system_clock::now();

    int n = 437674;
    int k = 3;

    // k ������ �ٲ��ֱ�


    // 0�� �������� �� �����ֱ�

    system_clock::time_point end = system_clock::now();
    microseconds micro = duration_cast<microseconds>(end - start);
    cout << "�ҿ� �ð� : " << micro.count() << endl;
    return 0;
}

int main()
{
    No();

    return 0;
}