inherit __DIR__"underjail.c";
#include <ansi.h>
void create()
{
  old_create();
  set("exits", ([ 
  "west" : __DIR__"room00c",
  "east" : __DIR__"room00e",  
]));
  set("new_exits",([
]));

}
void reset()
{
  old_reset();
}
