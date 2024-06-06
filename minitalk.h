/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saait-si <saait-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 17:41:31 by saait-si          #+#    #+#             */
/*   Updated: 2024/06/06 01:58:29 by saait-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <stdio.h>
# include <unistd.h>
# include <signal.h>
# include <stdbool.h>
# include <stdlib.h>
# include "pri/ft_printf.h"
# include <ctype.h>

int	ft_atoi(const char *str);
int	ft_isdigit(char *str);

#endif