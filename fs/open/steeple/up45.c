inherit ROOM;
#include <ansi.h>
void create()
{
set("short","試煉塔四十五樓");
set("long",@LONG

異於往常的寧靜，周遭也無任何打鬥的痕跡，令你開始懷疑
這裡是屬於試煉塔的一部份嗎？過沒多久，一股極大的氣流
突然纏住了你，看來，這一次你有危險了！！

LONG);
set("exits",([
"up":__DIR__"busy_room46",
"south":__DIR__"busy_room45",
]));
set("no_die_room",1);
set("light_up",1);
set("no_transmit",1);
set("no_auc", 1);
set("objects",([
__DIR__"obj/robot45":1,
]));
setup();
}
int valid_leave(object me,string dir)
{
if(dir=="up")
{
int check=me->query("quest/start_game");
if(check<46)
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
