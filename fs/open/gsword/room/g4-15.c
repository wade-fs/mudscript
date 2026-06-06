// Room: /open/gsword/room/g4-15.c
inherit ROOM;

void create ()
{
  set ("short", "太和殿");
	set( "build", 25 );
  set ("long", @LONG
一間寬廣的大殿，地上鋪著大紅毛毯，北首擺了八張大椅，應該是輩
分較高者之座倚，當掌門有要事公佈，往往會集結眾弟到太和殿，而一年
一度的派內比武大會，也是在此舉行。

LONG);

  set("exits", ([ /* sizeof() == 2 */
  "west" : "/open/gsword/room/g6-1.c",
  "east" : "/open/gsword/room/g4-11.c",
]));

  set("objects", ([ /* sizeof() == 1 */
         "/daemon/class/swordsman/cutegirl" :1,
]));

  set("light_up", 1);

  setup();
}
