// Room: /u/d/dhk/questsfan/rm27
inherit ROOM;
#include <ansi.h>
void create ()
{
  set ("short", "百草谷");
  set ("long", @LONG
顧名思義，就是充滿各式各樣的奇花異草的山谷。這裡可以說是
整座嵩山數有藥用、療效的奇花異草最聚集，也是最齊全的地方。而
且傳聞這裡住著一位有著〝毒神藥聖〞之稱的前輩，也因為他的存在
令整座百草谷更增添不少神秘的色彩。

LONG);

  set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/oldman.c" : 1,
]));
  set("exits", ([ /* sizeof() == 1 */
  "eastup" : __DIR__"rm21",
]));
  set("outdoors", "/u/d");
  set("no_fight",1);

  setup();
}
