inherit __DIR__"underjail.c";
#include <ansi.h>
void create()
{
  old_create();
  set("exits", ([ 
  "east" : __DIR__"room075",
  "west" : __DIR__"room07b",
]));
  set("new_exits",([
  "north" : __DIR__"room079",
  "south" : __DIR__"room07a",
]));

}
void reset()
{
  old_reset();
}
