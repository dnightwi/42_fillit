/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnightwi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 15:53:29 by dnightwi          #+#    #+#             */
/*   Updated: 2019/04/04 18:19:37 by dnightwi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	ft_bzero(void *s, size_t n)
{
	char	*arr;
	size_t	i;

	arr = (char *)s;
	i = 0;
	while (i < n)
	{
		arr[i] = 0;
		i++;
	}
}
