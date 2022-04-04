#ifndef _IS_INTEGRAL_HPP_
#define _IS_INTEGRAL_HPP_
# include "integral_constant.hpp"
// * LIBRARIES *
//is_integral class template
template <class T>
class is_integral : public integral_constant<bool, false> {};
template <>
class is_integral<bool> : public integral_constant<bool, true> {};
template <>
class is_integral<char> : public integral_constant<bool, true> {};
template <>
class is_integral<char16_t> : public integral_constant<bool, true> {};
template <>
class is_integral<char32_t> : public integral_constant<bool, true> {};
template <>
class is_integral<wchar_t> : public integral_constant<bool, true> {};
template <>
class is_integral<signed char> : public integral_constant<bool, true> {};
template <>
class is_integral<short int> : public integral_constant<bool, true> {};
template <>
class is_integral<int> : public integral_constant<bool, true> {};
template <>
class is_integral<long int> : public integral_constant<bool, true> {};
template <>
class is_integral<long long int> : public integral_constant<bool, true> {};
template <>
class is_integral<unsigned char> : public integral_constant<bool, true> {};
template <>
class is_integral<unsigned short int> : public integral_constant<bool, true> {};
template <>
class is_integral<unsigned int> : public integral_constant<bool, true> {};
template <>
class is_integral<unsigned long int> : public integral_constant<bool, true> {};
template <>
class is_integral<unsigned long long int> : public integral_constant<bool, true> {};
#endif
