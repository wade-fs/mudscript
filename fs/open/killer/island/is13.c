// Room: /u/u/unfinished/room/is13.c
inherit ROOM;

void create ()
{
  set ("short", "沙灘");
  set ("long", @LONG
小島的東北角. 海風不強, 沙灘上有許多螃蟹及貝殼, 景緻十分和諧, 是一
個休息的好地方. 除了螃蟹貝殼之外, 此處並沒有其他特別的事物. 西邊已不是
沙灘地形, 是遍地岩石的沿岸, 西邊高聳直立的岩壁顯得相當險峻.
LONG);

  set("outdoors", "/u/u");
  set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"is8.c",
  "west" : __DIR__"is12",
]));

  setup();
}
