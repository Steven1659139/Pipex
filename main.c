#include "pipex.h"

int redirection_and_pipes(char **argv, char **envp)
{
    int id;
    int pipe_fd[2];

    pipe(pipe_fd);
    id = fork();
    if (!id)
    {
        if (!redirect_read(argv[1]))
            return (0);
        if (!connect_write_fd(pipe_fd, 1))
            return (0);
        command_exeggutor(argv[2], envp);
    }
    wait(NULL);
    if (!redirect_write(argv[4]))
        return (0);
    if (!connect_read_fd(pipe_fd, 0))
        return (0);
    command_exeggutor(argv[3], envp);
    return (1);
}

int main(int argc, char **argv, char **envp)
{
    int id;

    if (argc != 5)
        return (0);
    if (!check_command(argv, envp))
        return (0);
    id = fork();
    if (!id)
        redirection_and_pipes(argv, envp);

}
