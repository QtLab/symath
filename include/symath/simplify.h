#ifndef INCLUDED_SYMATH_SIMPLIFY
#define INCLUDED_SYMATH_SIMPLIFY
#include "sum.h"
#include "product.h"

namespace symath {

	inline int simplify( int x ) {
		return x;
	}

	template<typename T>
	inline var<T> simplify( const var<T>& x ) {
		return x;
	}

	// sums

	template<typename TL,typename TR>
	auto simplify( const sum<TL,TR>& expr ) {
		return simplify(expr.left) + simplify(expr.right);
	}

	template<typename T>
	auto simplify( const negation<T>& expr ) {
		return -simplify(expr.arg);
	}

	template<typename T>
	auto simplify( const negation<negation<T>>& expr ) {
		return simplify(expr.arg.arg);
	}

	template<typename TL,typename TR>
	auto simplify( const sum<negation<TL>,negation<TR>>& expr ) {
		return -( simplify(expr.left.arg) + simplify(expr.right.arg) );
	}

	template<typename TL,typename TR>
	auto simplify( const sum<negation<TL>,TR>& expr ) {
		return simplify(expr.right) - simplify(expr.left.arg);
	}

	template<typename T,typename S>
	auto simplify( const sum<S,sum<T,S>>& expr ) {
		return simplify( simplify(expr.left + expr.right.right) * simplify(expr.right.left) );
	}

	template<typename T,typename S>
	auto simplify( const sum<S,sum<S,T>>& expr ) {
		return simplify( simplify(expr.left + expr.right.left) * simplify(expr.right.right) );
	}

	template<typename T,typename S>
	auto simplify( const sum<sum<S,T>,S>& expr ) {
		return simplify( simplify(expr.left.left + expr.right) + simplify(expr.left.right) );
	}
	
	// products

	template<typename TL,typename TR>
	auto simplify( const product<TL,TR>& expr ) {
		return simplify(expr.left) * simplify(expr.right);
	}

	template<typename T>
	auto simplify( const reciprocal<T>& expr ) {
		return make_reciprocal(simplify(expr.arg));
	}

	template<typename T>
	auto simplify( const reciprocal<reciprocal<T>>& expr ) {
		return simplify(expr.arg.arg);
	}

	template<typename TL,typename TR>
	auto simplify( const product<reciprocal<TL>,reciprocal<TR>>& expr ) {
		return make_reciprocal( simplify(expr.left.arg) * simplify(expr.right.arg) );
	}

	template<typename T,typename S>
	auto simplify( const product<S,product<T,S>>& expr ) {
		return simplify( simplify(expr.left * expr.right.right) * simplify(expr.right.left) );
	}

	template<typename T,typename S>
	auto simplify( const product<S,product<S,T>>& expr ) {
		return simplify( simplify(expr.left * expr.right.left) * simplify(expr.right.right) );
	}

	template<typename T,typename S>
	auto simplify( const product<product<S,T>,S>& expr ) {
		return simplify( simplify(expr.left.left * expr.right) * simplify(expr.left.right) );
	}

	template<typename T,typename S>
	auto simplify( const product<product<T,S>,S>& expr ) {
		return simplify( simplify(expr.left.right * expr.right) * simplify(expr.left.left) );
	}

	// functions

	template<typename T>
	auto simplify( const fn_exp<T>& expr ) {
		return exp(simplify(expr.arg));
	}
	
	template<typename T>
	auto simplify( const fn_log<T>& expr ) {
		return log(simplify(expr.arg));
	}

	template<typename T>
	auto simplify( const fn_sqrt<T>& expr ) {
		return sqrt(simplify(expr.arg));
	}

	template<typename T>
	auto simplify( const fn_sin<T>& expr ) {
		return sin(simplify(expr.arg));
	}

	template<typename T>
	auto simplify( const fn_cos<T>& expr ) {
		return cos(simplify(expr.arg));
	}

	template<typename T>
	auto simplify( const fn_tan<T>& expr ) {
		return tan(simplify(expr.arg));
	}

	template<typename T>
	auto simplify( const fn_csc<T>& expr ) {
		return csc(simplify(expr.arg));
	}

	template<typename T>
	auto simplify( const fn_sec<T>& expr ) {
		return sec(simplify(expr.arg));
	}

	template<typename T>
	auto simplify( const fn_cot<T>& expr ) {
		return cot(simplify(expr.arg));
	}

	template<typename T>
	auto simplify( const reciprocal<fn_sin<T>>& expr ) {
		return csc(simplify(expr.arg));
	}

	template<typename T>
	auto simplify( const reciprocal<fn_cos<T>>& expr ) {
		return sec(simplify(expr.arg));
	}

	template<typename T>
	auto simplify( const reciprocal<fn_tan<T>>& expr ) {
		return cot(simplify(expr.arg));
	}

	template<typename T>
	auto simplify( const reciprocal<fn_csc<T>>& expr ) {
		return sin(simplify(expr.arg));
	}

	template<typename T>
	auto simplify( const reciprocal<fn_sec<T>>& expr ) {
		return cos(simplify(expr.arg));
	}

	template<typename T>
	auto simplify( const reciprocal<fn_cot<T>>& expr ) {
		return tan(simplify(expr.arg));
	}

}

#endif
