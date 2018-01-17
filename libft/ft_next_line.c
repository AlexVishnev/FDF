/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_next_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avishnev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 14:12:29 by avishnev          #+#    #+#             */
/*   Updated: 2018/01/17 14:22:26 by avishnev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	t_gnl				*get_next(t_list **lst, const int fd)
{
	t_list			*tmp;
	t_gnl			*data;

	tmp = *lst;
	while (tmp)
	{
		if (((t_gnl *)tmp->content)->fd == fd)
			return ((t_gnl *)tmp->content);
		tmp = tmp->next;
	}
	if (!(data = (t_gnl *)malloc(sizeof(t_gnl *))))
		return (NULL);
	data->buf = ft_strnew(BUFF_SIZE);
	data->fd = fd;
	tmp = ft_lstnew(data, sizeof(t_gnl));
	ft_lstadd(lst, tmp);
	free(data);
	return ((t_gnl *)tmp->content);
}

static	char				**merge_lines(char **line, char *buf)
{
	char			*tmp;

	tmp = ft_strjoin(*line, buf);
	ft_strdel(line);
	*line = ft_strdup(tmp);
	ft_strclr(buf);
	ft_strdel(&tmp);
	return (line);
}

static	int					get_line(t_gnl **p, char **line)
{
	char			*tmp;
	char			*str;
	int				ret;

	tmp = NULL;
	ret = 1;
	while (!(str = ft_strchr((*p)->buf, '\n')) && ret > 0)
	{
		merge_lines(line, (*p)->buf);
		if ((ret = read((*p)->fd, (*p)->buf, BUFF_SIZE)) < 1 && !(**line))
			return (ret);
	}
	if (str && !(tmp = ft_strsub((*p)->buf, 0, str - (*p)->buf)))
		return (-1);
	if (str && !(line = merge_lines(line, tmp)))
		return (-1);
	ft_strdel(&tmp);
	tmp = str ? ft_strdup(str + 1) : ft_strdup("");
	ft_strclr((*p)->buf);
	ft_strcat((*p)->buf, tmp);
	ft_strdel(&tmp);
	return (1);
}

int							ft_next_line(const int fd, char **line)
{
	static t_list	*lst;
	t_gnl			*tmp;
	int				ret;

	if (!line || fd < 0 || !(tmp = get_next(&lst, fd)))
		return (-1);
	*line = ft_strdup("");
	if ((ret = get_line(&tmp, line)) < 1)
		ft_strdel(line);
	return (ret);
}
