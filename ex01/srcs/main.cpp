/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryabuki <ryabuki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 18:39:53 by yabukirento       #+#    #+#             */
/*   Updated: 2025/06/11 14:18:25 by ryabuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "../includes/Iter.hpp"

// const reference を受け取る関数
void printInt(int const& x) {
    std::cout << x << " ";
}

// non-const reference を受け取る関数（値を変更）
void incrementInt(int& x) {
    x++;
}

// const reference を受け取るテンプレート関数
template <typename T>
void printTemplate(const T& val) {
    std::cout << val << " ";
}

// non-const reference を受け取るテンプレート関数
template <typename T>
void doubleValue(T& val) {
    val = val + val;
}

void printArray(int* arr, std::size_t size) {
    for (std::size_t i = 0; i < size; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

int main() {
    std::cout << "=== Testing iter function ===" << std::endl;

    // Test 1: non-const array with const reference function
    std::cout << "Test 1: non-const array + const reference function" << std::endl;
    int arr1[] = {1, 2, 3, 4, 5};
    std::cout << "Original: ";
    printArray(arr1, 5);
    std::cout << "Print via iter: ";
    iter(arr1, 5, printInt);
    std::cout << std::endl;

    // Test 2: non-const array with non-const reference function
    std::cout << "\nTest 2: non-const array + non-const reference function" << std::endl;
    int arr2[] = {1, 2, 3, 4, 5};
    std::cout << "Before increment: ";
    printArray(arr2, 5);
    iter(arr2, 5, incrementInt);
    std::cout << "After increment: ";
    printArray(arr2, 5);

    // Test 3: const array with const reference function
    std::cout << "\nTest 3: const array + const reference function" << std::endl;
    const int arr3[] = {10, 20, 30, 40, 50};
    std::cout << "Const array via iter: ";
    iter(arr3, 5, printInt);
    std::cout << std::endl;

    // Test 4: Template functions with different types
    std::cout << "\nTest 4: Template functions with different types" << std::endl;
    std::string strs[] = {"Hello", "42", "Tokyo"};
    std::cout << "Strings (const template): ";
    iter(strs, 3, printTemplate<std::string>);
    std::cout << std::endl;

    std::cout << "String doubling: ";
    iter(strs, 3, doubleValue<std::string>);
    iter(strs, 3, printTemplate<std::string>);
    std::cout << std::endl;

    // Test 5: Different types
    std::cout << "\nTest 5: Different types" << std::endl;
    double doubles[] = {1.1, 2.2, 3.3};
    std::cout << "Doubles: ";
    iter(doubles, 3, printTemplate<double>);
    std::cout << std::endl;

    char chars[] = {'a', 'b', 'c'};
    std::cout << "Chars: ";
    iter(chars, 3, printTemplate<char>);
    std::cout << std::endl;

    return 0;
}
