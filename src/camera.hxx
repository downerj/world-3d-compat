#ifndef CAMERA_HXX
#define CAMERA_HXX

namespace my {

class Camera {
public:
  Camera();
  void setX(float x);
  void setY(float y);
  void setZ(float z);
  void moveX(float dx);
  void moveY(float dy);
  void moveZ(float dz);
  float getX() const;
  float getY() const;
  float getZ() const;

private:
  float _x;
  float _y;
  float _z;
};

} // namespace my

#endif // CAMERA_HXX
