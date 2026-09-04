#include "CohesionRule.h"
#include <glm/glm.hpp>

glm::vec2 CohesionRule::computeForce(const std::vector<BoidView>& neighborhood, const BoidView& boid) {
  glm::vec2 cohesionForce(0.f);

  // glm::length(vec) returns the length of a vector,
  // glm::normalize(vec) returns the normalized vector (length 1) in the same direction as vec.

  // begin solution
  glm::vec2 centralPos{0, 0};
  for (int i = 0; i < neighborhood.size(); i++)
  {
    centralPos += neighborhood[i].position;
  }
  centralPos /= neighborhood.size();
  cohesionForce = glm::normalize(boid.position - centralPos);

  // end solution

  return cohesionForce;
}
