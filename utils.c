#include "pipex.h"
/*
    Libère la liste des chaines passées en paramètre.

    args:
            str_list: liste des chaines de caractères à libérer
*/
void    free_str_list(char **str_list)
{
    int index;

    index = 0;
    while (str_list[index])
        free(str_list[index++]);
    free(str_list);
}

/*
    Obtiens le chemin de la variable d'environnement dans env_list

    args:
            env_list: Liste des variables d'environnement

    return: le chemin de la variable d'environnement
*/
char **get_path_envp(char **envp)
{
    char **path_envp;

    while (*envp && !ft_str_sameStart(*envp, "PATH="))
        envp++;
    if (!*envp)
        return (NULL);
    path_envp = ft_split(*envp + 5, ':');
    return (path_envp);
}
/*
    Obtiens le chemin bin de la commande, elle est utilisé au où la commande n'est pas dans le répertoire actuel.

    args:
            command: La commande à exécuter
            env_list: La liste contenant les variables d'environnements.

    return: BIN PATH
*/
char *get_bin(char *command, char **envp)

{
    char    **path_list;
    char    *full_path;
    char    *temp;
    int     index;

    path_list = get_path_envp(envp);
    temp = ft_strsufx("/", path_list[0]);
    full_path = ft_strjoin(temp, command);
    free(temp);
    index = 1;
    while (access(full_path, F_OK) == -1 && path_list[1])
    {
        free(full_path);
        temp = ft_strsufx("/", path_list[index++]);
        full_path = ft_strjoin(temp, command);
        free(temp);
    }
    free_str_list(path_list);
    if (!path_list[index])
    {
        free(full_path);
        return (command);
    }
    return (full_path);
}
/*
    Vérifie si la commande existe.

    args:
            command: La commande à exécuter
            env_list: La liste contenant les variables d'environnements

            return: renvoie 1 en cas de succès et 0 en cas d'échec.
*/
int check_command(char **argv, char **envp)
{
    char    **func_arg;
    char    *bin_path;
    int     index;
    char    *command;
    
    if (ft_str_sameStart(argv[1], "here_doc"))
        command = argv[3];
    else
        command = argv[2];
    func_arg = ft_split(command, ' ');
    bin_path = get_bin(func_arg[0], envp);
    if (!bin_path)
        return (0);
    index = 0;
    if (!ft_str_sameStart(bin_path, command))
        free(bin_path);
    if (*func_arg)
    {
        while (func_arg[index])
            free(func_arg[index++]);
    }
    free(func_arg);
    return (1);
}
