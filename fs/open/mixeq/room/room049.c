inherit __DIR__"underjail.c";
#include <ansi.h>
void create()
{
  old_create();
  set("exits", ([ 
  "east" : __DIR__"room048",
]));
  set("new_exits",([
  "north" : __DIR__"room04a",
]));

}
void reset()
{
  old_reset();
}
