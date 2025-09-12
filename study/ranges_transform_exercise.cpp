// TAGS: LEVEL=0; TOPICS=RANGES,BASELINE; FOCUS=ALGORITHMS
// EST_TIME: 20m
// GOAL: C++20 범위 라이브러리를 사용한 함수형 데이터 변환

#include <iostream>
#include <vector>
#include <string>
#include <ranges>
#include <algorithm>
#include <numeric>

// 문제: 숫자 벡터를 다양한 방법으로 변환하고 필터링하는 함수들을 구현하시오.
// 요구사항:
// - C++20 ranges와 views 사용 (raw loops 금지)
// - 함수형 프로그래밍 스타일 적용
// - 파이프라인 연산으로 가독성 향상
// - 지연 평가(lazy evaluation) 활용

// TODO: 범위 알고리즘을 사용한 데이터 변환 함수들 구현
// YOUR CODE HERE - START (TODO: ranges 기반 함수형 변환)

// TODO: 짝수만 필터링하여 제곱한 후 벡터로 반환
std::vector<int> transform_even_squares(const std::vector<int>& numbers) {
    // 힌트: std::ranges::views::filter, transform, to 사용
    
}

// TODO: 문자열 벡터에서 길이가 n 이상인 것들을 대문자로 변환
std::vector<std::string> transform_long_strings_upper(const std::vector<std::string>& strings, size_t min_length) {
    // 힌트: ranges::views::filter, transform 파이프라인 사용
    
}

// TODO: 숫자 범위에서 조건에 맞는 첫 번째 값 찾기 (optional 반환)
std::optional<int> find_first_divisible_by(const std::vector<int>& numbers, int divisor) {
    // 힌트: std::ranges::find_if 사용
    
}

// TODO: 두 벡터를 조합해서 변환 (zip_view 스타일)
std::vector<std::string> combine_name_age(const std::vector<std::string>& names, const std::vector<int>& ages) {
    // 힌트: std::ranges::views::zip, transform 조합
    // 결과 형태: "이름: 나이세"
    
}

// YOUR CODE HERE - END

int main() {
    // 테스트 1: 짝수 제곱 변환
    std::vector<int> numbers = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    auto even_squares = transform_even_squares(numbers);
    
    std::cout << "짝수 제곱: ";
    for (int n : even_squares) {
        std::cout << n << " ";
    }
    std::cout << std::endl;
    // 기대: 4 16 36 64 100
    
    // 테스트 2: 긴 문자열 대문자 변환
    std::vector<std::string> strings = {"cat", "elephant", "dog", "rhinoceros", "ant"};
    auto long_upper = transform_long_strings_upper(strings, 4);
    
    std::cout << "긴 문자열 대문자: ";
    for (const auto& s : long_upper) {
        std::cout << s << " ";
    }
    std::cout << std::endl;
    // 기대: ELEPHANT RHINOCEROS
    
    // 테스트 3: 조건 검색
    auto found = find_first_divisible_by(numbers, 3);
    if (found) {
        std::cout << "3으로 나누어지는 첫 번째 수: " << *found << std::endl;
    }
    // 기대: 3
    
    // 테스트 4: 이름-나이 조합
    std::vector<std::string> names = {"김철수", "이영희", "박민수"};
    std::vector<int> ages = {25, 30, 28};
    auto combined = combine_name_age(names, ages);
    
    std::cout << "이름-나이 조합:" << std::endl;
    for (const auto& entry : combined) {
        std::cout << entry << std::endl;
    }
    // 기대: 김철수: 25세, 이영희: 30세, 박민수: 28세
    
    // TODO: 추가 엣지 케이스 테스트 (빈 벡터, 크기 불일치 등)
    
    std::cout << "모든 테스트 완료!" << std::endl;
    return 0;
}
