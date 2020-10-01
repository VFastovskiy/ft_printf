/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_analyze_flags.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcharlet <kcharlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/03 11:56:33 by kcharlet          #+#    #+#             */
/*   Updated: 2020/08/03 18:25:29 by kcharlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	analyze_sum(t_print *printf, va_list *ap, char **c)
{
	printf->flags = analyze_flags(c);
	printf->width = analyze_width(c, ap);
	printf->precision = analyze_precision(c, ap);
	printf->length = analyze_length(c);
}

int		analyze_precision(char **str, va_list *ap)
{
	t_prec pr;

	pr.i = 0;
	if (str[0][0] != '.')
		return (-1);
	(*str)++;
	if ((*str)[0] == '*')
	{
		(*str)++;
		return (va_arg(*ap, int));
	}
	if (ft_isalpha((*str)[0]) || (*str)[0] == 0)
		return (0);
	while (ft_isdigit((*str)[pr.i]))
		pr.i++;
	pr.res = ft_strnew(pr.i + 1);
	pr.tmp = pr.res;
	if (!pr.res)
		return (-1);
	pr.res = ft_strsub(*str, 0, pr.i);
	free(pr.tmp);
	pr.result = ft_atoi(pr.res);
	free(pr.res);
	*str = &((*str)[pr.i]);
	return (pr.result);
}

int		analyze_width(char **width, va_list *ap)
{
	t_width wt;

	ft_init(width, &wt);
	if ((wt.str)[wt.i] == '*' && ft_isdigit(wt.str[wt.i + 1]) == 0)
	{
		(*width)++;
		return (va_arg(*ap, int));
	}
	else if ((wt.str)[wt.i] == '*' && ft_isdigit(wt.str[wt.i + 1]) == 1)
	{
		(*width)++;
		wt.w++;
		wt.skip = (va_arg(*ap, int));
	}
	while (ft_isdigit(**width))
	{
		++*width;
		wt.i++;
	}
	wt.str = ft_strsub(wt.str, wt.w, wt.i);
	(ft_strlen(wt.str) > 0) ? (wt.w = ft_atoi(wt.str)) : 0;
	free(wt.tmp);
	ft_strdel(&wt.str);
	return (wt.w);
}

char	*analyze_flags(char **flags)
{
	t_flags		fl;
	char		*str;
	char		*str2;

	fl.i = 0;
	fl.y = 0;
	str2 = *flags;
	while (str2[fl.i] == '#' || str2[fl.i] == '-' || str2[fl.i] == '0' \
							|| str2[fl.i] == '+' || str2[fl.i] == ' ')
		fl.i++;
	str = ft_strnew(fl.i);
	while (**flags == '#' || **flags == '-' || **flags == '0' \
							|| **flags == '+' || **flags == ' ')
	{
		fl.s = **flags;
		if (ft_strchr(str, fl.s) == NULL)
			str[fl.y++] = fl.s;
		++*flags;
	}
	str[fl.y] = '\0';
	return (str);
}

int		analyze_length(char **str)
{
	int i;

	i = 0;
	if ((*str)[0] == 'h' && (*str)[1] == 'h')
	{
		*str = *str + 2;
		i = 1;
	}
	else if ((*str)[0] == 'h' && (*str)[1] != 'h')
	{
		(*str)++;
		i = 2;
	}
	else if ((*str)[0] == 'l' && (*str)[1] == 'l')
	{
		*str = *str + 2;
		i = 3;
	}
	else
		i = analyze_length_add(str);
	return (i);
}
