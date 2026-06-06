// Room: /open/dancer/room/roomse3.c :cgy

inherit ROOM;

void create ()
{
  set ("short", "花園小徑");
  set ("long", @LONG
這是一條小徑，兩旁長滿了各式的鮮花，令人目不暇給，芬芳的
花香令人流連忘返，美麗的鮮花令人不禁想近而褻玩焉東邊是涼亭池
而西邊則是噴水池。

LONG);

  set("exits", ([ /* sizeof() == 2 */
  "west" : "/open/dancer/room/roomse2.c",
  "east" : "/open/dancer/room/roomse4.c",
]));

  set("light_up", 0);

  setup();
}
