/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchau <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 22:30:06 by hchau             #+#    #+#             */
/*   Updated: 2019/04/24 22:35:47 by hchau            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclr(t_list **alst)
{
	t_list		*temp;

	temp = *alst;
	if (!*alst)
		return ;
	while (*alst)
	{
		temp = (*alst)->next;
		free(*alst);
		*alst = NULL;
		*alst = temp;
	}
	free(alst);
	alst = NULL;
}
