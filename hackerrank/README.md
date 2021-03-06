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

## Day 6

사실 문자열을 다루는 것에 있어서는 오히려 C++가 자바보다 더 편한게 아닐까 하는 생각이 든다.  
사실 오늘 푼 문제는 별 건 없고, 자바의 StringBuilder와 StringBuffer의 차이점을 명확하게 알고있어야 겠다는 생각이 든다.  


한가지 더, 루프의 조건절에는 되도록이면 함수를 집어넣지 않는 쪽이 좋다.  
일단 조건 검사를 할 때마다 함수를 호출해버려서 시간 복잡도가 O(N)이 되어버린다.  
물론 vector.size()처럼 예외도 있지만, 말 그대로 예외일 뿐이다. 주의하자.

## Day 7

문제자체는 그냥 배열을 거꾸로 출력하면 끝나는 싱거운 문제였지만, 진짜로 문자열이나 배열을 뒤집으라고 요구하거나,  
저번에 codility에서 나왔던 문제처럼 cyclic_rotation같은 문제를 낸다면 어떻게 해야할 것인가?
당연히 잘 익혀놓아야 할 주제이다. 문자열 뒤집는 코드, 배열 뒤집는 코드를 공부하자.

## Day 8

이 단원은 상당히 중요하다. 먼저 map의 문법을 잘 보라! end(), find(), []또는 insert()를 쓰는 방법을 잘 익혀야 한다.  
그리고 주석에도 적어놓았듯이 문제를 잘 읽고 조건을 잘 살펴야 한다. 그리고 입력이 몇 개인지 주어지지 않았다면,  
scanf나 cin의 반환값을 이용해서 입력을 EOF까지 받는 것으로 하면 된다.

```{.cc}
#include <cmath>
#include <cstdio>
#include <cstring>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <map>
using namespace std;

char key[50];

int main() {
	int value;
	map<string, int> phonebook;
	int n, i; cin >> n;

	for(i = 0; i < n; i++){
		scanf("%s", key);
		scanf("%d", &value);
		phonebook[key] = value;
	}

	// 왜 이 코드가 말썽을 부렸느냐 하면, 출력이 초과되었기 때문이다.
	// 쿼리와 n이 같다는 조건은 없다. 단지 상한성과 하한선만 같을 뿐이다.
	// 즉, 얼마나 출력하라고 하는 쿼리의 갯수를 조절해 주는 코드를 담아줘야 한다. 
	// 이 문제는 백준 알고리즘 저지 10989문제에서도 한번 걸렸던 함정이다. 조심하도록 하자.
	while(scanf("%s", key) != EOF){
		if(phonebook.find(key) == phonebook.end())
			printf("Not found\n");
		else
			printf("%s=%d\n", key, phonebook.find(key)->second);
		//cout << key << "=" << phonebook.find(key)->second << '\n';
	}
	return 0;
}
```

## Day 9

재귀에 관한 문제인데, 그냥 factorial을 만드는 문제다. 너무 싱거운 문제이므로 그냥 넘어간다.

## Day 10

비트 다루기에 대한 문제인데, 비트 다루는 것은 많이 하지 않기 때문에 연습문제가 많이 필요하다.  
어쨌든 이문제는 codility의 첫문제는 binaryGap의 쉬운 버전이라고 생각하면 된다.

```{.c}
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


// codility의 binaryGap문제와 거의 유사한데, 전처리가 필요없어서 쉬운 문제다!

int main() {
	unsigned int size_checker = 0x80000000;
	unsigned int res_checker = 0x00000001;
	int n, range = 0, res = 0, i;
	int res_candi = 0;
	cin >> n;

	// 쉬프트 연산도 =을 넣어서 간단하게 만들어 주는 잊지 말것!
	// 그리고 int형 정수는 32번째 비트까지 있다는 것도 잊지 말것
	// 비트 다루는 법을 확실하게 익혀야 할 것 같다. 이런 문제가 적게 나온다는 보장이 없다!
	for(i = 0; i < 32; i++, res_checker <<= 1){
		if(res_checker & n){
			res++;
		} else{
			if(res_candi <= res)
				res_candi = res;
			res = 0;
		}
	}

	cout << res_candi;
	return 0;
}

```

## Day 12

C++의 상속에 관한 문제인데, 역시 C++문법은 좀 어렵다는 생각이 든다.

```{.cc}
class Student :  public Person{
	private:
		vector<int> testScores;  
	public:
		Student(string firstName, string lastName, int indentification, vector<int> &scores) 
			: Person(firstName, lastName, indentification){
			this->testScores = scores;
		}
		char calculate(){
			int sum = 0, mean;
			int range, i;

			range = this->testScores.size();
			for(i = 0; i < range; i++)
				sum += testScores[i];
			mean = sum/range;

			return mean >= 90 ? 'O' :
				(80 <= mean && mean < 90) ? 'E' :
				(70 <= mean && mean < 80) ? 'A' :
				(55 <= mean && mean < 70) ? 'P' :
				(40 <= mean && mean < 55) ? 'D' : 'T';
		}
		/*	
		 *   Class Constructor
		 *   
		 *   Parameters:
		 *   firstName - A string denoting the Person's first name.
		 *   lastName - A string denoting the Person's last name.
		 *   id - An integer denoting the Person's ID number.
		 *   scores - An array of integers denoting the Person's test scores.
		 */
		// Write your constructor here

		/*	
		 *   Function Name: calculate
		 *   Return: A character denoting the grade.
		 */
		// Write your function here
};
```
