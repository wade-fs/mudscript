// Room: /open/gsword/room/eghouse.c
inherit ROOM;

void create ()
{
  set ("short", "長廊");
  set ("long", @LONG
這是一條細長的走廊，一走到這，你可以聞到北邊傳來陣陣的飯菜香，
直讓你滿嘴的口水直流，肚子咕咕的叫了起來。你想這劍派不但武功，
一流，連廚藝都令人讚嘆不已，真是莫測高深。左手是一間大通鋪 ,右
邊則是儲藏室 .

LONG);

  set("exits", ([ /* sizeof() == 4 */
  "west" : "/open/gsword/room/g3-1.c",
  "north" : "/open/gsword/room/g3-4.c",
  "out" : "/open/gsword/room/g2-15.c",
  "east" : "/open/gsword/room/g3-3.c",
]));

  set("light_up", 1);

  setup();
}
