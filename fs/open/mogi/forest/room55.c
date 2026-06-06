// room7.1 by roger
// 新增quest <<皆傳之證>> 解謎要素
inherit ROOM;
#include <ansi.h>
void create () {
set ("short","魔森林");
	set( "build", 27 );
set("long",@LONG
    來到這裡,你覺得四周的氣氛突然凝重起來,似乎魔森林內的妖怪
全聚集在這裡,使你不敢再往前面通行,只想趕快離開這妖氣深重的地
方。

LONG);


        set("evil", 1);
        set("no_auc", 1);
        set("no_transmit", 1);
        set("light_up",-1);
        set("exits", ([ /* sizeof() == 1 */
      "east" : __DIR__"room48",
      ]));

        set("objects",([ /* sizeof() == 1 */
   __DIR__"npc/beast" : 1,
      ]));

        setup();
}

void init()
{
   object obj = this_object();
   object me = this_player();
   if(present("New_Hero Book",me))
   {
        tell_object(me,HIW + "\n\n\n\n天空中浮現三個詭異的太陽，同時" + HIC + "英雄真經" + HIW + "感受到此地幟盛的妖氣，頓時藍光大盛。\n" + NOR);
        set("exits/enter","/open/magic_palace/room/room1.c");
   }
}

int valid_leave(object me,string dir)
{
	me = this_player();
        if( dir == "enter" && present("New_Hero Book",me))
        {
                message_vision("$N一進入魔宮，大門立即關上。\n",me);
                delete("exits/enter");
        }
return 1;
}
