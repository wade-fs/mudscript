inherit __DIR__"underjail.c";
#include <ansi.h>
void create()
{
  old_create();
  set("exits", ([ 
  "north" : __DIR__"room028",
  "southeast" : __DIR__"room02a",
]));
  set("new_exits",([
]));

}
void reset()
{
  old_reset();
}
