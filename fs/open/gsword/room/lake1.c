// Room: /open/gsword/room/lake1.c

inherit ROOM;

void create ()
{
  set ("short", "昆明湖北");
  set ("long", @LONG
你眼前一片湖光盪漾,昆明湖由此遠望,浩浩漡漡,向南延伸一片,
垂柳與畫眉的對話,畫舫與湖光的相映. 煙波,水氣,交織成這蜀 	
州名景昆明湖.
LONG);

  set("objects", ([ /* sizeof() == 1 */
  "/open/gsword/mob/visitor" : 1,
]));

  set("outdoors", "/open/gsword");

  set("exits", ([ /* sizeof() == 3 */
  "southeast" : "/open/gsword/room/lake2.c",
  "north" : "/open/gsword/room/froad0.c",
  "southwest" : "/open/gsword/room/lake0.c",
]));

  set ("資源/液體", ([
       "種類" : "水",
       "名稱" : "清水",
       "止渴" : 30
  ]) );

  setup();
}
