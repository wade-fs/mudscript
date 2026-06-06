inherit ROOM;
#include <room.h>
#include <ansi.h>
void create ()
{
  set ("short", "浴室");
  set ("long", @LONG

這裡是臥房內的浴室，青瓷鋪成的地板上沾滿了水跡，一個約水池大小
的浴池佔滿了整個房間，輕紗籠罩在一旁令你有一種矇朧之感，水氣氳
繞四周，百花飄落在浴池內。

LONG);

set("exits", ([ /* sizeof() == 1 */
"west":__DIR__"r1.c",
]));
  set("item_desc", ([ /* sizeof() == 1 */
  "west" : (: look_door,     "west" :),
]));
  set("objects", ([ /* sizeof() == 2 */
 "/daemon/class/blademan/npc/maid1.c" :2,
 "/daemon/class/blademan/npc/haing.c" :1,
]));
  set("light_up", 1);
create_door("west","螢珀石屏風","east",DOOR_CLOSED);
  setup();
}
     void init()
     {
    add_action("do_cmd","cmd");
    }
      int do_cmd(string arg)
   {
     object user;
     user=this_player();
   this_object()->kill_ob(user);
     return 1; 
}
