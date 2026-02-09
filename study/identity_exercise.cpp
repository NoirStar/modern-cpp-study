// TAGS: LEVEL=0; TOPICS=OOP,BASICS; FOCUS=ENCAPSULATION
// EST_TIME: 20m
// GOAL: 객체 지향 프로그래밍의 기초 - 자기소개 기능 구현

#include <iostream>
#include <string>
#include <vector>

// 문제: "넌 머야?" (Who are you?) - 자기소개가 가능한 클래스 구현
// 요구사항:
// - Person 클래스를 구현하여 이름, 역할, 기술 스택을 저장
// - introduce() 메서드로 자기소개 출력
// - add_skill() 메서드로 기술 추가 가능
// - 적절한 생성자와 getter 메서드 제공
// - const-correctness 준수 (읽기 전용 메서드는 const로 선언)

// TODO: Person 클래스 구현 - 기본적인 객체 지향 프로그래밍
// YOUR CODE HERE - START (TODO: 자기소개 기능 구현)
class Person {
private:
    std::string name_;
    std::string role_;
    std::vector<std::string> skills_;

public:
    // TODO: 생성자 구현 - 이름과 역할 초기화
    Person(const std::string& name, const std::string& role) 
        : name_(name), role_(role) {
    }
    
    // TODO: 기술 추가 메서드 구현
    void add_skill(const std::string& skill) {
        skills_.push_back(skill);
    }
    
    // TODO: 자기소개 메서드 구현 - const 메서드로 선언
    void introduce() const {
        std::cout << "안녕하세요! 저는 " << name_ << "입니다." << std::endl;
        std::cout << "역할: " << role_ << std::endl;
        
        if (!skills_.empty()) {
            std::cout << "보유 기술: ";
            for (size_t i = 0; i < skills_.size(); ++i) {
                std::cout << skills_[i];
                if (i < skills_.size() - 1) {
                    std::cout << ", ";
                }
            }
            std::cout << std::endl;
        }
    }
    
    // TODO: getter 메서드들 구현 - const 메서드로 선언
    const std::string& get_name() const {
        return name_;
    }
    
    const std::string& get_role() const {
        return role_;
    }
    
    const std::vector<std::string>& get_skills() const {
        return skills_;
    }
};

// 추가 도전: StudySystem 클래스 구현 - 학습 시스템 소개
// YOUR CODE HERE - START (TODO: 학습 시스템 소개 클래스)
class StudySystem {
private:
    std::string system_name_;
    std::string version_;
    std::string description_;

public:
    StudySystem(const std::string& name, const std::string& version, const std::string& desc)
        : system_name_(name), version_(version), description_(desc) {
    }
    
    void introduce() const {
        std::cout << "\n=== 시스템 정보 ===" << std::endl;
        std::cout << "시스템: " << system_name_ << std::endl;
        std::cout << "버전: " << version_ << std::endl;
        std::cout << "설명: " << description_ << std::endl;
    }
};
// YOUR CODE HERE - END

int main() {
    std::cout << "=== 자기소개 프로그램 ===" << std::endl;
    std::cout << std::endl;
    
    // 테스트 1: 기본 Person 객체 생성 및 소개
    {
        Person student("김철수", "C++ 학습자");
        student.add_skill("RAII");
        student.add_skill("이동 의미론");
        
        student.introduce();
        // 기대 출력:
        // 안녕하세요! 저는 김철수입니다.
        // 역할: C++ 학습자
        // 보유 기술: RAII, 이동 의미론
    }
    
    std::cout << std::endl;
    
    // 테스트 2: 여러 기술을 가진 개발자
    {
        Person developer("이영희", "시니어 C++ 개발자");
        developer.add_skill("템플릿 프로그래밍");
        developer.add_skill("멀티스레딩");
        developer.add_skill("성능 최적화");
        developer.add_skill("디자인 패턴");
        
        developer.introduce();
        // 기대: 모든 기술이 쉼표로 구분되어 출력
    }
    
    std::cout << std::endl;
    
    // 테스트 3: 기술이 없는 초보자
    {
        Person beginner("박민수", "C++ 초보자");
        beginner.introduce();
        // 기대: 기술 목록 없이 이름과 역할만 출력
    }
    
    // 테스트 4: 학습 시스템 소개
    {
        StudySystem system(
            "Modern C++ Study",
            "1.0.0",
            "C++ 현대적 프로그래밍을 위한 적응형 학습 시스템"
        );
        system.introduce();
        // 기대: 시스템 정보가 깔끔하게 출력
    }
    
    // TODO: const-correctness 테스트 추가
    // const Person 객체를 만들어 introduce()와 getter들이 작동하는지 확인
    
    std::cout << "\n모든 테스트 완료!" << std::endl;
    return 0;
}
