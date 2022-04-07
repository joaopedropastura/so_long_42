#include <mlx.h>

int main(void)
{
	void	*mlx;
	void	*mlx_win;
	void	*img;
	int		x;
	int		y;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 400, 400, "ola");
	img = mlx_xpm_file_to_image(mlx, "img/player-front.xpm", &x, &y);
	mlx_put_image_to_window(mlx, mlx_win, img, 0, 0);
	mlx_loop(mlx);
}
