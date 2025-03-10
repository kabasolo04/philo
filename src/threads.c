/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabasolo <kabasolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 16:36:05 by kabasolo          #+#    #+#             */
/*   Updated: 2025/03/10 14:36:50 by kabasolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	dinner_time(int id, t_data *data, int last_meal, int eaten)
{
	if (eaten > 0 && mod_print(id, "is sleeping", data))
		zzz(data->time_to_sleep, data, last_meal, id);
	mod_print(id, "is thinking", data);
	if (id % 2 == 0 && eaten == 0)
		usleep((data->time_to_eat / 2) * 1000);
	wait_fork(id, id, data, last_meal);
	wait_fork(id, (id % data->philo_num) + 1, data, last_meal);
	last_meal = eat(id, data, last_meal);
	leave_fork(id, data);
	leave_fork((id % data->philo_num) + 1, data);
	return (last_meal);
}

void	*philo(void *date)
{
	t_data	*data;
	int		id;
	int		eaten;
	int		last_meal;

	data = date;
	pthread_mutex_lock(&data->id_setting);
	id = data->id++;
	pthread_mutex_unlock(&data->id_setting);
	last_meal = 0;
	eaten = -1;
	pthread_mutex_lock(&data->read);
	while (++eaten != data->diet && data->stop == 0)
	{
		pthread_mutex_unlock(&data->read);
		last_meal = dinner_time(id, data, last_meal, eaten);
		pthread_mutex_lock(&data->read);
	}
	pthread_mutex_unlock(&data->read);
	return (NULL);
}

void	*god(void *data)
{
	pthread_mutex_lock(&((t_data *)data)->write);
	((t_data *)data)->stop = 1;
	pthread_mutex_unlock(&((t_data *)data)->write);
	return (NULL);
}
