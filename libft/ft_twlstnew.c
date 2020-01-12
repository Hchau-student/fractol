/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_twlistnew.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchau <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 22:33:23 by hchau             #+#    #+#             */
/*   Updated: 2019/04/24 22:40:27 by hchau            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_twlist			*ft_twlstnew(void const *content, size_t content_size)
{
	t_twlist		*newlist;

	if (!(newlist = (t_twlist*)malloc(sizeof(t_twlist))))
		return (NULL);
	if (content == NULL)
	{
		newlist->content_size = 0;
		newlist->content = NULL;
	}
	else
	{
		if (!(newlist->content = malloc((sizeof(content)) * (content_size))))
		{
			free(newlist);
			newlist = NULL;
			return (NULL);
		}
		newlist->content_size = content_size;
		newlist->content = ft_memcpy(newlist->content, content, content_size);
		newlist->content_size = content_size;
	}
	newlist->next = NULL;
	newlist->prev = NULL;
	return (newlist);
}
