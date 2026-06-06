#include <room.h>

 inherit ROOM;

 void create()
{
        set("short", "高山森林");
        set("long", @LONG
這是一片無盡的樹海，在濃密的樹葉遮擋下，只有少數的光線能從隙縫中
透出，樹林中偶有飛禽走獸穿梭，高山的低溫加上缺乏陽光的溫暖，使你
感到一陣陣的寒意湧上心頭。\n
LONG
        );

        set("exits", ([
"east":__DIR__"forest1",
                "north":"/u/b/bigcat/room/forest4",
"south":__DIR__"forest2"
        ]) );
setup();

}
