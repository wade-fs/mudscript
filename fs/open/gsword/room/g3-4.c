// Room: /open/gsword/room/eghouse.c
inherit ROOM;

void create ()
{
  set ("short", "長廊");
  set ("long", @LONG
這是一條細長的走廊，一走到這，你可以聞到北邊傳來陣陣的飯菜香，
直讓你滿嘴的口水直流，肚子咕咕的叫了起來。你想這劍派不但武功，
一流，連廚藝都令人讚嘆不已，真是莫測高深。

LONG);

  set("exits", ([ /* sizeof() == 2 */
  "north" : "/open/gsword/room/g3-6.c",
  "south" : "/open/gsword/room/g3-2.c",
]));

  set("light_up", 1);

  setup();
}
