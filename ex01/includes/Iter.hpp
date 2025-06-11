/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryabuki <ryabuki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 18:34:51 by yabukirento       #+#    #+#             */
/*   Updated: 2025/06/11 14:16:21 by ryabuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

#include <cstddef>

template <typename T, typename F>
void iter(T* array, std::size_t length, F func) {
    for (std::size_t i = 0; i < length; ++i) {
        func(array[i]);
    }
}

template <typename T, typename F>
void iter(const T* array, std::size_t length, F func) {
    for (std::size_t i = 0; i < length; ++i) {
        func(array[i]);
    }
}

#endif
