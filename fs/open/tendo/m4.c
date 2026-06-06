// Room: /d/oldpine/epath2.c

inherit ROOM;

void create ()
{
	set ("short", "道路");
  set ("long", @LONG
這裡離蜀中已經很遠了，天氣卻不知怎地似乎有回升的現
象，並不像先前那樣地冰冷。  在這裡山勢為之平緩，平坦的
高原更凸顯出前方那座山脊的宏偉高大，凝神望去....似乎是
武林的道教勝地--------<<崑崙山>>!!

LONG);

  set("objects", ([ /* sizeof() == 1 */
//"/open/main/obj/torch" : 1,
]));

  set("outdoors", "/open/gsword");

  set("exits", ([ /* sizeof() == 2 */
"east" : "/open/tendo/m3",
"north" : "/open/tendo/kunlun/v1",
]));

  setup();
}
