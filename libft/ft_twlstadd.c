/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_twlistadd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchau <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 22:28:43 by hchau             #+#    #+#             */
/*   Updated: 2019/04/24 22:29:03 by hchau            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_twlstadd(t_twlist **alltwlist, t_twlist *new)
{
	if (!alltwlist || !new)
		return ;
	if (*alltwlist == NULL)
		new->next = NULL;
	else
	{
		new->next = *alltwlist;
		(*alltwlist)->prev = new;
	}
	*alltwlist = new;
}
