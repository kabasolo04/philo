/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabasolo <kabasolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 11:02:20 by kabasolo          #+#    #+#             */
/*   Updated: 2024/09/03 15:52:15 by kabasolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	status(t_data *data, long int last_meal, int id)
{
	pthread_mutex_lock(&data->stat_lock);
	pthread_mutex_lock(&data->god_doing_stuff);
	if (data->status[id] && my_time(GET, data) - last_meal > data->time_to_die)
	{
		data->status[id] = 0;
		printf("%ld %d died\n", my_time(GET, data), id);
		pthread_mutex_unlock(&data->god_doing_stuff);
		usleep(15000);
	}
	else
		pthread_mutex_unlock(&data->god_doing_stuff);
	pthread_mutex_unlock(&data->stat_lock);
}

void	mod_print(int id, char *line, t_data *data)
{
	pthread_mutex_lock(&data->stat_lock);
	pthread_mutex_lock(&data->god_doing_stuff);
	if (data->status[id] == 1)
		printf("%ld %d %s\n", my_time(GET, data), id, line);
	pthread_mutex_unlock(&data->god_doing_stuff);
	pthread_mutex_unlock(&data->stat_lock);
}

long int	my_time(int mood, t_data *data)
{
	static long int	first_time;
	long int		now_time;
	struct timeval	tv;

	if (gettimeofday(&tv, NULL) == 0)
		now_time = tv.tv_sec * 1000 + tv.tv_usec / 1000;
	else
		return (-1);
	if (mood == SET)
	{
		pthread_mutex_lock(&data->time);
		first_time = now_time;
		pthread_mutex_unlock(&data->time);
	}
	if (mood == GET)
	{
		pthread_mutex_lock(&data->time);
		now_time -= first_time;
		pthread_mutex_unlock(&data->time);
		return (now_time);
	}
	return (0);
}

int	ft_atoi(char *line)
{
	int	n;
	int	i;

	if (!line)
		return (0);
	n = 0;
	i = -1;
	while (line[++i])
	{
		n = n * 10 + line[i] - '0';
		if (!(line[i] >= '0' && line[i] <= '9'))
			return (-2);
	}
	return (n);
}
