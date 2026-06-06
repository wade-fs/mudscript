inherit __DIR__"underjail.c";
#include <ansi.h>
void create()
{
  old_create();
  set("exits", ([ 
  "west" : __DIR__"room02b",
  "northeast" __DIR__"room041",
]));
  set("new_exits",([
  "east" : __DIR__"room02d",
]));

}
void reset()
{
  old_reset();
}
