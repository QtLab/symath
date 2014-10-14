#ifndef INCLUDED_SYMATH_PRODUCT
#define INCLUDED_SYMATH_PRODUCT
#include "symbols.h"

using namespace std;

namespace symath {

	template<typename TL,typename TR>
	struct product : binary_op<TL,TR> {
		using binary_op<TL,TR>::binary_op;
	};

	template<typename TL,typename TR>
	std::ostream& operator<<( std::ostream& stream, const product<TL,TR>& x ) {
		return stream << x.left << " " << x.right;
	}

	template<typename TL,typename TR>
	product<TL,TR> operator*( const TL& lhs, const TR& rhs ) {
		return product<TL,TR>(lhs,rhs);
	}

	template<typename T>
	struct reciprocal : unary_op<T> {
		using unary_op<T>::unary_op;
	};

	template<typename T>
	std::ostream& operator<<( std::ostream& stream, const reciprocal<T>& x ) {
		//return stream << "1 / ( " << x.arg << " )";
		return stream << "\\frac{1}{" << x.arg << "}";
	}

	template<typename TL,typename TR>
	std::ostream& operator<<( std::ostream& stream, const product<TL,reciprocal<TR>>& x ) {
		//return stream << x.left << " / ( " << x.right.arg << " )";
		return stream  << "\\frac{" << x.left << "}{" << x.right.arg << "}";
	}

	template<typename TL,typename TR>
	auto operator/( const TL& lhs, const TR& rhs ) {
		return lhs * reciprocal<TR>(rhs);
	}

	template<typename T>
	auto make_reciprocal( const T& x ) {
		return reciprocal<T>(x);
	}

}

#endif
