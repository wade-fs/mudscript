// Room: /u/r/ranko/room/v3.c
inherit ROOM;

void create ()
{
  set ("short", "隔世村中央");
  set ("long", @LONG
這裡是隔世村的正中央，兩旁接著村中的大路，往北及往南則
各有一條小路，此處有一口青石砌成的水井，是村裡用水的來源之
一，許多村民正在此地排隊等待汲水。
LONG);
  

  set("objects", ([ /* sizeof() == 1 */
  "/open/poison/obj/well.c" : 1,
  "/open/poison/npc/oldman.c" : 1,
]));
  set("light_up", 1);
  set("outdoors", "/open/poison");
  set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"pa4.c",
  "west" : __DIR__"v2-5.c",
  "north" : __DIR__"pa1.c",
  "east" : __DIR__"v2-4",
]));

  setup();
}
