/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slavoie <marvin@42quebec.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 00:30:19 by slavoie           #+#    #+#             */
/*   Updated: 2022/03/21 00:35:48 by slavoie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
void	ft_yo_its_wrong(void)
{
	ft_putstr_fd(RED"Erreur", 2);
	exit(EXIT_FAILURE);
}


char	*get_path(char *command, char **envp)
{
	char	**path_list;
	char	*full_path;
	char	*temp;
	int		i;

	i = 0;
	while (ft_strnstr(envp[i], "PATH", 4) == 0)
		i++;
	path_list = ft_split(envp[i] + 5, ':');
	i = 0;
	while (path_list[i])
	{
		temp = ft_strjoin(path_list[i], "/");
		full_path = ft_strjoin(temp, command);
		free (temp);
		if (access(full_path, F_OK) == 0)
			return (full_path);
		free(full_path);
		i++;
	}
	i = -1;
	while (path_list[++i])
		free(path_list[i]);
	free(path_list);
	return (0);
}


void	command_exeggutor(char *argv, char **envp)
{
	char	**command;
	char	*full_path;
	int		i;

	i = -1;
	command = ft_split(argv, ' ');
	full_path = get_path(command[0], envp);
	if (!full_path)
	{
		while (command[++i])
			free(command[i]);
		free(command);
		ft_yo_its_wrong();
		//ft_putstr_fd("Erreur lors de la récupération du path,", 2);
		//ft_putstr_fd("la mémoire allouée à été libéré.", 2);
	}
	if (execve(full_path, command, envp) == -1)
		ft_yo_its_wrong();
		//ft_putstr_fd("Erreur lors de l'exécution de la commande.", 2);
}
