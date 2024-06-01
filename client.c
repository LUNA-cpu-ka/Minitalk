/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saait-si <saait-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 17:43:11 by saait-si          #+#    #+#             */
/*   Updated: 2024/05/29 10:51:41 by saait-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <stdio.h>
// handling -1 case ;
// handling reserved pid (1 - 10)

int	ft_isdigit(char *str)
{
	while (*str)
	{
		if (*str < '0' || *str > '9')
			return (0);
		str++;
	}
	return (1);
}

int	ft_strncmp(const char *str1, const char *str2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (str1[i] && str2[i] && str1[i] == str2[i] && i < n - 1)
		i++;
	return ((unsigned char)str1[i] - (unsigned char)str2[i]);
}

int	ft_atoi(const char *str)
{
	int		i;
	int		sign;
	long	result;

	i = 0;
	sign = 1;
	result = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] != '\0' && str[i] >= '0' && str[i] <= '9')
	{
		result *= 10;
		result += str[i] - '0';
		i++;
	}
	return (result * sign);
}

void	send_signal(int pid, char byte)
{
	int	shift;

	shift = 7;
	while (shift >= 0)
	{
		if ((byte >> shift) & 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(400);
		shift--;
	}
}
int main(int argc, char *argv[])
{
    char    *msg;
    int     pid;
    int     i;

    if (argc != 3 || !ft_isdigit(argv[1]))
    {
        ft_printf("CHECK YOUR ARGUMENTS 👾");
        return(0);
    }
    pid = ft_atoi(argv[1]);
	if (pid <= '0' && pid <= 10)
	{
		ft_printf("From 0 to 10 are typically reserved by the kernel for special system processes 👾");
		return 0;
	}
    msg = argv[2];
    i = 0;
    while (msg[i])
    {
        send_signal(pid, msg[i]);
        i++;
    }
    return (0);
}
