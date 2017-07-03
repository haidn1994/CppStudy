/*
#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
*/
#include "../../include/std_lib_facilities.h"

// inline void keep_window_open() { char ch; cin >> ch; }

int main(void)
{
	cout << "표현식 (+와 -만 처리함): ";

	int lval = 0;
	int rval;
	char op;
	int result;
	cin >> lval >> op >> rval;	// 1 + 3과 같은 형식을 읽는다.

	if(op == '+')
		result = lval + rval;
	else if(op == '-')
		result = lval - rval;

	cout << "결과: " << result << '\n';
	keep_window_open();
	return 0;
}

