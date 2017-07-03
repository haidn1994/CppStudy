#include "../../include/std_lib_facilities.h"

int main(void)
{
	cout << "표현식 입력(+, -, *, / 처리함)\n";
	cout << "표현식의 끝에 x를 입력(예, 1+2*3x): ";

	int lval = 0;
	int rval;
	cin >> lval;	// 가장 왼쪽 피연산자 입력
	if(!cin) error("첫 번째 피연산자 없음");
	
	for(char op; cin >> op; ){
		if(op != 'x') cin >> rval;
		if(!cin) error("두 번째 피연산자가 없다.");

		switch(op){
		case '+':
			lval += rval;
			break;
		case '-':
			lval -= rval;
			break;
		case '*':
			lval *= rval;
			break;
		case '/':
			lval /= rval;
			break;
		default:
			cout << "결과:" << lval << '\n';
			keep_window_open();
			return 0;
		}
	}
	error("잘못된 표현식");
}
