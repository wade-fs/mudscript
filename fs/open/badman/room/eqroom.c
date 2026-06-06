// Room: /open/badman/room/eqroom.c
inherit ROOM;

void create ()
{
  set ("short", "惡人的EQ儲存室");
  set ("long", @LONG
這是用來讓惡人休息及惡人的前輩為了要照顧後輩所做的寶物儲存室...
看者這許多的寶物..大家要有...感謝先輩的照顧.... .
LONG);

  set("light_up", 1);
  set("no_magic", 1);
  set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"g1",
]));
  set("no_fight", 1);

  setup();
}
