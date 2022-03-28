/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slavoie <marvin@42quebec.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 00:36:33 by slavoie           #+#    #+#             */
/*   Updated: 2022/03/21 00:38:19 by slavoie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include	"Libft/libft.h"
# include	<fcntl.h>
# include	<unistd.h>

void	baby_process(char **argv, char **envp, int *fd);
void	baby_process2(char **argv, char **envp, int *fd);
char	*get_path(char *command, char **envp);
void	command_exeggutor(char *argv, char **envp);
void	ft_yo_its_wrong(void);

#endif
