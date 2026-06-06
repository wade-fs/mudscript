// Room: /u/g/guetenr/beggar/room/beg2/clr3.c
inherit ROOM;

void create ()
{
  set ("short", "蒼鬱林道");
  set ("long", @LONG
一排夾道的榆樹林，向兩旁的山峰綿延而去，氣勢壯闊雄渾。舉目遠望
，四野微曦，一彎殘月垂掛在天際，鴻雁在遼闊的穹蒼來回地翻飛。一條寬
大的碎石道筆直地向東延伸，行進之間隱隱可聽見深山傳來陣陣的晨鐘，在
山林間繚繞迴盪不絕於耳。
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"clr2.c",
  "north" : __DIR__"clr4.c",
]));
  set("outdoors", "/open/");

  setup();
}
