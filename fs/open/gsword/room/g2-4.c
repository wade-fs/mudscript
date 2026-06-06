// Room: /open/gsword/room/nghouse.c
inherit ROOM;

void create ()
{
  set ("short", "大長廊");
  set ("long", @LONG
仙劍派的大長廊 ,連接派內各廳堂 ,兩側的牆壁上滿是當年仙劍派的
開山祖師--逍遙子--大戰群魔的情景，看著祖師爺身形飄忽，一隻木劍在
手中竟能使的如此渾圓如意，看的你心炫神怡。長廊呈東西走向 ,東邊盡
頭是一片藥圃 ,南方為仙劍學術重心 -- 春秋閣 .北方是藥房 .

LONG);

  set("exits", ([ /* sizeof() == 4 */
  "north" : "/open/gsword/room/g2-2.c",
  "west" : "/open/gsword/room/g2-5.c",
  "south" : "/open/gsword/room/g2-3.c",
  "east" : "/open/gsword/room/g2-1.c",
]));

  set("light_up", 1);

  setup();
}
