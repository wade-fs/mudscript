// Room: /u/d/dhk/questsfan/room29
inherit ROOM;

void create ()
{
  set ("short", "虹晶橋中段");
  set ("long", @LONG
踏著狹小的橋身，你似乎有著一股虛無縹緲的感覺。
又橋下的超強風速夾帶著強勁的吸引力，使得你一路搖搖
晃晃的。望著橋下完全見不到光的黑暗，使你不禁幻想此
崖到底有多身呢？一不留神差點摔了下去，冷汗直流。

LONG);

  set("exits", ([ /* sizeof() == 2 */
  "run" : __DIR__"room28",
  "fly" : __DIR__"room30",
]));
  set("outdoors", "/u/d");

  setup();
}
