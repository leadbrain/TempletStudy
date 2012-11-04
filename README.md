# Templete Study

스터디 과제를 올리는 곳 입니다.

## 5장 과제
정렬 알고리즘 속도 비교를 수행하는 프로그램을 작성하시면 됩니다.(문제를 수정하였습니다.)

<요구사항>
1. 배열을 정렬하는 클래스 템플릿를 구현
(1) 두개의 템플릿 파라미터를 가진다. 
  템플릿 파라미터
  - 배열의 자료형
  - 배열 정렬에 쓰일 알고리즘 클래스 템플릿(Default는 quick sort)

(2) 정렬을 수행할 멤버 함수
  - 배열을 정렬 알고리즘 클래스를 통해 정렬 수행

2. 정렬 알고리즘 클래스 템플릿 구현
(1) 정렬을 수행할 멤버 함수

(2) 구현할 정렬 알고리즘 
  - insertion sort
  - bubble sort
  - quick sort

3. 3가지 정렬 알고리즘의 속도 비교 결과 출력

4. 확실하게 명시되지 않은 부분은 자유


<구현된 템플릿을 사용할 main함수 예>

	int main() {
  	  int test_array[10] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1}; // test_array 생성 방식은 자유
  
  	  ArraySorter<int, InsertionSort> insertion_sorter();
  	  insertion_sorter.SortArray(test_array, 10); // 인자 : 배열의 주소, 배열 사이즈
	
  	  ArraySorter<int, BubbleSort> bubble_sorter();
  	  bubble_sorter.SortArray(test_array, 10); // 인자 : 배열의 주소, 배열 사이즈

  	  ArraySorter<int, QuickSort> quick_sorter();
  	  quick_sorter.SortArray(test_array, 10); // 인자 : 배열의 주소, 배열 사이즈
  	  return 0;
	};


## 4장 과제

둘 중에 하나를 골라 구현해 주세요. 물론 두 가지 모두 하셔도 좋습니다~

문제 1. 두 숫자의 최소 공배수(LCM)을 반환하는 템플릿(구조체 혹은 클래스)를 구현하라.

문제 2. 팩토리얼(factorial) 템플릿(구조체 혹은 클래스)을 구현하라.

### 샘플 코드
	template <int num>
	struct Square {
	//static const int = num * num;
	Enum {
	  ret = num * num
	};
	}

### 출처
Dreamincode [link]: Exercise 2.1, 2.3 

문제를 구현하기 전에 출처에 있는 링크를 한 번씩 확인해 주세요.

특별한 제약 사항은 없으며 데이터형이 아닌 템플릿 파라미터를 활용하면 되겠습니다.


## 3장 과제 - 클래스 템플릿 작성

스터디 때 말했던 tbb 사용하는 과제는 64bit 및 플랫폼 호환성 이슈로 아래와 같이 변경합니다.

### 요구사항

1. 저장할 타입과, 아래에서 설명하는 Condition 타입, 2개를 템플릿 파라메터로 하는 ConditionStack 클래스 템플릿 작성

2. ConditionStack형 객체는 아래와 같은 기능의 멤버함수를 호출할 수 있어야 함 (함수이름, 리턴타입, 파라메터등은 자유)
    *  Push - 스택에 항목 추가
    *  Top - 스텍에서 최근 추가된 항목 리턴
    *  Pop - 스택에서 최근 추가된 항목을 일정 기준에 의해 제거, 기준은 Condition 타입에서 하게 할 것

3. ConditionStack 에서 Condition 타입 사용방법은 자유임 (함수 연산자 호출, 특정 멤버함수 호출등)

4. Condition 클래스 구현
    *  bool 값을 리턴하는 멤버함수 또는 오버로드된 연산자를 제공할 것

5. stl, boost 등의 모든 라이브러리 사용은 자유임

6. 위 요구사항 외의 모호한 부분은 자유임

### 추가 요구사항 - 선택 과제임

6. ConditionStack 클래스 템플릿의 Condition 템펠릿 파라메터에 기본 템플릿 인자를 추가할 것



## 2장 과제

2개 이상의 input 이 들어 왔을 때 input 들이 동일한지 검사하는 함수 템플릿 작성

output은 bool형으로 input 들의 값만 비교

or 자료형 비교 포함 할지에 대해서는 자유

예)

	template <typename T> bool 함수이름 (T input_1, T input_2, ...)
	template <typename T1, typename T2, ...> bool 함수이름 (T1 input_1, T2 input_2, ...)






