// Room: /u/d/dhk/questsfan/rm26
inherit ROOM;
#include <ansi.h>
void create ()
{
  set ("short", ""HIC"雲"WHT"中"HIC"天"NOR"");
  set ("long", @LONG
走過石林來到這片雲中天地，聽說這裡也是嵩山有名的名境之一
，但是聽說也是嵩山危險的區域之一。因為這兒的地理位置特殊。四
周又是白雲圍繞，若沒有掌握好時機，只要大霧一起。就有兩樣危險
: 1.會有迷路的危險。2.會有走向深淵因而失足掉落山淵的危險。但
是話說回來這兒若是輕霧狀時，那真有身置仙境之感。

LONG);

  set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"rm15",
]));
  set("outdoors", "/u/d");

  setup();
}
