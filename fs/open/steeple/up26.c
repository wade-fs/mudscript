inherit ROOM;
#include <ansi.h>
void create()
{
set("short","試煉塔二十六樓");
set("long",@LONG

機器運轉的聲音隆隆作響，每一次轉動的聲響都讓你身心不自主的
鼓動起來，看來這裡的強度已經不再是一般人所能輕易通過了，沒
有一定的強度以上，或許只能在這附近徘徊不進吧。

LONG);
set("exits",([
"up":__DIR__"busy_room27",
"south":__DIR__"busy_room26",
]));
set("no_die_room",1);
set("light_up",1);
set("no_transmit",1);
set("no_auc", 1);
set("objects",([
__DIR__"obj/robot26":1,
]));
setup();
}
int valid_leave(object me,string dir)
{
if(dir=="up")
{
int check=me->query("quest/start_game");
if(check<27)
{
tell_object(me,HIR"系統：你的晶片資料不足以通往樓上。\n"NOR);
return 0;
}
{
message_vision(HIW"系統：讀取"+me->query("name")+"晶片，通過。\n"NOR,me);
return 1;
}
}
if(dir=="south")
return 1;
}
