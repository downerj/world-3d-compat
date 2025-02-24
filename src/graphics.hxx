#ifndef GRAPHICS_HXX
#define GRAPHICS_HXX

#include "camera.hxx"

namespace my {

class Graphics {
public:
  Graphics();
#ifdef DEBUG
  static void printInfo();
#endif // DEBUG
  const Camera& getCamera() const;
  Camera& getCamera();
  void resize(int width, int height);
  void display() const;

private:
  int _width;
  int _height;
  Camera _camera;
};

} // namespace my

#endif // GRAPHICS_HXX
