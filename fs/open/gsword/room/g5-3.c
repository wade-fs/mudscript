// Room: /open/gsword/room/nghouse.c
inherit ROOM;

void create ()
{
  set ("short", "大長廊");
  set ("long", @LONG
仙劍派的大長廊，連接派內各廳堂，兩側的牆壁上滿是當年仙劍派的
開山祖師〔逍遙子〕大戰群魔的情景，看著祖師爺身形飄忽，一隻木劍在
手中竟能使的如此渾圓如意，看的你心炫神怡。兩旁為客房。長廊向南北
延伸，北方為後堂，南邊為劍士公會總本部 ─ 凌霄寶殿。

LONG);

  set("exits", ([ /* sizeof() == 4 */
  "west" : "/open/gsword/room/g5-7.c",
  "north" : "/open/gsword/room/g5-4.c",
  "south" : "/open/gsword/room/g5-2.c",
  "east" : "/open/gsword/room/g5-6.c",
]));

  set("light_up", 1);

  setup();
}
