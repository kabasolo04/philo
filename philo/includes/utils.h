/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabasolo <kabasolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 18:28:39 by kabasolo          #+#    #+#             */
/*   Updated: 2024/09/02 16:41:50 by kabasolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <string.h>    // memset
# include <stdio.h>     // printf
# include <stdlib.h>    // malloc, free
# include <unistd.h>    // write, usleep
# include <sys/time.h>  // gettimeofday

# define SET 0
# define GET 1

void		mod_print(int id, char *line, t_data *data);
void		status(t_data *data, long int last_meal, int id);
long int	my_time(int mood, t_data *data);
int			ft_atoi(char *line);

#endif //UTILS_H