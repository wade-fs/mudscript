// Room: /open/prayer/room/tanshu/19.c

inherit ROOM;

void create()
{
	set("short", "茅廁");
	set("long", @LONG

    嗚～好臭！一進來就聞到了米田共的味道，這邊是茅廁，坑坑洞
洞的，連個門也沒有，本門的弟兄如果有人犯錯，通常會被門主罰來
這裡掃茅廁，如果沒事不要待在這裡，以免被誤會在這做壞事！         

LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"18.c",
]));
	set("no_clean_up", 0);

	setup();
	}
