/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_twlistdelone.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchau <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 22:31:42 by hchau             #+#    #+#             */
/*   Updated: 2019/04/24 22:31:56 by hchau            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_twlstdelone(t_twlist **atwlist, void (*del)(void*, size_t))
{
	if (!*atwlist || !atwlist || !del)
		return ;
	del((*atwlist)->content, (*atwlist)->content_size);
	ft_memdel(&(*atwlist)->content);
	free(*atwlist);
	*atwlist = NULL;
}
