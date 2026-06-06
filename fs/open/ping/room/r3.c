// Room: /u/m/moner/open/room/r3.c 
inherit ROOM;
 
void create ()
{
  set ("short", "三樓樓梯");
  set ("long", @LONG

往下可以回到二樓, 樓梯的扶手和整座樓梯都是選用上等木材製造的,
它的雕工精細的讓你真是嘆為觀止, 往西是三樓的走廊。


LONG);

  set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"r2.c",
  "down" : __DIR__"r4.c",
]));

  setup();
replace_program(ROOM);
}
