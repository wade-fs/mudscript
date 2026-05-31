// Room: /d/snow/sroad4.c

inherit ROOM;

void create ()
{
  set ("short", "[1;35m過去時空[0m 青石官道");
  set ("long", @LONG
這是一條寬敞堅實的青石板大道﹐大道兩旁種著整齊的花木﹐從這
裡往北的路帶著一點朦朧﹐往南則是銜接雪亭鎮街道的路口。
LONG);

  set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"sroad3",
  "north" : "/d/cele/sroad1",
]));
  set("outdoors", "snow");

  setup();
}
