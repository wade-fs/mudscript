// Room: /open/wu/room/luroom7.c
// 瀧山武館的練武場
inherit ROOM;
void create ()
{
  set ("short", "練武場");
  set ("long", @LONG
你站在瀧山派練武場的一角,你眼前擺滿了許多的銅頭人,銅頭人身上拳
痕磊磊,指痕處處,想必是武館弟子用來練拳的地方,你現在看到二位瀧山
武學精深的弟子正在和銅頭人拆招。
LONG);

  set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"luroom4",
  "north" : __DIR__"luroom6",
  "east" : __DIR__"luroom10",
]));
  set("objects", ([ /* sizeof() == 1 */
  "/open/wu/npc/d_trainee" : 2,
]));

  setup();
}
