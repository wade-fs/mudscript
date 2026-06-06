inherit __DIR__"underjail.c";
#include <ansi.h>
void create()
{
  old_create();
  set("exits", ([ 
  "east" : __DIR__"room078",
  "north" : __DIR__"room060",
]));
  set("new_exits",([
  "west" : __DIR__"room07d",
  "south" : __DIR__"room07c",
]));

}
void reset()
{
  old_reset();
}
