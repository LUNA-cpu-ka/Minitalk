/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saait-si <saait-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 23:21:47 by saait-si          #+#    #+#             */
/*   Updated: 2024/06/07 23:28:29 by saait-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	send_signal(int pid, char byte)
{
	int	shift;
	int	a;

	shift = 7;
	while (shift >= 0)
	{
		if ((byte >> shift) & 1)
			a = kill(pid, SIGUSR1);
		else
			a = kill(pid, SIGUSR2);
		usleep(400);
		shift--;
		if (a == -1)
			exit(write(2, "Error\n", 6));
	}
}

void ft_recieve(int a)
{
    if (a == SIGUSR2)
        ft_printf("SUCCESS\n");
}

int	main(int argc, char *argv[])
{
	char	*msg;
	int		pid;
	int		i;

	if (argc != 3 || !ft_isdigit(argv[1]))
	{
		ft_printf("CHECK YOUR ARGUMENTS 👾");
		return (0);
	}
	pid = ft_atoi(argv[1]);
	if (0 <= pid && pid <= 10)
	{
		ft_printf("From 0 to 10 are typically reserved by the kernel");
		ft_printf("for special system processes 👾\n");
		return (0);
	}
	msg = argv[2];
	i = -1;
	
	while (msg[++i])
	{
		signal(SIGUSR2, ft_recieve);
		send_signal(pid, msg[i]);
	}
	send_signal(pid, '\0');
	return (0);
}
