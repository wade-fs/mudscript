inherit ROOM;
#include <ansi.h>
void create ()
{
  set ("short", "樓梯");
	set( "build", 15 );
  set ("long", @LONG
看來這裡是通往三樓的樓梯，走到這裡你已經打得手有點發軟，而傳
說中三樓才是妖魔古堡的菁英聚集地帶，各式奇幻的武功和厲害的妖
魔正準備頃巢而出。不過上樓前卻看到一個滿臉殺氣的惡鬼橫在樓梯
間？
LONG);
set("evil", 1);
set("no_auc", 1);
set("no_transmit", 1);
set("light_up", -1);

  set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"room34",
  "up" : __DIR__"room41",
]));
  
  set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/ground-ghost.c" : 1,
]));

  setup();
}
int valid_leave(object me, string dir)
{
 object ob;
 me=this_player();
 ob=this_object();
        if(dir=="up"&&present("ghost",environment(me)))
  {

message_vision(HIY + "地邪鬼對$N怒喝 : 幹什麼！？\n" + NOR,me);
 ob->kill_ob(me);

return 0;
}
return 1;
}
