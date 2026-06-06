//by Casey
inherit ROOM;
#include <ansi.h>
void create ()
{
  set ("short", HIC"迎風台上"NOR);
  set ("long", @LONG
冒著陣陣強風的襲捲 ,你艱辛的爬上一片高地。但
迎面而來的狂風令你連眼睛都難以睜開 ,在呼嘯的風
生之中 ,感到自己的渺小..

LONG);
  set("outdoors", "/u/p");
  set("no_transmit", 1);
  set("exits", ([ /* sizeof() == 1 */
 "westdown" : __DIR__"d-19",
 
 ]));
  set("evil", 1);
  set("no_auc", 1);

  setup();
}


