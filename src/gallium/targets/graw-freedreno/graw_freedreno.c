#include "pipe/p_compiler.h"
#include "pipe/p_context.h"
#include "pipe/p_screen.h"
#include "util/u_debug.h"
#include "util/u_memory.h"
#include "target-helpers/inline_sw_helper.h"
#include "target-helpers/inline_debug_helper.h"
#include "state_tracker/graw.h"

#include <X11/Xlib.h>
#include <X11/Xlibint.h>
#include <X11/Xutil.h>
#include <stdio.h>

static struct {
   Display *display;
   void (*draw)(void);
} graw;

struct pipe_screen *
graw_create_window_and_screen( int x,
                               int y,
                               unsigned width,
                               unsigned height,
                               enum pipe_format format,
                               void **handle)
{
   return NULL;
}


void
graw_set_display_func( void (*draw)( void ) )
{
   graw.draw = draw;
}

void
graw_main_loop( void )
{
   int i;
   for (i = 0; i < 10; i++) {
      graw.draw();
      sleep(1);
   }
}
