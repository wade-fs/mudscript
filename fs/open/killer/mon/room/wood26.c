//written by acelan...../u/a/acelan/room/wood26.c
#include <ansi.h>

inherit ROOM;

void create()
{
        set("short", "岩壁");
        set("long", @LONG
似乎已經走到森林的盡頭了, 往前是一大片光禿禿的岩壁(wall)
, 看來已經沒有辦法再繼續前進了。微弱的陽光由後方的森林穿射而
出, 四周的殺意似乎減輕了許多, 但卻又多了幾分詭異與肅殺。
LONG
        );
   set("exits", ([ /* sizeof() == 1 */
       "south" : "/open/killer/mon/room/wood19.c",
   ]));

        set("no_clean_up", 0);
        set("item_desc", ([ /* sizeof() == 1 */
            "wall" : "這般光滑的岩壁, 若非有極高的輕功, 否則萬難攀登。\n",
        ]));
        set("search_desc", ([ /* sizeof() == 1 */
"wall" : "岩壁上似乎有著些許\腳印, 看來已有前輩高人來過此地。\n這不禁令你想要運起輕功\ (moveup), 上去一探究竟。\n",
        ]));
        setup();
}
void init()
{
   add_action("do_moveup", "moveup");
}
int do_moveup( string arg)
{
   object user;
   user= this_player();
   if( user->query("quest/rain")==1)
   {
      tell_object( user, HIW + "你大喝一聲, 運起輕功\, 飛快的往岩頂升去....\n" + NOR);
      user->move("/open/killer/mon/room/wood30.c");
   }
   else
   {
      tell_object( user, HIW + "你大喝一聲, 運起輕功\, 飛快的往岩頂升去....\n" + NOR);
      tell_object( user, HIR + "突然你運氣一個不順暢, 氣一濁, 旋即就沉身往下墜去...\n" + NOR);
      tell_object( user, HIB + "看來你的輕身功\夫並不足以攀登這片岩壁...\n" + NOR);
   }
   return 1;
}
