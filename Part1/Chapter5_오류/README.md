# 오류

4장에서 오류라는 말을 반복적으로 언급했다. 실습문제와 연습문제를 풀면서 왜 그렇게 했는지 힌트를 얻었을 수도 있다.  
프로그램을 개발하면서 오류를 완벽히 피할 수는 없지만, 완성된 프로그램은 오류가 전혀 없거나,  
적어도 받아들일 수 없다고 치부되는 오유를 포함해서는 안된다. 오류를 분류하는 다양한 방법은 다음과 같다.  

### 컴파일 시간 오류

컴파일러가 찾아낸 오류, 컴파일 시간 오류는 해당 오류가 위반한 언어의 규칙에 따라 다음과 같이 더 세부적으로 나눌 수 있다. 
* 문법 오류
* 타입 오류

### 링크 시간 오류

목적 파일을 실행 프로그램에 통합하는 과정에서 링커가 찾아낸 오류

### 실행 시간 오류

프로그램을 실행하는 동안 확인된 오류. 실행 시간 오류는 다음곽 같이 더 세부적으로 나눌 수 있다.  

* 컴퓨터(하드웨어나 운영체제)가 감지한 오류
* 라이브러리(예, 표준 라이브러리)가 감지한 오류
* 사용자 코드가 감지한 오류

### 논리 오류

프로그래머가 잘못된 결과의 원인을 분석하는 과정에서 찾아낸 오류

## 프로그래머와 오류

프로그래머라는 직업이 모든 오류를 제거하는 일이라고 말하고 싶은 생각이 들 정도다.  
이상적으로는 맞는 말이지만, 그렇지 않는 경우가 더러 있다.  
사실 실세계의 프로그램에선 '모든 오류'가 무슨 의미인지 정확히 알기조차 어려울 때도 있다.  
프로그램을 실행하는 동안 컴퓨터의 전원 코드를 뽑았다면 이 역시 처리해야 할 오류일까?  
대부분의 경우에 "당연히 아니요"라고 대답하겠지만 의료 감시 프로그램이나 전화 교환기 프로그램이라면 어떨까?  
이런 경우라면 사용자는 컴퓨터의 전원 공급이 멈추거나 프로그램이 저장된 메모리를 우주선(cosmic ray)이 손상시켜도  
여러분의 프로그램이 포함된 시스템의 어딘가에서 적절한 조치를 취해주리라고 기대할만 하다.  
결국 핵심적인 질문은 "이 프로그램이 그런 오류를 감지해야 하는가?"라고 할 수 있다.  
특별히 따로 언급하지 않는 한 여러분의 프로그램에 대래 다음과 같이 가정한다.  

1. 모든 적법한 입력에 대해 요구받은 결과를 생성한다.

2. 모든 적법하지 않은 입력에 대해 적절한 오류 메시지를 출력한다.

3. 하드웨어의 오동작은 고려하지 않는다.

4. 시스템 소프트웨어의 오동작은 고려하지 않는다.

5. 오류를 감지한 후에는 종료해도 좋다.  

3과 4, 5번 가정을 만족하지 않는 모든 프로그램은 이 책의 범위를 벗어난 진보된 프로그램이라 할 수 있다.  
하지만 1번과 2번 가정은 기본적인 전문가 정신에 포함되며, 이러한 전문가 정신은 우리의 목표 중 하나이기도 하다.  
항상 이상을 100%만족할 수는 없다고 해도 우리는 그 이상을 추구해야 한다.  
이를 위해 우리는 기본적으로 적절한 수준의 소프트웨어를 만들기 위해 다음과 같은 세 가지 접근 방법을 취할 수 있다.  

* 소프트웨어를 조직화해서 오류를 최소화한다.  

* 우리가 만든 대부분의 오류를 테스트와 디버깅으로 제거한다.  

* 남아있는 오류는 사소한 오류임을 확인한다.  

이 세 가지 방법 중 하나만으로는 오류를 완벽히 제거할 수 없으므로, 세 가지 방법을 모두 병행해야 한다.  

## 오류의 원인

오류의 원인 중 몇 가지를 살펴보자.  

### 엉터리 명세

프로그램이 해야 할 일을 정확히 명시하지 않으면 사각 지대를 제대로 확인하고, 모든 경우를 처리했는지  
(예를 들어, 모든 입력에 대해 정확한 답변이나 적정한 오류 메시지를 출력하는지) 알기 어렵다.  

### 불완전한 프로그램

개발 과정에서 고려하지 않은 경우가 있을 수 있다.  
이를 피할 수는 없지만, 모든 경우를 처리했음을 확인하는 일을 목표로 삼아야 한다.  

### 예상 밖의 인자

함수는 인자를 받아들이며, 우리가 처리하지 않은 인자가 함수에 전달되면 문제가 생긴다.  
예를 들어 sqrt(-1.2)처럼 표준 라이브러리의 제곱근 함수에 -1.2를 인자로 전달하면 어떻게 될까?  
double을 인자로 받는 sqrt()는 double을 반환하므로, 올바른 결과를 반환할 수 없다.  

### 예상 밖의 입력

