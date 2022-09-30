/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elsie <elsie@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 18:17:42 by elsie             #+#    #+#             */
/*   Updated: 2022/09/30 19:15:30 by elsie            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*free_null(char *str)
{
	free(str);
	return (NULL);
}

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	if (!s)
		return ;
	if (write(fd, s, ft_strlen(s)) == -1)
		return ;
}

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (-1);
	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*res;

	i = -1;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	res = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!res)
		return (free(s1), NULL);
	while (s1[++i])
		res[i] = s1[i];
	while (s2[j])
	{
		res[i] = s2[j];
		i++;
		j++;
	}
	res[i] = 0;
	free(s1);
	return (res);
}

int	find_bsn_or_bso(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (-1);
	while (s[i])
	{
		if (s[i] == '\n' || s[i] == '\0')
			return (1);
		i++;
	}
	return (0);
}
