inherit ROOM;
#include <ansi.h>
void create()
{
set("short","試煉塔八樓");
set("long",@LONG

看來這裡的強度似乎比以往來的強許多，可是這種程度的敵手，
實在是讓你提不太起勁來對付，看來這裡也能輕鬆通過。

LONG);
set("exits",([
"up":__DIR__"busy_room08",
"south":__DIR__"busy_room07",
]));
set("no_die_room",1);
set("light_up",1);
set("no_transmit",1);
set("no_auc", 1);
set("objects",([
__DIR__"obj/robot08":1,
]));
setup();
}

int valid_leave(object me,string dir)
{
if(dir=="up")
{
int check=me->query("quest/start_game");
if(check<=8)
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
