/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fractal.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rejocic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 14:57:09 by rejocic           #+#    #+#             */
/*   Updated: 2018/11/09 14:57:10 by rejocic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTAL_H
# define FRACTAL_H
# define WIDTH 1500
# define HEIGHT 1200

# include "minilibx_macos/mlx.h"
# include "libft/libft.h"
# include <math.h>
# include <pthread.h>

typedef struct		s_cords
{
	float			tmpx;
	float			cx;
	float			cy;
	float			xcord;
	float			ycord;
	float			h;
	float			v;
}					t_cords;

typedef struct		s_comms
{
	int				r;
	int				g;
	int				b;
	float			zoom;
	unsigned char	shift;
}					t_comms;

typedef struct		s_mlx
{
	void			*mlx_ptr;
	void			*win_ptr;
	void			*img_ptr;
	char			*addr;
	int				bpp;
	int				lsize;
	int				endian;
	unsigned int	max_iter;
	int				fractal;
	t_comms			comms;
	t_cords			cords;
}					t_mlx;

typedef	void		*(*t_threads)(void *param);

int					shut(t_mlx *mlx);
void				window(t_mlx *mlx);
void				whatfract(t_mlx *mlx, char **argv);
int					key_press(int keycode, t_mlx *mlx);
int					key_press2(int keycode, t_mlx *mlx);
int					key_release(int keycode, t_mlx *mlx);
int					mouse_move(int x, int y, t_mlx *mlx);
int					mouse_press(int button, int x, int y, t_mlx *mlx);
void				ft_put_pixel(t_mlx *mlx, int x, int y, int color);
int					ft_image(t_mlx *mlx);
int					fractal(t_mlx *mlx, float y, float max_y);
void				juliacalc(t_mlx *mlx, float x, float y);
void				mandelcalc(t_mlx *mlx, float x, float y);
void				shipcalc(t_mlx *mlx, float x, float y);
void				*mf1(void *param);
void				*mf2(void *param);
void				*mf3(void *param);
void				*mf4(void *param);
void				*mf5(void *param);
void				*mf6(void *param);
void				*mf7(void *param);
void				*mf8(void *param);

#endif
