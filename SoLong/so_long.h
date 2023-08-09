/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iggonzal <iggonzal@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 13:01:43 by iggonzal          #+#    #+#             */
/*   Updated: 2023/08/06 22:43:33 by iggonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./minilibx/mlx.h"
# include "./get_next_line/get_next_line.h"
# include <fcntl.h>
# include <stdio.h>

typedef struct s_vars {
	void			*mlx;
	void			*img;
	void			*win;
	int				win_w;
	int				win_h;
	int				x_p;
	int				y_p;
	int				movement;
	char			**map;
	int				collect;
}	t_vars;

typedef struct s_vars_map {
	int	c;
	int	p;
	int	e;
	int	x;
	int	y;
}	t_map_vars;

char	**get_map(char *fmap);
void	move(t_vars **v, char *img_path, char *direction);
char	**ft_split(char *s, char c);
char	*ft_stringjoin(char const *s1, char const *s2);
char	*ft_itoa(int n);
int		ft_strcmp(const char *s1, const char *s2);
void	put_image(t_vars **v, int x, int y, char *img);
void	put_text(t_vars ***v);
void	put_image_to_map(char p, int x1, int y1, t_vars **v);
int		get_height(char **map);
void	check_map_valid(t_vars *vars);
void	check_file_is_valid(char *file_line);
void	check_elements(t_vars **vars);
void	ft_error(t_vars **v, char *err);
void	exit_door(t_vars **v);

#endif
