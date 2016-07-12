#include "1.h"
Comlex run(Comlex x,Comlex y)
{
	Comlex res;
	double znam = (y.Re*y.Re) + (y.Im*y.Im);
	res.Re = y.Re;
	res.Im = -y.Im;
	res = mult(res,x);
	res.Re /= znam;
	res.Im /= znam;
	return res;
}