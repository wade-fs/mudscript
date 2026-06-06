inherit __DIR__"underjail.c";
#include <ansi.h>
void create()
{
  old_create();
  set("exits", ([ 
  "north" : __DIR__"room06b",
  "south" : __DIR__"room064",
]));
  set("new_exits",([
]));

}
void reset()
{
  old_reset();
}
