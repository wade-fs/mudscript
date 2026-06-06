// Room: /u/r/rence/room/happy.c

inherit ROOM;

void create ()
{
  set ("short", "喜塔");
  set ("long", @LONG

塔門的上方有一塊木雕，上頭所著的火寫著『"HIR"喜塔"NOR"』，整座塔
共分兩層，塔的四周長滿了爬藤類的植物，微風吹來，藤蔓隨之擺盪，好
一股清幽的氣氛。塔門旁站著一為接待員，笑嘻嘻地望著你。

LONG);

  set("objects", ([ /* sizeof() == 1 */
  "/u/r/rence/npc/gmob2.c" : 1,
]));
  set("outdoors", "/u/r/rence");
  set("exits", ([ /* sizeof() == 2 */
        "out" : "/u/r/rence/room/road",
        "enter" : "/u/r/rence/room/floor5",
]));

  setup();
}
