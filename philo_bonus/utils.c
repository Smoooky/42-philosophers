/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sstyr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 13:41:59 by sstyr             #+#    #+#             */
/*   Updated: 2021/12/02 13:42:00 by sstyr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

size_t	ft_strlen(const char *s)
{
	register const char	*str;

	str = s;
	while (*s)
		++s;
	return (s - str);
}

void	ft_putnbr_fd(unsigned long long n, int fd)
{
	char	str[13];
	int		length;

	if (n == 0)
		str[0] = '0';
	length = 0;
	while (n != 0)
	{
		str[length++] = '0' + (n % 10);
		n = (n / 10);
	}
	if (length > 0)
		length--;
	while (length >= 0)
		write(fd, &str[length--], 1);
}

size_t	ft_strcpy(char *dst, const char *src)
{
	size_t	i;

	i = 0;
	while (src[i] != '\0' )
	{
		dst[i] = src[i];
		++i;
	}
	dst[i] = '\0';
	return (i);
}

unsigned long long	get_time(void)
{
	static struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * (uint64_t)1000) + (tv.tv_usec / 1000));
}
