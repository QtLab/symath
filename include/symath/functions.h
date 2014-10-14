#ifndef INCLUDED_SYMATH_FUNCTIONS
#define INCLUDED_SYMATH_FUNCTIONS
#include "symbols.h"

namespace symath {
	
	// exp

	template<typename T>
	struct fn_exp : unary_op<T> {
		using unary_op<T>::unary_op;
	};

	template<typename T>
	std::ostream& operator<<( std::ostream& stream, const fn_exp<T>& x ) {
		return stream << "\\exp(" << x.arg << ")";
	}

	template<typename T>
	auto exp( const T& x ) {
		return fn_exp<T>(x);
	}

	// log

	template<typename T>
	struct fn_log : unary_op<T> {
		using unary_op<T>::unary_op;
	};

	template<typename T>
	std::ostream& operator<<( std::ostream& stream, const fn_log<T>& x ) {
		return stream << "\\log(" << x.arg << ")";
	}

	template<typename T>
	auto log( const T& x ) {
		return fn_log<T>(x);
	}

	// sqrt

	template<typename T>
	struct fn_sqrt : unary_op<T> {
		using unary_op<T>::unary_op;
	};

	template<typename T>
	std::ostream& operator<<( std::ostream& stream, const fn_sqrt<T>& x ) {
		return stream << "\\sqrt{" << x.arg << "}";
	}

	template<typename T>
	auto sqrt( const T& x ) {
		return fn_sqrt<T>(x);
	}

	// sin

	template<typename T>
	struct fn_sin : unary_op<T> {
		using unary_op<T>::unary_op;
	};

	template<typename T>
	std::ostream& operator<<( std::ostream& stream, const fn_sin<T>& x ) {
		return stream << "\\sin(" << x.arg << ")";
	}

	template<typename T>
	auto sin( const T& x ) {
		return fn_sin<T>(x);
	}

	// cos

	template<typename T>
	struct fn_cos : unary_op<T> {
		using unary_op<T>::unary_op;
	};

	template<typename T>
	std::ostream& operator<<( std::ostream& stream, const fn_cos<T>& x ) {
		return stream << "\\cos(" << x.arg << ")";
	}

	template<typename T>
	auto cos( const T& x ) {
		return fn_cos<T>(x);
	}

	// tan

	template<typename T>
	struct fn_tan : unary_op<T> {
		using unary_op<T>::unary_op;
	};

	template<typename T>
	std::ostream& operator<<( std::ostream& stream, const fn_tan<T>& x ) {
		return stream << "\\tan(" << x.arg << ")";
	}

	template<typename T>
	auto tan( const T& x ) {
		return fn_tan<T>(x);
	}

	// csc

	template<typename T>
	struct fn_csc : unary_op<T> {
		using unary_op<T>::unary_op;
	};

	template<typename T>
	std::ostream& operator<<( std::ostream& stream, const fn_csc<T>& x ) {
		return stream << "\\csc(" << x.arg << ")";
	}

	template<typename T>
	auto csc( const T& x ) {
		return fn_csc<T>(x);
	}

	// sec

	template<typename T>
	struct fn_sec : unary_op<T> {
		using unary_op<T>::unary_op;
	};

	template<typename T>
	std::ostream& operator<<( std::ostream& stream, const fn_sec<T>& x ) {
		return stream << "\\sec(" << x.arg << ")";
	}

	template<typename T>
	auto sec( const T& x ) {
		return fn_sec<T>(x);
	}

	// cot

	template<typename T>
	struct fn_cot : unary_op<T> {
		using unary_op<T>::unary_op;
	};

	template<typename T>
	std::ostream& operator<<( std::ostream& stream, const fn_cot<T>& x ) {
		return stream << "\\cot(" << x.arg << ")";
	}

	template<typename T>
	auto cot( const T& x ) {
		return fn_cot<T>(x);
	}

}

#endif
