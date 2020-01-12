/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_twlistclr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchau <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 22:30:06 by hchau             #+#    #+#             */
/*   Updated: 2019/04/24 22:35:47 by hchau            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_twlstclr(t_twlist **alltwlist)
{
	t_twlist		*temp;

	temp = *alltwlist;
	if (!*alltwlist)
		return ;
	while (*alltwlist)
	{
		temp = (*alltwlist)->next;
		free(*alltwlist);
		*alltwlist = NULL;
		*alltwlist = temp;
	}
	free(alltwlist);
	alltwlist = NULL;
}
