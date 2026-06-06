// Room: /open/main/room/M12b.c

inherit ROOM;

void create()
{
	set("light_up",1);
	set("short", "環山長廊");
	set("long", @LONG
	走到這雲霧已不如剛剛那樣的濃密，可以確定的確有
	東西在燃燒，但奇特的是那火勢一直保持著同樣的大
	小，似乎不會受到山風吹襲的影響。


LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "westup" : __DIR__"M11a",
  "eastdown" : __DIR__"M13b",
]));

	setup();
}
