/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseluis <joseluis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 16:56:25 by lufreder          #+#    #+#             */
/*   Updated: 2024/06/06 14:29:07 by joseluis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdbool.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <errno.h>
# include <string.h>
# include <math.h>
# include "libft.h"
# include "get_next_line_bonus.h"
# include "ft_printf.h"
# include <mlx.h>

#define KEY_UP 'W'
#define KEY_RIGHT 'D'
#define KEY_LEFT 'A'
#define KEY_BOTTOM 'S'


typedef struct s_game
{
	int		x;
	int		y;
	int		start_x;
	int		start_y;
	int		width;
	int		height;
	int		fd;
	void	*mlx;
	int		numberP;
	int		numberC;
	int		numberE;
	int		collectibles;
	int		reachable_collectibles;
	int		collected;
	int		coin;
	void	*win;
	int		window;
	int		visited;
	int		exit_found;
	char	**map;
	char	**map_copy;
}		t_game;

typedef struct s_data
{
	void		*mlx_ptr; // MLX pointer
	void		*win_ptr; // MLX window pointer
	void		*textures[5]; // MLX image pointers (on the stack)
	t_game		*map; // Map pointer (contains map details - preferably kept on the stack)
}	t_data;


int 	map_read(t_game *game, char *av[]);
int		check_map_access(char *av[]);
bool	are_there_walls(t_game *map);
bool	are_PCE_ok(t_game *game);
bool	check_requirements(t_game *game);


#endif