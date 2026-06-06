inherit ROOM;

void create ()
{
  set ("short", "牟尼院外");
  set ("long", @LONG
這裡就是天龍寺的武學重地牟尼院外,天龍寺的高僧都是在此潛修武
學奧秘,因此牟尼院也就成為天龍寺對外人的三禁地之一,在這裡有兩位
天龍寺的上級武僧在此把守。
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"aa18",
  "east" : __DIR__"aa16",
]));
  set("objects", ([ /* sizeof() == 1 */
"/open/tailong/npc/monkf5.c":2,
]));

  setup();
  replace_program(ROOM);
}
