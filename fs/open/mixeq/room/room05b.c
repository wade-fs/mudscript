inherit __DIR__"underjail.c";
#include <ansi.h>
void create()
{
  old_create();
  set("exits", ([ 
  "south" : __DIR__"room05c",
  "east" : __DIR__"room05a",
]));
  set("new_exits",([
]));

}
void reset()
{
  old_reset();
}
