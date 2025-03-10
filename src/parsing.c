/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabasolo <kabasolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 14:19:23 by kabasolo          #+#    #+#             */
/*   Updated: 2025/03/10 14:29:19 by kabasolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	ft_atoi(char *line)
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

static int	parse_input(t_data	*data, char **argv)
{
	data->philo_num = ft_atoi(argv[1]);
	data->time_to_die = ft_atoi(argv[2]);
	data->time_to_eat = ft_atoi(argv[3]);
	data->time_to_sleep = ft_atoi(argv[4]);
	data->diet = ft_atoi(argv[5]) - (!argv[5]);
	data->stop = 0;
	data->id = 1;
	if (data->philo_num <= 0 || data->time_to_die < 0)
		return (0);
	if (data->time_to_eat < 0 || data->time_to_sleep < 0 || data->diet == -2)
		return (0);
	return (1);
}

static int	malloc_data(t_data *data)
{
	int	i;

	data->forks = (int *)malloc(sizeof(int) * (data->philo_num + 1));
	if (!data->forks)
		return (0);
	i = -1;
	while (++i <= data->philo_num)
		data->forks[i] = 1;
	data->fork_lock = malloc(sizeof(pthread_mutex_t) * (data->philo_num + 1));
	if (!data->fork_lock)
		return (free(data->forks), 0);
	return (1);
}

static void	start_mutex(t_data *data)
{
	int	i;

	i = -1;
	while (++i <= data->philo_num)
		pthread_mutex_init(&data->fork_lock[i], NULL);
	pthread_mutex_init(&data->id_setting, NULL);
	pthread_mutex_init(&data->read, NULL);
	pthread_mutex_init(&data->write, NULL);
}

int	parsing(int argc, char **argv, t_data *data)
{
	if (argc < 5 || 6 < argc)
		return (write(2, "Wrong number of arguments\n", 26), 0);
	if (!parse_input(data, argv))
		return (write(2, "Input error\n", 12), 0);
	if (!malloc_data(data))
		return (write(2, "Memory error\n", 13), freedom(data));
	start_mutex(data);
	my_time();
	return (1);
}
