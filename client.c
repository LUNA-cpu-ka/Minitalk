/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*All Hallows’ Eve Plus
   By: saait-si <saait-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 09:42:13 by saait-si          #+#    #+#             */
/*   Updated: 2024/05/22 10:55:37 by saait-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
bool check_dip(char *dip)
{
    int i;
    i = 0;
    while (dip[i] != '\0')
    {
        while (dip[i] < '0' || dip[i] > '9')
            return false;
        i++;
    }

    return true;
}

int main(int ac, char **av)
{
    char *dip;
    // char *message;
    dip = av[1];
    int pad;
    pad = getpid();
    printf("this is the pad: %d\n", pad);

    if (ac != 3)
        printf("ARGUMENT ERROR 😑");
    else if( !check_dip(dip))
        printf("YOU NEED A DIP code  😑");
    else 
        printf("Koulchi howa hadak ! ✅");
    return(0);
}
