/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabasolo <kabasolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 18:36:39 by kabasolo          #+#    #+#             */
/*   Updated: 2025/03/10 13:46:41 by kabasolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# include <pthread.h>

typedef struct s_data
{
	int				philo_num;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				diet;

	int				id;
	int				stop;

	int				*forks;
	pthread_mutex_t	*fork_lock;

	pthread_mutex_t	id_setting;
	pthread_mutex_t	read;
	pthread_mutex_t	write;

}	t_data;

#endif //STRUCTS_H