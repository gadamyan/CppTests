//
//  CppTests
//
//  Created by Gevorg Adamyan
//

#pragma once

#include <concepts>

namespace cpptests::core::cpp20 {

    template<typename T>
    concept Integral = std::is_integral_v<T>;

    template<typename T>
    concept Floating = std::is_floating_point_v<T>;

    template<typename T>
    concept IntegralOrFloating = Integral<T> || Floating<T>;

    template<typename T>
    concept IntegralAndChar = std::is_integral_v<T> && std::is_same_v<T, char>;

    template<typename T>
    concept SameAsChar = std::is_same_v<T, char>;

    template<typename T>
    concept CustomConcept = requires (T x) {
        x++;
        {*x};
        typename T::value_type;
        requires SameAsChar<typename T::value_type>;
    };

    template <CustomConcept T>
    void f1(T v) {}

    template <typename T> requires CustomConcept<T>
    void f2(T v) {}

    template <typename T>
    void f3(T v) requires CustomConcept<T> {}

    void f4(CustomConcept auto v) {}

    auto f5 = []<CustomConcept T> (T v) {};
    auto f6 = []<typename T> requires CustomConcept<T> (T v) {};
    auto f7 = []<typename T> (T v) requires CustomConcept<T> {};
    auto f8 = [](CustomConcept auto v) {};


    void conceptOverload(Floating auto value) {}
    void conceptOverload(SameAsChar auto value) {}

    template <typename T, typename std::enable_if_t<std::is_floating_point_v<T>, bool> = true>
    void enableIfOverload(T value) {}

    template <typename T, std::enable_if_t<std::is_same_v<T, char>, bool> = true>
    void enableIfOverload(T value) {}
}
