/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elsie <elsie@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 16:22:35 by elsie             #+#    #+#             */
/*   Updated: 2022/09/30 19:10:22 by elsie            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*cpy_line_2(char *line, char *next_line)
{
	int	i;

	i = 0;
	while (next_line[i] && next_line[i] != '\n')
	{
		line[i] = next_line[i];
		i++;
	}
	if (next_line[i] == 0)
		line[i] = 0;
	else if (next_line[i] == '\n')
	{
		line[i] = '\n';
		i++;
		line[i] = 0;
	}
	return (line);
}

char	*cpy_line(char *next_line)
{
	char	*line;
	int		i;
	char	fin;

	i = 0;
	if (!next_line)
		return (NULL);
	while (next_line[i])
	{
		if (next_line[i] == '\n')
			break ;
		i++;
	}
	fin = next_line[i];
	if (fin == 0)
		line = malloc(sizeof(char) * (i + 1));
	else if (fin == '\n')
		line = malloc(sizeof(char) * (i + 2));
	if (!line)
		return (NULL);
	line = cpy_line_2(line, next_line);
	return (line);
}

char	*cpy_after_bsn(char *tmp, char *next_line, char end)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (next_line[i] && next_line[i] != '\n')
		i++;
	if (end == '\n')
		i++;
	while (next_line[i])
	{
		tmp[j] = next_line[i];
		i++;
		j++;
	}
	tmp[j] = 0;
	return (tmp);
}

char	*keep_the_rest(char *next_line)
{
	char	*tmp;
	int		i;
	int		j;
	char	end;

	i = 0;
	j = 0;
	if (!next_line)
		return (NULL);
	while (next_line[i] && next_line[i] != '\n')
		i++;
	end = next_line[i];
	j = ft_strlen(next_line) - i;
	if (end == 0)
		return (NULL);
	else if (end == '\n')
		tmp = malloc(sizeof(char) * j);
	if (!tmp)
		return (NULL);
	tmp = cpy_after_bsn(tmp, next_line, end);
	free(next_line);
	return (tmp);
}

char	*get_next_line(int fd)
{
	int				n;
	char			buff[BUFFER_SIZE + 1];
	static char		*next_line;
	char			*line;

	n = 1;
	if (fd < 0 || BUFFER_SIZE < 0)
		return (NULL);
	if (!next_line)
	{
		next_line = malloc(sizeof(char));
		if (!next_line)
			return (NULL);
		next_line[0] = '\0';
	}
	while (n > 0 && find_bsn_or_bso(next_line) != 1)
	{
		n = read(fd, buff, BUFFER_SIZE);
		buff[n] = '\0';
		next_line = ft_strjoin(next_line, buff);
		if (!next_line)
			return (NULL);
	}
	if (next_line[0] == '\0')
		return (next_line = free_null(next_line), NULL);
	line = cpy_line(next_line);
	if (!line)
		return (next_line = free_null(next_line), NULL);
	next_line = keep_the_rest(next_line);
	if (!next_line)
		return (line = free_null(line), NULL);
	return (line);
}

/*int	main(void)
{
	char	*line;
	int		fd;
	
	fd = open("test.txt", O_RDONLY);
	if (fd <= 2)
		return (ft_putstr_fd("Erreur fd\n", 2), 1);
	line = NULL;
    line = get_next_line(fd);
	while (line != NULL)
	{
		printf("%s", line);
		line = free_null(line);
		line = get_next_line(fd);
	}
	if (line)
		line = free_null(line);
	return (0);
}*/