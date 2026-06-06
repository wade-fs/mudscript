// Room: /open/gsword/room/su7.c

inherit ROOM;

void create ()
{
  set ("short", "青石小徑");
  set ("long", @LONG
走在青石小徑上,這裡已不是蜀中鬧區,高大的建築漸漸減少,取代
的是一般平房,你西方有一潭清水,正是聞名的蜀中昆明湖.
LONG);

  set("exits", ([ /* sizeof() == 3 */
  "north" : "/open/gsword/room/suroom0",
  "west" : "/open/gsword/room/lake2",
  "south" : "/open/gsword/room/su6",
]));

  set("outdoors", "/open/gsword");

  setup();
}
