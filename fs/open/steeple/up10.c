inherit ROOM;
string moveout();
#include <ansi.h>
void create()
{
set("short","試煉塔中繼站");
set("long",@LONG

你可以看到許多挑戰者正在此休息、聊天，每個人的臉上都看不出來剛剛
打打殺殺的疲憊感，反倒是露出了十分輕鬆的笑容，看來能來到這裡的人
都已經有了一些最基本的功力了。

在房間的正中央有個透明的玻璃柱狀物(glass pillar)。
LONG);
set("exits",([
"up":__DIR__"busy_room11.c",
]));
set("item_desc",([
"glass pillar":(:moveout:),
"pillar":(:moveout:),
]));
set("no_die_room",1);
set("light_up",1);
set("no_fight",1);
set("no_transmit",1);
set("no_auc", 1);
setup();
}
int valid_leave(object me,string dir)
{
if(dir=="up")
{
int check=me->query("quest/start_game");
if(check<11)
{
tell_object(me,HIR + "系統：你的晶片資料不足以通往樓上。\n" + NOR);
return 0;
}
{
message_vision(HIW + "系統：讀取"+me->query("name")+"晶片，通過。\n" + NOR,me);
return 1;
}
}
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
