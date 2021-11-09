# minishell

<img src="https://github.com/Georgik0/demo_bash/blob/master/minishell.gif" width="1400" height="1400" />

Minishell is a school project meant to learn how to make your own shell.

`make` assembles the project \
`./minishell` launches a shell

# В проекте реализовано:
◦ `echo` with option -n \
◦ `cd` with only a relative or absolute path \
◦ `pwd` with no options \
◦ `export` with no options \
◦ `unset` with no options \
◦ `env` with no options or arguments \
◦ `exit` with no options \
The rest of the commands are implemented through execve()

◦ `’` inhibit all interpretation of a sequence of characters. \
◦ `"` inhibit all interpretation of a sequence of characters except for $. 

Redirections: \
◦ `<` should redirect input. \
◦ `>` should redirect output. 

Pipes `|` The output of each command in the pipeline is connected via a pipe to the \
input of the next command. 
