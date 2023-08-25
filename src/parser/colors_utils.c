#include "cub3d.h"

unsigned int	convert_to_hex(int r, int g, int b)
{
	unsigned int	rgb;
	unsigned int	rgba;

	rgb = (r << 16) | (g << 8) | b;
	rgba = (rgb << 8) | 0xff;
	return (rgba);
}
