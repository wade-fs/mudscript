inherit __DIR__"underjail.c";
#include <ansi.h>
void create()
{
  old_create();
  set("exits", ([ 
  "south" : __DIR__"room063",
]));
  set("new_exits",([
  "west" : __DIR__"room066",
  "east" : __DIR__"room065",
  "north" : __DIR__"room068",
]));

}
void reset()
{
  old_reset();
}
