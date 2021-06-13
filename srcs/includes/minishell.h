#ifndef MINISHELL_H
# define MINISHELL_H

//	Инклюды
# include "env.h"
# include "ast.h"
# include <stdio.h>
# include <stdlib.h>
#include <sys/_types/_size_t.h>

//	Дефайны
# define TRUE 1
# define FALSE 0

typedef struct s_fd
{
	int	in;
	int	out;
}		t_fd;

typedef struct s_exec
{
	t_ast	*root;
	// Мб будет полезно
	t_ast	*node;
	int		curr_node_type;
	//
	int		tempin;
	int		tempout;
	int		exit_status;
	int		fd[2];
	int		r_or_w;
	int		*pids;
	int		flag_echo;
	size_t	size_pids;
	t_fd	*fd_arr;
	size_t	fd_size;
}			t_exec;

t_exec	*init_exec(t_ast *root);
int		termcap(t_env_list *env);
int		check_input_params(int argc, char **argv);
int		detour_tree(t_exec *exec, t_ast *node, t_env_list *env);
//free_functions
void	free_lexer(t_lexer *lexer);
void	free_parser(void *parser);
void	free_root_parser(void *root);
void	free_exec(void *exec);
int		free_unique(int code, void *content, void(*del)(void *));

#endif /* ifndef MINISHELL_H */