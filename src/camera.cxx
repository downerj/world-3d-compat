#include "camera.hxx"

my::Camera::Camera() : _x(0.), _y(0.), _z(0.) {}

void my::Camera::setX(float x) {
  _x = -x;
}

void my::Camera::setY(float y) {
  _y = -y;
}

void my::Camera::setZ(float z) {
  _z = -z;
}

void my::Camera::moveX(float dx) {
  _x -= dx;
}

void my::Camera::moveY(float dy) {
  _y -= dy;
}

void my::Camera::moveZ(float dz) {
  _z -= dz;
}

float my::Camera::getX() const {
  return _x;
}

float my::Camera::getY() const {
  return _y;
}

float my::Camera::getZ() const {
  return _z;
}
