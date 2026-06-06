inherit ROOM;
#include <ansi.h>
void create () {
set ("short",HIB"青龍室"NOR);
	set( "build", 12 );
        set ("long","這裡就是青龍密室，牆上雕著一隻栩栩如生張牙舞爪的青色巨龍，
但是屋內正中央放著一本密笈，隱隱有火焰繚繞，寶光流動不息，
令你不禁呆了一呆。
");

        set("evil", 1);
        set("no_auc", 1);
        set("no_transmit", 1);
        set("light_up",-1);
        set("exits", ([
            "north" :  __DIR__"room37",
      ]));
        set("objects",([ /* sizeof() == 1 */
        __DIR__"obj/fire_book" : 1,
        __DIR__"obj/sspill" : 2,
      ]));

        setup();
}
