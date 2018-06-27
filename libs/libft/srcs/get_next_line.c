/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-huu- <tle-huu-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/09 15:21:43 by tle-huu-          #+#    #+#             */
/*   Updated: 2018/03/16 14:54:34 by tle-huu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "get_next_line.h"
#include <fcntl.h>
#include <unistd.h>

t_chunk		*new_chunk(int fd, char *str)
{
	t_chunk		*newb;

	if (!(newb = (t_chunk *)ft_memalloc(sizeof(t_chunk))))
	{
		ft_printf("Error allocating memory new chunk\n");
		exit(2);
	}
	newb->fd = fd;
	newb->str = str;
	return (newb);
}

t_list		*get_fd(t_list **list, int fd)
{
	t_list		*tmp;
	t_chunk		*new_chunky;

	if (list)
	{
		tmp = *list;
		while (tmp)
		{
			if (((t_chunk *)tmp->content)->fd == fd)
				return (tmp);
			tmp = tmp->next;
		}
		new_chunky = new_chunk(fd, "\0");
		tmp = ft_lstnew(new_chunky, sizeof(t_chunk));
		free(new_chunky);
		ft_lstadd(list, tmp);
		return (tmp);
	}
	return (NULL);
}

int			check(char *str)
{
	int		i;

	i = 0;
	if (str)
	{
		while (str[i])
		{
			if (str[i] == '\n')
				return (i);
			i++;
		}
	}
	return (-1);
}

void		update(t_list **curr, char **line)
{
	int		index;
	char	*test;

	index = 0;
	index = (check(((t_chunk *)((*curr)->content))->str) == -1) ?
	(int)ft_strlen(((t_chunk *)((*curr)->content))->str)
	: check(((t_chunk *)((*curr)->content))->str);
	test = ((t_chunk *)((*curr)->content))->str;
	ft_strdel(line);
	*line = ft_strsub(((t_chunk *)((*curr)->content))->str, 0, index);
	if (index == (int)(ft_strlen(((t_chunk *)((*curr)->content))->str)))
		ft_strclr(((t_chunk *)((*curr)->content))->str);
	else
	{
		((t_chunk *)((*curr)->content))->str = ft_strsub(test, index + 1,
			(int)ft_strlen(test) - index - 1);
	}
	ft_strdel(&test);
}

int			get_next_line(const int fd, char **line)
{
	static	t_list		*list = NULL;
	t_list				*curr;
	int					reader;
	char				buff[BUFF_SIZE + 1];
	char				*test;

	if (fd < 0 || !line || read(fd, buff, 0) < 0)
		return (-1);
	curr = get_fd(&list, fd);
	while ((reader = read(fd, buff, BUFF_SIZE)))
	{
		buff[reader] = 0;
		test = ((t_chunk *)curr->content)->str;
		if (!(((t_chunk *)curr->content)->str =
		ft_strjoin(((t_chunk *)curr->content)->str, buff)))
			return (-1);
		if (test && test[0])
			free(test);
		if (check(buff) >= 0)
			break ;
	}
	if (reader < BUFF_SIZE && !ft_strlen(((t_chunk *)curr->content)->str))
		return (0);
	update(&curr, line);
	return (1);
}
