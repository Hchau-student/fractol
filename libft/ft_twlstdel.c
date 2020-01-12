/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_twlistdel.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchau <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 22:32:58 by hchau             #+#    #+#             */
/*   Updated: 2019/04/24 22:36:32 by hchau            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_twlstdel(t_twlist **alltwlist, void (*del)(void *, size_t))
{
	t_twlist		*temp;

	if (!*alltwlist || !alltwlist || !del)
		return ;
	while (*alltwlist)
	{
		temp = (*alltwlist)->next;
		del((*alltwlist)->content, (*alltwlist)->content_size);
		ft_memdel(&(*alltwlist)->content);
		free(*alltwlist);
		*alltwlist = NULL;
		*alltwlist = temp;
	}
}
