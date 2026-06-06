inherit ROOM;
#include <ansi.h>
void create ()
{
  set ("short", "古堡三樓");
	set( "build", 24 );
  set ("long","終於到了最後考驗的時候，一路殺將上來最終的目的就是要看看焚天魔王
的廬山真面目，眼前這黑白雙剎就是焚天的兩大護法，數千年來一直忠實
的聽令於魔王，他們不但各有驚人絕招而且相互呼應的攻守招式更是非同
小可。
");
set("evil", 1);
set("no_auc", 1);
set("no_transmit", 1);
set("light_up", -1);

  set("exits", ([ /* sizeof() == 1 */
  
  "north" : __DIR__"room93",
  "east" : __DIR__"room64",
]));
  
  set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/black-ghost" : 1,
  __DIR__"npc/white-ghost" : 1,
]));

  setup();
}
int valid_leave(object me, string dir)

{
        if(dir=="east"&&present("ghost",environment(me)))
  {

message_vision(HIY"黑白雙剎說:「閣下先露一手驚人的藝業吧！」\n"NOR,me);

return 0;
}
return 1;
}
