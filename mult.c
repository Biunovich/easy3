#include "1.h"
Comlex run(Comlex x,Comlex y)
{
	Comlex res;
	res.Re = (x.Re * y.Re) - (x.Im * y.Im);
	res.Im = (x.Im * y.Re) + (x.Re * y.Im);
	return res;
}