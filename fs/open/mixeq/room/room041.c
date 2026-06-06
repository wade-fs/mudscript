inherit __DIR__"underjail.c";
#include <ansi.h>
void create()
{
  old_create();
  set("exits", ([ 
  "east" : __DIR__"room040",
  "southwest" : __DIR__"room02c",
]));
  set("new_exits",([
]));

}
void reset()
{
  old_reset();
}
