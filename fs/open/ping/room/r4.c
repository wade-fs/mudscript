// Room: /u/m/moner/open/room/r4.c 
inherit ROOM;
 
void create ()
{
  set ("short", "二樓樓梯");
  set ("long", @LONG

    往上可以通往三樓, 往下回到一樓, 樓梯的扶手和整座樓梯都是選用上等
木材製造的, 它的雕工精細的讓你真是嘆為觀止, 往西是二樓的走廊。


LONG);

  set("exits", ([ /* sizeof() == 3 */
  "up" : __DIR__"r3.c",
  "west" : __DIR__"r5.c",
  "down" : __DIR__"r7.c",
]));

  setup();
  replace_program(ROOM);
}
