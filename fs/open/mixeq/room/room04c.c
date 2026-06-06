inherit __DIR__"underjail.c";
#include <ansi.h>
void create()
{
  old_create();
  set("exits", ([ 
  "east" : __DIR__"room04b",
]));
  set("new_exits",([
  "west" : __DIR__"room04d",
]));

}
void reset()
{
  old_reset();
}
