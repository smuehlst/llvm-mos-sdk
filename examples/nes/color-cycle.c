#include <ppu.h>

int main(void) {
  // Enable BG rendering.
  ppu_wait_vblank();
  PPUMASK = 0b00001000;

  char color = 0;
  for (;;) {
    // Wait for 0.5 second.
    for (int i = 0; i < 30; ++i)
      ppu_wait_vblank();

    // Increment the palette color 0.
    ppu_write_addr(0x3f00);
    PPUDATA = ++color;
  }
}
