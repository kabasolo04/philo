/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabasolo <kabasolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 09:57:25 by kabasolo          #+#    #+#             */
/*   Updated: 2025/03/10 14:34:29 by kabasolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	simulation(t_data *data)
{
	pthread_t	*threads;
	int			i;
	int			n;

	threads = malloc(sizeof(pthread_t) * (data->philo_num + 1));
	i = -1;
	while (++i < data->philo_num)
	{
		threads[i] = i + 1;
		if (pthread_create(&threads[i], NULL, philo, data))
			break ;
	}
	pthread_mutex_lock(&data->write);
	pthread_create(&threads[i], NULL, god, data);
	n = -1;
	while (++n < i)
		pthread_join(threads[n], NULL);
	pthread_mutex_unlock(&data->write);
	pthread_join(threads[n], NULL);
	return (free(threads));
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (!parsing(argc, argv, &data))
		return (1);
	simulation(&data);
	freedom(&data);
	return (0);
}
