// Room: /open/gsword/room/g6-4.c
inherit ROOM;

void create ()
{
  set ("short", "懸崖下");
  set ("long", @LONG
你來到一片小廣場，北邊一片光禿禿的峭壁，正是仙劍派的思過崖，
這思過崖也並不如何高，只是地勢陡峭，看來十分兇險，東北方有條小徑
，似可登上懸崖，左首有條小徑，通往未知的地方，聽說除了掌門及輩份
較高的的仙劍七俠外，其它弟子皆不能擅入。
 
LONG);

  set("light_up", 1);
  set("outdoors", "/open/gsword");

  set("exits", ([ /* sizeof() == 4 */
  "northeast" : "/open/gsword/room/g6-5.c",
  "southeast" : "/open/gsword/room/g6-3",
  "west" : "/open/gsword/room/g6-8.c",
  "northwest" : "open/gsword/room/h-2.c",
]));

  setup();
}
