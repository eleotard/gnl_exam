/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elsie <elsie@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 16:26:10 by elsie             #+#    #+#             */
/*   Updated: 2022/09/30 18:50:28 by elsie            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

//# define BUFFER_SIZE

char	*get_next_line(int fd);
char	*free_null(char *str);
void	ft_putstr_fd(char *s, int fd);
int		ft_strlen(char *s);
char	*ft_strjoin(char *s1, char *s2);
int		find_bsn_or_bso(char *s);

#endif