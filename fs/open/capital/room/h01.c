// Room: /open/capital/room/h01.c

inherit ROOM;

void create ()
{
  set ("short", "文來胡同");
  set ("long", @LONG
書生們為了彼此間能夠時常保持聯繫，做學術知識上的交流，於是
便在此地成立了工會，西面那座大宅就是書生工會。門口還貼著一副對
聯。
LONG);

  set("objects", ([ /* sizeof() == 1 */
  "/open/capital/npc/sch0" : 1,
]));
  set("outdoors", "/open/capital");
  set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"SCH",
  "east" : __DIR__"h04",
]));

  setup();
}
