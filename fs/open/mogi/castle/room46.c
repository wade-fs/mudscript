
inherit ROOM;
#include <ansi.h>
void create ()
{
  set ("short", "古堡三樓");
  set ("long","牆壁上點著青綠色的鬼火，仔細一看是由酷似骷髏\的銀器作成燈座，綠
光便由骷髏\的兩隻眼睛裡射出，豪華中透著恐怖的氣息。地上也鋪著厚
厚的地毯，令人不禁驚奇地東張西望。四周的妖魔似乎也都披金戴銀，
性情也溫和的多，但一身武藝看起來比樓下的是有過之而無不及，你不
禁懷疑自己真是在魔界？
           
                  前方似乎有人躺在走道中？
");
set("evil", 1);
set("no_auc", 1);
set("no_transmit", 1);
set("light_up", -1);

  set("exits", ([ /* sizeof() == 1 */
  
  "north" : __DIR__"room47",
  "south" : __DIR__"room40",
  "west" : __DIR__"room67",
  "east" : __DIR__"room74",
]));
  
  set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/drunk-ghost.c" : 1,
]));

  setup();
}
int valid_leave(object me, string dir)

{
        if(dir=="north"&&present("ghost",environment(me)))
  {

message_vision(HIY"醉魔喃喃說：「唔...酒再來一罈...」\n"NOR,me);

return 0;
}
return 1;
}
