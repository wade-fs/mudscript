inherit ROOM;
#include <ansi.h>
void create()
{
set("short","試煉塔傳送站");
set("long",@LONG

這裡放置著列代挑戰天閣的人物，每一張挑戰書都有著悠久的
年代歷史，看來試煉之塔也是算文明古物了。
在地上散落著一些泛黃的紙(papers)。

LONG);
set("no_die_room",1);
set("no_fight",1);
set("light_up",1);
set("item_desc",([
"papers":"恭喜你獲得挑戰天閣的資格，但礙於目前NPC數未全，所以先到處為止。\n",
]));
set("no_transmit",1);
set("no_auc", 1);
setup();
}
