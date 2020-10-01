/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float_round_d_ld.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blakeish <blakeish@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/03 12:44:51 by kcharlet          #+#    #+#             */
/*   Updated: 2020/08/03 20:25:58 by blakeish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	float_round_one(char *ftoa_a, int **i, t_round *p)
{
	if (ftoa_a[p->x] == '9')
	{
		while (ftoa_a[p->x] == '9')
		{
			++p->r;
			ftoa_a[p->x] = '0';
			--p->x;
		}
		p->x >= 0 ? ftoa_a[p->x] += 1 : 1;
		if (ftoa_a[0] == '0' && p->r == p->d)
			**i = 1;
	}
	else
	{
		while (ftoa_a[(p->x) - 1] == '9')
		{
			++p->r;
			ftoa_a[(p->x) - 1] = '0';
			--p->x;
		}
		p->x >= 1 ? ftoa_a[(p->x) - 1] += 1 : 1;
		if (ftoa_a[0] == '0' && p->r == p->d - 1)
			**i = 1;
	}
}

void	float_round(char *ftoa_a, int *i, int fprec)
{
	t_round		p;

	p.r = 0;
	p.d = ft_strlen(ftoa_a);
	p.x = p.d - 1;
	if (ftoa_a[p.d - 1] >= '5' && ftoa_a[p.d - 1] <= '9' && fprec > 0)
		float_round_one(ftoa_a, &i, &p);
	else if (ftoa_a[p.d - 1] >= '5' && ftoa_a[p.d - 1] <= '9' && fprec == 0)
		*i = 1;
	p.d == 1 && ftoa_a[0] == '5' ? *i = 3 : 1;
	ftoa_a[p.d] = '\0';
}
