
#include <ansi.h>
inherit ROOM;

void create ()
{
  set ("short", "永德殿");
  set ("long", @LONG
這裡便是天子的寢宮永德殿，不過天子通常並不每天都在這裡睡
，有時就跑到後宮去跟那三千粉黛共度良宵，不過最主要的原因其實
是怕有刺客行刺，故每晚都換地方睡，你偷偷的進來之後，心想不拿
白不拿，好好的找找看看有沒啥好料的。
LONG);

  set("objects", ([ /* sizeof() == 1 */
//  "/open/capital/npc/Csoldier" : 1,
]));
  set("outdoors", "/open/capital");
  set("no_transmit", 1);
  set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"kr2-4",
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
 message_vision(HIC"皇宮守衛大聲的對你說:皇城禁地豈容你大聲喧嘩，還不快滾!!!\n"NOR,me);
 return 1;
                }
 else
 {
 return 0;
 }
}









