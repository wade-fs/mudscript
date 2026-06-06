inherit __DIR__"underjail.c";
#include <ansi.h>
void create()
{
  old_create();
  set("exits", ([ 
  "north" : __DIR__"seroom3",
]));
  set("new_exits",([
  "west" : __DIR__"room043",
]));

}
void reset()
{
  old_reset();
}
