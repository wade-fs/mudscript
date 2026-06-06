inherit ROOM;

void create ()
{
  set ("short", "走道");
  set ("long", @LONG
這裡是天龍寺中通往外院的走道,聽說天龍寺中有著許多著名的建築
諸如三閣、七樓、九殿、百廈,規模宏大,想到這裡,不禁令人想好好參觀
一下
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"aa7",
  "west" : __DIR__"aa11",
]));

  setup();
  replace_program(ROOM);
}
