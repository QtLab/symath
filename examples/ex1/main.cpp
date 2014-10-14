#include <symath/symath.h>

using namespace std;
using namespace symath;

int main() {

	var<real> x(symbols::x);

	auto z = 2 * sqrt( x );
	auto y = cos( z ) + 3 * log( x );

	auto dydx = simplify(derivative(y,x));

	cout << dydx << endl;

	cout << "Press enter to continue . . . "; cin.get();
}

