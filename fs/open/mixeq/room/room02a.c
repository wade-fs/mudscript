inherit __DIR__"underjail.c";
#include <ansi.h>
void create()
{
  old_create();
  set("exits", ([ 
  "northwest" : __DIR__"room029",
  "east" : __DIR__"room02b",
]));
  set("new_exits",([
]));

}
void reset()
{
  old_reset();
}
