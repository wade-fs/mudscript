// Room: /u/m/moner/open/room/r7.c 
inherit ROOM;
 
void create ()
{
  set ("short", "一樓樓梯");
  set ("long", @LONG

    往上可以通往二樓, 樓梯的扶手和整座樓梯都是選用上等木材製造的
它的雕工精細的讓你真是嘆為觀止, 樓梯的兩旁也掛滿了火把。


LONG);

  set("exits", ([ /* sizeof() == 2 */
  "up" : __DIR__"r4.c",
  "west" : __DIR__"room14.c",
]));

  setup();
  replace_program(ROOM);
}
