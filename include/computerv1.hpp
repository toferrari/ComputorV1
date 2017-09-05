/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   computerv1.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tferrari <tferrari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/22 18:05:46 by tferrari          #+#    #+#             */
/*   Updated: 2017/09/05 16:02:33 by tferrari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMPUTERV1_HPP
# define COMPUTERV1_HPP

#include <iostream>
#include <string>
#include <math.h>
#include <sstream>
#include <vector>
#include <stdlib.h>
#include <stdio.h>

#define DEGRE		equa.degre
#define TMP			equa.tmp

using namespace std;

class Equation
{
public:

	Equation();
	int				check_nb(string str, int lr);
	int				check_star(string str, int lr, int *i);
	int				check_x(string str, int lr, int *i);
	int				check_transition(string str, int lr);
	double			discriment(double a, double b, double c);
	double			unknow(double a, double b);
	double			discriment_r1(double a, double b, double disc);
	double			discriment_r2(double a, double b, double disc);
	double			discriment_zero(double a, double b);
	void			ecrire();

private:

	double		la;
	double		lb;
	double		lc;
	double		ra;
	double		rb;
	double		rc;
	double		tmp;
	int			signe;
	int			degre;
	int			rdegre;
	int			ldegre;
	double		disc;
	double		r1;
	double		r2;
};

#endif