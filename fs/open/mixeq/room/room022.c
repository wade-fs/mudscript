inherit __DIR__"underjail.c";
#include <ansi.h>
void create()
{
  old_create();
  set("exits", ([ 
  "west" : __DIR__"seroom7",
  "east" : __DIR__"room023",  
]));
  set("new_exits",([
]));

}
void reset()
{
  old_reset();
}
