inherit __DIR__"underjail.c";
#include <ansi.h>
void create()
{
  old_create();
  set("exits", ([ 
  "northeast" : __DIR__"room02e",
]));
  set("new_exits",([
  "southwest" : __DIR__"room034",
]));

}
void reset()
{
  old_reset();
}
