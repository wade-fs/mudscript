//open/prayer/room/youkoun/23.c

#include <room.h>
#include "/open/open.h"
 
inherit ROOM;
 
void create()
{
        set("short","密道");
        set("long",@LONG

        這密道裡鬼影幢幢, 內部還不時傳來奇怪的聲音, 聽起來
        好像是男人的叫聲!!可能嗎??瑤光門不是禁止男性進來嗎
        ??怎麼會有男人的叫聲??

LONG);

        set("exits", ([ /* sizeof() == 2 */
        "north":__DIR__"24",    
        "south":__DIR__"22",    
 
        ]) );
        set("no_fight", 0);
                
  setup();
}
