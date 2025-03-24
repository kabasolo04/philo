/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabasolo <kabasolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 14:00:55 by kabasolo          #+#    #+#             */
/*   Updated: 2025/03/24 12:17:36 by kabasolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	wait_fork(int id, int fork_id, t_data *data, int last_meal)
{
	pthread_mutex_lock(&data->fork_lock[fork_id]);
	pthread_mutex_lock(&data->read);
	while (data->stop == 0 && !take_fork(id, fork_id, data))
	{
		pthread_mutex_unlock(&data->fork_lock[fork_id]);
		pthread_mutex_unlock(&data->read);
		usleep(900);
		status(data, last_meal, id);
		pthread_mutex_lock(&data->fork_lock[fork_id]);
		pthread_mutex_lock(&data->read);
	}
	pthread_mutex_unlock(&data->fork_lock[fork_id]);
	pthread_mutex_unlock(&data->read);
}

int	take_fork(int id, int fork_id, t_data *data)
{
	if (data->forks[fork_id])
	{
		data->forks[fork_id] = 0;
		printf("%d %d has taken a fork\n", my_time(), id);
		return (1);
	}
	return (0);
}

void	leave_fork(int fork_id, t_data *data)
{
	pthread_mutex_lock(&data->fork_lock[fork_id]);
	data->forks[fork_id] = 1;
	pthread_mutex_unlock(&data->fork_lock[fork_id]);
}

int	eat(int id, t_data *data, int last_meal)
{
	mod_print(id, "is eating", data);
	last_meal = my_time();
	zzz(data->time_to_eat, data, last_meal, id);
	return (last_meal);
}
