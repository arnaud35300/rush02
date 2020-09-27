/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rush.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlamothe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/26 14:21:22 by mlamothe          #+#    #+#             */
/*   Updated: 2020/09/27 15:26:38 by arguilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_RUSH_H

# define FT_RUSH_H

# include <stdlib.h>

# include <fcntl.h>

# include <unistd.h>

# define NBYTES 2048

typedef struct s_elem	t_elem;
struct	s_elem
{
	char	*nbr;
	char	*word;
	t_elem	*next;
};

typedef struct s_list	t_list;
struct	s_list
{
	t_elem *first;
};


int		ft_strcmp(char *s1, char *s2);

char	*ft_get_word(char *nbr, t_list *list, int flag);

t_list	*ft_parse_args(char *namefile);

int		count_size(int size, char **strs, char *sep);

char	*ft_strjoin(int size, char **strs, char *sep);

char	*ft_joined_file(char *namefile);

char	*ft_create_word(char *str, int i, int size);

int		*check_line(char *text, int i, int *i_lines);
#endif
