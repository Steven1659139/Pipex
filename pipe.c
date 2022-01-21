#include "pipex.h"

int connect_write_fd(int pipe[2], int fd)
/*   
    Connecte l'extrémité d'écriture au fd désigné.
         args:
                pipe: le pipe à brancher
                fd: le file descriptor à brancher 

     return: 1 en cas de succès et 0 en cas d'échec*/
{
    close(pipe[0]);
    if (dup2 (pipe[1], fd) < -1)
        return (0);
    close(pipe[1]);
    return(1);
}

int connect_read_fd(int pipe[2], int fd)
/*
    Connecte l'etrémité de lecture au fd désigné.
        
        args:   
            pipe: pipe à brancher
            fd: file descriptor à brancher

        return: 1 en cas de succès et 0 en cas d'échec
*/
{
    close(pipe[1]);
    if (dup2(pipe[0], fd) < -1);
        return (0);
    return (1);
}

int close_pipe(int *pipe)
/*
    Ferme toutes les extrémités du pipe en argument.

    args:
            pipe: le pipe à fermer

    return: 1 en cas de succès et 0 en cas d'échec
*/
{
if (close(pipe[0]) == -1)
    return (0);
if (close(pipe[1]) == -1)
    return (0);
return (1);
}