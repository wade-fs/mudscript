inherit __DIR__"underjail.c";
#include <ansi.h>
void create()
{
  old_create();
  set("exits", ([ 
  "northwest" : __DIR__"room02e",
]));
  set("new_exits",([
  "southeast" : __DIR__"room036",
]));

}
void reset()
{
  old_reset();
}
