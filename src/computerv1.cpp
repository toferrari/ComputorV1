/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   computerv1.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tferrari <tferrari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/26 12:07:15 by tferrari          #+#    #+#             */
/*   Updated: 2019/01/16 14:06:56 by tferrari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "computerv1.hpp"

Equation::Equation()
{
	a = 0.0;
	b = 0.0;
	c = 0.0;
	disc = 0.0;
	degre = 0;
	signe = 1.0;
	show = 0;
}

int			Equation::bonus(string str)
{
	if (str.find("-s") != -1)
		show = 1;
	else
		return (0);
	return (1);
}

void			Equation::number(float nb, int deg)
{
	degre = (degre < deg) ? deg : degre;
	if (deg == 2)
		a += signe * nb;
	else if (deg == 1)
		b += signe * nb;
	else
		c += signe * nb;
}

void			Equation::degres(string str)
{
	int	i;

	if ((i = str.find("X^")) != -1)
	{
		if (str[1] == 'X'&& str[0] == '-')
			number(-1.00, atoi(&str[i + 2]));
		else if ((str[1] == 'X'&& str[0] == '+' )|| str[0] == 'X')
			number(1.00, atoi(&str[i + 2]));
		else
			number(atof(str.c_str()), atoi(&str[i + 2]));
	}
	else if (str.find("X") != -1)
		{
			if (str[1] == 'X'&& str[0] == '-')
				number(-1.0, 1);
			else if ((str[1] == 'X'&& str[0] == '+' )|| str[0] == 'X')
				number(1.0, 1);
			else
				number(atof(str.c_str()), 1);
		}
	else
		number(atof(str.c_str()), 0);
}

void			Equation::up_equal()
{
	signe = -1.0;
}

double			Equation::discriment()
{
	double tmp;

	tmp = ABS(4 * a * c);
	if (show)
	{
		cout << "Δ = b² - 4ac" << endl;
		cout << "Δ = " << b << "² - 4 * " << a << " * " << c << endl;
		if ((4 * a * c) < 0)
			cout << "Δ = " << b * b << " + " << tmp << endl;
		else
			cout << "Δ = " << b * b << " - " << 4 * a * c << endl;
		cout << "Δ = " << (b * b) - (4 * a * c) << endl;
	}
	return ((b * b) - (4 * a * c));
}

double			Equation::unknow()
{
	return ((-c) / b);
}

double			Equation::discriment_r1()
{
	if (show == 1)
	{
		printf("\033[4m-b -√(Δ)\033[0m\n	2a\n");
		printf("x1 = \033[4m-(%.2f) -√(%.2f)\033[0m\n	2 * %.2f\n", b, disc, a);
		printf("x1 = ");
	}
	return ((-b - ft_sqrt(disc)) / (2 * a));
}

double			Equation::discriment_r2()
{
	if (show == 1)
	{
		printf("\033[4m-b +√(Δ)\033[0m\n	2a\n");
		printf("x2 = \033[4m-(%.2f) +√(%.2f)\033[0m\n	2 * %.2f\n", b, disc, a);
		printf("x2 = ");
	}
	return ((-b + ft_sqrt(disc)) / (2 * a));
}

int				Equation::pgcd(double x, double y)
{
	if (y == 0)
		return (x);
	return (pgcd(y, fmod(x,y)));
}

int				Equation::reduce_racine()
{
	int i;
	int j;

	i = 1;
	while (i * i <= abs(disc))
	{
		if (i * i == abs(disc))
		{
			disc = 0;
			return (i);
		}
		i++;
	}
	j = 1;
	i = 1;
	while (i * i * j <= abs(disc))
	{
		while (i * i * j <= abs(disc))
		{
			if (i * i * j == abs(disc))
			{
				disc /= i * i;
				return (i);
			}
			i++;
		}
		i = 1;
		j++;
	}
	return (0);
}

void			Equation::complex_reduce()
{
	double racine_disc_reduce;

	racine_disc_reduce = reduce_racine();
	complex_r1(racine_disc_reduce);
	complex_r2(racine_disc_reduce);
}

void			Equation::complex_r1(double racine_disc_reduce)
{
	if (show == 1)
	{
		printf("x1 = \033[4m");
		if (b < 0)
			printf("%.2f ", -b);
		else if (b > 0)
			printf("-%.2f ", b);
		printf("-i√(%.2f)\033[0m\n\t%.2f\n\n", -disc * racine_disc_reduce * racine_disc_reduce, a*2);
		printf("x1 = \033[4m");
		if (b < 0)
			printf("%.2f ", -b);
		else if (b > 0)
			printf("-%.2f ", b);
		printf("-i√(%.2f * %.2f)\033[0m\n\t%.2f\n\n", racine_disc_reduce * racine_disc_reduce, -disc, a*2);
		printf("x1 = \033[4m");
		if (b < 0)
			printf("%.2f ", -b);
		else if (b > 0)
			printf("-%.2f ", b);
		printf("-i%.2f√(%.2f)\033[0m\n\t%.2f\n\n", racine_disc_reduce, -disc, a*2);
	}
	printf("x1 = ");
	if (b / (2 * a) < 0)
		printf("%.2f ", -b / (2 * a));
	else if (b / (2 * a) > 0)
		printf("-%.2f ", b / (2 * a));
	if (racine_disc_reduce / (2 * a) < 0)
		printf("+ i%.2f√(%.2f)\n\n", (racine_disc_reduce / abs(2 * a)), -disc);
	else if (racine_disc_reduce > 0)
		printf("- i%.2f√(%.2f)\n\n", (racine_disc_reduce / (2 * a)), -disc);
	else
		printf("- i%.2f√(%.2f)\n\n", (1 / (2 * a)), -disc);
}

void			Equation::complex_r2(double racine_disc_reduce)
{
	if (show == 1)
	{
		printf("x2 = \033[4m");
		if (b < 0)
			printf("%.2f ", -b);
		else if (b > 0)
			printf("-%.2f ", b);
		printf("+ i√(%.2f)\033[0m\n\t%.2f\n\n", -disc * racine_disc_reduce * racine_disc_reduce, a*2);
		printf("x2 = \033[4m");
		if (b < 0)
			printf("%.2f ", -b);
		else if (b > 0)
			printf("-%.2f ", b);
		printf("+ i√(%.2f * %.2f)\033[0m\n\t%.2f\n\n", racine_disc_reduce * racine_disc_reduce, -disc, a*2);
		printf("x2 = \033[4m");
		if (b < 0)
			printf("%.2f ", -b);
		else if (b > 0)
			printf("-%.2f ", b);
		printf("+ i%.2f√(%.2f)\033[0m\n\t%.2f\n\n", racine_disc_reduce, -disc, a*2);
	}
	printf("x2 = ");
	if (b / (2 * a) < 0)
		printf("%.2f ", -b / (2 * a));
	else if (b / (2 * a) > 0)
		printf("-%.2f ", b / (2 * a));
	if (racine_disc_reduce / (2 * a) < 0)
		printf("- i%.2f√(%.2f)\n\n", (racine_disc_reduce / abs(2 * a)), -disc);
	else if (racine_disc_reduce > 0)
		printf("+ i%.2f√(%.2f)\n\n", (racine_disc_reduce / (2 * a)), -disc);
	else
		printf("+ i%.2f√(%.2f)\n\n", (1 / (2 * a)), -disc);
}

double			Equation::discriment_zero()
{
	double tmp;
	return (((tmp = (-b) / (2 * a)) >= 0) ? 0.00 : tmp);
}

void			Equation::reducted()
{
	printf("Reducted form : ");
	if (a == 1)
		printf("x² ");
	else if (a == -1)
		printf("-x² ");
	else if (a != 0)
		printf("%.2fx² ", a);
	if (b > 0)
		printf("+%.2fx ", b);
	else if (b < 0)
		printf("-%.2fx ", -b);
	if (c > 0)
		printf("+%.2f", c);
	else if (c < 0)
		printf("-%.2f", -c);
	printf(" = 0\n");
}

void			Equation::execpt()
{
	cout << "Reducted form : x = x\nPolynomial degre : " << degre,
	cout << "\nAll number ℝ are solutions.\n";
}

void			Equation::ecrire()
{
	if (degre == 0)
	{
		printf("Invalid equation.\n");
		return;
	}
	printf("a= %.2f, b = %.2f, c = %2.f, degre = %d\n", a, b, c, degre);
	if (a == 0 && b ==0 && c == 0)
		return (execpt());
	reducted();
	if ((degre == 1 && b != 0) || (degre == 2 && a == 0))
		cout << "Polynomial degree: 1\nThe solution is:\n",
		cout << "x = " << unknow() << endl;
	else if (degre == 2)
	{
		cout << "Polynomial degree: 2" << endl << "The solution is:" << endl;
		disc = discriment();
		if (disc > 0)
			cout << "Discriminant is strictly positive, the two solutions are:",
			cout << endl << "x1 = " << discriment_r1(),
			cout <<  "\n\nx2 = " << discriment_r2() << endl;
		else if (disc == 0)
			cout << "Discriminant equals zero, the only one solution is :",
			cout << endl << "x = " << discriment_zero() << endl;
		else if (disc < 0)
		{
			cout << "Discriminant is strictly negative, 2 complex solutions\n",
			complex_reduce();
			// complex_r1();
			// complex_r2();
		}
	}
	else if (degre > 2)
		cout << "Polynomial degree: "<< degre <<"\nThe polynomial degree is"
		"stricly greater than 2, I can't solve.\n";
}
