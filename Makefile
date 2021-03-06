# Minishell project
# Authors: auhoris & skitsch

# Bin
name			= minishell

# Directories
srcdir			= srcs
objdir			= objs
libdir			= libs
incdir			= $(srcdir)/includes
libftdir		= $(libdir)/libft
termcapdir		= $(srcdir)/termcap
historydir		= $(srcdir)/history
executordir		= $(srcdir)/executor

# Files
sources			= $(wildcard $(srcdir)/*.c) \
				  $(wildcard $(termcapdir)/*.c) \
				  $(wildcard $(historydir)/*.c) \
				  $(wildcard $(executordir)/*.c)

inclds			= $(wildcard $(incdir)/*.h)

objects			= $(sources:$(srcdir)/%.c=$(objdir)/%.o) \
					$(sources:$(srcdir)/%.c=$(objdir)/%.o) \
					$(sources:$(srcdir)/%.c=$(objdir)/%.o) \
					$(sources:$(srcdir)/%.c=$(objdir)/%.o)

# Dependencies
deps			= $(objects:%.o=%.d)

# Flags and linkers
cc				= gcc
cflags			= -Wall -Werror -Wextra
dbgf			= -std=c11 -ggdb3
sanitize		= -fsanitize=address
termcap			= -ltermcap

# Additional libraries
libft_a			= libft.a
libs			= $(libftdir)/$(libft_a) #$(gnldir)/$(gnl_a)

# Utils
rm				= rm -rf



all:			 lib $(name)

lib:
				@make -C $(libftdir)

$(name):		$(objects) $(libs)
				$(cc) $(dbgf) $(cflags) $(termcap) $^ -o $@
				@echo "\033[0;32m"$@" compiled"

# $(name):		$(objects) $(libs)
# 				$(cc) $(sanitize) $(cflags) $(termcap) $^ -o $@
# 				@echo "\033[0;32m"$@" compiled"

# $(name):		$(objects) $(libs)
# 				$(cc) $(sanitize) $(termcap) $^ -o $@
# 				@echo "\033[0;32m"$@" compiled"

-include $(deps)
$(objdir)/%.o	: $(srcdir)/%.c Makefile
				@mkdir -p $(dir $@)
				@$(cc) $(cflags) -MMD -c $< -o $@
				@echo "Compiled "$<" successfully!"


clean:
				@make -C $(libftdir) clean
				$(rm) $(objdir)
fclean:			clean
				@make -C $(libftdir) fclean
				$(rm) $(name)
re:				fclean all

shclean:
				$(rm) $(objdir)


.PHONY:			clean fclean re all
# .SILENT:		$(name) $(objects)
