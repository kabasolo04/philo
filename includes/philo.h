/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabasolo <kabasolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 17:24:54 by kabasolo          #+#    #+#             */
/*   Updated: 2025/03/24 12:19:16 by kabasolo         ###   ########.fr       */
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
void		wait_fork(int id, int fork_id, t_data *data, int last_meal);
int			take_fork(int id, int fork_id, t_data *data);
void		leave_fork(int fork_id, t_data *data);
int			eat(int id, t_data *data, int last_meal);

#endif //PHILO_H
