#pragma once

#include <type_traits>

class Solution1
{
};

template <typename T>
concept addable = requires (T f) { f + f; }; // `requires` expression.

template<typename T> /*...*/
concept Bob = requires (T x) // optional set of fictional parameter(s)
{
    // simple requirement: expression must be valid
    x++;    // expression must be valid

    // type requirement: `typename T`, T type must be a valid type
    typename T::value_type;
//    typename S<T>;

    // compound requirement: {expression}[noexcept][-> Concept];
    // {expression} -> Concept<A1, A2, ...> is equivalent to
    // requires Concept<decltype((expression)), A1, A2, ...>
    {*x};  // dereference must be valid
    {*x} noexcept;  // dereference must be noexcept
    // dereference must  return T::value_type
//    {*x} noexcept -> std::same_as<typename T::value_type>;

    // nested requirement: requires ConceptName<...>;
    requires addable<T>; // constraint Addable<T> must be satisfied
};


//template<typename T>
//concept Addable = requires(T a, T b)
//{
//    a + b;
//};
//
//template<typename T>
//concept Dividable = requires(T a, T b)
//{
//    a/b;
//};
//
//template<typename T>
//concept DivAddable = Addable<T> && Dividable<T>;
//
//template<typename T>
//void f(T x)
//{
//    if constexpr(Addable<T>){ /*...*/ }
//    else if constexpr(requires(T a, T b) { a + b; }){ /*...*/ }
//}


// `T` is not limited by any constraints.
template <typename T>
concept always_satisfied = true;
// Limit `T` to integrals.
template <typename T>
concept integral = std::is_integral_v<T>;
// Limit `T` to both the `integral` constraint and signedness.
template <typename T>
concept signed_integral = integral<T> && std::is_signed_v<T>;
// Limit `T` to both the `integral` constraint and the negation of the `signed_integral` constraint.
template <typename T>
concept unsigned_integral = integral<T> && !signed_integral<T>;

template <typename T>
concept callable = requires (T f) { f(); }; // `requires` expression.

template <typename T>
requires callable<T> // `requires` clause.
void f(T);

template <typename T>
requires requires (T x) { x + x; } // `requires` clause and expression on same line.
T add(T a, T b) {
    return a + b;
}

template <Bob T>
void mm(T b) {

}




template <class T>
using Constructible = std::is_constructible<T>;



//template <class T>
//struct pointer_value
//{
//    using type = typename std::pointer_traits<T>::element_type;
//};
//
//template <class T>
//using pointer_value_t = typename pointer_value<T>::type;
//
//template <pointer_value_t T>
//void aaa(T m) {
//
//}


template <class T>
constexpr auto decay_copy(T&& arg)
        -> std::enable_if_t<std::is_convertible<T, std::decay_t<T>>::value, std::decay_t<T>>
{
    return std::forward<T>(arg);
}

template <typename T>
concept decayCopyable = std::is_convertible_v<T, std::decay_t<T>>;// && std::decay_t<T>;


template <class RR>
std::enable_if_t<std::is_reference_v<RR>, const RR&>
extract_value(RR value) noexcept
{
    return value.get();
}

template <typename T>
concept extractable = std::is_reference_v<T>;

//template <extractable T>
//T extract_value() noexcept
//{
//    return value.get();
//}


template <class T,
        class U = T,
        std::enable_if_t<std::is_move_constructible<T>::value && std::is_assignable<T&, U&&>::value, int> = 0>
constexpr T exchange(T& obj, U&& new_value) noexcept(std::is_nothrow_move_constructible<T>::value&& std::is_nothrow_assignable<T&, U&&>::value)
{
    T old_value = std::move(obj);
    obj = std::forward<U>(new_value);
    return old_value;
}


template <typename T>
concept Exchangeable = std::is_move_constructible_v<T> && std::is_assignable_v<T&, T&&>;

template <typename T>
constexpr T exchange(T& obj, T&& new_value) noexcept(std::is_nothrow_move_constructible_v<T>&& std::is_nothrow_assignable_v<T&, T&&>) requires Exchangeable<T>
{
    T old_value = std::move(obj);
    obj = std::forward<T>(new_value);
    return old_value;
}