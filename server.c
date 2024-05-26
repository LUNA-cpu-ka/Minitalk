/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saait-si <saait-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 09:47:10 by saait-si          #+#    #+#             */
/*   Updated: 2024/05/26 14:49:03 by saait-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
void function(int end)
{
    static int bit;
    static char character;
    
    bit <<= 1;
    if (end == SIGUSR1)
        character |= 1;
    bit++;
    while (bit == 8)
    {
        write(1,&character,1);
        bit = 0;
        character = 0;
    }
}
int main()
{
    int pid;
    pid = getpid();
    printf("YOUR CLIENT PID'S: %d\n", pid);
    printf("Please wait for client to write the message for you 👻\n");
    signal(SIGUSR1, function);
    signal(SIGUSR2, function);
    
    while (1)
    {
        pause();
    }
    
    return(0);
}