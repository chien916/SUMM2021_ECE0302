#ifndef FANCYPOWER_HPP
#define FANCYPOWER_HPP
/**
 *
 * @param n the value of n in x^n
 * @param x the value of x in x^n
 * @pre the value of power (n) must be more or equal to zero
 * @post the value of x^n will be returned to the function caller
 * @return the value of x^n using Egptian's Power Algorithms
 */
int fancyPower(int n, int x) {
	bool isEven = (n % 2 == 0);
	if (n == 0) {//boundary condition: return 1 if n=0
		return 1;
	} else if (n == 1) {//boundary condition: return itself if n=1
		return x;
	} else if (isEven) {//case when n is even
		return fancyPower(0.5 * n, x * x);
	} else {//case when n is odd
		return (x * fancyPower(0.5 * (n - 1), x * x));
	}


}

#endif
