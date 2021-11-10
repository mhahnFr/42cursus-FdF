# The name of the executable.
NAME	=	fdf

# The flags to compile with.
CFLAGS	=	-Wall -Werror -Wextra -g

# The macro to get the object file names from the source file names.
OBJ		=	$(patsubst %.c,%.o,$(SRC))

# The source files.
SRC		=	./delegate/app_delegate.c ./view/init.c ./model/generate.c \
			./CLI/cli.c ./model/model.c ./model/vertex.c ./utils/arraylist.c \
			./main.c ./utils/arraylist_remove.c ./utils/arraylist_array.c \
			./view/window.c ./view/event/key_listener.c \
			./view/event/window_event.c ./view/event/key_event.c \
			./delegate/delegate.c ./renderer/renderer.c ./utils/math/matrix.c \
			./CLI/cli_destroy.c ./view/window_destroy.c \
			./view/event/key_event_destroy.c ./renderer/renderer_destroy.c \
			./utils/math/matrix_new.c ./utils/math/matrix_calculations.c \
			./utils/math/matrix_filler.c ./CLI/cli_error.c \
			./utils/arraylist_size.c ./utils/arraylist_array_unsafe.c \
			./model/vertex_copy.c ./utils/arraylist_get.c \
			./utils/arraylist_insert.c ./utils/arraylist_reset_indices.c \
			./renderer/renderer_camera.c ./renderer/renderer_draw.c \
			./utils/math/vector.c ./utils/math/vector_delete.c \
			./renderer/renderer_image.c ./utils/point.c \
			./utils/math/matrix_destroy.c ./utils/math/vector_add_sub.c \
			./utils/math/vector_division.c \
			./utils/math/vector_multiplications.c

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

# The name of the get_next_line library.
GNL_A	=	libgnl.a

# The directory of the get_next_line library.
GNL_D	=	./gnl

# The full path to the get_next_line library.
GNL_P	=	$(GNL_D)/$(GNL_A)

# The flags to link with.
LFLAGS	=	-framework OpenGL -framework AppKit -lz -L$(MLX_D) -lmlx -L$(LFT_D) \
			-lft -L$(FT_PF_D) -lftprintf -L$(GNL_D) -lgnl

# The flags to use for compiling the minilibx.
MLX_F	=	$(CFLAGS) -D GL_SILENCE_DEPRECATION -Wno-unused-parameter \
			-Wno-unused-variable

# The path to the ft_printf library.
FT_PF_D	=	./ft_printf

# The name of the ft_printf library.
FT_PF_A	=	libftprintf.a

# The full path of the ft_printf library.
FT_PF_P	=	$(FT_PF_D)/$(FT_PF_A)

# The includes for all files.
INCL	=	-I$(MLX_D) -I$(LFT_D) -I$(FT_PF_D) -I$(GNL_D) -I.


# Makes whatever is needed.
.phony: all
all: $(NAME)

# Runs a test file.
.phony: run
run: $(NAME)
	./$(NAME) tester/files/42.fdf 1000 1000

# Runs the norm checker on each registered source file.
.phony: nor
nor:
	norminette $(SRC) $(patsubst %.c,%.h,$(SRC)) | grep :

# Links the object files and the minilbx library.
$(NAME): $(MLX_P) $(LFT_P) $(FT_PF_P) $(GNL_P) $(OBJ)
	$(CC) $(OBJ) $(LFLAGS) -o $(NAME)

# Compiles each file individually.
%.o: %.c
	$(CC) $(CFLAGS) $(INCL) -c -o $@ $<

# Makes whatever is needed for the get_next_line library.
.phony: $(GNL_P)
$(GNL_P):
	make -C $(GNL_D) $(GNL_A)

# Makes whatever is needed for the ft_printf library.
.phony: $(FT_PF_P)
$(FT_PF_P):
	make -C $(FT_PF_D) $(FT_PF_A)

# Makes what is necessary for the libft.
.phony: $(LFT_P)
$(LFT_P):
	make -C $(LFT_D) $(LFT_A)

# Creates the minilibx library if needed.
.phony: $(MLX_P)
$(MLX_P):
	make -C $(MLX_D) $(MLX_A) CFLAGS='$(MLX_F)'

# Removes only the temporary files of the program, but not the library files.
.phony: cleano
cleano:
	- $(RM) $(OBJ)
	- $(RM) *~
	- find . -name \*~ -print -delete

# Removes only the files of the program, also the executable, but not the
# library files.
.phony: fcleano
fcleano: cleano
	- $(RM) $(NAME)

# Removes all unnecessary files created by this makefile.
.phony: clean
clean: cleano
	- make -C $(MLX_D) clean
	- make -C $(LFT_D) clean
	- make -C $(GNL_D) clean

# Removes everything created by this makefile.
.phony: fclean
fclean: clean fcleano
	- make -C $(LFT_D) fclean
	- make -C $(GNL_D) fclean

# Recompiles only the program files, not the librarys.
.phony: reo
reo: fcleano run

# Recompiles the project.
.phony: re
re: fclean all
