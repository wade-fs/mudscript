inherit ROOM;
#include <ansi.h>
void create ()
{
  set ("short", "古堡三樓");
	set( "build", 53 );
  set ("long","牆壁上點著青綠色的鬼火，仔細一看是由酷似骷髏\的銀器作成燈座，綠
光便由骷髏\的兩隻眼睛裡射出，豪華中透著恐怖的氣息。地上也鋪著厚
厚的地毯，令人不禁驚奇地東張西望。四周的妖魔似乎也都披金戴銀，
性情也溫和的多，但一身武藝看起來比樓下的是有過之而無不及。此
關是由羅剎女把守，看前方那位英氣勃勃且美豔萬分的女將不就是煉
陰女，焚天手下一等一的女將嗎。
");
set("evil", 1);
set("no_auc", 1);
set("no_transmit", 1);
set("light_up", -1);

  set("exits", ([ /* sizeof() == 1 */
  
  "north" : __DIR__"room62",
  "west" : __DIR__"room58",
]));
  
  set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/locha-queen.c" : 1,
]));

  setup();
}
int valid_leave(object me, string dir)

{
        if(dir=="north"&&present("locha queen",environment(me)))
  {

message_vision(HIY"煉陰女說:「先露一手能服我的真功\夫吧！」\n"NOR,me);

return 0;
}
return 1;
}
