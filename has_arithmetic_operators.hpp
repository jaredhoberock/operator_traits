#pragma once

#include <type_traits>
#include <utility>

namespace __has_arithmetic_namespace
{


struct any
{
  template<typename T> any(T) {}
};


struct no {};


no operator+(any, any);
no operator+=(any, any);

no operator-(any, any);
no operator-=(any, any);

no operator*(any, any);
no operator*=(any, any);

no operator/(any, any);
no operator/=(any, any);


template<typename T1, typename T2 = T1, typename Result = typename std::common_type<T1,T2>::type>
struct has_operator_plus
  : std::is_same<
      decltype(std::declval<T1>() + std::declval<T2>()),
      Result
    >
{
};


template<typename T1, typename T2 = T1, typename Result = T1&>
struct has_operator_plus_assign
  : std::is_same<
      decltype(std::declval<T1&>() += std::declval<T2>()),
      Result
    >
{
};


template<typename T1, typename T2 = T1, typename Result = typename std::common_type<T1,T2>::type>
struct has_operator_minus
  : std::is_same<
      decltype(std::declval<T1>() - std::declval<T2>()),
      Result
    >
{
};


template<typename T1, typename T2 = T1, typename Result = T1&>
struct has_operator_minus_assign
  : std::is_same<
      decltype(std::declval<T1&>() -= std::declval<T2>()),
      Result
    >
{
};


template<typename T1, typename T2 = T1, typename Result = typename std::common_type<T1,T2>::type>
struct has_operator_multiplies
  : std::is_same<
      decltype(std::declval<T1>() * std::declval<T2>()),
      Result
    >
{
};


template<typename T1, typename T2 = T1, typename Result = T1&>
struct has_operator_multiplies_assign
  : std::is_same<
      decltype(std::declval<T1&>() *= std::declval<T2>()),
      Result
    >
{
};


template<typename T1, typename T2 = T1, typename Result = typename std::common_type<T1,T2>::type>
struct has_operator_divides
  : std::is_same<
      decltype(std::declval<T1>() / std::declval<T2>()),
      Result
    >
{
};


template<typename T1, typename T2 = T1, typename Result = T1&>
struct has_operator_divides_assign
  : std::is_same<
      decltype(std::declval<T1&>() /= std::declval<T2>()),
      Result
    >
{
};


}


template<typename T1, typename T2 = T1, typename Result = typename std::common_type<T1,T2>::type>
struct has_operator_plus : __has_arithmetic_namespace::has_operator_plus<T1,T2,Result> {};


template<typename T1, typename T2 = T1, typename Result = T1&>
struct has_operator_plus_assign : __has_arithmetic_namespace::has_operator_plus_assign<T1,T2,Result> {};


template<typename T1, typename T2 = T1, typename Result = typename std::common_type<T1,T2>::type>
struct has_operator_minus : __has_arithmetic_namespace::has_operator_minus<T1,T2,Result> {};


template<typename T1, typename T2 = T1, typename Result = T1&>
struct has_operator_minus_assign : __has_arithmetic_namespace::has_operator_minus_assign<T1,T2,Result> {};


template<typename T1, typename T2 = T1, typename Result = typename std::common_type<T1,T2>::type>
struct has_operator_multiplies : __has_arithmetic_namespace::has_operator_multiplies<T1,T2,Result> {};


template<typename T1, typename T2 = T1, typename Result = T1&>
struct has_operator_multiplies_assign : __has_arithmetic_namespace::has_operator_multiplies_assign<T1,T2,Result> {};


template<typename T1, typename T2 = T1, typename Result = typename std::common_type<T1,T2>::type>
struct has_operator_divides : __has_arithmetic_namespace::has_operator_divides<T1,T2,Result> {};


template<typename T1, typename T2 = T1, typename Result = T1&>
struct has_operator_divides_assign : __has_arithmetic_namespace::has_operator_divides_assign<T1,T2,Result> {};


template<typename T1, typename T2 = T1>
struct has_arithmetic_operators : std::integral_constant<
  bool,
  has_operator_plus<T1,T2>::value &&
  has_operator_plus_assign<T1,T2>::value &&
  has_operator_minus<T1,T2>::value &&
  has_operator_minus_assign<T1,T2>::value &&
  has_operator_multiplies<T1,T2>::value &&
  has_operator_multiplies_assign<T1,T2>::value &&
  has_operator_divides<T1,T2>::value &&
  has_operator_divides_assign<T1,T2>::value
>
{};

