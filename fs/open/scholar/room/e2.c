// Room: /u/r/red/room/flower.c
inherit ROOM;

void create ()
{
  set ("short", "走廊");
  set ("long", @LONG
這是通往儒門學識廳的一條走道，走道的兩旁掛滿著
許許多多的畫，且畫中有詩，儒生們喜歡一邊看著畫，一
邊互相考考彼此的文學造詣。
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"e1.c",
  "east" : __DIR__"e3.c",
]));

  setup();
}
