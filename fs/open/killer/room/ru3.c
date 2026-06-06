// Room: /open/killer/room/ru0.c
inherit ROOM;
void create ()
{
  set ("short", "大廳");
	set( "build", 497 );
  set ("long", @LONG
這裡是黑牙聯總壇的大廳，佈置非常的平常，但是卻暗藏殺機。
連四周的燭光，似乎也傳來陣陣的殺機，看來這不是一般人該進來的地方。
看似平常的一盆花，搞不好就是你致命的原因。你最好小心一點。
這裡也經過特殊設計，例如此處特別狹窄就是防止敵人可大舉侵入。
前方就是傳說中的超級殺手葉秀殺，接見來訪客人的地方。
戒備非常的森嚴，你最好不要輕舉妄動。

LONG);

  set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"masterm.c",
  "south" : __DIR__"ru1.c",
]));
  set("objects",([
      "/open/killer/npc/killer_a.c":2,]));
  set("light_up", 10);
  setup();
}
