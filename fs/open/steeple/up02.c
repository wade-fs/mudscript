inherit ROOM;
#include <ansi.h>
void create()
{
set("short","試煉塔三樓");
set("long",@LONG

這是試煉之塔最最簡單的一層樓，裡面不外乎是一堆阿貓阿狗，
看來應該是很簡單就能通過了。

LONG);
set("exits",([
"up":__DIR__"busy_room03",
"south":__DIR__"busy_room02",
]));
set("no_die_room",1);
set("light_up",1);
set("no_transmit",1);
set("no_auc", 1);
set("objects",([
__DIR__"obj/robot03":1,
]));
setup();
}

int valid_leave(object me,string dir)
{
if(dir=="up")
{
int check=me->query("quest/start_game");
if(check<=3)
{
tell_object(me,HIR + "系統：你的晶片資料不足以通往樓上。\n" + NOR);
return 0;
}
{
message_vision(HIW + "系統：讀取"+me->query("name")+"晶片，通過。\n" + NOR,me);
return 1;
}
}
if(dir=="south")
return 1;
}
