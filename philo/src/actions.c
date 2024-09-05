/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabasolo <kabasolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 14:00:55 by kabasolo          #+#    #+#             */
/*   Updated: 2024/09/04 13:28:09 by kabasolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	zzz(long int ms, t_data *data, long int last_meal, int id)
{
	long int	time;

	time = my_time(GET, data);
	if (time - last_meal + ms > data->time_to_die)
	{
		usleep(((data->time_to_die + 1) - (time - last_meal)) * 1000);
		status(data, last_meal, id);
		return ;
	}
	usleep(ms * 1000);
}

void	wait_fork(int id, t_data *data, long int last_meal)
{
	while (1)
	{
		status(data, last_meal, id);
		pthread_mutex_lock(&data->edit_fork);
		if (data->forks[id])
			return ((void)pthread_mutex_unlock(&data->edit_fork));
		pthread_mutex_unlock(&data->edit_fork);
		usleep(500);
	}
}

void	take_fork(int id, int fork_id, t_data *data)
{
	pthread_mutex_lock(&data->fork_lock[fork_id]);
	pthread_mutex_lock(&data->edit_fork);
	data->forks[fork_id] = 0;
	mod_print(id, "has taken a fork", data);
	pthread_mutex_unlock(&data->edit_fork);
}

void	leave_fork(int fork_id, t_data *data)
{
	pthread_mutex_lock(&data->edit_fork);
	data->forks[fork_id] = 1;
	pthread_mutex_unlock(&data->edit_fork);
	pthread_mutex_unlock(&data->fork_lock[fork_id]);
}

int	eat(int id, t_data *data, long int last_meal)
{
	mod_print(id, "is eating", data);
	last_meal = my_time(GET, data);
	zzz(data->time_to_eat, data, last_meal, id);
	return (last_meal);
}
