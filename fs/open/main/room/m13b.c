// Room: /open/main/room/M13b.c

inherit ROOM;

void create()
{
	set("light_up",1);
	set("short", "環山長廊");
	set("long", @LONG
	朦朧的雲霧，令人分不清時刻與方向，若要繼續往
	上走，只有沿著山壁的方向向上行走了。


	
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "westup" : __DIR__"M12b",
  "eastdown" : __DIR__"M14a",
]));

	setup();
}
