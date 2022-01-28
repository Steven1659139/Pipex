#include "pipex.h"

/*
    Redirige la sortie du processus vers un fichier.

    args:
            file:  le fichier où écrire

    return: 1 en cas de succès et 0 en cas d'échec
*/
int redirect_write(char *file)
{
    int fd_file;

    fd_file = open(file, O_RDWR | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
    if (fd_file == -1)
        return (0);
    if (dup2(fd_file, 1) < -1)
        return (0);
    close(fd_file);
    return (1);
}
/*
    Redirige le fichier vers l'entrée du processus

    args:
            file: Le fichier à lire

    return: 1 en cas de succès et 0 en cas d'échec
*/
int redirect_read(char *file)
{
    int fd_file;

    fd_file = open(file, O_RDONLY);
    if (fd_file == -1)
        return (0);
    if (dup2(fd_file, 0) < -1)
        return (0);
    close(fd_file);
    return (1);
}
/*
    Exécute la commande passée en paramètre.

    args:
            command: la commande à exécuter
            env_list: la liste des variables d'environnements

    return: 1 en cas de succès et 0 en cas d'échec
*/
void command_exeggutor(char *command, char **env_list)
{
    char **args;
    char *bin_path;

    args = ft_split(command, ' ');
    bin_path = get_bin(args[0], env_list);
    execve(bin_path, args++, env_list);
}

