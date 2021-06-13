#include "../includes/env.h"
#include "../includes/types.h"
#include "../includes/errors.h"
#include "../../libs/libft/srcs/libft.h"
#include <unistd.h>

static void	value_key_free(char *value, char *key, t_env_list *new)
{
	free(value);
	free(key);
	free(new);
}

//Почему не сделать через env_addback?
static int	create_new_env(char *key, char *value, t_env_list *env)
{
	t_env_list	*new;

	new = env_new(ft_strdup(key), ft_strdup(value));
	if (new == NULL)
		return (ERROR_MALLOC);
	env_addback(&env, new);
	/* t_env_list	*new;

	new = (t_env_list *)malloc(sizeof(t_env_list));
	if (new == NULL)
		return (ERROR_MALLOC);
	new->key = ft_strdup(key);
	new->value = ft_strdup(value);
	if (new->key == NULL || new->value == NULL)
	{
		value_key_free(new->value, new->key, new);
		return (ERROR_MALLOC);
	}
	new->next = NULL;
	while (env->next != NULL)
	{
		env = env->next;
	}
	env->next = new; */
	return (OUT);
}

int	set_key_value(char *str, t_env_list *env)
{
	char	*chr;
	char	*key;
	char	*value;
	int		len;

	while (env->next != NULL)
		env = env->next;
	chr = ft_strchr(str, '=');
	if (chr == NULL)
		return (OUT);
	len = chr - str;
	key = ft_substr(str, 0, len);
	value = ft_strdup(chr + 1);
	if (key == NULL || value == NULL)
	{
		value_key_free(value, key, NULL);
		return (ERROR_MALLOC);
	}
	if (create_new_env(key, value, env) == ERROR_MALLOC)
	{
		value_key_free(value, key, NULL);
		return (ERROR_MALLOC);
	}
	value_key_free(value, key, NULL);
	return (OUT);
}

char	*get_value(char *str)
{
	char	*chr;
	char	*key;
	int	len;

	chr = ft_strchr(str, '=');
	len = chr - str;
	key = ft_substr(str, 0, len);
	return (key);
}

int	unset_env_elem(t_env_list **env, char *key)
{
	t_env_list	*tmp;
	t_env_list	*prev;
	t_env_list	*start;

	if (!(*env))
		return (OK);
	start = *env;
	while (start)
	{
		if (ft_strcmp((start)->key, key) == 0)
		{
			prev->next = start->next;
			tmp = start;
			env_list_delone(tmp);
			return (OK);
		}
		prev = start;
		start = start->next;
	}
	return (OK);
}
// int	set_export_variables(char *key, char *value, t_env_list *env)
// {
// 	t_env_list	*new;

// 	new = (t_env_list *)malloc(sizeof(t_env_list));
// 	if (new == NULL)
// 		return (ERROR_MALLOC);
// 	new->key = ft_strdup(key);
// 	new->value = ft_strdup(value);
// 	new->next = NULL;
// 	if (new->key == NULL || new->value == NULL)
// 		return (ERROR_MALLOC);
// 	while (env->next != NULL)
// 	{
// 		env = env->next;
// 	}
// 	env->next = new;
// 	return (OUT);
// }