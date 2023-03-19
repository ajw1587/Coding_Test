#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

using namespace std;

// 주민등록번호가 주어지면 나이, 성별을 판단하여 출력하시오.
// 123456-1234567 -> 14개
int No05()
{
	char personal[20];
	char sex;
	int year, age;
	
	scanf("%s", &personal);

	if (personal[7] == '1' || personal[7] == '2') year = 1900 + ((personal[0] - 48) * 10 + (personal[1] - 48));
	else year = 2000 + ((personal[0] - 48) * 10 + (personal[1] - 48));
	age = 2023 - year;

	if (personal[7] == '1' || personal[7] == '3') sex = 'M';
	else sex = 'W';

	return 0;
}

//int main()
//{
//	No05();
//
//	return 05;
//}