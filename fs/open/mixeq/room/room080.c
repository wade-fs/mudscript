inherit __DIR__"underjail.c";
#include <ansi.h>
void create()
{
  old_create();
  set("exits", ([ 
  "east" : __DIR__"seroom8",
]));
  set("new_exits",([
  "south" : __DIR__"room081",
]));

}
void reset()
{
  old_reset();
}
