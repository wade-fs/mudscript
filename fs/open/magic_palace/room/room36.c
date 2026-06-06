inherit ROOM;
#include <ansi.h>
void create ()
{
set ("short","虹光之扉");
	set( "build", 54 );
set("long",@LONG
不同於前面幾處的詭譎變化，這裡有的只是一股你感到很熟悉的氣息，
面前這位老者，背上背著一柄木刀和紙劍，神元氣足，精芒內斂，不用說，
他就是中原正道第一人，四絕高手之一的武聖--劍光芒了，與魔界金典決戰
是英雄新經的宿命，也難怪他會在這裡了...
LONG);
        set("no_auc", 1);
        set("no_transmit", 1);
        set("light_up",-1);
        set("exits", ([ /* sizeof() == 1 */
        "north"     : __DIR__"room37",
      ]));
        set("objects", ([ /* sizeof() == 1 */
        "/open/magic_palace/npc/4-3.c" : 1,
      ]));
        setup();
}
/*
int valid_leave(object me,string dir)
{
	object obj = present("Sword Shining");
        if( dir == "north" )
        {
          if(obj)  return notify_fail(HIY"劍光芒"HIW"怒道:『中原武人無不對我敬若天神，你卻敢無視我的存在!?』\n"NOR);
        }

return 1;
}*/
