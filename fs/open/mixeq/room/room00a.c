inherit __DIR__"underjail.c";
#include <ansi.h>
void create()
{
  old_create();
  set("exits", ([ 
  "east" : __DIR__"room009",
]));
  set("new_exits",([
  "down" : __DIR__"seroom0",
]));

}
void reset()
{
  old_reset();
}
