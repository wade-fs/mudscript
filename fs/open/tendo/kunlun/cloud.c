//雲 by frequency
#include <ansi.h>
inherit ROOM;

void create ()
{
  set ("short", HIW + "雲霧內" + NOR);
  set ("long", @LONG
四周觸目所及，皆是白茫茫的雲氣霧氣，根本看不清前方景象，
你只能憑著大無畏的勇氣繼續前進了。
LONG);

  set("exits", ([
  "east" : __DIR__"cloud.c",
  "west" : __DIR__"cloud.c",
  "north" : __DIR__"cloud.c",
  "south" : __DIR__"cloud.c",
               ]));
  set("no_transmit",1);
  setup();
}

int valid_leave( object me, string dir )   
{        
	me = this_player();
	message_vision(HIW + "$N在雲霧環繞之下盲目前進。\n" + NOR,me);                                    
        if(dir=="west" || dir=="east" || dir=="south" || dir=="north")
        { 
          if(!userp(me)) {
            me->move(__DIR__"cloud2.c");
            return notify_fail("你到達了更深一層的雲霧中\n");
          }
          if(random(20) == 1)
          {
          me->move(__DIR__"cloud2.c");
          me->start_busy(1);
          return notify_fail("你到達了更深一層的雲霧中\n");
          }
        }
        return 1;
} 
