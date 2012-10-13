# Templete Study

스터디 과제를 올리는 곳 입니다.

## 3장 과제

스터디 때 말했던 tbb 사용하는 과제는 64bit 및 플랫폼 호환성 이슈로 아직 이른 것 같습니다.

변경된 과제는 아래와 같습니다.

<RandomStack 클래스 템플릿 작성>
[요구사항]
  1. 저장할 타입과, 아래에서 설명하는 Randomizer 타입을 인자로 하는 RandomStack 클래스 템플릿 작성
    예)

	temmplate <typenaem T, typename Randomizer> class RandomStack;

  2. RandomStack형 객체는 아래 멤버함수를 호출할 수 있어야 함 (함수이름, 리턴타입, 파라메터등은 자유)
    a. Push 또는 push_back - 스택에 항목 추가
	b. Pop 또는 pop_back - 스택에서 최근 추가된 항목 제거
	c. Top 또는 back - 스텍에서 최근 추가된 항목 리턴
	d. RandomPop 또는 random_pop - 스택에서 최근 추가된 항목이 일정 확률로 제거되거나 제거되지 않음
	             - 확률 계산을 Randomizer 타입에서 하게 할 것
				 - RandomStack 구현부 에서 Randomizer 타입 사용방법은 자유임 (함수 연산자 호출, 특정 멤버함수 호출등)

  3. Randomizer 타입
    a. double형 확률값을 리턴하는 멤버함수 또는 오버로드된 연산자를 제공할 것

  4. stl, boost 등의 모든 라이브러리 사용은 자유임
  
[추가 요구사항 - 선택 과제임]
  5. 위 사항을 모두 만족한 상태에서 Randomizer 타입에 기본 템플릿 인자를 추가할 것


## 2장 과제

2개 이상의 input 이 들어 왔을 때 input 들이 동일한지 검사하는 함수 템플릿 작성

output은 bool형으로 input 들의 값만 비교

or 자료형 비교 포함 할지에 대해서는 자유

예)

	template <typename T> bool 함수이름 (T input_1, T input_2, ...)
	template <typename T1, typename T2, ...> bool 함수이름 (T1 input_1, T2 input_2, ...)






