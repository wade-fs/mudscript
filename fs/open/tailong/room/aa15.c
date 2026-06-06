inherit ROOM;

void create ()
{
  set ("short", "西院走廊");
  set ("long", @LONG
你沿著走廊往前走 ,沿路看著天龍寺中的各式華麗建築,突然在眼前延
伸出了一條叉路,往東北方一望,那邊好像有個美麗的花園,你可以試著往那
邊走過去看看,說不定會有什麼奇遇哦。
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"aa13",
  "north" : __DIR__"aa16",
]));

  setup();
  replace_program(ROOM);
}
