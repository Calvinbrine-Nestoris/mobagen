#include "JohnConway.h"

// Reference: https://playgameoflife.com/info
void JohnConway::Step(World& world) {
  int neighborCount;
  bool life;
    for (int i = 0; i < world.SideSize(); i++)
    {
        for (int j = 0; j < world.SideSize(); j++) {
          neighborCount = CountNeighbors(world, glm::ivec2(i, j));
          life = world.Get(glm::ivec2(i, j));
          if (neighborCount == 3 && !life)
          {
            world.SetNext(glm::ivec2(i, j), true);
          }
          else if (neighborCount < 2 && life)
          {
            world.SetNext(glm::ivec2(i, j), false);
          }
          else if (neighborCount > 3 && life)
          {
            world.SetNext(glm::ivec2(i, j), false);
          }
          else if (life)
          {
            world.SetNext(glm::ivec2(i, j), true);
          }
          neighborCount = 0;
        }
    }
}

int JohnConway::CountNeighbors(World& world, Point2D point) {
  // todo: implement
  Point2D tempPoint = point;
  int neighborCount = 0;

  tempPoint.x = point.x - 1;
  if (world.Get(tempPoint) == true)
  {
    neighborCount++;
  }
  tempPoint.x = point.x + 1;
  if (world.Get(tempPoint) == true) {
    neighborCount++;
  }
  tempPoint = point;
  tempPoint.y = point.y - 1;
  if (world.Get(tempPoint) == true) {
    neighborCount++;
  }
  tempPoint.y = point.y + 1;
  if (world.Get(tempPoint) == true) {
    neighborCount++;
  }
  
  return neighborCount;
}
