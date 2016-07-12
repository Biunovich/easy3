#include "1.h"
Comlex run(Comlex x,Comlex y)
{
	Comlex res;
	double znam = (y.Re*y.Re) + (y.Im*y.Im);
	res.Re = (x.Re * y.Re) + (x.Im * y.Im);
	res.Im = (y.Re * x.Im) - (y.Im * x.Re);
	res.Re /= znam;
	res.Im /= znam;
	return res;
}