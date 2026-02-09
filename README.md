# Modern C++ Study

C++ 현대적 프로그래밍 스터디 저장소입니다.

## 스터디 구조

### 🤖 "넌 머야?" (Who am I?)
이 시스템은 **Modern C++ Study**로, GitHub Copilot과 함께하는 적응형 C++ 학습 플랫폼입니다.
- 학습자의 실력을 자동으로 평가하고 맞춤형 연습 문제 제공
- 실시간 피드백과 코드 리뷰
- 8가지 핵심 주제에 대한 체계적인 학습 경로

`who_am_i.py` 스크립트를 실행하여 자신의 학습 진행 상황과 프로필을 확인할 수 있습니다.

### 📁 `.github/chatmodes/`
- VS Code GitHub Copilot 대화형 학습 모드
- `studycpp.chatmode.md` - C++ 학습 전용 모드

### 📁 `.studycpp/`
- 학습자 프로필 및 진행상황 추적
- 자동 난이도 조정 시스템

### 📁 `study/`
- 과제 및 연습 문제
- 기초 진단부터 고급 주제까지

## 주요 학습 주제

1. **RAII** - 자원 관리와 예외 안전성
2. **Ranges** - C++20 범위 기반 알고리즘
3. **Templates** - 메타프로그래밍과 컨셉
4. **Concurrency** - 멀티스레딩과 동기화
5. **Coroutines** - C++20 코루틴
6. **Error Handling** - 예외와 에러 코드
7. **Performance** - 최적화 기법
8. **Architecture** - 설계 패턴과 아키텍처

## 시작하기

### 내 프로필 확인하기 ("넌 머야?")

```bash
# 학습자 프로필 및 진행 상황 확인
python3 who_am_i.py

# 사용자 ID 업데이트
python3 who_am_i.py update
```

### 연습 문제 실행하기

```bash
# 자기소개 프로그램 (객체 지향 기초)
g++ -std=c++20 -Wall -Wextra -Werror study/identity_exercise.cpp -o identity_test
./identity_test

# RAII 과제 (완료)
g++ -std=c++20 -Wall -Wextra -Werror study/baseline_raii_exercise.cpp -o raii_test
./raii_test

# Ranges 과제 (진행 중)
g++ -std=c++20 -Wall -Wextra -Werror study/ranges_transform_exercise.cpp -o ranges_test
./ranges_test
```

## 진행 상황

- ✅ 기초 환경 설정
- ✅ RAII 기초 진단 과제 완료 (91/100점)
- 🔄 Ranges 과제 진행 중
- ⏳ Templates 과제 대기 중

## 학습 성과

### Level 0 - 기초 과정
- **RAII Mastery**: 40/100 (완료된 상태)
  - 자원 관리 패턴 이해
  - 이동 의미론 구현
  - 예외 안전성 보장

---

**C++ Developer Study Path by GitHub Copilot**
