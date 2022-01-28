#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdio.h>
# include <sys/wait.h>
# include <stdlib.h>
# include <fcntl.h>

# include "Libft/libft.h"

int connect_write_fd(int pipe[2], int fd);
int connect_read_fd(int pipe[2], int fd);
int close_pipe(int *pipe);  
int     redirect_write(char *file);
int     redirect_read(char *file);
void    command_exeggutor(char *command, char **env_list);

void    free_str_list(char **str_list);
char    get_path(char **env);
char    *get_bin(char *command, char **env);
int     check_command(char **argv, char **env); 

#endif
