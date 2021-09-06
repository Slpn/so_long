/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snarain <snarain@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 21:23:34 by snarain           #+#    #+#             */
/*   Updated: 2021/09/06 01:53:36 by snarain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFFER_SIZE 1

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>

void	savecheck(char *save);

int		get_next_line(int fd, char **line);
int		ft_strchrG(char *s, char c);
int		ft_strlenG(char *s);
int		ft_bzeroG(void *s);

char	*ft_strdupG(char *s);
char	*newline(char *buffer);
char	*ft_strjoinG(char *s1, char *s2);

#endif
