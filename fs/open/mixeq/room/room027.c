inherit __DIR__"underjail.c";
#include <ansi.h>
void create()
{
  old_create();
  set("exits", ([ 
  "west" : __DIR__"room026",
  "north" : __DIR__"room01c",
]));
  set("new_exits",([
]));

}
void reset()
{
  old_reset();
}
