// Room: /u/w/whatup/poison_hole/room03.c
inherit ROOM;

void create ()
{
  set ("short", "小山坡");
  set ("long", @LONG
從這裡上去，路上彎彎曲曲的，到處都是岔路，每一條也不清楚
通往哪裡。路上黃沙滾滾，伸手不見五指，似乎需要一點時間才能適
應這裡的情況。
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"room09.c",
  "northup" : __DIR__"room11.c",
]));
  set("outdoors", "/u/w");

  setup();
}
