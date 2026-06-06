// Room: /u/p/pokai/room/wu/l
inherit ROOM;

void create()
{
  set ("short", "武威七殺塔二樓--");
  set ("long", @LONG
踏入這兒給你的第一個印象，還是那片惱人的暗紅色，和著地上斑斑的
血跡，使你覺得這兒充滿一片血腥，不禁有一股衝動想要往回走。
LONG);

  set("light_up", 1);
  set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"tower2-3",
  "north" : __DIR__"tower2-1",
]));
  setup();
}
