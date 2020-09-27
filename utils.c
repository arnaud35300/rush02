/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arguilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/27 12:40:19 by arguilla          #+#    #+#             */
/*   Updated: 2020/09/27 18:20:05 by arguilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int		is_number(char c)
{
	return ((c >= '0' && c <= '9'));
}

int		is_space(char c)
{
	return ((c == 32 || (c >= 9 && c <= 13)));
}

int		check_arg(char *str)
{
	int i;
	int check;

	i = 0;
	check = 0;
	while (str[i] != '\0' && is_space(str[i]))
		i++;
	while (str[i] != '\0' && is_number(str[i]))
	{
		check = 1;
		i++;
	}
	while (str[i] != '\0' && is_space(str[i]))
		i++;
	return ((str[i] == '\0' && check) ? 1 : 0);
}

char	*assign_zero(char first, int nb)
{
	char	*str;
	int		i;

	if (!(str = (char*)malloc(sizeof(char) * (nb + 2))))
		return (0);
	i = -1;
	while (++i < (nb + 1))
		str[i] = (i == 0) ? first : '0';
	str[i] = '\0';
	return (str);
}

void 	ft_putstr(char *str)
{
	int i;

	i = -1;
	while(str[++i] != '\0')
		write(1, &str[i], 1);
}
