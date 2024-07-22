#include "Array.hpp"
#include <iostream>
#include <vector>

int main() {
    try {
        
        Array<int> arr1;  // 빈 배열 생성
        Array<int> arr2(5);  // 크기가 5인 배열 생성

        // 배열 요소에 값 할당
        for (unsigned int i = 0; i < arr2.size(); ++i) {
            arr2[i] = i * 10;
        }

        // 복사 생성자 테스트
        Array<int> arr3 = arr2;
        arr3[0] = 100;

        std::cout << "arr2: ";
        for (unsigned int i = 0; i < arr2.size(); ++i) {
            std::cout << arr2[i] << " ";
        }
        std::cout << std::endl;

        std::cout << "arr3: ";
        for (unsigned int i = 0; i < arr3.size(); ++i) {
            std::cout << arr3[i] << " ";
        }
        std::cout << std::endl;

        // 대입 연산자 테스트
        Array<int> arr4;
        arr4 = arr2;
        arr4[1] = 200;

        std::cout << "arr2: ";
        for (unsigned int i = 0; i < arr2.size(); ++i) {
            std::cout << arr2[i] << " ";
        }
        std::cout << std::endl;

        std::cout << "arr4: ";
        for (unsigned int i = 0; i < arr4.size(); ++i) {
            std::cout << arr4[i] << " ";
        }
        std::cout << std::endl;

        // 예외 처리 테스트
        std::cout << arr2[10] << std::endl;  // 인덱스 초과 예외 발생
    }
    catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}