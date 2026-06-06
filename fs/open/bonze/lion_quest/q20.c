inherit ROOM;
#include "bonze.c"

void create ()
{
  set ("short", "林間小徑");
  set ("long", @LONG
這是一條通往後山的林間小徑，茂密的矮樹叢與高大原始的山林是
這裡的主色調。風景絕佳景色優美，放眼望去鳥語花卉美不勝收，偶爾
會在這裡巧見樹蛙、蝴蝶、飛鷹…等原生生態下活躍的生物。

LONG);

  set("light_up", 1);
  set("outdoors", "/u/b");
  set("no_transmit",1);
  set("exits", ([ /* sizeof() == 2 */
    "west" : __DIR__"q21.c",
	]));
  set("objects", ([ /* sizeof() == 1 */
//  __DIR__"npc/b1_zhang_wuji_v1.c" : 1, //b1為解迷mob 暫無戰鬥力 設定完畢後 需改為具有戰鬥力的mob //未完成 所以開放時暫時取消 by blazakira
  __DIR__"npc/b9_dancer_violet.c" : 1,
]));
  setup();
}
