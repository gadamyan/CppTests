//
//  TestFactory.cpp
//  cpptests
//
//  Created by Adamyan, Gevorg on 10/28/18.
//  Copyright © 2018 Adamyan, Gevorg. All rights reserved.

#include <gtest/gtest.h>

#include <concepts>

namespace {

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

    template <typename T>
    concept Addable = requires (T value) { value + value; };

    template<typename T>
    concept CustomConcept = requires (T x) {
        x++;
        {*x};
        typename T::value_type;
        requires SameAsChar<typename T::value_type>;
    };

    void testCustomComponent() {
        auto testLambda = [](CustomConcept auto itr) {};
        std::vector charVector = { 'a', 'b', 'c' };
        testLambda(charVector.begin());
    }

    void func1(Integral auto value) {
    }

    void func1(IntegralOrFloating auto value) {
    }

    void func1(SameAsChar auto value) {
    }

    template <typename T, typename std::enable_if_t<std::is_floating_point_v<T>, bool> = true>
    void func2(T value) {
    }

    template <typename T, std::enable_if_t<std::is_same_v<T, char>, bool> = true>
    void func2(T value) {
    }

    void TestEnableIf() {
        func2('c');
        func2(3.0);
    }

    template <class T>
    constexpr auto decay_copy(T&& arg) -> std::enable_if_t<std::is_convertible<T, std::decay_t<T>>::value, std::decay_t<T>>
    {
        return std::forward<T>(arg);
    }

    template <typename T>
    concept DecayCopyable = std::is_convertible_v<T, std::decay_t<T>>;

    template <DecayCopyable T>
    constexpr auto decay_copy(T&& arg) -> std::decay_t<T> {
        return std::forward<T>(arg);
    }

    // `T` is a constrained type template parameter.
    template <CustomConcept T>
    void f1(T v);

    // `T` is a constrained type template parameter.
    template <typename T>
    requires CustomConcept<T>
    void f2(T v);

    // `T` is a constrained type template parameter.
    template <typename T>
    void f3(T v) requires CustomConcept<T>;

    // `v` is a constrained deduced parameter.
    void f4(CustomConcept auto v);

    // `v` is a constrained non-type template parameter.
    template <CustomConcept auto v>
    void f5();

    // `T` is a constrained type template parameter.
    auto f6 = []<CustomConcept T> (T v) {};

    // `T` is a constrained type template parameter.
    auto f7 = []<typename T> requires CustomConcept<T> (T v) {};

    // `T` is a constrained type template parameter.
    auto f8 = []<typename T> (T v) requires CustomConcept<T> {};

    // `v` is a constrained deduced parameter.
    auto f9 = [](CustomConcept auto v) {};

    // `v` is a constrained non-type template parameter.
    auto f10 = []<CustomConcept auto v> () {};

    // Forms for auto-deduced variables:
    // `foo` is a constrained auto-deduced value.
//    CustomConcept auto val1 = ...;


template<typename T>
class optional{
public:
    optional() = default;

    // trivial copy-constructor
    optional(const optional&) requires(std::is_trivial_v<T>) = default;

    // non-trivial copy-constructor
    optional(const optional& rhs)
    requires(!std::is_trivial_v<T>){
        std::cout << "not trivial\n";
    }

    // trivial destructor
    ~optional() requires(std::is_trivial_v<T>) = default;

    // non-trivial destructor
    ~optional() requires(!std::is_trivial_v<T>){
    }
    // ...
private:
    T value;
};

//static_assert(std::is_trivial_v<optional<int>>);
static_assert(!std::is_trivial_v<optional<std::string>>);

}
