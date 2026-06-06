inherit __DIR__"underjail.c";
#include <ansi.h>
void create()
{
  old_create();
  set("exits", ([ 
  "north" : __DIR__"seroom2",
  "south" : __DIR__"room028",
]));
  set("new_exits",([
]));

}
void reset()
{
  old_reset();
}
