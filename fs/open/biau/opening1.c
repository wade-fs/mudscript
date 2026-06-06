// Room: /open/su/room/biau_beyond.c

inherit ROOM;

void create()
{
	set("short", "鑣局校場");
	set("long", @LONG
往北一眼看去,到處都是練武用的器材,還有一群鑣師在互相切搓武藝,新進的
見習生正一板一眼的練習武功,喝聲震天,看來十分努力,往東去便是外堂,瓢把子
趙鼎天就在那裏接見外客.
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"armory",
//"south" : "/open/su/room/postoffice",
  "west" : __DIR__"opening0",
  "east" : __DIR__"room0",
]));

	setup();
}
