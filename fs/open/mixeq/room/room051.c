inherit __DIR__"underjail.c";
#include <ansi.h>
void create()
{
  old_create();
  set("exits", ([ 
  "north" : __DIR__"room050",
]));
  set("new_exits",([
  "south" : __DIR__"room052",
]));

}
void reset()
{
  old_reset();
}
