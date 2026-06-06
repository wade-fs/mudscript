// Room: /open/prayer/room/tanshu/17.c

inherit ROOM;

void create()
{
	set("short", "後院");
	set("long", @LONG

    陣陣花香朝你撲鼻而來，美麗的花蝴蝶在花叢中，舞出曼麗的舞
姿，黃鶯在枝頭上唱著清脆嘹亮的哥聲，正是鳥語花香的淨地，令你
想不到一代莽夫也能有此雅興。

LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"15.c",
  "east" : __DIR__"18.c",
]));
	set("objects", ([ /* sizeof() == 1 */
  "/open/prayer/npc/gardener1.c" : 1,
]));
	set("no_clean_up", 0);

	setup();
	}
