/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slavoie <marvin@42quebec.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 00:39:03 by slavoie           #+#    #+#             */
/*   Updated: 2022/03/21 16:57:57 by slavoie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	baby_process(char **argv, char **envp, int *fd)
{
	int	infile;

	infile = open(argv[1], O_RDONLY, 0777);
	if (infile == -1)
		ft_yo_its_wrong();
	dup2(fd[1], 1);
	dup2(infile, 0);
	close(fd[0]);
	command_exeggutor(argv[2], envp);
}

void	daddy_process(char **argv, char **envp, int *fd)
{
	int	outfile;

	outfile = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (outfile == -1)
		ft_yo_its_wrong();
	dup2(fd[0], 0);
	dup2(outfile, 1);
	close(fd[1]);
	command_exeggutor(argv[3], envp);
}

int	main(int argc, char **argv, char **envp)
{
	int	fd[2];
	int	pid1;

	if (argc == 5)
	{
		if (pipe(fd) == -1)
			ft_yo_its_wrong();
		pid1 = fork();
		if (pid1 == -1)
			ft_yo_its_wrong();
		if (pid1 == 0)
			baby_process(argv, envp, fd);
		//waitpid(pid1, NULL, 0);
		daddy_process(argv, envp, fd);
		
	}
	else
	{
		ft_putstr_fd("Erreur dans l'entrée des arguments.\n", 2);
		ft_putstr_fd("Veuillez les entrées de la manière suivante:", 1);
		ft_putstr_fd("./pipex infile 'cmd1' 'cmd2' outfile\n", 1);
	}
	return (0);
}
