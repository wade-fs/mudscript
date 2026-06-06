inherit __DIR__"underjail.c";
#include <ansi.h>
void create()
{
  old_create();
  set("exits", ([ 
  "east" : __DIR__"room042",
]));
  set("new_exits",([
  "west" : __DIR__"room044",
]));

}
void reset()
{
  old_reset();
}
