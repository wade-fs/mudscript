inherit ROOM;
void create() {
	set( "short", "$HIR$火$HIY$龍$HIC$舌$NOR$" );
	set( "exits", ([
		"north"     : "/open/clan/time-limit/room/room196",
	]) );
	set( "long", @LONG
熊熊火燄形成一條龍的型態,並且作勢要將你吞沒,讓你越走越心驚膽顫,這就是武林
火龍舌,四周噴出的火燄,讓你熱得汗如雨下,前方有個人型火燄,想必就是風輪火轉萬俟
焉了,他是位功力深厚但頭腦簡單的仙覺,龍骨聖刀正是他的得意之作,聖刀配合龍氣與血
角三青,能發揮出驚人的力量,因此引起武林人士的爭奪

LONG);
	setup();
	replace_program(ROOM);
}
