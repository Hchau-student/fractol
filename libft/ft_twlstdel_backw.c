/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_twlstdel_backw.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchau <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 21:37:45 by hchau             #+#    #+#             */
/*   Updated: 2019/10/30 21:37:47 by hchau            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_twlstdel_backw(t_twlist **alltwlist, void (*del)(void *, size_t))
{
	t_twlist		*temp;

	if (!*alltwlist || !alltwlist || !del)
		return ;
	while (*alltwlist)
	{
		temp = (*alltwlist)->prev;
		del((*alltwlist)->content, (*alltwlist)->content_size);
		ft_memdel(&(*alltwlist)->content);
		free((*alltwlist)->content);
		free(*alltwlist);
		*alltwlist = NULL;
		*alltwlist = temp;
	}
}
