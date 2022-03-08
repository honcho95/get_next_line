/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbaskhan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 14:09:21 by tbaskhan          #+#    #+#             */
/*   Updated: 2022/02/21 14:55:54 by tbaskhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

char		*get_line(char *memo);
char		*next_line(char *memo);
char		*read_line(int fd, char *memo);
char		*get_next_line(int fd);
char		*ft_strchr(char *s, int c);
char		*ft_strjoin(char *s1, char *s2);
size_t		ft_strlen(char *str);

#endif
