#include <iostream>
#include <string>
using namespace std;

int main(void)
{
	cout << "성을 입력하고 엔터를 누르세요\n";
	/* 앞쪽은 타입(type) */string first_name; // 뒤쪽은 변수(variable)
	// 실제 메모리의 장소/공간은 객체(object)
	cin >> first_name; // first_name에 문자열을 읽는다.  
	cout << "Hello! " << first_name << "!\n";

	return 0;
}
