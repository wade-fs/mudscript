// Room: /open/prayer/room/tanshu/14.c

inherit ROOM;

void create()
{
	set("short", "練武場");
	set("long", @LONG

    你耳邊聽到了門生的叫喝聲,"殺～殺～",看他們頂著大太陽辛勤
的練武,看他們眼中充滿鬥志的眼神,無非想要有朝一日能學會先天乾
坤功,好揚名立萬.

LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"11.c",
  "south" : __DIR__"22.c",
]));
	set("objects", ([ /* sizeof() == 1 */
  "/open/prayer/npc/trainee2.c" : 1,
]));
	set("light_up", 1);
	set("no_clean_up", 0);

	setup();
	}
