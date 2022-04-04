#ifndef _IS_INTEGRAL_CONSTANT_HPP_
#define _IS_INTEGRAL_CONSTANT_HPP_
// * FT NAMESPACE - [IS INTEGRAL CONSTANT] *
namespace ft
{
template <class T, T v>
class integral_constant {
	public:
		static const T			value = v;
		typedef T				value_type;
};
}
#endif
