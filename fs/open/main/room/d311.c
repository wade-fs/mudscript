#include <ansi.h>
inherit ROOM;
 
void create ()
{
  set ("short", "荒舞修羅道");
  set ("long", @LONG

    你正站在通往天界之城的必經之地，也是介於人神之間的悲劇性種族
 -- 修羅出沒的峽谷口，由於天界眾神與魔界之間長年的征戰，使得天界
元氣大傷，也讓修羅日漸坐大，虎視眈眈的想佔領天界之城，如果你想踏
進這塊危機四伏的區域，得先作好心裡準備。

LONG);

  set("objects", ([ /* sizeof() == 1 */
  "/u/s/superobs/statue.c" : 1,
]));
  set("outdoors", 1);
  set("exits", ([ /* sizeof() == 1 */
//"south" : __DIR__"sky1",
  "out" : __DIR__"d1",

]));

  setup();
}
