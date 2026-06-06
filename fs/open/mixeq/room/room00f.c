inherit __DIR__"underjail.c";
#include <ansi.h>
void create()
{
  old_create();
  set("exits", ([ 
  "southwest" : __DIR__"room00e",
  "east" : __DIR__"room010",  
]));
  set("new_exits",([
]));

}
void reset()
{
  old_reset();
}
