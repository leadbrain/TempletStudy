# Templete Study

스터디 과제를 올리는 곳 입니다.



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






