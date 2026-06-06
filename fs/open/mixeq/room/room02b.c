inherit __DIR__"underjail.c";
#include <ansi.h>
void create()
{
  old_create();
  set("exits", ([ 
  "west" : __DIR__"room02a",
  "east" : __DIR__"room02c",
]));
  set("new_exits",([
]));

}
void reset()
{
  old_reset();
}
