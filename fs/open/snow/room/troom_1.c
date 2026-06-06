// Room: /u/e/eiei/work/troom_1.c
inherit ROOM;

void create ()
{
  set ("short", "林間小徑");
  set ("long", @LONG
    走出雪蒼派的總部之後，就可以看到這一條通往山上的
    小路。路旁長滿了一些叫不出名字的植物，雖然看起來
    有點詭異，不過由於顏色鮮豔，所以散發出另一種美麗
    的氣息。
LONG);

  set("outdoors", "/u/e/eiei/work");
  set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"troom_0.c",
  "north" : __DIR__"troom_2.c",
]));

  setup();
}
