inherit __DIR__"underjail.c";
#include <ansi.h>
void create()
{
  old_create();
  set("exits", ([ 
  "north" : __DIR__"room012",
  "southeast" : __DIR__"room01b",
  
]));
  set("new_exits",([
]));

}
void reset()
{
  old_reset();
}
