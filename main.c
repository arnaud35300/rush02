/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arguilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/27 13:41:56 by arguilla          #+#    #+#             */
/*   Updated: 2020/09/27 16:07:26 by arguilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_rush.h"
#include "utils.h"

char *concatenate(char a, char b)
{
	char *str;
	if (!(str = (char*)malloc(sizeof(char) * 3)))
		return (0);
	str[0] = a;
	str[1] = b;
	str[2] = '\0';
	return (str);
}

int main(int argc, char **argv)
{
	if (argc != 2 && argc != 3)
		return (0);	
	if (!check_arg(((argc == 2 ) ? argv[1] : argv[2])))
		return (0);
	t_list *list;
	if (argc == 2)
		list = ft_parse_args("./numbers.dict.txt");
	if (argc == 3)
		list = ft_parse_args(argv[1]);

	//printf("%s\n", ft_get_word("5", list));
	//return (0);

	char *str;
	str = (argc = 2) ? argv[1] : argv[2];
	unsigned long  i;
	int j = 0;
	int k;
	int f = 0;
	unsigned long len;
	k = 0;
	len = ft_strlen(str);
	i = ft_strlen(str);
	int check;
	check = 0;
	while (i-- > 0)
	{
		j++;
		k++;
		if (k > 3)
		{
			f++;
			k = 1;
		}

//		if (len('1' + j * '0') > struct_len(max))
//			return (error);
		// gestion de la premiere centaine
			// si premier caractere est different de 0 et que le caractere d'apres n'est pas 1
			// TODO : verifier que str[i -1] soit possible
			// exemple : if (i - 1) == 0

			// gerer le 0 de base
			// if (strlen(1) && str[i] == '0')
			// 		echo 'zero';
			if (f)	
				printf("%s\n", ft_get_word(assign_zero('1', (f * 3)), list, ((f * 3) + 1)));
				 // find(1 + (f * 3)) ---> f * 3 == nombre de zero

			if (ft_strlen(str) == 1 && str[i] == '0')
				printf("%s\n", ft_get_word(&str[i], list, 0));

			if (k == 1 && str[i] != '0' && str[i - 1] != '1')
			{
				printf("%s\n", ft_get_word(&str[i], list, 0));
			}
			if (k == 2 && str[i] != '0' && str[i] != '1')
			{
				printf("%s\n", ft_get_word(assign_zero(str[i], 1), list, 2));
			}
			if (k == 2 && str[i] == '1')
			{
				printf("%s\n", ft_get_word(concatenate(str[i], str[i + 1]), list, 2));	
			}
			if (k == 3)
			{
				printf("%s\n", ft_get_word(assign_zero('1', 2), list, 3));
				printf("%s\n", ft_get_word(&str[i], list, 0));
			}
	}
}
