//by Casey
inherit ROOM;
#include <ansi.h>
void create ()
{
  set ("short", HIW"天雷崖上"NOR);
  set ("long", @LONG
艱難的靠著山壁間凸起的石塊 ,你登上了這座山
崖。濃雲密怖著 ,處處閃爍著電光 ,周圍的樹木盡
是焦黑的斷枝殘梗

LONG);
  set("outdoors", "/u/p");
  set("no_transmit", 1);
  set("exits", ([ /* sizeof() == 1 */
 "climb" : __DIR__"d-7",
 
 ]));
  set("evil", 1);
  set("no_auc", 1);

  setup();
}


