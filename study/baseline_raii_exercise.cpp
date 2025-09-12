// TAGS: LEVEL=0; TOPICS=RAII,BASELINE; FOCUS=OWNERSHIP
// EST_TIME: 15m
// GOAL: RAII와 이동 의미론을 사용한 안전한 자원 관리 구현

#include <iostream>
#include <memory>
#include <string>

// 문제: 파일 핸들(FILE*)을 안전하게 관리하는 RAII 클래스를 구현하시오.
// 요구사항:
// - 파일이 자동으로 열리고 블록 종료 시 자동으로 닫혀야 함
// - 복사 생성과 복사 대입은 금지 (= delete)
// - 이동 생성과 이동 대입은 허용하되 소유권이 명확히 이전되어야 함
// - get() 메서드로 내부 FILE* 포인터 접근 가능
// - 예외가 발생해도 파일이 누수되지 않아야 함

// TODO: file_wrapper 클래스 구현 - RAII 패턴과 이동 의미론 적용
class file_wrapper {
    // YOUR CODE HERE - START (TODO: 파일 핸들 안전 관리)
    
    // YOUR CODE HERE - END

public:
    // TODO: 생성자 구현 - 파일명과 모드를 받아 파일 열기
    
    // TODO: 소멸자 구현 - 자동 파일 닫기
    
    // TODO: 복사 생성자와 복사 대입 연산자 금지
    
    // TODO: 이동 생성자와 이동 대입 연산자 구현
    
    // TODO: get() 메서드 구현 - FILE* 반환
};

int main() {
    // 테스트 1: 기본 파일 열기와 자동 닫기
    {
        file_wrapper file("test.txt", "w");
        if (file.get()) {
            fprintf(file.get(), "안녕하세요, RAII!");
        }
        // 기대: 여기서 블록 종료 시 파일이 자동으로 닫힘
    }
    
    // 테스트 2: 이동 의미론 테스트
    {
        file_wrapper file1("test.txt", "r");
        file_wrapper file2 = std::move(file1);
        
        // 기대: file1.get() == nullptr, file2.get() != nullptr
        std::cout << "이동 후 file1 상태: " << (file1.get() ? "유효" : "무효") << std::endl;
        std::cout << "이동 후 file2 상태: " << (file2.get() ? "유효" : "무효") << std::endl;
    }
    
    // TODO: 예외 안전성 테스트 추가 (파일 열기 실패 등)
    
    std::cout << "모든 테스트 완료!" << std::endl;
    return 0;
}
