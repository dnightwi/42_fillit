/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strupcase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnightwi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 15:10:23 by dnightwi          #+#    #+#             */
/*   Updated: 2019/04/12 15:10:26 by dnightwi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strupcase(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if ((str[i] <= 'z') && (str[i] >= 'a'))
		{
			str[i] -= 32;
		}
		i++;
	}
	return (str);
}
