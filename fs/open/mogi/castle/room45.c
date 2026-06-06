inherit ROOM;
#include <ansi.h>
void create () {
set ("short",HIW"白虎室"NOR);
	set( "build", 58 );
        set ("long","這裡就是白虎密室，牆上雕著一隻巨大的白色老虎，散發出懾人
的氣勢。但房間中央清香四溢，仙光隱隱流轉，走近一看是片小
小的葉子，看來這就是傳說中的三葉仙蘭，百年開花結果一次，
但結果後一刻鐘內果實爆裂汁液四散，常人根本無法目睹。
");

        set("evil", 1);
        set("no_auc", 1);
        set("no_transmit", 1);
        set("light_up",-1);
        set("exits", ([
            "north" :  __DIR__"room44",
                      ]));
        set("objects",([ /* sizeof() == 1 */
        __DIR__"obj/leave" : 1,
        __DIR__"obj/ninepill" : 5,
                      ]));

        setup();
}


