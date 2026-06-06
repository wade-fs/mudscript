inherit __DIR__"underjail.c";
#include <ansi.h>
void create()
{
  old_create();
  set("exits", ([ 
  "north" : __DIR__"room016",
  "south" : __DIR__"room01d",
]));
  set("new_exits",([
//  "west" : __DIR__"room009",
]));

}
void reset()
{
  old_reset();
}
