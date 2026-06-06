inherit __DIR__"underjail.c";
#include <ansi.h>
void create()
{
  old_create();
  set("exits", ([ 
  "west" : __DIR__"room02d",
]));
  set("new_exits",([
  "east" : __DIR__"room036",
  "northwest" : __DiR__"room02f",
  "northeast" : __DiR__"room031",
  "southwest" : __DiR__"room033",
  "southeast" : __DiR__"room035",
]));

}
void reset()
{
  old_reset();
}
