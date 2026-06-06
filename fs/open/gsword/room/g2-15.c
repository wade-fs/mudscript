// Room: /open/gsword/room/nghouse.c
inherit ROOM;

void create ()
{
  set ("short", "大長廊");
	set( "build", 48 );
  set ("long", @LONG
仙劍派的大長廊 ,連接派內各廳堂 ,兩側的牆壁上滿是當年仙劍派的
開山祖師--逍遙子--大戰群魔的情景，看著祖師爺身形飄忽，一隻木劍在
手中竟能使的如此渾圓如意，看的你心炫神怡。北邊的三樓大屋就是仙劍
生活重心 -- 流雲軒 .南邊是掌管財物收支的帳房 .

LONG);

  set("exits", ([ /* sizeof() == 4 */
  "west" : "/open/gsword/room/g2-16.c",
  "south" : "/open/gsword/room/g2-17.c",
  "east" : "/open/gsword/room/g2-14.c",
  "enter" : "/open/gsword/room/g3-2.c",
]));

  set("light_up", 1);

  setup();
}
