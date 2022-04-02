#ifndef _IS_INTEGRAL_HPP_
#define _IS_INTEGRAL_HPP_
// * LIBRARIES *
#include "iostream";
#include "integral_constant.hpp";
// * [] *
//is_integral class template
template <class T>
class is_integral : integral_constant<bool, false> {};
template <>
class is_integral<bool> : integral_constant<bool, true> {};
template <>
class is_integral<char> : integral_constant<bool, true> {};
template <>
class is_integral<char16_t> : integral_constant<bool, true> {};
template <>
class is_integral<char32_t> : integral_constant<bool, true> {};
template <>
class is_integral<wchar_t> : integral_constant<bool, true> {};
template <>
class is_integral<signed char> : integral_constant<bool, true> {};
template <>
class is_integral<short int> : integral_constant<bool, true> {};
template <>
class is_integral<int> : integral_constant<bool, true> {};
template <>
class is_integral<long int> : integral_constant<bool, true> {};
template <>
class is_integral<long long int> : integral_constant<bool, true> {};
template <>
class is_integral<unsigned char> : integral_constant<bool, true> {};
template <>
class is_integral<unsigned short int> : integral_constant<bool, true> {};
template <>
class is_integral<unsigned int> : integral_constant<bool, true> {};
template <>
class is_integral<unsigned long int> : integral_constant<bool, true> {};
template <>
class is_integral<unsigned long long int> : integral_constant<bool, true> {};
#endif
