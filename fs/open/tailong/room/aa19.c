inherit ROOM;

void create ()
{
  set ("short", "西院走廊");
  set ("long", @LONG
從這往東望,遠遠的就可以看到天龍寺的主建築物--大雄寶殿,天龍寺
的大雄寶殿比起其他寺廟要來得華麗多了,然而定睛一看,在大雄寶殿的
後面又延伸出一個小房間,不知道那間房間裡面有著什麼。
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"aa20",
  "south" : __DIR__"aa16",
]));

  setup();
  replace_program(ROOM);
}
