// Room: /open/main/room/M11a.c

inherit ROOM;

void create()
{
	set("light_up",1);
	set("short", "環山長廊");
	set("long", @LONG
	距離那火光越來越近了，但卻感覺不到那火熱的氣息，
	反而是給人一種祥和的感覺，令人覺得十分的溫暖。


LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "westup" : __DIR__"M10",
  "eastdown" : __DIR__"M12b",
]));

	setup();
}
