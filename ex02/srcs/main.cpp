/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabukirento <yabukirento@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 18:39:53 by yabukirento       #+#    #+#             */
/*   Updated: 2025/06/11 14:35:18 by yabukirento      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "../includes/Array.hpp"

int main() {
    try {
        // テスト1: サイズ指定コンストラクタとoperator[]による要素への代入テスト
        Array<int> a(5);
        for (unsigned int i = 0; i < a.size(); ++i)
            a[i] = i * 10;

        // テスト2: size()メソッドとoperator[]による読み取りテスト
        std::cout << "Array a: ";
        for (unsigned int i = 0; i < a.size(); ++i)
            std::cout << a[i] << " ";
        std::cout << std::endl;

        // テスト3: コピーコンストラクタのディープコピー動作テスト
        Array<int> b = a;
        b[0] = 999;

        // テスト4: ディープコピーの検証（元の配列aが変更されていないことを確認）
        std::cout << "Array a after b modified: ";
        for (unsigned int i = 0; i < a.size(); ++i)
            std::cout << a[i] << " ";
        std::cout << std::endl;

        // テスト4: コピーされた配列bの内容確認
        std::cout << "Array b: ";
        for (unsigned int i = 0; i < b.size(); ++i)
            std::cout << b[i] << " ";
        std::cout << std::endl;

        // テスト5: 範囲外アクセスによる例外発生テスト
        std::cout << "Access out-of-bounds: ";
        std::cout << a[100] << std::endl;

    } catch (const std::exception& e) {
        // テスト6: 例外キャッチとエラーメッセージ表示テスト
        std::cerr << "Caught exception: " << e.what() << std::endl;
    }

    return 0;
}
