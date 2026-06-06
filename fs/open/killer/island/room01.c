#include <ansi.h>
inherit ROOM;
void create ()
{
set("short","房間");
set("long",@LONG
房間的擺設極為簡單，與平常人家的臥房沒有什麼兩樣，但是卻多了幾具殘缺
不全的屍骨與血漬，由此可見這裡似乎曾經有過廝殺的場面，而且由血漬噴灑的情
況看來，多半是一刀斃命，手法乾淨俐落，就連殺了不少人的你都不由得看的入迷
。
LONG);
set("exits",([
"east":__DIR__"b_r02",
]));
set("objects",([
__DIR__"npc/corpse01":1,
]));
setup();
}
void init()
{
        add_action("do_search", "search");
}

int do_search()
{
object me;
me = this_player();
if (me->query_temp("quest_corpse")==2)
{
tell_object(me,"這具屍體看起來完整多了!!\n");
return 1;
}
else
{
tell_object(me,"你發覺到屍體少了一些部位。\n");
me->set_temp("quest_corpse",1);
return 1;
}
}
