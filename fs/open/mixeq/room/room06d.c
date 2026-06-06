inherit __DIR__"underjail.c";
#include <ansi.h>
void create()
{
  old_create();
  set("exits", ([ 
  "east" : __DIR__"seroom6",
  "west" : __DIR__"room06e",
]));
  set("new_exits",([
]));

}
void reset()
{
  old_reset();
}
