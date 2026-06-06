inherit __DIR__"underjail.c";
#include <ansi.h>
void create()
{
  old_create();
  set("exits", ([ 
  "east" : __DIR__"room04a",
]));
  set("new_exits",([
  "west" : __DIR__"room04c",
]));

}
void reset()
{
  old_reset();
}
