/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_twlistmap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchau <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 22:32:13 by hchau             #+#    #+#             */
/*   Updated: 2019/04/24 22:37:42 by hchau            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_twlist		*ft_twlstmap(t_twlist *twlist, t_twlist *(*f)(t_twlist *elem))
{
	t_twlist		*tmp;
	t_twlist		*new;
	t_twlist		*head;

	if (!f || !twlist)
		return (NULL);
	tmp = f(twlist);
	if (!(head = ft_twlstnew(tmp->content, tmp->content_size)))
		return (NULL);
	new = head;
	head->next = new;
	twlist = twlist->next;
	while (twlist)
	{
		tmp = f(twlist);
		if (!(new->next = ft_twlstnew(tmp->content, tmp->content_size)))
		{
			ft_twlstclr(&twlist);
			return (NULL);
		}
		new = new->next;
		twlist = twlist->next;
	}
	return (head);
}
