#include "/open/open.h"
inherit ROOM;

void create ()
{
  set ("short", "通吃小築後方");
  set ("long", @LONG

	這是通吃小築通往後山的山路，前方是一段陡峭的爬坡路段，
	相傳當年天下第一高手楊小邪就是在這裡鍛鍊出，天下第一的跑功！！
            所謂的跑功，就是不靠內力，純粹靠腳力的快速移動術！！
	你也想練看看嗎？  只可惜楊小邪與他師傅歐陽不空早已不知去向......

LONG);

  set("exits", ([ /* sizeof() == 3   */
     "north" : __DIR__"hr16.c",   
     "south" : __DIR__"hr7.c",   
]));

set("objects",([
  "/open/killer/npc/magnpc1.c":2,]));

  setup();
}

void init()
{
//
}

int do_look(string str)
{
  object me;

   if(str )
    return notify_fail("你想看什麼？？看看有沒有人救你嗎？？用哭的比較快啦！！\n");
   return 1;
}
