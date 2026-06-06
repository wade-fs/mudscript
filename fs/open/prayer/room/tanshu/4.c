// Room: /open/prayer/room/tanshu/4.c

inherit ROOM;

void create()
{
	set("short", "大廳");
	set("long", @LONG

    這裡是門主接見賓客的地方,上頭是葛輝的虎皮寶坐,左右兩排則
是紅檀木的椅子,牆上一幅金色龍頭的壁畫,使得葛輝不失一股霸氣,
他正高高在上,吩咐屬下職務。

LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"3.c",
  "west" : __DIR__"7.c",
  "east" : __DIR__"5.c",
  "enter" : __DIR__"16.c",
]));
	set("light_up", 1);
	set("objects", ([ /* sizeof() == 1 */
  "/open/prayer/npc/tanshu" : 1,
]));
	set("no_clean_up", 0);
	set("valid_startroom", 1);

	setup();
	}
