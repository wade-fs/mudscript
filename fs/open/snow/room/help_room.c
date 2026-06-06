#include <room.h>
#include "/open/open.h"
inherit ROOM;

void create ()
{
  set("short","神秘小屋");
  set ("long", @LONG
這裡是一間極為神秘的小屋﹐你似乎對這裡不曾有
任何印象﹐你非常地懷疑這裡是否是陰曹地府 ?
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "west" : "/open/snow/room/help_room2",
]));


   set("light_up",1);


  setup();
}
