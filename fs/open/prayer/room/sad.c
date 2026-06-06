inherit ROOM;

void create ()
{
  set ("short", "哀塔");
  set ("long", @LONG

塔門的上方有一塊木雕，上頭所著的火寫著『哀塔』，整座塔
共分兩層，塔的四周長滿了爬藤類的植物，微風吹來，藤蔓隨之擺盪，好
一股清幽的氣氛。塔門旁站著一為接待員，笑嘻嘻地望著你。

LONG);

  set("objects", ([ /* sizeof() == 1 */
  "/u/r/rence/npc/gmob4.c" : 1,
]));
  set("outdoors", "/u/r/rence");
  set("exits", ([ /* sizeof() == 1 */
	"out" : "/u/r/rence/room/road",
]));

  setup();
}
 
