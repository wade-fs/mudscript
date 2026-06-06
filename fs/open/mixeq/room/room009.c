inherit __DIR__"underjail.c";
#include <ansi.h>
void create()
{
  old_create();
  set("exits", ([ 
  "east" : __DIR__"room008",
]));
  set("new_exits",([
  "west" : __DIR__"room00a",
]));

}
void reset()
{
  old_reset();
}
