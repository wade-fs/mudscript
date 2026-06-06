inherit __DIR__"underjail.c";
#include <ansi.h>
void create()
{
  old_create();
  set("exits", ([ 
  "west" : __DIR__"room064",
  "north" : __DIR__"room069",
]));
  set("new_exits",([
]));

}
void reset()
{
  old_reset();
}
