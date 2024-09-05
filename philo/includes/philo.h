/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabasolo <kabasolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 17:24:54 by kabasolo          #+#    #+#             */
/*   Updated: 2024/09/03 15:54:33 by kabasolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include "structs.h"
# include "utils.h"

//Thread
void		*god(void *data);
void		*philo(void *data);
//Actions
void		zzz(long int ms, t_data *data, long int last_meal, int id);
void		wait_fork(int id, t_data *data, long int last_meal);
void		take_fork(int id, int fork_id, t_data *data);
void		leave_fork(int fork_id, t_data *data);
int			eat(int id, t_data *data, long int last_meal);

#endif //PHILO_H
