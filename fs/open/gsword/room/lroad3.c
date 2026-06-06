#include <room.h>

 inherit ROOM;

void create ()
{
  set ("short", "八卦亭");
  set ("long", @LONG
這個八卦亭算來已有一百多年的歷史了，雖然老舊，但卻不失其狀闊的氣度。
八根石柱上分別雕刻著『天』，『澤』，『雷』，『水』，『地』，『山』，
『風』，『火』隱隱中似乎含意甚高。中間的一張石桌以純白奇岩所造，更顯
八卦亭的不平凡。

LONG);

  set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"lroad2",
]));
  set("outdoors", "/open/gsword/room");

  setup();
}
