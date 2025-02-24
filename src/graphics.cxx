#include "graphics.hxx"

#include <cmath>
#include <cstddef>

#include <GL/gl.h>
#include <GL/glu.h>

#include "debug.hxx"

namespace {

const float pi = std::atan(1)*4;

float degToRad(float degrees) {
  return degrees * pi / 180.;
}

const float vertices[] = {
  -1., -1., 0.,
  1., -1., 0.,
  0., 1., 0.,
};

const float colors[] = {
  1., 0., 0.,
  0., 1., 0.,
  0., 0., 1.,
};

const unsigned short indices[] = {
  0, 1, 2,
};

} // namespace

my::Graphics::Graphics() : _width(), _height(), _camera() {
  _camera.setZ(100.);
}

#ifdef DEBUG
void my::Graphics::printInfo() {
  LOG("OpenGL Vendor: " << glGetString(GL_VENDOR) << '\n');
  LOG("OpenGL Renderer: " << glGetString(GL_RENDERER) << '\n');
  LOG("OpenGL Version: " << glGetString(GL_VERSION) << '\n');
  //LOG("OpenGL Extensions: " << glGetString(GL_EXTENSIONS) << '\n');
}
#endif // DEBUG

const my::Camera& my::Graphics::getCamera() const {
  return _camera;
}

my::Camera& my::Graphics::getCamera() {
  return _camera;
}

void my::Graphics::resize(int width, int height) {
  _width = width;
  _height = height;
}

void my::Graphics::display() const {
  glViewport(0, 0, _width, _height);
  glClearColor(0., .5, 1., 1.);
  glClear(GL_COLOR_BUFFER_BIT);
  glPushMatrix();
  const float aspect = static_cast<float>(_width) / static_cast<float>(_height);
  gluPerspective(pi/2., aspect, .01, 1000.);
  glTranslatef(_camera.getX(), _camera.getY(), _camera.getZ());
  glBegin(GL_TRIANGLES); {
    for (std::size_t i = 0; i < sizeof(indices)/sizeof(*indices); ++i) {
      const float x = vertices[i*3];
      const float y = vertices[i*3 + 1];
      const float z = vertices[i*3 + 2];
      const float r = colors[i*3];
      const float g = colors[i*3 + 1];
      const float b = colors[i*3 + 2];
      glColor3f(r, g, b);
      glVertex3f(x, y, z);
    }
  } glEnd();
  glPopMatrix();
}
