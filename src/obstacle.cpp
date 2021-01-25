#include "obstacle.h"
#include "SDL.h"
#include <iostream>

Obstacle::Obstacle(int size, int grid_width, int grid_height) 
    : size(size), 
      grid_width(grid_width),
      grid_height(grid_height) {
}

void Obstacle::PlaceObstacle(int x, int y, float head_x, float head_y){
    for(int i = 0; i < size; i++){
        SDL_Point point;

        point.x = fmod(x + i + grid_width, grid_width);
        point.y = fmod(y + i + grid_height, grid_height);

        position.push_back(point);
    }

    // to avoid that obstacle is placed in same cell as intial snake
    // if happening, replace obstacle
    if(ObstacleCell(head_x, head_y)){
        position.clear();
        PlaceObstacle(x, y, head_x, head_y);
    }
}

bool Obstacle::ObstacleCell(int x, int y) {
  for (auto const &item : position) {
    if (x == item.x && y == item.y) {
      return true;
    }
  }
  return false;
}