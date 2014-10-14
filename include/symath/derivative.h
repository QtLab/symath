#ifndef INCLUDED_SYMATH_DERIVATIVE
#define INCLUDED_SYMATH_DERIVATIVE
#include "sum.h"
#include "product.h"
#include "functions.h"

namespace symath {

	inline int derivative( int, const var<real>& x ) {
		return 0;
	}

	inline int derivative( const var<real>& y, const var<real>& x ) {
		return (x==y)?1:0;
	}

	// sums

	template<typename TL,typename TR>
	auto derivative( const sum<TL,TR>& expr, const var<real>& variable ) {
		return derivative(expr.left,variable) + derivative(expr.right,variable);
	}

	template<typename TL>
	auto derivative( const sum<TL,int>& expr, const var<real>& variable ) {
		return derivative(expr.left,variable);
	}

	template<typename TR>
	auto derivative( const sum<int,TR>& expr, const var<real>& variable ) {
		return derivative(expr.right,variable);
	}

	template<typename T>
	auto derivative( const negation<T>& expr, const var<real>& variable ) {
		return -derivative(expr.arg,variable);
	}

	// products

	template<typename TL,typename TR>
	auto derivative( const product<TL,TR>& expr, const var<real>& variable ) {
		return derivative(expr.left,variable) * expr.right + expr.left * derivative(expr.right,variable);
	}
	
	template<typename TR>
	auto derivative( const product<int,TR>& expr, const var<real>& variable ) {
		return expr.left * derivative(expr.right,variable);
	}

	template<typename TL>
	auto derivative( const product<TL,int>& expr, const var<real>& variable ) {
		return derivative(expr.left,variable) * expr.right;
	}

	template<typename T>
	auto derivative( const reciprocal<T>& expr, const var<real>& variable ) {
		return -derivative(expr.arg,variable) / ( expr.arg * expr.arg );
	}

	// functions

	template<typename T>
	auto derivative( const fn_exp<T>& expr, const var<real>& variable ) {
		return exp(expr.arg) * derivative(expr.arg,variable);
	}

	template<typename T>
	auto derivative( const fn_log<T>& expr, const var<real>& variable ) {
		return derivative(expr.arg,variable) / expr.arg;
	}

	template<typename T>
	auto derivative( const fn_sqrt<T>& expr, const var<real>& variable ) {
		return derivative(expr.arg,variable) / ( 2 * expr );
	}

	template<typename T>
	auto derivative( const fn_sin<T>& expr, const var<real>& variable ) {
		return cos(expr.arg) * derivative(expr.arg,variable);
	}

	template<typename T>
	auto derivative( const fn_cos<T>& expr, const var<real>& variable ) {
		return -sin(expr.arg) * derivative(expr.arg,variable);
	}

	template<typename T>
	auto derivative( const fn_tan<T>& expr, const var<real>& variable ) {
		return (sec(expr.arg) * sec(expr.arg)) * derivative(expr.arg,variable);
	}

	template<typename T>
	auto derivative( const fn_csc<T>& expr, const var<real>& variable ) {
		return -(csc(expr.arg) * cot(expr.arg)) * derivative(expr.arg,variable);
	}

	template<typename T>
	auto derivative( const fn_sec<T>& expr, const var<real>& variable ) {
		return (tan(expr.arg) * sec(expr.arg)) * derivative(expr.arg,variable);
	}

	template<typename T>
	auto derivative( const fn_cot<T>& expr, const var<real>& variable ) {
		return -(csc(expr.arg) * csc(expr.arg)) * derivative(expr.arg,variable);
	}

}

#endif
