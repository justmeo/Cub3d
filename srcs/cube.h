/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaqdasi <fmaqdasi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 16:21:03 by cafriem           #+#    #+#             */
/*   Updated: 2024/11/06 19:36:52 by fmaqdasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE_H
# define CUBE_H

# include "../get_next_line/get_next_line.h"
# include "../libft/libft.h"
# include <fcntl.h>
# include <math.h>
# include <signal.h>
# include <stdbool.h>
# include <stdint.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

# define PIE 3.14
# define DOF 50
# ifdef OSX
#  include <mlx.h>
#  define ESC 53
#  define W 13
#  define A 0
#  define S 1
#  define D 2
#  define LEFT 123
#  define RIGHT 124
#  define SHIFT 257
# else
#  include "../mlx-linux/mlx.h"
#  define ESC 65307
#  define W 119
#  define A 97
#  define S 115
#  define D 100
#  define LEFT 65361
#  define RIGHT 65363
#  define SHIFT 65505
# endif

typedef struct s_data
{
	void			*img;
	char			*addr;
	int				bpp;
	int				line_length;
	int				endian;
	int				width;
	int				height;
}					t_data;

typedef struct map
{
	char			**points;
	char			**file_map;
	int				width;
	int				height;
	char			*t_n;
	char			*t_s;
	char			*t_e;
	char			*t_w;
	unsigned int	**i_n;
	unsigned int	**i_s;
	unsigned int	**i_e;
	unsigned int	**i_w;
	int				p_row;
	int				p_colom;
	int				f;
	int				c;
}					t_map;

typedef struct angles
{
	bool			w;
	bool			s;
	bool			a;
	bool			d;
	bool			left;
	bool			right;
}					t_dir;

typedef struct player
{
	float			p_angle;
	float			p_dy;
	float			p_dx;
	float			p_y;
	float			p_x;
}					t_player;

typedef struct cub3d
{
	int				width;
	int				height;
	void			*mlx;
	void			*mlx_window;
	t_data			img;
	t_map			map;
	t_player		player;
	t_dir			dir;
	bool			m;
	int				fail;
}					t_cub3d;

typedef struct point
{
	float			x;
	float			y;
}					t_point;

typedef struct casting
{
	int				rays;
	int				dof;
	float			x;
	float			distv;
	float			disth;
	float			distt;
	float			r_angle;
	float			angle_diff;
	t_point			rayh;
	t_point			rayv;
	t_point			off;
	t_point			player;
	t_point			lines;
	t_point			height;
}					t_cast;

typedef struct dda
{
	int				i;
	float			s;
	float			t;
	float			y;
	float			x;
}					t_dda;

void				create_map(t_cub3d *cube);

// dda help:
bool				v_condition(t_point x1, float increase_x, float increase_y,
						int i);
bool				v_angle(t_cast *cast);

// some map:
int					mouse(int x, int y, t_cub3d *cube);
int					file_check(char *string);

// map utils:
char				*readfile(int fd);
int					create_trgb(int t, int r, int g, int b);
int					get_color(char *line);
void				check_updown(t_cub3d *cub3d, int row, int colom);
int					check_leftright(t_cub3d *cub3d, int row, int colom);
int					valid_letter(char letter);

// map valid:
void				check_valid(t_cub3d *cub3d, int row, int colom);
void				map_checker(t_cub3d *cub3d);
void				map_size(t_cub3d *cub3d);
char				*get_pl(t_cub3d *cub3d, int c, char *str);
void				mapread(t_cub3d *cub3d, int start);
void				check_player_exist(t_cub3d *cube);

void				player_info(t_cub3d *cub3d);
void				texture_parse(t_cub3d *cub3d);
void				openmap(t_cub3d *cub3d, char *argv[]);
void				set_booleans(t_cub3d *cube);

// keypresses:
void				change_angle(t_cub3d *cube);
int					move(t_cub3d *cube);

// drawing:
void				draw_square(int i, int j, t_cub3d *cube, int color);
void				draw_angle(t_cub3d *cube3d);
void				draw_player(t_cub3d *cube3d);
double				deg2rad(double degrees);
bool				is_wall(t_cub3d *cube, t_point ray);

// dda:
void				dda(t_point x1, t_point x2, t_cub3d *cube, int color);
void				wall_text_h(t_point x1, t_point x2, t_cub3d *cube,
						t_cast *cast);
void				wall_text_v(t_point x1, t_point x2, t_cub3d *cube,
						t_cast *cast);

// casting:
void				draw_floor_ceiling(t_cub3d *cube);
void				set_horizontals(t_cub3d *cube, t_cast *cast);
void				set_rayh(t_cub3d *cube, t_cast *cast);
void				set_verticals(t_cub3d *cube, t_cast *cast);
void				set_rayv(t_cub3d *cube, t_cast *cast);

// map:
float				dist(t_point player, t_point ray, float angle);
void				initialize_cast(t_cast *cast, t_cub3d *cube);
void				cast_n_project(t_cub3d *cube, t_cast *cast);
void				draw_rays(t_cub3d *cube);

// bonus utiLs:
int					keydown(int keycode, t_cub3d *cube);
int					keyup(int keycode, t_cub3d *cube);

// error.c:
void				error(t_cub3d *cube, int flag);
void				valid_line(char *string, t_cub3d *cube, char *freeme);
void				mapread(t_cub3d *cub3d, int start);

// functions:
void				create_map(t_cub3d *cube);
int					close_x(t_cub3d *cube);
int					close_esc(int keycode, t_cub3d *cube);
void				pixel_put(t_data *data, int x, int y, int color);

int					keydown(int keycode, t_cub3d *cube);
int					keyup(int keycode, t_cub3d *cube);

void				draw_map(t_cub3d *cube);

void				dda(t_point x1, t_point x2, t_cub3d *cube, int color);

void				free_point(unsigned int **map);
void				door_or_wall(t_cub3d *cube, t_cast *cast);
void				close_free(t_cub3d *cube);
int					check_digit(char *string);
// this
void				ft_freesplit(char **split);
void				ft_freesplitint(int **split);
char				*ft_strjoinfree(char *str1, char *str2, int flag);
char				*ft_strtrim_free(char *s1, char const *set);
int					ft_double_pointer_counter2(char **dp);
// to here

double				deg2rad(double degrees);
void				init(t_cub3d *cube);

#endif