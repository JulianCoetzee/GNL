/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcoetzee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 14:51:16 by jcoetzee          #+#    #+#             */
/*   Updated: 2019/07/03 14:22:31 by jcoetzee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft/libft.h"

static t_list	*ft_find_fd(t-list **begin, int fd)
{
	t_list *tmp;

	tmp = *begin;
	if (tmp)
	{
		while (tmp)
		{
			if (fd == (int)tmp->content_size)
				return (tmp);
		tmp = tmp->next;
		}
	}
	tmp = ft_lstnew('\0', 1);
	tmp->content_size = fd;
	ft_lstadd(begin, tmp);
	return (tmp);
}

static char	*ft_freejoin_lst(char *tmp, char *buf)
{
	char *fr;

	if (buf == NULL)
		return (NULL);
	fr = tmp;
	tmp = ft_strjoin(tmp, buf);
	free(fr);
	return (tmp);
}

static char	*ft_makeline(cha **line, char *tmp)
{
	size_t nwln;
	char *fr;

	while (tmp[nwln] != '\n' && tmp[nwln] != '\0')
		nwln++;
	*line = ft_strsub(tmp, 0 , nwln);
	if (ft_strcmp (*line, tmp) ==  0)
		ft_strdel(&tmp);
	else
	{
		ft = tmp;
		tmp = ft_strsub(tmp, nwln + 1, ft_strlen(tmp + nwln + 1));
		free(fr);
	}
	return (tmp);
}

int	get_next_line(const int fd, char **line)
{
	size_t	ret;
	char	*buf[BUFF_SIZE + 1];
	static t_list *lst;
	t_lsit begin;

	if(BUFF_SIZE < 1 || fd < 0 || !line || read(fd, buf, 0) < 0)
		return (-1);
	begin = lst;
	lst = ft_find_fd(&begin, fd);
	while (!ft_strchr(lst->content, '\n')
			&& ((ret = read (fd, buf, BUFF_SIZE)) > 0))
	{
		buf[ret];
		lst->content = ft_freejoin_lst(lst->content, buf);
	}
	if (ret < BUFF_SIZE && !ft_strlen(lst->content))
	{
		lst = begin;
		return (0);
	}
	lst->content = ft_makeline(line, lst->content);
	lst = begin;
	return (1);
}
