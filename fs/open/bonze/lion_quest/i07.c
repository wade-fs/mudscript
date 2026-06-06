inherit ROOM;
#include "bonze.c"

void create ()
{
  set ("short", "營地內");
  set ("long", @LONG
與其說這座營地井然有序的模樣，不如說是從該營地的門面上就可
以看出是哪個門派駐紮在此地。在你眼前的主帳似乎是很有權力的人才
能持有的，可能可以從這裡詢問到這些門派集合起來的目的為何。

LONG);

  set("light_up", 1);
//  set("outdoors", "/u/b");
  set("no_transmit",1);
  set("exits", ([ /* sizeof() == 2 */
    "east" : __DIR__"i06.c",
    "enter" : __DIR__"i11.c",
	]));

  set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/b9_dancer_violet.c" : 1,
  ]));

  setup();
}

//測試是否可以阻擋移動之npc
int valid_leave(object me, string dir)
{
	if (dir=="enter" && me->query_temp("quests/bonze/mob") == 1) //如果要往enter離開 且 有mark ("quests/bonze/mob") 時 阻擋之!
//	if(!wizardp(me)) //本次設定只針對npc 所以不影響巫師行動
		return notify_fail("STOP!\n");
	return ::valid_leave(me,dir); //為valid_leave(me,dir)函數的結尾
}
