/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabukirento <yabukirento@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 18:39:53 by yabukirento       #+#    #+#             */
/*   Updated: 2025/06/08 08:58:23 by yabukirento      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "../includes/Iter.hpp"

void printInt(int const& x) {
    std::cout << x << " ";
}

template <typename T>
void printTemplate(const T& val) {
    std::cout << val << " ";
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    std::string strs[] = {"Hello", "42", "Tokyo"};

    std::cout << "Integers: ";
    iter(arr, 5, printInt);
    std::cout << std::endl;

    std::cout << "Strings: ";
    iter(strs, 3, printTemplate<std::string>);
    std::cout << std::endl;

    return 0;
}
