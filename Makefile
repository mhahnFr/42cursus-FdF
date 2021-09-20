# The name of the executable.
NAME	=	fdf

# The flags to compile with.
CFLAGS	=	-Wall -Werror -Wextra

# The macro to get the object file names from the source file names.
OBJ		=	$(patsubst %.c,%.o,$(SRC))

# The source files.
SRC		=	./main.c ./delegate/app_delegate.c ./view/init.c ./model/generate.c \
			./CLI/cli.c

# The path to the home made libft.
LFT_D	=	./libft

# The base name of the libft.
LFT_A	=	libft.a

# The full path to the libft.
LFT_P	=	$(LFT_D)/$(LFT_A)

# The path to the minilibx.
MLX_D	=	./minilibx_macos

# The name of the minilibx library.
MLX_A	=	libmlx.a

# The full path to the minilibx library.
MLX_P	=	$(MLX_D)/$(MLX_A)

# The flags to link with.
LFLAGS	=	-framework OpenGL -framework AppKit -lz -L$(MLX_D) -lmlx -L$(LFT_D) \
			-lft -L$(FT_PF_D) -lftprintf

# The flags to use for compiling the minilibx.
MLX_F	=	$(CFLAGS) -O2 -D GL_SILENCE_DEPRECATION -Wno-unused-parameter \
			-Wno-unused-variable

# The path to the ft_printf library.
FT_PF_D	=	./ft_printf

# The name of the ft_printf library.
FT_PF_A	=	libftprintf.a

# The full path of the ft_printf library.
FT_PF_P	=	$(FT_PF_D)/$(FT_PF_A)


# Makes whatever is needed.
all: $(NAME)

# Links the object files and the minilbx library.
$(NAME): $(MLX_P) $(LFT_A) $(FT_PF_P) $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(LFLAGS) -o $(NAME)

# Compiles each file individually.
%.o: %.c
	$(CC) $(CFLAGS) -I$(MLX_D) -I$(LFT_D) -I$(FT_PF_D) -I. -c -o $@ $<

# Makes whatever is needed for the ft_printf library.
.phony: $(FT_PF_P)
$(FT_PF_P):
	make -C $(FT_PF_D) $(FT_PF_A)

# Makes what is necessary for the libft.
.phony: $(LFT_A)
$(LFT_A):
	make -C $(LFT_D) $(LFT_A)

# Creates the minilibx library if needed.
.phony: $(MLX_P)
$(MLX_P):
	make -C $(MLX_D) $(MLX_A) CFLAGS='$(MLX_F)'

# Removes all unnecessary files created by this makefile.
.phony: clean
clean:
	- $(RM) $(OBJ)
	- make -C $(MLX_D) clean
	- make -C $(LFT_D) clean

# Removes everything created by this makefile.
.phony: fclean
fclean: clean
	- $(RM) $(NAME)
	- make -C $(LFT_D) fclean

# Recompiles the project.
re: fclean all
