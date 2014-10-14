#ifndef INCLUDED_SYMATH_SYMBOLS
#define INCLUDED_SYMATH_SYMBOLS
#include <string>
#include <iostream>

namespace symath {

	struct real {};

	struct symbol {
		const wchar_t unicode;
		const std::string latex;
		
		symbol( wchar_t unicode, const char* latex ) : unicode(unicode), latex(latex) {}

		bool operator==( const symbol& rhs ) const {
			return unicode == rhs.unicode;
		}
	};

	namespace symbols {
		extern symbol a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t,u,v,w,x,y,z,
		              A,B,C,D,E,F,G,H,I,J,K,L,M,N,O,P,Q,R,S,T,U,V,W,X,Y,Z,
					  alpha,beta,gamma,delta,epsilon,varepsilon,zeta,eta,theta,vartheta,iota,kappa,lambda,mu,nu,xi,pi,varpi,rho,varrho,sigma,varsigma,tau,upsilon,phi,varphi,chi,psi,omega,
					  Gamma,Delta,Theta,Lambda,Xi,Pi,Sigma,Upsilon,Phi,Psi,Omega;
	}
	
	template<typename T>
	struct var {
		using type = T;
		const symbol& name;

		explicit var( const symbol& name ) : name(name) {}

		bool operator==( const var<T>& rhs ) const {
			return name == rhs.name;
		}
	};

	template<typename T>
	std::ostream& operator<<( std::ostream& stream, const var<T>& x ) {
		return stream << x.name;
	}

	inline std::ostream& operator<<( std::ostream& stream, const symbol& x ) {
		return stream << x.latex;
	}

	template<typename T>
	struct unary_op {
		using type = T;
		T arg;
		explicit unary_op( const T& x ) : arg(x) {}
	};

	template<typename TL,typename TR>
	struct binary_op {
		using type_left = TL;
		using type_right = TR;
		TL left;
		TR right;
		binary_op( const TL& left, const TR& right ) : left(left), right(right) {}
	};

}

#endif
