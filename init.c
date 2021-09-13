#include "so_long.h"

void init_data(t_mlx *data)
{
    data->wall.img = NULL;
    data->wall_in.img = NULL;
    data->grass.img = NULL;
    data->Luffy.img = NULL;
    data->fruit.img = NULL;
    data->map.length = 1;
    data->map.width = 0;
    data->map.collect = 0;
    data->moves = 0;
    data->item = 0;
}
