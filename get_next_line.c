/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbaskhan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 17:05:48 by tbaskhan          #+#    #+#             */
/*   Updated: 2022/02/28 13:54:34 by tbaskhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*	get_line --> return une ligne jusqu'au \n	 */

char	*get_line(char *memo)
{
	int		i;
	char	*s;

	i = 0;
	if (!memo[i])
		return (NULL);
	while (memo[i] && memo[i] != '\n')
		i++;
	s = (char *)malloc((i + 2) * sizeof(char));
	if (!s)
		return (NULL);
	i = 0;
	while (memo[i] && memo[i] != '\n')
	{	
		s[i] = memo[i];
		i++;
	}
	if (memo[i] == '\n')
	{
		s[i] = memo[i];
		i++;
	}
	s[i] = '\0';
	return (s);
}

/*	next_line --> 	 */

char	*next_line(char *memo)
{
	int		i;
	int		j;
	char	*s;

	i = 0;
	while (memo[i] && memo[i] != '\n')
		i++;
	if (!memo[i])
	{
		free(memo);
		return (NULL);
	}
	s = (char *)malloc((ft_strlen(memo) - i + 1) * sizeof(char));
	if (!s)
		return (NULL);
	i ++;
	j = 0;
	while (memo[i])
		s[j++] = memo[i++];
	s[j] = '\0';
	free(memo);
	return (s);
}

/*	read_line -->	*/

char	*read_line(int fd, char *memo)
{
	char	*buff;
	int		rread;

	buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	rread = 1;
	while (!ft_strchr(memo, '\n') && rread != 0)
	{
		rread = read(fd, buff, BUFFER_SIZE);
		if (rread == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[rread] = '\0';
		memo = ft_strjoin(memo, buff);
	}
	free(buff);
	return (memo);
}

/*	get_next_line -->	*/

char	*get_next_line(int fd)
{
	char		*line;
	static char	*memo;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	memo = read_line(fd, memo);
	if (!memo)
		return (NULL);
	line = get_line(memo);
	memo = next_line(memo);
	return (line);
}
