// Room: /open/prayer/room/tanshu/16.c

inherit ROOM;

void create()
{
	set("short", "書房");
	set("long", @LONG

    這裡是門主的書房，門主個人最喜歡字畫，三不五時自己也喜歡
寫寫唐宋詩詞，牆上掛了一些古今名人的作品，原來葛輝如此愛好藝
術，主要是可以讓習武之人，減少幾分暴戾之氣。

LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "out" : __DIR__"4.c",
]));
	set("no_clean_up", 0);

	setup();
	}
