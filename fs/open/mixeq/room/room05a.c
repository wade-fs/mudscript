inherit __DIR__"underjail.c";
#include <ansi.h>
void create()
{
  old_create();
  set("exits", ([ 
  "north" : __DIR__"room059",
  "west"  : __DIR__"room05b",
]));
  set("new_exits",([
]));

}
void reset()
{
  old_reset();
}
