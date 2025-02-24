#ifndef WINDOW_HXX
#define WINDOW_HXX

#include "graphics.hxx"
#include "keyboard.hxx"

namespace my {

class Window {
public:
  Window(int* argc, char** argv, Graphics& graphics);
  ~Window();
  const Graphics& getGraphics() const;
  Graphics& getGraphics();
  const Keyboard& getKeyboard() const;
  Keyboard& getKeyboard();
  void run() const;

private:
  int _handle;
  Graphics& _graphics;
  Keyboard _keyboard;
};

} // namespace my

#endif // WINDOW_HXX
