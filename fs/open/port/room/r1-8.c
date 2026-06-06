// Room: /open/gblade/port/room/p1-6.c
inherit ROOM;

void create()
{
	set("short","張老兒藥鋪");
  set ("long", @LONG
這是一家頗具規模的藥鋪 . 屋子的東北兩面牆邊各擺了個大
藥櫃 , 整齊的存放著各種藥材 . 藥鋪老闆賈種民曾擔任過御醫
 , 說不定你可以向他買到只有皇帝才吃的到的仙丹妙藥喔 !

LONG);

  set("light_up", 1);
	set("objects",([
	]));
  set("exits", ([ /* sizeof() == 1 */
	"west" : "/open/port/room/r1-3",
]));
  setup();
}
