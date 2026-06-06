inherit __DIR__"underjail.c";
#include <ansi.h>
void create()
{
  old_create();
  set("exits", ([ 
  "west" : __DIR__"room00d",
  "northeast" : __DIR__"room00f",  
]));
  set("new_exits",([
]));

}
void reset()
{
  old_reset();
}
