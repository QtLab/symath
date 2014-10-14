#ifndef INCLUDED_SYMATH_SUM
#define INCLUDED_SYMATH_SUM
#include "symbols.h"

using namespace std;

namespace symath {

	template<typename TL,typename TR>
	struct sum : binary_op<TL,TR> {
		using binary_op<TL,TR>::binary_op;
	};

	template<typename TL,typename TR>
	std::ostream& operator<<( std::ostream& stream, const sum<TL,TR>& x ) {
		return stream << "( " << x.left << " + " << x.right << " )";
	}

	template<typename TL,typename TR>
	sum<TL,TR> operator+( const TL& lhs, const TR& rhs ) {
		return sum<TL,TR>(lhs,rhs);
	}

	template<typename T>
	struct negation : unary_op<T> {
		using unary_op<T>::unary_op;
	};

	template<typename T>
	std::ostream& operator<<( std::ostream& stream, const negation<T>& x ) {
		return stream << "-" << x.arg;
	}

	template<typename TL,typename TR>
	std::ostream& operator<<( std::ostream& stream, const sum<TL,negation<TR>>& x ) {
		return stream  << "( " << x.left << " - " << x.right.arg << " )";
	}

	template<typename T>
	negation<T> operator-( const T& x ) {
		return negation<T>(x);
	}
	
	template<typename TL,typename TR>
	auto operator-( const TL& lhs, const TR& rhs ) {
		return lhs + -rhs;
	}
}

#endif
