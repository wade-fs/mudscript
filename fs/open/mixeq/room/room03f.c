inherit __DIR__"underjail.c";
#include <ansi.h>
void create()
{
  old_create();
  set("exits", ([ 
  "south" : __DIR__"room040",
  "west" : __DIR__"room03e",
]));
  set("new_exits",([
]));

}
void reset()
{
  old_reset();
}
