#include <iostream>
#include <chrono>
#include <vector>
#include <string>

using namespace std;
using namespace chrono;
typedef long long ll;

// k�������� �Ҽ� ���� ���ϱ�
// https://school.programmers.co.kr/learn/courses/30/lessons/92335

string change_num(int n, int k)
{
    string out;
    while (n)
    {
        out += to_string(n % k);
        n /= k;
    }

    reverse(out.begin(), out.end());
    return out;
}

vector<string> divide_num(string num)
{
    vector<string> out;
    string tmp = "";

    for (int i = 0; i < num.size(); i++)
    {
        if (num[i] == '0' && tmp != "")
        {
            if (tmp != "1")
            {
                out.push_back(tmp);
            }
            tmp = "";
        }
        else  // num[i] != '0'
        {
            tmp += num[i];
        }
    }

    if (!tmp.empty()) out.push_back(tmp);

    return out;
}

bool check_answer(ll num)
{
    if (num < 2) return false;

    for (int i = 2; i <= sqrt(num); i++)
    {
        if (num % i == 0) return false;
    }

    return true;
}

int No()
{
    system_clock::time_point start = system_clock::now();

    int answer = 0;
    //int n = 437674;
    //int k = 3;
    int n = 110011;
    int k = 10;

    // k ������ �ٲ��ֱ�
    string num = change_num(n, k);

    // 0�� �������� �� �����ֱ�
    vector<string> divi_num = divide_num(num);

    // �Ҽ� �Ǵ��ϱ�
    for (int i = 0; i < divi_num.size(); i++)
    {
        ll num = stol(divi_num[i]);
        if (check_answer(num)) answer++;
    }

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