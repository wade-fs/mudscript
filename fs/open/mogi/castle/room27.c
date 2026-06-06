inherit ROOM;
#include <ansi.h>
void create ()
{
  set ("short", "孤身不過廊");
	set( "build", 24 );
  set ("long","這條長廊就是古堡裡有名的「孤身不過」長廊，顧名思義，意指若你
想孤身闖過這道長廊簡直難如登天。沿途不但有越來越多的妖魔鎮守
更不知道那裡會有暗器射出。雖然長廊不見的很長，但是恐怖的程度
會讓你有永遠走不完的驚慄。
");
set("evil", 1);
set("no_auc", 1);
set("no_transmit", 1);
set("light_up", -1);

  set("exits", ([ /* sizeof() == 1 */
  
  "north" : __DIR__"room28",
  "south" : __DIR__"room26",
]));
  
  set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/mob5.c" : 3,
]));

  setup();
}
int valid_leave(object me, string dir)

{
        if(dir=="north"&&present("ghost",environment(me)))
  {

message_vision(HIY"八指飛魔冷笑道:「先過我這關吧！」\n"NOR,me);

return 0;
}
return 1;
}
