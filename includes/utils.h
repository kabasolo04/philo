/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabasolo <kabasolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 18:28:39 by kabasolo          #+#    #+#             */
/*   Updated: 2025/03/24 12:19:25 by kabasolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <string.h>    // memset
# include <stdio.h>     // printf
# include <stdlib.h>    // malloc, free
# include <unistd.h>    // write, usleep
# include <sys/time.h>  // gettimeofday

void	status(t_data *data, int last_meal, int id);
void	zzz(int ms, t_data *data, int last_meal, int id);
int		mod_print(int id, char *line, t_data *data);
int		my_time(void);

int		parsing(int argc, char **argv, t_data *data);
int		freedom(t_data *data);

#endif //UTILS_H