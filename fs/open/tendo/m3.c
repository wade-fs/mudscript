// Room: /d/oldpine/epath2.c

inherit ROOM;

void create ()
{
	set ("short", "道路");
  set ("long", @LONG
風聲颼颼，寒意更甚。遠方的山頂，依稀飄著幾朵白雲，一
片銀白。已讓你分不清是山或雲?!
LONG);

  set("objects", ([ /* sizeof() == 1 */
  "/open/main/obj/torch" : 1,
]));

  set("outdoors", "/open/gsword");

  set("exits", ([ /* sizeof() == 2 */
"west" : "/open/tendo/m4",
"east" : "/open/tendo/m2",
]));

  setup();
}
