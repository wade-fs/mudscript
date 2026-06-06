inherit __DIR__"underjail.c";
#include <ansi.h>
void create()
{
  old_create();
  set("exits", ([ 
  "north" : __DIR__"room044",
]));
  set("new_exits",([
  "east" : __DIR__"room046",
]));

}
void reset()
{
  old_reset();
}
