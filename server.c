/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saait-si <saait-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 09:47:10 by saait-si          #+#    #+#             */
/*   Updated: 2024/06/07 23:22:32 by saait-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	function(int sig_endm, siginfo_t *info, void *vp)
{
	static int	bit;
	static char	character;
	static int	pid;

	(void)vp;
	if (pid != info->si_pid)
	{
		bit = 0;
		character = 0;
		pid = info->si_pid;
	}
	character <<= 1;
	if (sig_endm == SIGUSR1)
		character |= 1;
	bit++;
	if (character && bit == 8)
	{
		write(1, &character, 1);
		bit = 0;
		character = 0;
	}
}

int	main(void)
{
	int					pid;
	struct sigaction	sig;

	sig.sa_sigaction = function;
	sig.sa_flags = SA_SIGINFO;
	pid = getpid();
	ft_printf("YOUR SERVER PID'S: %d\n", pid);
	ft_printf("Please wait for client to write the message for you 👻\n");
	sigaction(SIGUSR1, &sig, NULL);
	sigaction(SIGUSR2, &sig, NULL);
	while (1)
		pause();
	return (0);
}
