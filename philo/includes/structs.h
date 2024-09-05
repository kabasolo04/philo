/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabasolo <kabasolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 18:36:39 by kabasolo          #+#    #+#             */
/*   Updated: 2024/09/03 17:23:31 by kabasolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# include <pthread.h> // pthread_* (funciones de hilos y mutex)

typedef struct s_data
{
	int				philo_num;
	long int		time_to_die;
	long int		time_to_eat;
	long int		time_to_sleep;
	int				diet;

	int				id;
	int				finish;

	int				*status;
	int				*forks;

	pthread_mutex_t	id_setting;
	pthread_mutex_t	time;
	pthread_mutex_t	stat_lock;
	pthread_mutex_t	god_doing_stuff;
	pthread_mutex_t	edit_fork;
	pthread_mutex_t	*fork_lock;
}	t_data;

#endif //STRUCTS_H