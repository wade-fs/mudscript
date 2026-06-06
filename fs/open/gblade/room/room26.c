// Room: /u/m/moner/tree/room26.c
inherit ROOM;

void create()
{
  set ("short", "密室");
	set( "build", 15 );
  set ("long", @LONG

這是一間狹窄的密室，室內僅有一個石床依偎在牆旁。石室的天頂上
有一個破洞，刺目的陽光從上方傾而入，映著光線，你慢慢的看清四周，
環顧四周，你驚訝的發現室內滿怖刀痕，細細的觀察那些刀痕，看起來好
像是高手所為。

LONG);

  set("light_up", 1);
        set("objects",([
"/daemon/class/blademan/master_oldman.c":1,
]));

  set("exits", ([ /* sizeof() == 2 */
"out" :"/open/snow/room/hole13.c",
]));
  setup();
}
