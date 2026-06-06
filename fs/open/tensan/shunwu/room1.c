inherit ROOM;
#include <ansi.h>
#include "room.msg"

void create () {
        set ("short","玄武幻陣");
        set ("long",
        "你一踏入玄武幻陣即發現此陣非比尋常，如果沒有做好萬全的準備\n"+
        "最好馬上離開\n"
        );
    
        set("no_auc", 1);
        set("no_transmit", 1);
        set("light_up",-1);
        set("exits", ([ /* sizeof() == 1 */
        "北門" : __DIR__"room2",
        "離陣" : __DIR__"room2",      
        ]));
  

        setup();
}
