/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabukirento <yabukirento@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 18:34:51 by yabukirento       #+#    #+#             */
/*   Updated: 2025/06/11 14:32:43 by yabukirento      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <stdexcept>
#include <cstddef>

class OutOfBoundsException : public std::exception {
public:
    const char* what() const throw() {
        return "Array: Index out of bounds";
    }
};

template <typename T>
class Array {
private:
    T* _data;
    std::size_t _size;

public:
    Array() : _data(NULL), _size(0) {}

    Array(unsigned int n) : _data(new T[n]()), _size(n) {}

    Array(const Array& other) : _data(NULL), _size(0) {
        *this = other;
    }

    ~Array() {
        delete[] _data;
    }

    Array& operator=(const Array& other) {
        if (this != &other) {
            Array tmp(other);
            std::swap(_data, tmp._data);
            std::swap(_size, tmp._size);
        }
        return *this;
    }

    T& operator[](std::size_t index) {
        if (index >= _size)
            throw OutOfBoundsException();
        return _data[index];
    }

    const T& operator[](std::size_t index) const {
        if (index >= _size)
            throw OutOfBoundsException();
        return _data[index];
    }

    std::size_t size() const {
        return _size;
    }
};

#endif
