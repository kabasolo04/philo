/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabasolo <kabasolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 09:57:25 by kabasolo          #+#    #+#             */
/*   Updated: 2024/09/05 12:50:15 by kabasolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static t_data	parse_input(char **argv)
{
	t_data	data;

	data.philo_num = ft_atoi(argv[1]);
	data.time_to_die = ft_atoi(argv[2]);
	data.time_to_eat = ft_atoi(argv[3]);
	data.time_to_sleep = ft_atoi(argv[4]);
	data.diet = ft_atoi(argv[5]) - (!argv[5]);
	data.finish = 0;
	data.id = 1;
	if (data.philo_num == -2 || data.philo_num == 0 || data.time_to_die == -2)
		return (write(2, "Input error\n", 12), exit(1), data);
	if (data.time_to_eat == -2 || data.time_to_sleep == -2 || data.diet == -2)
		return (write(2, "Input error\n", 12), exit(1), data);
	return (data);
}

static t_data	malloc_data(t_data data, int i)
{
	data.status = (int *)malloc(sizeof(int) * (data.philo_num + 1));
	if (!data.status)
		return (write(2, "Memory error\n", 13), exit(1), data);
	i = -1;
	while (++i <= data.philo_num)
		data.status[i] = 1;
	data.forks = (int *)malloc(sizeof(int) * (data.philo_num + 1));
	if (!data.forks)
	{
		write(2, "Memory error\n", 13);
		return (free(data.forks), exit(1), data);
	}
	i = -1;
	while (++i <= data.philo_num)
		data.forks[i] = 1;
	data.fork_lock = malloc(sizeof(pthread_mutex_t) * (data.philo_num + 1));
	if (!data.fork_lock)
	{
		write(2, "Memory error\n", 13);
		return (free(data.forks), free(data.fork_lock), exit(1), data);
	}
	i = -1;
	while (++i <= data.philo_num)
		pthread_mutex_init(&data.fork_lock[i], NULL);
	return (data);
}

static t_data	start_mutex(t_data data)
{
	pthread_mutex_init(&data.id_setting, NULL);
	pthread_mutex_init(&data.time, NULL);
	pthread_mutex_init(&data.stat_lock, NULL);
	pthread_mutex_init(&data.god_doing_stuff, NULL);
	pthread_mutex_init(&data.edit_fork, NULL);
	return (data);
}

static int	create_threads(t_data *data)
{
	pthread_t	*threads;
	int			i;

	threads = malloc(sizeof(pthread_t) * (data->philo_num + 1));
	i = -1;
	while (++i < data->philo_num)
	{
		threads[i] = i + 1;
		if (pthread_create(&threads[i], NULL, philo, data))
			return (write(2, "Error\n", 6), 1);
	}
	threads[i] = i + 1;
	if (pthread_create(&threads[i], NULL, god, data))
		return (write(2, "Error\n", 6), 1);
	i = -1;
	while (++i <= data->philo_num)
	{
		pthread_join(threads[i], NULL);
		pthread_mutex_lock(&data->god_doing_stuff);
		data->finish ++;
		pthread_mutex_unlock(&data->god_doing_stuff);
	}
	return (free(threads), 0);
}

int	main(int argc, char **argv)
{
	t_data		data;
	int			i;

	if (argc < 5 || 6 < argc)
		return (write(2, "Wrong number of arguments\n", 26), 1);
	data = parse_input(argv);
	data = malloc_data(data, 0);
	data = start_mutex(data);
	my_time(SET, &data);
	create_threads(&data);
	pthread_mutex_destroy(&data.id_setting);
	pthread_mutex_destroy(&data.time);
	pthread_mutex_destroy(&data.stat_lock);
	pthread_mutex_destroy(&data.god_doing_stuff);
	pthread_mutex_destroy(&data.edit_fork);
	i = -1;
	while (++i <= data.philo_num)
		pthread_mutex_destroy(&data.fork_lock[i]);
	free(data.fork_lock);
	free(data.forks);
	free(data.status);
	return (0);
}
