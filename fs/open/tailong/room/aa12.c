inherit ROOM;

void create ()
{
  set ("short", "走道");
  set ("long", @LONG
往這裡走來也有一段時間了,在路旁的石椅正好可以讓你休息一下好
好看看這裡的景色,四周扶疏的樹木,旁邊的小池塘,遠處的華麗樓閣,都讓
你覺得好像身處在大戶人家的庭園中,而不是在寺廟中, 然而在不遠處矗
立的高塔更引起你一探究竟的好奇心
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"aa10",
  "east" : __DIR__"aa14",
]));

  setup();
  replace_program(ROOM);
}
