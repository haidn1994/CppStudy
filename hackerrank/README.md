# 해커랭크 30일 코스

## Day 0

C++의 getline()은 주의해야 할 사항이 있는데, 그건 웹페이지에 잘 정리되어 있다.  

> 

간단히 말하자면 입출력 함수에서 개행문자나 공백문자등을 어떻게 다루는 지 정확하게 알고 있어야 한다.

## Day 1

삼항 연산자는 안쪽에 식(Expression)이 반드시 와야 한다.  
문(Statement)이 오게되면 제대로 된 평가를 할 수 없게 된다.  


예를 들어 Continue나 break같은 키워드는 Statement로 평가되는데, 삼항 연산자 내부에 들어갈 수 없어서 컴파일 에러를 일으킨다.  

## Day 2

1. 피연산자를 빼먹고 변수 옆에 ()를 쓰면 컴파일러는 함수를 호출하는 것이라고 생각한다.
	* 피연산자를 빼먹지 말자!
2. 최소한 double과 int, int와 long, unsigned와 signed의 캐스팅 규칙은 기억하고 있는 것이 좋다.
3. round(), ceil(), trunc()와 캐스팅 연산은 인자로 받은 변수의 상태를 바꾸는 것이 **아니다.**
	* 상태를 바꾸는 것이 아니라 데이터를 복사한 다음 연산해서 반환값으로 넘길 뿐이다.
	* 정 바꾸고 싶다면 '=' 연산을 써야 한다.

## Day 3

별거 없기는 하지만 아래 사항을 기억하면 좋다.  

1. 비트연산자를 이용한 짝수 판별법 (N%2 == 0 vs N&1): 많이는 아니겠지만 약간 빨라지는 것은 기대할 수 있다.
2. 괄호를 활용한 ||와 &&의 조합

## Day 4

1. this는 현재 클래스의 이름공간에 접근하는 **포인터**다.  
	* 따라서 this에 접근하고 싶다면 "::"나 "."이 아닌 "->"을 써야 한다.

2. 클래스나 네임스페이스에 접근하고 싶다면 ::을 사용하는데 맞는 것 같은데, 정확히 어떤 연산자인지 공부 할 것!
	* 메서드 선언시에도 ::연산자는 사용된다. ::연산자를 사용해서 선언하면 virtual인가? 공부해서 확실하게 알자.

3. static 연산자를 함수 내부에서 사용하면 해당 메모리가 그 함수를 위해서 예약되고, 런타임이 종료되기 전까지 유지된다.  
	* 잘쓰면 좋다. 하지만 파악하기 어려운 구조를 만들고 메모리를 낭비할 수 있기 때문에 남발하지 말고 주석을 제대로 달 것

## Day 5

루프도 별 거 없다. 하지만 2개는 공부하자.

1. C++에서 여러가지 Iterator가 존재하는데(FowardIterator등등), 이 정체에 대해서 공부하자.
2. 향상된 for문에 대해서 공부해보자.
