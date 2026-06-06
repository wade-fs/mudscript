inherit ROOM;
#include <ansi.h>
void create ()
{
  set ("short", "樓梯");
	set( "build", 24 );
  set ("long", @LONG
這裡有一道木製的樓梯,看起來可以通到二樓,但是在樓梯前卻站
著一個惡鬼,手拿著大刀,以不懷好意的眼神看著你。
LONG);
set("evil", 1);
set("no_auc", 1);
set("no_transmit", 1);
set("light_up", -1);

  set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"room10",
  "west" : __DIR__"room19",
  "up" : __DIR__"room24",
]));
  
  set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/sky-ghost.c" : 1,
]));

  setup();
}
int valid_leave(object me, string dir)
{
 object ob;
 me=this_player();
 ob=this_object();
 if(dir=="up"&&present("sky-ghost",environment(me)))
  {

message_vision(HIY + "天邪鬼對$N怒喝 : 幹什麼！？\n" + NOR,me);
 ob->kill_ob(me);

return 0;
}
return 1;
}
