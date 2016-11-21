/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palatorr <palatorr@student.42.us.or>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/14 22:03:01 by palatorr          #+#    #+#             */
/*   Updated: 2016/10/14 22:03:02 by palatorr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_realloc(void *src, size_t srcsize, size_t newsize)
{
	void	*ret;

	if (!src)
		return (ft_memalloc(newsize));
	ret = ft_memalloc(newsize);
	ft_memcpy(ret, src, newsize > srcsize ? srcsize : newsize);
	free(src);
	return (ret);
}
