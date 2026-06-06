inherit __DIR__"underjail.c";
#include <ansi.h>
void create()
{
  old_create();
  set("exits", ([ 
  "east" : __DIR__"room06c",
  "west" : __DIR__"room06a",
  "south" : __DIR__"room068",
]));
  set("new_exits",([
  "north" : __DIR__"boss04",
]));

}
void reset()
{
  old_reset();
}
