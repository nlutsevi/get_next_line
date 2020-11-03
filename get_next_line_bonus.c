/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlutsevi <nlutsevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/14 18:15:47 by nlutsevi          #+#    #+#             */
/*   Updated: 2020/09/17 17:16:34 by nlutsevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int		ft_one_line(char **content, char **line)
{
	*line = ft_strdup(*content);
	free(*content);
	*content = NULL;
	return (0);
}

int		get_new_line(char **content, char **line, int numbytes)
{
	char	*temp;
	char	*temp2;

	if (numbytes < 0)
		return (-1);
	if (numbytes == 0 && !*content)
	{
		*line = ft_strdup("");
		return (0);
	}
	else if ((temp = ft_strchr(*content, '\n')))
	{
		*temp = '\0';
		*line = ft_strdup(*content);
		temp2 = ft_strdup(temp + 1);
		free(*content);
		*content = temp2;
		return (1);
	}
	else if ((ft_strchr(*content, '\0')))
	{
		ft_one_line(&*content, &*line);
	}
	return (0);
}

int		get_next_line(int fd, char **line)
{
	static char		*content[FD_SIZE];
	char			*buff;
	char			*temp;
	int				numbytes;

	if ((fd < 0 || line == NULL || BUFF_SIZE < 0 || \
		(!(buff = (char*)malloc(sizeof(char) * (BUFF_SIZE + 1))))))
		return (-1);
	while ((numbytes = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[numbytes] = '\0';
		if (!(content[fd]))
			content[fd] = ft_strdup(buff);
		else
		{
			temp = ft_strjoin(content[fd], buff);
			free(content[fd]);
			content[fd] = temp;
		}
		if (ft_strchr(buff, '\n'))
			break ;
	}
	free(buff);
	buff = NULL;
	return (get_new_line(&content[fd], &*line, numbytes));
}
