// Room: /open/gsword/room/eghouse.c
inherit ROOM;

void create ()
{
  set ("short", "長廊");
  set ("long", @LONG
這是一條細長的走廊，一走到這，你可以聞到西邊傳來陣陣的飯菜香，
直讓你滿嘴的口水直流，肚子咕咕的叫了起來。你想這劍派不但武功，
一流，連廚藝都令人讚嘆不已，真是莫測高深。
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "west" : "/open/gsword/room/eghouse1.c",
  "east" : "/open/gsword/room/north.c",
]));

  set("light_up", 1);

  set("file_name", "/open/gsword/room/eghouse.c");

  setup();
}
