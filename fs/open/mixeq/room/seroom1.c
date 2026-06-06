//seroom，room1~room8的內容大致相同，不同的就是出口啦
inherit __DIR__"underjail.c";
#include <ansi.h>
void create()
{
  old_create();
  set("exits", ([ 
  "up" : __DIR__"seroom0",
]));
  set("new_exits", ([ 
  "north" : __DIR__"room00b",
]));
}
void reset()
{
  old_reset();
}

