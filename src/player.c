/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseluis <joseluis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 13:54:51 by lufreder          #+#    #+#             */
/*   Updated: 2024/06/06 14:28:07 by joseluis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	update_player_position(t_vars *vars)
{
	int	new_x = vars->player->pos.x + 1;
	int	new_y = vars ->player->pos.y + 1;
}

int	players_move(int keyboard, t_vars *vars)
{
	if(keyboard == KEY_RIGHT)
		vars->player.pos.x += 1;
	if(keyboard == KEY_LEFT)
		vars->player.pos.x -= 1;
	if (keyboard == KEY_UP)
		vars->player.pos.y += 1;
	if (keyboard == KEY_BOTTOM)
		vars->player.pos.y -= 1;
}
