/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlamothe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/26 14:32:48 by mlamothe          #+#    #+#             */
/*   Updated: 2020/09/27 15:28:41 by arguilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rush.h"
#include "utils.h"
#include <stdio.h>

t_list		*ft_init_list(void)
{
	t_list		*list;
	t_elem		*elem;

	if (!(list = malloc(sizeof(t_list*))))
		return (NULL);
	if (!(elem = malloc(sizeof(t_elem*))))
		return (NULL);
	elem->nbr = "";
	elem->word = "";
	elem->next = NULL;
	list->first = elem;
	return (list);
}

/*int			ft_strlen(char *str)
{
	int i;

	i = 0;
	while (*(str + i) != 0)
		i++;
	return (i);
}*/

void		ft_add_elem(char *text, int *i_lines, t_list *list)
{
	t_elem	*elem;
	t_elem	*actual;

	if (!(elem = malloc(sizeof(t_elem))))
		return ;
	elem->nbr = ft_create_word(text, i_lines[0], (i_lines[1] - i_lines[0]));
	elem->word = ft_create_word(text, i_lines[2], (i_lines[3] - i_lines[2]));
	elem->next = NULL;
	actual = list->first;
	if (actual->nbr[0] == 0)
	{
		list->first = elem;
		return ;
	}
	while (actual->next != NULL)
		actual = actual->next;
	actual->next = elem;
}

void		ft_fill_structs(char *text, t_list *list)
{
	int		i;
	int		*i_lines;

	if (!(i_lines = malloc(4 * sizeof(int))))
		return ;
	i = -1;
	while (text[++i])
	{
		if (text[i] != '\n')
		{
			i_lines = check_line(text, i, i_lines);
			if (i_lines[0] != -1)
				ft_add_elem(text, i_lines, list);
		}
		while (text[i] != '\n')
		{
			++i;
			if (text[i] == 0)
				--i;
		}
	}
}

int			ft_strcmp(char *s1, char *s2)
{
	int i;

	i = 0;
	while (s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	if (s1[i] != 0 || s2[i] != 0)
		return ((unsigned char)s1[i] - (unsigned char)s2[i]);
	return (0);
}

char		*ft_get_word(char *nbr, t_list *list, int flag)
{
	// 215 000
	// 15 000
	if (flag)
		nbr[flag] = '\0';
   	else
		nbr[1] = '\0';
	t_elem	*actual;

	actual = list->first;
	while (actual != NULL)
	{
		if (ft_strcmp(nbr, actual->nbr) == 0)
			return (actual->word);
		actual = actual->next;
	}
	return (0);
}

t_list		*ft_parse_args(char *namefile)
{
	t_list	*list;
	char	*text;

	text = ft_joined_file(namefile);
	list = ft_init_list();
	ft_fill_structs(text, list);
	return (list);
}
