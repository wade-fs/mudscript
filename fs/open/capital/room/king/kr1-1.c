
#include <ansi.h>
inherit ROOM;

void create ()
{
  set ("short", "慈禧殿");
  set ("long", @LONG
這兒就是當今皇太后慈禧太后的寢宮，因為年事已大，所以太后
大部份的時間都待在寢宮中休息，偶而公主會跑來找太后撒嬌一下，
除此之外，就是每天早晨皇上會來請安了。不過你卻看到太后的房裡
掛著一把刀，使你猜不透那把刀是用來作什麼的。
LONG);

  set("objects", ([ /* sizeof() == 1 */
  "/open/capital/npc/kmother" : 1,
  "/open/capital/npc/kingirl" : 2,
]));
  //set("outdoors", "/open/capital");
  set( "light_up", 1 );
  set("no_transmit", 1);
  set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"kr2-3",
]));

  setup();
}
void init()
{
        add_action("do_exert","exert");
}
int do_exert(string str)
{
 object me;
 me=this_player();
 if(str=="roar"){
 message_vision(HIC + "皇宮守衛大聲的對你說:皇城禁地豈容你大聲喧嘩，還不快滾!!!\n" + NOR,me);
 return 1;
                }
 else
 {
 return 0;
 }
}
