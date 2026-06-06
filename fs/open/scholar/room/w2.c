// Room: /u/r/red/room/flower.c
inherit ROOM;

void create ()
{
  set ("short", "走廊");
  set ("long", @LONG
這是通往儒門計謀廳的一條走道，走道的兩旁貼滿著
許許多多的地形圖，儒生們喜歡一邊看著圖，一邊幻想自
己身處於戰場上，正指揮著兵士們作戰。
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"w3.c",
  "east" : __DIR__"w1.c",
]));

  setup();
}
