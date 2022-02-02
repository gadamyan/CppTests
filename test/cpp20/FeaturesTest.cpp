//
//  CppTests
//
//  Created by Gevorg Adamyan
//

#include <gtest/gtest.h>

#include <numeric>
#include <span>
#include <compare>

namespace {

TEST(Cpp20Test, designated_initialiser)
{
    struct MyStruct {
        int x = 10;
        int y;
        int z;
    };

    const MyStruct myStruct {.x = 1, .z = 2};
    ASSERT_EQ(1, myStruct.x);
    ASSERT_EQ(0, myStruct.y);
    ASSERT_EQ(2, myStruct.z);
}

TEST(Cpp20Test, template_parameters_for_lambdas)
{
    auto oldLambda = [](auto vector) { // C++17
        using T = typename decltype(vector)::value_type;
        const T result = std::accumulate(vector.cbegin(), vector.cend(), 0);
        return result;
    };

    auto newLambda = []<typename T>(std::vector<T> vector) { // C++20
        const T result = std::accumulate(vector.cbegin(), vector.cend(), 0);
        return result;
    };

    const std::vector list { 1, 2, 3 };
    ASSERT_EQ(6, oldLambda(list));
    ASSERT_EQ(6, newLambda(list));
}


TEST(Cpp20Test, three_way_comparison)
{
    struct Struct1 {
        int x;
        int y;
        auto operator<=>(const Struct1 &) const = default;
    };
    ASSERT_EQ((Struct1 { .x =1, .y = 1 }), (Struct1 { .x =1, .y =1 }));
    ASSERT_GT((Struct1 { .x =3, .y = 1 }), (Struct1 { .x =1, .y =1 }));

    struct Struct2 {
        int a;
        int b;

        std::strong_ordering operator<=>(const Struct1& other) const {
            if (auto cmpA = a <=> other.x; cmpA != std::strong_ordering::equal) {
                return cmpA;
            }
            return b <=> other.y;
        }

        bool operator==(const Struct1& other) const {
            return (*this <=> other) == std::strong_ordering::equal;
        }
    };
    ASSERT_EQ((Struct1 { .x =1, .y = 1 }), (Struct2 { .a =1, .b =1 }));
    ASSERT_GT((Struct1 { .x =3, .y = 1 }), (Struct2 { .a =1, .b =1 }));
}

TEST(Cpp20Test, three_way_comparison_weak_ordering)
{
    struct Struct1 {
        int x;
        int y;
        std::weak_ordering operator<=>(const Struct1 &) const = default;
    };
    ASSERT_EQ((Struct1 { .x =1, .y = 1 }), (Struct1 { .x =1, .y =1 }));
    ASSERT_GT((Struct1 { .x =3, .y = 1 }), (Struct1 { .x =1, .y =1 }));

    struct Struct2 {
        Struct1 a;
        int b;

        std::weak_ordering operator<=>(const Struct2& other) const = default;
    };
    ASSERT_EQ((Struct2 { .a = { 1, 1 }, .b = 1 }), (Struct2 { .a = { 1, 1 }, .b =1 }));
    ASSERT_GT((Struct2 { .a = { 2, 1 }, .b = 1 }), (Struct2 { .a = { 1, 1 } , .b =1 }));
}

TEST(Cpp20Test, deprecated_auto_capture_of_this)
{
    class MyClass {
        int mValue = 1;
        void func(){
            auto bob = [=](){ // C++17, deprecated in C++20
                return mValue;
            };
            auto bob1 = [=, this] { // C++20
                return mValue;
            };
            bob();
            bob1();
        }
    };
}

TEST(Cpp20Test, range_based_for_loop_with_initializer)
{
    int sum = 0;
    for (auto list = std::vector { 1, 2, 3 }; auto& value : list) {
        sum += value;
    }
    ASSERT_EQ(6, sum);
}

template<typename T1, typename T2>
struct MyPair{
    T1 value1;
    T2 value2;
};
template<class T1, class T2> MyPair(T1, T2) -> MyPair<T1, T2>; // deduction guide

TEST(Cpp20Test, class_template_argument_deduction)
{
    const MyPair instance { 1, 2.0 };
    ASSERT_EQ(1, instance.value1);
    ASSERT_EQ(2.0, instance.value2);
}

TEST(Cpp20Test, likely_unlikely_attributs)
{
    bool unlikely = false;
    bool likely = false;
    for (int i = 0; i < 1000; ++i) {
        if (i == 50) [[unlikely]] {
            unlikely = true;
        }
        if (i != 500) [[likely]] {
            likely = true;
        }
    }
    ASSERT_TRUE(unlikely);
    ASSERT_TRUE(likely);
}

TEST(Cpp20Test, polymorphic_constexpr)
{
    class Parent {
    public:
        virtual int func() const = 0;
    };

    class Child: public Parent {
    public:
        constexpr int func() const override { return 1; }
    };
    Child child;
    Parent* parent = &child;
    ASSERT_EQ(1, parent->func());
}

consteval int sqrFunc(int n) {
    return n * n;
}
TEST(Cpp20Test, immediate_function)
{
    constexpr int value = sqrFunc(10);
//    int x = 10; int value = sqrFunc(x); // Error
    ASSERT_EQ(100, value);
}

TEST(Cpp20Test, map_contains)
{
    const std::map<int, char> testMap { {1, 'a'}, {2, 'b'}, {3, 'c'} };
    const std::set<int> testSet { 1, 2, 3 };

    ASSERT_TRUE(testMap.contains(1));
    ASSERT_FALSE(testMap.contains(4));
    ASSERT_TRUE(testSet.contains(1));
    ASSERT_FALSE(testSet.contains(4));
}

TEST(Cpp20Test, starts_ends_with)
{
    std::string str = "foobar";
    ASSERT_TRUE(str.starts_with("foo"));
    ASSERT_FALSE(str.ends_with("baz"));
}

TEST(Cpp20Test, span)
{
    auto func = [](std::span<int> values) {
        return std::accumulate(values.begin(), values.end(), 0);
    };
    std::vector<int> myVector = { 1, 2, 3 };
    std::array<int, 3> myArray = { 1, 2, 3 };

    ASSERT_EQ(6, func(myVector));
    ASSERT_EQ(6, func(myArray));
}

constexpr int GetValue(int x) {
    if (std::is_constant_evaluated()) {
        return x;
    }
    return x * x;
}

TEST(Cpp20Test, is_constant_evaluated)
{
    constexpr int compileTimeResult = GetValue(2);
    const int value = 2;
    ASSERT_EQ(2, compileTimeResult);
    ASSERT_EQ(4, GetValue(value));
}
}
