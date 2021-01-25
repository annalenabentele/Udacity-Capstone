#ifndef RENDERER_H
#define RENDERER_H

#include <vector>
#include "SDL.h"
#include "snake.h"
#include <string>
#include <mutex>
#include "obstacle.h"

class Renderer {
 public:
  Renderer(const std::size_t screen_width, const std::size_t screen_height,
           const std::size_t grid_width, const std::size_t grid_height);
  ~Renderer();

  void Render(Snake const snake, SDL_Point const &food, Obstacle const &obstacle);
  void UpdateWindowTitle(int score, int fps, std::string name);

 private:
  SDL_Window *sdl_window;
  SDL_Renderer *sdl_renderer;

  const std::size_t screen_width;
  const std::size_t screen_height;
  const std::size_t grid_width;
  const std::size_t grid_height;

  void RenderSnake(Snake const snake);
  void RenderFood(SDL_Point const &food);
  void RenderObstacle(Obstacle const &obstacle);
  std::mutex _mutex;
};

#endif