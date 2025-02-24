#include "game.hxx"
#include "graphics.hxx"
#include "window.hxx"

int main(int argc, char** argv) {
  // Note: Omitting empty parens to avoid most vexing parse.
  my::Graphics graphics;
  my::Window window(&argc, argv, graphics);
#ifdef DEBUG
  my::Graphics::printInfo();
#endif // DEBUG
  window.run();
}
