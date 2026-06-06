inherit __DIR__"underjail.c";
#include <ansi.h>
void create()
{
  old_create();
  set("exits", ([ 
  "south" : __DIR__"room060",
]));
  set("new_exits",([
  "north" : __DIR__"room062",
]));

}
void reset()
{
  old_reset();
}
