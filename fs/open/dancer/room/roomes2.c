// Room: /open/dancer/room/roomes2.c :cgy

inherit ROOM;

void create ()
{
  set ("short", "花園小徑");
  set ("long", @LONG
這是一條小徑，兩旁長滿了各式的鮮花，令人目不暇給，芬芳的
花香令人流連忘返，美麗的鮮花令人不禁想近而褻玩焉南邊即是噴水
池。

LONG);

  set("exits", ([ /* sizeof() == 2 */
  "north" : "/open/dancer/room/roomes1.c",
  "south" : "/open/dancer/room/roomse2.c",
]));

  set("light_up", 0);

  setup();
}
