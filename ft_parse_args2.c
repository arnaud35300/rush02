/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_args2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlamothe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/27 12:28:37 by mlamothe          #+#    #+#             */
/*   Updated: 2020/09/27 12:40:01 by mlamothe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rush.h"

int			count_size(int size, char **strs, char *sep)
{
	int smax;
	int i;
	int j;

	smax = 0;
	i = -1;
	if (size <= 0)
		return (1);
	while (++i < size && strs[i] != NULL)
	{
		j = -1;
		while (strs[i][++j])
			++smax;
	}
	i = -1;
	j = 0;
	while (sep[++i])
		j++;
	smax = smax + ((size - 1) * j) + 1;
	return (smax);
}

char		*ft_strjoin(int size, char **strs, char *sep)
{
	char	*joined;
	int		mot;
	int		lettre;
	int		i;

	if (!strs || !sep ||
		(!(joined = malloc(count_size(size, strs, sep) * sizeof(char)))))
		return (NULL);
	mot = -1;
	i = -1;
	while (++mot < size && strs[mot] != NULL)
	{
		lettre = -1;
		while (strs[mot][++lettre])
			joined[++i] = strs[mot][lettre];
		lettre = -1;
		while (mot < size - 1 && sep[++lettre] && strs[mot + 1] != NULL)
			joined[++i] = sep[lettre];
	}
	joined[i + 1] = 0;
	return (joined);
}

char		*ft_joined_file(char *namefile)
{
	int		i;
	int		j;
	int		file;
	char	buf[NBYTES];
	char	**joined;

	if ((file = open(namefile, O_RDONLY)) == -1)
		return (0);
	i = 0;
	while (read(file, buf, NBYTES))
		++i;
	if (!(joined = malloc(i * sizeof(char *))))
		return (NULL);
	close(file);
	if ((file = open(namefile, O_RDONLY)) == -1)
		return (0);
	j = 0;
	while (read(file, buf, NBYTES))
	{
		joined[j] = buf;
		++j;
	}
	return (ft_strjoin(j, joined, ""));
}

char		*ft_create_word(char *str, int i, int size)
{
	char	*word;
	int		j;

	if (!(word = malloc((size + 1) * sizeof(char))))
		return (NULL);
	j = -1;
	while (++j < size)
	{
		word[j] = str[i];
		++i;
	}
	return (word);
}

int			*check_line(char *text, int i, int *i_lines)
{
	while (text[i] != '\n')
	{
		i_lines[0] = i;
		while (text[i] >= '0' && text[i] <= '9')
			++i;
		i_lines[1] = i;
		while (text[i] == ' ')
			++i;
		if (text[i] == ':')
			++i;
		else
			i_lines[0] = -1;
		while (text[i] == ' ')
			++i;
		i_lines[2] = i;
		while (text[i] >= 32 && text[i] <= 126)
			++i;
		if (text[i] != '\n')
			i_lines[0] = -1;
		else
			i_lines[3] = i;
	}
	return (i_lines);
}
