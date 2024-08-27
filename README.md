# Pipex

**Pipex** est un projet développé dans le cadre du programme de l'école 42. Il s'agit d'une réimplémentation simplifiée de la commande Unix `pipe`, qui permet de rediriger la sortie d'une commande vers l'entrée d'une autre. Ce projet explore la gestion des processus, la redirection des entrées/sorties, et l'exécution de commandes en C.

## Fonctionnalités

- **Gestion des Processus** :
  - Création de processus fils pour exécuter des commandes distinctes.
  - Communication inter-processus via des pipes.
  - Synchronisation des processus avec `waitpid()`.

- **Redirection des Entrées/Sorties** :
  - Redirection de l'entrée standard (`stdin`) et de la sortie standard (`stdout`) vers des fichiers ou des pipes.
  - Utilisation de `dup2()` pour manipuler les descripteurs de fichiers.

- **Exécution de Commandes Unix** :
  - Recherche des chemins d'exécution des commandes via la variable d'environnement `PATH`.
  - Utilisation de `execve()` pour exécuter des commandes en passant les arguments et l'environnement.

- **Gestion des Erreurs** :
  - Gestion centralisée des erreurs avec des messages d'erreur colorés.
  - Validation des permissions des commandes avant leur exécution.

## Installation

Pour compiler et exécuter **Pipex**, suivez les étapes ci-dessous :

1. Clonez ce dépôt sur votre machine locale :
    ```bash
    git clone https://github.com/votre-nom-utilisateur/pipex.git
    ```

2. Accédez au répertoire du projet :
    ```bash
    cd pipex
    ```

3. Compilez le projet en utilisant `make` :
    ```bash
    make
    ```

## Utilisation

**Pipex** peut être utilisé pour exécuter deux commandes en les connectant via un pipe, avec redirection de l'entrée et de la sortie. Par exemple :

```bash
./pipex infile "command1" "command2" outfile
