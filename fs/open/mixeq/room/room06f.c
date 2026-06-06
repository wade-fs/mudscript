inherit __DIR__"underjail.c";
#include <ansi.h>
void create()
{
  old_create();
  set("exits", ([ 
  "east" : __DIR__"room06e",
  "west" : __DIR__"room072",
]));
  set("new_exits",([
  "north" : __DIR__"room070",
  "south" : __DIR__"room071",
]));

}
void reset()
{
  old_reset();
}
