inherit __DIR__"underjail.c";
#include <ansi.h>
void create()
{
  old_create();
  set("exits", ([ 
  "southwest" : __DIR__"room031",
]));
  set("new_exits",([
]));

}
void reset()
{
  old_reset();
}
