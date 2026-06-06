// Room: /u/w/whatup/poison_hole/room01.c
inherit ROOM;

void create ()
{
  set ("short", "小山坡");
  set ("long", @LONG
從這裡上去，路上彎彎曲曲的，到處都是岔路，每一條也不清楚
通往哪裡。路上黃沙滾滾，伸手不見五指，似乎需要一點時間才能適
應這裡的情況。
LONG);

  set("outdoors", "/u/w");
  set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"room02.c",
  "eastdown" : "/open/main/room/r13.c",
]));

  setup();
}
