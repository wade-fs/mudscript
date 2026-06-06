#include <room.h>

 inherit ROOM;

 void create()
{
        set("short", "樹洞");
        set("long", @LONG
這是樹身的內部,想不到這竟然別有洞天,兩把半熄的火把(torch)掛在左上角,火光
忽明忽滅,前方還不時傳來悽厲的吼叫聲,分不清到底是野獸亦或是人類,使你對這兒
產生一種莫名的恐懼,          
LONG
        );

        set("item_desc",(["torch":
"兩把即將熄滅的火把\n"]));        
        
        set("exits", ([
		"out": "/u/b/bigcat/room/lnroad1",
                "north":"/u/b/bigcat/room/tree1"
        ]) );
        
setup();
}
