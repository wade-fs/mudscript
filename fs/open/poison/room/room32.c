inherit ROOM;

void create ()
{
  set ("short", "山崖");
  set ("long", @LONG
"哇哈哈哈哈哈"一爬上來 ,你不禁對自己的輕功造詣大感滿意 ,
登上這萬丈高崖 ,環顧四週景物 ,一股豪氣頓時湧現心頭 .路邊
有一隻猴子 ,正看著你的表現而大惑不解 .

LONG);

  set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"room33.c",
  "eastdown" : __DIR__"room26",
]));
  set("objects", ([ /* sizeof() == 1 */
  "/u/h/houng/mob/monkey2.c" : 1,
]));

  setup();
}
