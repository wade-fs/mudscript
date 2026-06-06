//by Casey
inherit ROOM;
#include <room.h>
#include <ansi.h>
void create ()
{
  seteuid(getuid());   
        set("short",MAG"地底牢籠"NOR);
	set( "build", 27 );
        set("long", @LONG
你來到一間漆黑無比的房間，空氣中全是瀰漫著腐屍和膿
血的味道就算有著火把，還是不能將四周看的十分清楚，從牢
籠的深處，還傳來十分微弱的動物呼吸聲...


LONG
        );       
  set("light_up", -1);
 set("evil", 1);
  set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"f-7",
 "north" : __DIR__"f-0",
 "east" : __DIR__"f-2",
 


]));
  set("no_transmit",1);
  set("no_auc",1);
 
  
  setup();
}


