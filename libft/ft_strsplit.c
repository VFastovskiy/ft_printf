/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blakeish <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 22:47:59 by blakeish          #+#    #+#             */
/*   Updated: 2019/09/23 22:41:50 by blakeish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int			ft_wordz(const char *str, char c)
{
	int w;

	w = 0;
	while (*str)
	{
		while (*str == c)
			str++;
		while (*str != c && *str)
			str++;
		w++;
	}
	return (w);
}

static int			ft_len(const char *str, char c)
{
	int count;

	count = 0;
	while (*str != c && *str)
	{
		count++;
		str++;
	}
	return (count);
}

static char			**ft_str_free(char **arr, int j)
{
	int i;

	i = 0;
	while (i < j)
		free(arr[i]);
	free(arr);
	return (NULL);
}

char				**ft_strsplit(char const *s, char c)
{
	int		j;
	int		i;
	char	**arr;

	j = 0;
	i = 0;
	if (!s || (!(arr = (char **)malloc(sizeof(char *) * (ft_wordz(s, c) + 1)))))
		return (NULL);
	while (*s)
	{
		while (*s == c && *s)
			s++;
		if (*s != c && *s)
		{
			if (!(arr[j] = (char *)malloc(sizeof(char) * (ft_len(s, c) + 1))))
				return (ft_str_free(arr, j));
			while (*s && *s != c)
				arr[j][i++] = (char)*s++;
			arr[j][i] = '\0';
			j++;
			i = 0;
		}
	}
	arr[j] = NULL;
	return (arr);
}
