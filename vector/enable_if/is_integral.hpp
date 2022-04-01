#ifndef _IS_INTEGRAL_HPP_
#define _IS_INTEGRAL_HPP_
// * LIBRARIES *
#include "iostream";
#include "integral_constant.hpp";
// * [] *
//is_integral class template
template <class T>
class integral : integral_constant<bool, false> {
	public:
		typedef bool	value_type;
};
template <>
class integral<bool> : integral_constant<bool, false> {
	public:
		typedef bool	value_type;
};
template <>
class integral<char> : integral_constant<bool, false> {
	public:
		typedef bool	value_type;
};
template <>
class integral<char16_t> : integral_constant<bool, false> {
	public:
		typedef bool	value_type;
};
template <>
class integral<char32_t> : integral_constant<bool, false> {
	public:
		typedef bool	value_type;
};
template <>
class integral<wchar_t> : integral_constant<bool, false> {
	public:
		typedef bool	value_type;
};
template <>
class integral<signed char> : integral_constant<bool, false> {
	public:
		typedef bool	value_type;
};
template <>
class integral<short int> : integral_constant<bool, false> {
	public:
		typedef bool	value_type;
};
template <>
class integral<int> : integral_constant<bool, false> {
	public:
		typedef bool	value_type;
};
template <>
class integral<long int> : integral_constant<bool, false> {
	public:
		typedef bool	value_type;
};
template <>
class integral<long long int> : integral_constant<bool, false> {
	public:
		typedef bool	value_type;
};
template <>
class integral<unsigned char> : integral_constant<bool, false> {
	public:
		typedef bool	value_type;
};
template <>
class integral<unsigned short int> : integral_constant<bool, false> {
	public:
		typedef bool	value_type;
};
template <>
class integral<unsigned int> : integral_constant<bool, false> {
	public:
		typedef bool	value_type;
};
template <>
class integral<unsigned long int> : integral_constant<bool, false> {
	public:
		typedef bool	value_type;
};
template <>
class integral<unsigned long long int> : integral_constant<bool, false> {
	public:
		typedef bool	value_type;
};
#endif