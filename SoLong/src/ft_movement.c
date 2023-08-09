/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_movement.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iggonzal <iggonzal@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 13:03:27 by iggonzal          #+#    #+#             */
/*   Updated: 2023/08/06 22:42:22 by iggonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	collected(t_vars **v)
{
	int	img_w;
	int	img_h;

	(*v)->collect--;
	(*v)->map[((*v)->y_p / 50)][((*v)->x_p / 50)] = '0';
	(*v)->img = mlx_xpm_file_to_image(
			(*v)->mlx, "./img/floor.xpm", &img_w, &img_h);
	mlx_put_image_to_window(
		(*v)->mlx, (*v)->win, (*v)->img, (*v)->x_p, (*v)->y_p);
}

void	move_make(t_vars **v, char map_move, char *direction)
{
	if (map_move == 'E')
	{
		if ((*v)->collect <= 0)
			exit_door(v);
	}
	else if (map_move != '1')
	{
		if (ft_strcmp(direction, "left") == 0)
			(*v)->x_p -= 50;
		if (ft_strcmp(direction, "up") == 0)
			(*v)->y_p -= 50;
		if (ft_strcmp(direction, "down") == 0)
			(*v)->y_p += 50;
		if (ft_strcmp(direction, "right") == 0)
			(*v)->x_p += 50;
		put_text(&v);
	}
}

char	move_position(t_vars **v, int x, int y)
{
	return ((*v)->map[((*v)->y_p / 50) + y][((*v)->x_p / 50) + x]);
}

void	move(t_vars **v, char *img_path, char *direction)
{
	int		img_w;
	int		img_h;

	(*v)->img = mlx_xpm_file_to_image(
			(*v)->mlx, "./img/floor.xpm", &img_w, &img_h);
	mlx_put_image_to_window(
		(*v)->mlx, (*v)->win, (*v)->img, (*v)->x_p, (*v)->y_p);
	if (ft_strcmp(direction, "left") == 0)
		move_make(
			v, move_position(v, -1, 0), direction);
	else if (ft_strcmp(direction, "up") == 0)
		move_make(
			v, move_position(v, 0, -1), direction);
	else if (ft_strcmp(direction, "down") == 0)
		move_make(
			v, move_position(v, 0, 1), direction);
	else if (ft_strcmp(direction, "right") == 0)
		move_make(
			v, move_position(v, 1, 0), direction);
	if (move_position(v, 0, 0) == 'C')
		collected(v);
	(*v)->img = mlx_xpm_file_to_image(
			(*v)->mlx, img_path, &img_w, &img_h);
	mlx_put_image_to_window(
		(*v)->mlx, (*v)->win, (*v)->img, (*v)->x_p, (*v)->y_p);
}
