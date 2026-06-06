inherit __DIR__"underjail.c";
#include <ansi.h>
void create()
{
  old_create();
  set("exits", ([ 
  "east" : __DIR__"room03e",
  "west" : __DIR__"room03c",
]));
  set("new_exits",([
]));

}
void reset()
{
  old_reset();
}
