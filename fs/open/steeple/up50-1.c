inherit ROOM;
string moveout();
#include <ansi.h>
void create()
{
set("short","試煉塔傳送站");
set("long",@LONG

經過了漫長五十樓的打鬥後，你終於來到了可以通往天閣的
門檻了，四周猶如一個圓盤，而你就站在圓盤正中央，抬頭往
上看，一片浩瀚星空網羅眼底，閃亮的星星彷彿在祝福你一般
，不斷的發出閃爍的亮光，美不勝收。

在你身旁有個透明的玻璃柱狀物(glass pillar)。
LONG);
set("exits",([
"north":__DIR__"up50-2",
]));
set("no_die_room",1);
set("no_fight",1);
set("light_up",1);
set("no_transmit",1);
set("no_auc", 1);
set("item_desc",([
"glass pillar":(:moveout:),
"pillar":(:moveout:),
]));
setup();
}
string moveout()
{
object me;
me=this_player();
tell_object(me,HIW + "
這是一個玻璃柱狀的空柱，旁邊有一些按鈕(button)，你可以按下去。\n" + NOR);
return "\n";
}

void init()
{
add_action("do_push","push");
}

int do_push(string arg)
{
object me=this_player();
if(!arg)
return 0;
if(arg!="button")
{
tell_object(me,"你伸長ㄌ手，卻不找不到要按下的東西。\n");
return 1;
}
else
{
message_vision(HIW + "$N緩緩走進了玻璃柱狀內。\n" + NOR,me);
me->move(__DIR__"moveroom");
return 1;
}
}
