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
	if (pid <= '1' && pid <= 10)
	{
		ft_printf("From 1 to 10 are typically reserved by the kernel for special system processes 👾");
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
