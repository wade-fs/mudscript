inherit __DIR__"underjail.c";
#include <ansi.h>
void create()
{
  old_create();
  set("exits", ([ 
  "north" : __DIR__"room03f",
  "west" : __DIR__"room041",
]));
  set("new_exits",([
]));

}
void reset()
{
  old_reset();
}