일반적으로 프로그램은 데이터를 읽는다.(키보드나 파일, GUI, 네트워크 연결 등으로부터)  
프로그램은 이러한 입력에 대해 많은 가정을 한다. 예를 들어 사용자는 숫자를 입력한다는 가정을 한다.  
하지만 사용자가 예상대로 정수를 입력하지 않고 "닥쳐"라고 입력하면 어떻게 될까?  

### 예상 밖의 상태

대부분의 프로그램은 시스템의 서로 다른 부분에서 사용할 데이터(상태)를 유지한다. 주소 목록과 전화번호부,  
온도 측정 결과를 저장하는 vector등을 예로 들 수 있다. 그런 데이터가 불완전하거나 틀렸다면 어떨까?  
프로그램의 여러 부분에서 여전히 그 데이터가 필요한데?  

### 논리 오류

코드가 의도한대로 동작하지 않는 경우를 말한다. 이런 문제는 찾아서 고치는 수밖에 없다.  


이 목록은 실용적으로 쓸모가 있다. 프로그램을 어느 정도로 확인해야 하는지 알려주는 체크리스트(Checklist)로 사용할 수 있다.  
앞에서 언급한 잠재적 오류의 원인을 모두 고려하지 않고는 어떤 프로그램도 완벽할 수 없다.  
이러한 고려 없이 여럿이 함께 작성한 프로그램은 오류 발생 확률이 크고  
전면적인 수정 없이 오류를 제거하기도 어렵기 때문에 프로젝트 맨 처음부터 이런 사항을 고려하는 편이 신중한 자세라 할 수 있다.  

## 컴파일 시간 오류

### 문법 오류

### 타입 오류

### 오류가 아닌 경우

컴파일러와 작업하다 보면 여러분의 의도를 알아챌 정도로 컴파일러가 똑똑하길 바라는 경우가 있다.  
즉, 컴파일러가 보고하는 오류 중 일부를 오류가 아니라고 생각했을 수도 있다.  
이는 자연스러운 일이다. 하지만 더 놀라운 일은, 여러분이 경험을 쌓아갈 수록 컴파일러가 오류를 적게 보고하기보다는  
더 많은 코드를 거부해주길 내심 바라게 된다는 점이다.  


여러분이 경험을 쌓아가면서 컴파일러의 능력을 최대한 활용해서 오류를 찾아내고,  
컴파일러의 알려진 약점을 피해가는 방법을 배우게 된다. 그러나 과신하지는 말자.  
"내 프로그램이 컴파일 됐다."고 해서 프로그램이 실행되는 것을 의미하지는 않는다.  
프로그램이 실행된다고해도 처음에 논리적 결함을 찾아내기 전에는 잘못된 결과가 나오기 마련이다.  

## 링크 시간 오류



## 실행 시간 오류

프로그램에 컴파일 시간 오류와 링크 시간 오류가 없다면 프로그램을 실행할 수 있다.  
정말 재밌는 일은 이제부터 시작이다. 프로그램을 작성할 떄 오류를 찾을 수는 있지만,
실행중에 감지한 오류를 처리하는 방법을 알아내기를 항상 쉽지는 않다.  

```{.cpp}
int area(int length, int width) // 사각형 넓이 계산
{
	return length * width;
}

int framed_area(int x, int y) // 테두리를 제외한 사각형 넓이 계산
{
	return area(x-2, y-2);
}

int main(void)
{
	int x = -1;
	int y = 2;
	int z = 4;

	// ...

	int area1 = area(x, y);
	int area2 = framed_area(1, z);
	int area3 = framed_area(y, z);
	double ratio = double(area1)/area3; // 부동소수점 나눗셈을 수행하기 위해 double로 변환
	// 참고로 C++의 형변환은 C에 비해서 더 엄격한 편이다.
}

/*
	이 코드의 에러에 대해서 알겠는가? 어떤 오류가 있는가?
	참고로 컴파일 시간 에러와 링크 시간 에러는 없는 코드다.
 */
```

(인자에 직접 값을 넣는 대신)변수 x, y, z를 사용해서 사람이 이해하기 힘들고, 컴파일러가 오류를 찾기 어렵게 만들었다.  
결국 area1과 area2에는 계산된 사각형 넓이가 음수가 대입된다. 이렇게 수학과 물리학을 뿌리 채 거부하는 오류를 용인해야 할까?  
그렇지 않다면 이 오류는 누가 찾아내야 하는가? area를 호출한 쪽(Caller)에서? 아니면 함수 스스로?  
그리고 오류를 찾아낸 후에는 어떻게 보고해야 할까?  

사실 이 코드는 마지막 나누는 코드에서 0으로 나눗셈을 시도하기 때문에 하드웨어 감지 오류가 발생한다.  
이제 area()의 인자에 관련된 오류를 고쳐보자. 여기엔 두 가지 대안이 있다.  

1. area()를 호출하는 쪽에서 잘못된 인자를 처리한다.  
2. area()(호출된 함수) 안에서 잘못된 인자를 처리한다.  

### 호출하는 쪽(Caller)에서의 오류 처리

### 호출하는 쪽(Callee)에서의 오류 처리
