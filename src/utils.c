/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabasolo <kabasolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 11:02:20 by kabasolo          #+#    #+#             */
/*   Updated: 2025/03/10 14:33:20 by kabasolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	zzz(int ms, t_data *data, int last_meal, int id)
{
	long int	time;

	time = my_time();
	if (time + ms - last_meal > data->time_to_die + 1)
	{
		usleep((data->time_to_die + 1 - (time - last_meal)) * 1000);
		status(data, last_meal, id);
		return ;
	}
	usleep(ms * 1000);
}

int	mod_print(int id, char *line, t_data *data)
{
	pthread_mutex_lock(&data->read);
	if (data->stop == 0)
		printf("%d %d %s\n", my_time(), id, line);
	pthread_mutex_unlock(&data->read);
	return (1);
}

int	my_time(void)
{
	static long int	first_time = 0;
	long int		now_time;
	struct timeval	tv;

	if (gettimeofday(&tv, NULL) == 0)
		now_time = tv.tv_sec * 1000 + tv.tv_usec / 1000;
	else
		return (-1);
	if (first_time == 0)
		first_time = now_time;
	return (now_time - first_time);
}

int	freedom(t_data *data)
{
	int	i;

	i = -1;
	while (++i <= data->philo_num)
		pthread_mutex_destroy(&data->fork_lock[i]);
	pthread_mutex_destroy(&data->id_setting);
	pthread_mutex_destroy(&data->read);
	pthread_mutex_destroy(&data->write);
	if (data->fork_lock)
		free(data->fork_lock);
	if (data->forks)
		free(data->forks);
	return (0);
}
