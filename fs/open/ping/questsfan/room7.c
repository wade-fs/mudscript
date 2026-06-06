// Room: /u/d/dhk/questsfan/room7
inherit ROOM;

void create ()
{
  set ("short", "深不見底的絕崖");
  set ("long", @LONG
好不容易走出草陣，確發現此地竟是一處絕崖。崖下
有一陣一陣的狂風殺！殺！殺！的吹著。而且崖面竟有著
雲狀的霧，你的心霎時涼了一節，這裡有這麼高嗎？這而
的北方似乎有三座會發出異光的橋影…

LONG);

  set("outdoors", "/u/d");
  set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"room6",
  "goup" : __DIR__"room28",
]));

  setup();
}
