inherit __DIR__"underjail.c";
#include <ansi.h>
void create()
{
  old_create();
  set("exits", ([ 
  "east" : __DIR__"room04d",
]));
  set("new_exits",([
  "north" : __DIR__"room04f",
]));

}
void reset()
{
  old_reset();
}
