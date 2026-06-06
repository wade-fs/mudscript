//tesinroad
#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", HIY"鐵心居"NOR);
        set("long", @LONG
走出樹林.頓時海闊天空.你見到一個完全不屬於中原武林的景象...
你正前方有一個類似房屋的建築.路旁亦發現一顆極大的花崗石..上面
寫著『鐵心居』。
LONG );
        set("exits", ([ /* sizeof() == 3 */
 "enter":"/open/gsword/room2/tesinroom.c",
 "south":"/open/gsword/room2/tesinroad1.c",

]));
        set("light_up",1);
        set("no_transmit", 1);
        setup();
}




