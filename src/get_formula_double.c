//
// Created by Hugor Chau on 2020-01-14.
//

#include "../incs/header.h"

double		my_pow(double src, double power)
{
	return (pow(src, power));
}

double		my_plus(double first, double second)
{
	return (first + second);
}

double		my_minus(double first, double second)
{
	return (first - second);
}

double		my_multiplication(double first, double second)
{
	return (first * second);
}

double		my_more(double first, double second)
{
	if (first > second)
		return (TRUE);
	return (FAULSE);
}

double		my_less(double first, double second)
{
	if (first < second)
		return (TRUE);
	return (FAULSE);
}

t_complex	my_init(double re, double im)
{
	t_complex	res;

	res.imagine = im;
	res.real = re;
	return (res);
}

double		int_to_double(int src)
{
	return ((double)src);
}

double		my_div(double first, double second)
{
	return (first / second);
}

int			double_to_int(double src)
{
	return ((int)src);
}