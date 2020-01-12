/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_twlistiter.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchau <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 22:30:56 by hchau             #+#    #+#             */
/*   Updated: 2019/04/24 22:31:11 by hchau            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_twlstiter(t_twlist *twlist, void (*f)(t_twlist *elem))
{
	if (!f || !twlist)
		return ;
	while (twlist)
	{
		f(twlist);
		twlist = twlist->next;
	}
}
