// Room: /u/l/lotus/girl/tin3.c

inherit ROOM;

void create ()
{
  set ("short", "穿堂");
  set ("long", @LONG
掛了兩盞明晃晃的花燈, 煞是好看。東面有一座樓梯, 西面通往
客人休息的房間, 最好不要亂闖房間, 被打擾的客人脾氣會很不好...
LONG);

  set("exits", ([ /* sizeof() == 3 */
  "north" : __DIR__"guest2.c",
  "west" : __DIR__"w1.c",
  "east" : __DIR__"tin4.c",
]));
  set("light_up", 1);

  setup();
}
