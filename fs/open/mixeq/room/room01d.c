inherit __DIR__"underjail.c";
#include <ansi.h>
void create()
{
  old_create();
  set("exits", ([ 
  "south" : __DIR__"room01c",
  "north" : __DIR__"room01e",
]));
  set("new_exits",([
//  "west" : __DIR__"room009",
]));

}
void reset()
{
  old_reset();
}
