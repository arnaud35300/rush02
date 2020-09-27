/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cut_str.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arguilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/27 18:15:55 by arguilla          #+#    #+#             */
/*   Updated: 2020/09/27 18:22:19 by arguilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "utils.h"

int		get_tab_len(int str_len)
{
	int len;

	len = 1;
	while (str_len - 3 > 0)
	{
		str_len -= 3;
		len++;
	}
	return (len);
}

void	check_modulo(int str_len, char *item, int i)
{
	if (i == 0)
	{
		if (str_len % 3 == 2)
			item[2] = '\0';
		if (str_len % 3 == 1)
			item[1] = '\0';
	}
}

void	assign_tab_value(char *tab, char *str, int k)
{
	tab[k] = *str;
	(*str)++;
}

char	**cut_str(char *str)
{
	char	**tab;
	int		str_len;
	int		tab_len;
	int		i;
	int		k;

	i = -1;
	str_len = ft_strlen(str);
	tab_len = get_tab_len(str_len);
	if (!(tab = malloc(sizeof(char*) * (tab_len + 1))))
		return (0);
	if (!(tab[tab_len] = malloc(sizeof(char) * 1)))
		return (0);
	tab[tab_len][0] = '\0';
	while (++i < tab_len)
	{
		if (!(tab[i] = malloc(sizeof(char) * 4)))
			return (0);
		tab[i][3] = '\0';
		check_modulo(str_len, tab[i], i);
		k = -1;
		while (*str && tab[i][++k] != '\0')
			assign_tab_value(tab[i], str, k);
	}
	return (tab);
}
