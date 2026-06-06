// Room: /open/bonze/room/k01.c
//增加共用檔案與調整npc位置 by blazakira 2010/11/22

#include "bonze.c"
inherit ROOM;
void create ()
{
  set ("short", "伙房");
  set ("long", @LONG
這裡是少林寺的伙房，為了應付少林寺龐大的人口，到處都是特大
號的煮飯工具。伙房師父忙進忙出的，手上拿著各式的工具開始開伙，
如果少林弟子有需要的話，還可以跟這些師父要吃的。
LONG);

  set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"k03.c",
  "west" : __DIR__"k07",
  "east" : __DIR__"k04.c",
  "south" : __DIR__"k02.c",
]));
  set("no_magic", 1);
  set("no_fight", 1);
  set("light_up", 1);
  set("objects", ([ /* sizeof() == 1 */
  FQ_NPC"k_monk2.c" : 1,
]));

  setup();
}

//測試是否可以阻擋移動之npc
int valid_leave(object me, string dir)
{
	if (dir=="west" && me->query_temp("quests/bonze/stop")) //如果要往west離開 且 有mark ("quests/bonze/stop") 時 阻擋之!
//	if(!wizardp(me))
		return notify_fail("STOP!\n");
	return 1;
}
