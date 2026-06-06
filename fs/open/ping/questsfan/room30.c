// Room: /u/d/dhk/questsfan/room30
inherit ROOM;

void create ()
{
  set ("short", "虹晶橋後段");
  set ("long", @LONG
晶橋的後半段可能因為越來越接近另一岸了，同時也
較遠離斷崖中心了，其強勁的吸引力也緩和下來了。當你
踏到陸地的那一剎那、百感交集儼然覺得剛從鬼門關走了
一遭，但幸運的逛了回來了。哎！踩在陸地上的感覺真踏
實啊！！！

LONG);

  set("exits", ([ /* sizeof() == 2 */
  "godown" : __DIR__"room8",
  "fly" : __DIR__"room29",
]));
  set("outdoors", "/u/d");

  setup();
}
