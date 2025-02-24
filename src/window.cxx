#include "window.hxx"

#include <GL/freeglut.h>

namespace {

const unsigned int initialWidth = 400;
const unsigned int initialHeight = 400;
const char* const title = "GLTest";
void keyboardCallback(unsigned char key, int x, int y);
void keyboardUpCallback(unsigned char key, int x, int y);
void reshapeCallback(int width, int height);
void displayCallback();

} // namespace

my::Window::Window(int* argc, char** argv, Graphics& graphics)
:  _handle(-1), _graphics(graphics), _keyboard() {
  glutInit(argc, argv);
  glutInitWindowSize(initialWidth, initialHeight);
  glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);
  _handle = glutCreateWindow(title);
  glutDisplayFunc(displayCallback);
  glutReshapeFunc(reshapeCallback);
  glutKeyboardFunc(keyboardCallback);
  glutKeyboardUpFunc(keyboardUpCallback);
  glutSetWindowData(this);
  graphics.resize(initialWidth, initialHeight);
}

my::Window::~Window() {
  glutDestroyWindow(_handle);
}

const my::Graphics& my::Window::getGraphics() const {
  return _graphics;
}

my::Graphics& my::Window::getGraphics() {
  return _graphics;
}

const my::Keyboard& my::Window::getKeyboard() const {
  return _keyboard;
}

my::Keyboard& my::Window::getKeyboard() {
  return _keyboard;
}

void my::Window::run() const {
  glutMainLoop();
}

namespace {

void keyboardCallback(unsigned char key, int, int) {
  my::Window* window = static_cast<my::Window*>(glutGetWindowData());
  my::Keyboard& keyboard(window->getKeyboard());
  switch (key) {
    case 'a':
      keyboard.a = true;
      break;
    case 'd':
      keyboard.d = true;
      break;
    case 's':
      keyboard.s = true;
      break;
    case 'w':
      keyboard.w = true;
      break;
  }
}

void keyboardUpCallback(unsigned char key, int, int) {
  my::Window* window = static_cast<my::Window*>(glutGetWindowData());
  my::Keyboard& keyboard(window->getKeyboard());
  switch (key) {
    case 'a':
      keyboard.a = false;
      break;
    case 'd':
      keyboard.d = false;
      break;
    case 's':
      keyboard.s = false;
      break;
    case 'w':
      keyboard.w = false;
      break;
  }
}

void reshapeCallback(int width, int height) {
  my::Window* window = static_cast<my::Window*>(glutGetWindowData());
  window->getGraphics().resize(width, height);
}

void displayCallback() {
  my::Window* window = static_cast<my::Window*>(glutGetWindowData());
  my::Camera& camera(window->getGraphics().getCamera());
  const my::Keyboard& keyboard(window->getKeyboard());
  if (keyboard.a) {
    camera.moveX(-.1);
  } else if (keyboard.d) {
    camera.moveX(.1);
  }
  if (keyboard.w) {
    camera.moveZ(-1.);
  } else if (keyboard.s) {
    camera.moveZ(1.);
  }
  window->getGraphics().display();
  glutSwapBuffers();
  glutPostRedisplay();
}

} // namespace
