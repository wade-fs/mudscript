inherit __DIR__"underjail.c";
#include <ansi.h>
void create()
{
  old_create();
  set("exits", ([ 
  "west" : __DIR__"room015",
  "south" : __DIR__"room01e",  
]));
  set("new_exits",([
  "east"  : __DIR__"room017",
]));

}
void reset()
{
  old_reset();
}
