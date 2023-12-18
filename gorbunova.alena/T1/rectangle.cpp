#include "rectangle.hpp"

Rectangle::Rectangle(point_t pointOne, point_t pointTwo):
  pointOne_(pointOne),
  pointTwo_(pointTwo)
{}
double gorbunova::Rectangle::getArea() const
{
  rectangle_t f = getFrameRect();
  return f.width * f.height;
}
rectangle_t gorbunova::Rectangle::getFrameRect() const
{
  double width = pointTwo_.x - pointOne_.x;
  double height = pointTwo_.y - pointOne_.y;
  point_t pos = { (pointTwo_.x - pointOne_.x)/2,(pointTwo_.y - pointOne_.y)/2) };
  return rectangle_t{ width, height, pos };
}
void gorbunova::Rectangle::move(point_t center)
{
  rectangle_t f = getFrameRect();
  double xMove = center.x - f.pos.x;
  double yMove = center.y - f.pos.y;
  pointOne_.x += xMove;
  pointOne_.y += yMove;
  pointTwo_.x += xMove;
  pointTwo_.y += yMove;
}
void gorbunova::Rectangle::move(double xMove, double yMove)
{
  pointOne_.x += xMove;
  pointOne_.y += yMove;
  pointTwo_.x += xMove;
  pointTwo_.y += yMove;
}
void gorbunova::Rectangle::scale(point_t pos, double z)
{
  pointOne_.x *= z;
  pointOne_.y *= z;
  pointTwo_.x *= z;
  pointTwo_.y *= z;
}

