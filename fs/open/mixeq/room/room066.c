inherit __DIR__"underjail.c";
#include <ansi.h>
void create()
{
  old_create();
  set("exits", ([ 
  "east" : __DIR__"room064",
  "north" : __DIR__"room067",
]));
  set("new_exits",([
]));

}
void reset()
{
  old_reset();
}
