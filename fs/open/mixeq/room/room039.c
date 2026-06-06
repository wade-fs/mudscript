inherit __DIR__"underjail.c";
#include <ansi.h>
void create()
{
  old_create();
  set("exits", ([ 
  "west" : __DIR__"room038",
]));
  set("new_exits",([
//  "east" : __DIR__"boss02",
]));

}
void reset()
{
  old_reset();
}
