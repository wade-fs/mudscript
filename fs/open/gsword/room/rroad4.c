#include <room.h>

 inherit ROOM;

 void create()
{
        set("short", "小徑");
        set("long", @LONG
這是一條滿佈青苔的小路,由地上的痕跡看來,這似乎鮮少有人經過,
兩旁的巨石足足有10尺高,看的你不禁連連咋舌,前方暗濛濛的一片
隱隱約約好像看到有兩個人的身影.          



LONG
        );

        set("exits", ([
"north": "/u/b/bigcat/room/lnroad1",
"down": "/u/b/bigcat/room/rroad2"
        ]) );
        
setup();

}
