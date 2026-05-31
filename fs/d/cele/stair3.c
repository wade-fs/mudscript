inherit ROOM;

void create ()
{
  set ("short", "[1;35m過去時空[0m 白石階梯");
  set ("long", @LONG
    你現在正走在一條長長的白石階梯上﹐階梯隨著山峰蜿蜒盤旋﹐宛
如一條白龍﹐水煙閣就矗立在北邊的山峰頂上﹐即使是從這麼近的距離
你仍然感覺這座樓閣飄飄渺渺﹐難以捉摸。

LONG);

  set("outdoors", "cele");
  set("exits", ([ /* sizeof() == 1 */
  "northup"  : "/d/cele/frontyard",
  "eastdown": "/d/cele/stairtop",
]));


  setup();
}
