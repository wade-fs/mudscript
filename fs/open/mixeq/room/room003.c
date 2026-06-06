inherit __DIR__"underjail.c";
#include <ansi.h>
void create()
{
  old_create();
  set("exits", ([ 
  "east" : __DIR__"room002",
]));
  set("new_exits",([
  "north" : __DIR__"room004",
  "south" : __DIR__"room006",
  "west" : __DIR__"room008",
]));

}
void reset()
{
  old_reset();
}
