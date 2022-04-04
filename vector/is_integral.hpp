#ifndef _IS_INTEGRAL_HPP_
#define _IS_INTEGRAL_HPP_
# include "integral_constant.hpp"
// * LIBRARIES *
namespace ft
{
template <class T>
class is_integral : public ft::integral_constant<bool, false> {};
template <>
class is_integral<bool> : public ft::integral_constant<bool, true> {};
template <>
class is_integral<char> : public ft::integral_constant<bool, true> {};
template <>
class is_integral<char16_t> : public ft::integral_constant<bool, true> {};
template <>
class is_integral<char32_t> : public ft::integral_constant<bool, true> {};
template <>
class is_integral<wchar_t> : public ft::integral_constant<bool, true> {};
template <>
class is_integral<signed char> : public ft::integral_constant<bool, true> {};
template <>
class is_integral<short int> : public ft::integral_constant<bool, true> {};
template <>
class is_integral<int> : public ft::integral_constant<bool, true> {};
template <>
class is_integral<long int> : public ft::integral_constant<bool, true> {};
template <>
class is_integral<long long int> : public ft::integral_constant<bool, true> {};
template <>
class is_integral<unsigned char> : public ft::integral_constant<bool, true> {};
template <>
class is_integral<unsigned short int> : public ft::integral_constant<bool, true> {};
template <>
class is_integral<unsigned int> : public ft::integral_constant<bool, true> {};
template <>
class is_integral<unsigned long int> : public ft::integral_constant<bool, true> {};
template <>
class is_integral<unsigned long long int> : public ft::integral_constant<bool, true> {};
}
#endif
