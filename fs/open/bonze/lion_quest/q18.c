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
//    "east" : __DIR__"q19.c", //三神僧quest未完成 所以不開放通行 by blazakira
    "west" : __DIR__"q17.c",
	]));

  set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/b9_swordman_disciple.c" : 1,
	  ]));

  setup();
}

/* 暫時不特地做安全區 解謎不清怪 讓玩家有點風險也比較有趣
//測試是否可以阻擋移動之npc
int valid_leave(object me, string dir)
{
	if (dir=="east" && me->query_temp("quests/bonze/mob") == 1) //如果要往east離開 且 有mark ("quests/bonze/mob") 時 阻擋之!
//	if(!wizardp(me))
		return notify_fail("STOP!\n");
	return 1;
}
*/