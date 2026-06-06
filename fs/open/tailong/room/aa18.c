inherit ROOM;

void create ()
{
  set ("short", "牟尼院");
  set ("long", @LONG
走進牟尼院內,頓時感到壓力倍增,面前是天龍寺中的三大高僧"觀、
相、參",三個人若列名在武林中也都是數一數二的高手,如今三人都聚在
此,天龍寺果然是一個臥虎藏龍之地。
LONG);

  set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"aa17",
]));
  set("objects", ([ /* sizeof() == 3 */
"/open/tailong/npc/chian.c":1,
"/open/tailong/npc/guan.c":1,
"/open/tailong/npc/shian.c":1,
]));

  setup();
  replace_program(ROOM);
}
