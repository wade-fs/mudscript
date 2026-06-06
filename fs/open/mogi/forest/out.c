//調整為新版的re d的房間 by blazakira 2010/10/12
inherit ROOM;
#include <ansi.h>
void create ()
{
  set ("short", "魔森林盡頭");
  set ("long","
這裡就是魔森林的盡頭了，只見前方橫著一張大大的蜘蛛網，蜘蛛網上
爬著一隻巨大的蜘蛛，它就是傳說中的魔域入口看守者，網中人!!
");
set("evil", 1);
set("no_auc", 1);
set("no_transmit", 1);
set("light_up", -1);

  set("exits", ([ /* sizeof() == 1 */
  "enter":__DIR__"room58",  
    "west" : __DIR__"room57",
  "回到人間" : "/open/trans/room/room4",
]));
  
  set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/netor.c" : 1,
]));

  setup();
}
int valid_leave(object me, string dir)

{
        if(dir=="enter"&&present("netor",environment(me)))
  {

message_vision(HIY"網中人說：『讓我試試你的能耐吧\n"NOR,me);

return 0;
  }
       if(dir=="回到人間"){
me->set("startroom","/open/trans/room/room4");
message_vision(HIY"一陣天懸地轉,$N已回到人間了\n"NOR,me);
return 1;
                          }  
return 1;
}
