// Room: /u/m/moner/water/r1.c
inherit ROOM;

void create ()
{
  set ("short", "寢房");
  set ("long", @LONG

    這是魔刀新進弟子的寢房，剛入魔刀之人，因其心尚未完全至習刀
的境界，加上對環境的陌生，使的悟習刀招的效率降半，故把寢房設在
師父的左近，便於監導。一張竹籐編成的床橫臥在屋子中央。 

LONG);

  set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"r8.c",
"east":__DIR__"r1.c",
]));
  set("light_up", 1);

  setup();
}
