#ifndef OBSTACLE_H
#define OBSTACLE_H

#include <vector>
#include "SDL.h"

class Obstacle {
    public:
        Obstacle(int size, int grid_width, int grid_height);

        void PlaceObstacle(int x, int y, float head_x, float head_y);
        bool ObstacleCell(int x, int y);

        std::vector<SDL_Point> position;

    private:
        int size;
        int grid_width;
        int grid_height;
};
 
#endif