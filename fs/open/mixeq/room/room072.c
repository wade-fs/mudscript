inherit __DIR__"underjail.c";
#include <ansi.h>
void create()
{
  old_create();
  set("exits", ([ 
  "east" : __DIR__"room06f",
  "west" : __DIR__"room075",
]));
  set("new_exits",([
  "north" : __DIR__"room073",
  "south" : __DIR__"room074",
]));

}
void reset()
{
  old_reset();
}
