inherit __DIR__"underjail.c";
#include <ansi.h>
void create()
{
  old_create();
  set("exits", ([ 
  "east" : __DIR__"room05f",
  "south" : __DIR__"room07b",
]));
  set("new_exits",([
  "north" : __DIR__"room060",
]));

}
void reset()
{
  old_reset();
}
