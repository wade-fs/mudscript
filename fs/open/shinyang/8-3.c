// Room: /u/w/whatup/area/shinyang/6-3
inherit ROOM;

void create ()
{
  set ("short", "金華大道東");
  set ("long", @LONG
這是金華大道東，平整的路面上沒有什麼塵土，這裡來往走動的
旅客似乎少了許多，不過大道的兩邊種滿了榕樹，似乎替人門遮蔽不
少炎熱的陽光，更有老人正在樹下乘涼看著一旁打鬧的小孩子，享受
著含飴弄孫的樂趣。
LONG);

  set("no_transmit", 1);
  set("exits", ([ /* sizeof() == 3 */
  "north" : __DIR__"8-4.c",
  "west" : __DIR__"7-3",
  "east" : __DIR__"9-3.c",
]));
  set("no_auc", 1);
  set("outdoors", "/open");

  setup();
}
