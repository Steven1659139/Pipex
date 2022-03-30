/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slavoie <marvin@42quebec.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 00:30:19 by slavoie           #+#    #+#             */
/*   Updated: 2022/03/29 12:09:31 by slavoie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_yo_its_wrong(void)
{
	ft_putstr_fd(RED"Erreur\n", 2);
	exit(EXIT_FAILURE);
}

void	free_path(char **path_list)
{
	int	i;

	i = -1;
	while (path_list[++i])
		free(path_list[i]);
	free(path_list);
}

char	*get_path(char *command, char **envp)
{
	char	**path_list;
	char	*full_path;
	char	*temp;
	int		i;

	i = 0;
	while (envp[i] != NULL && ft_strnstr(envp[i], "PATH=", 5) == 0)
		i++;
	if (envp[i] == NULL)
		return (NULL);
	path_list = ft_split(envp[i] + 5, ':');
	i = 0;
	while (path_list[i])
	{
		temp = ft_strjoin(path_list[i], "/");
		full_path = ft_strjoin(temp, command);
		free (temp);
		if (access(full_path, F_OK | X_OK) == 0)
			return (full_path);
		free(full_path);
		i++;
	}
	free_path(path_list);
	return (0);
}

void	command_exeggutor(char *argv, char **envp)
{
	char	**command;
	char	*full_path;
	int		i;

	i = -1;
	command = ft_split(argv, ' ');
	if (access(command[0], F_OK | X_OK) == 0)
		full_path = command[0];
	else
		full_path = get_path(command[0], envp);
	if (!full_path)
	{
		while (command[++i])
			free(command[i]);
		free(command);
		ft_yo_its_wrong();
	}
	if (execve(full_path, command, envp) == -1)
		ft_yo_its_wrong();
}
