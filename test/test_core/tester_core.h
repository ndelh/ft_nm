/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester_core.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndelhota <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 16:31:53 by ndelhota          #+#    #+#             */
/*   Updated: 2026/04/28 18:31:15 by ndelhota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_CORE_H
 #define TEST_CORE_H

# include "../tester.h"

//standard_test
void	standard_test(t_data *data);
void	flag_test(t_data *data);

//fork
void	true_nm_fork(t_test *test_node, t_data *data);
void    my_nm_fork(t_test *test_node, t_data *data);
void	diff_test(t_data *data, t_test *node, char *flags);

//utils
void	create_doc(t_data *data);
void	close_doc(t_data *data);

#endif
