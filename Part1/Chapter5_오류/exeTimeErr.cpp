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
