inherit ROOM;
void create() {
	set( "short", "狂龍殿廣場" );
	set( "object", ([
		"amount3"  : 1,
		"amount7"  : 1,
		"amount6"  : 1,
		"file1"    : "/open/mogi/castle/obj/seven5-dark-head",
		"file10"   : "/open/mogi/castle/obj/fire-king-head",
		"file2"    : "/open/mogi/castle/obj/seven6-dark-head",
		"amount10" : 1,
		"amount2"  : 1,
		"amount5"  : 1,
		"file4"    : "/open/mogi/castle/obj/seven3-dark-head",
		"amount1"  : 1,
		"file3"    : "/open/mogi/castle/obj/seven7-dark-head",
		"file6"    : "/open/mogi/castle/obj/seven2-dark-head",
		"amount4"  : 1,
		"file5"    : "/open/mogi/castle/obj/seven4-dark-head",
		"file7"    : "/open/mogi/castle/obj/seven1-dark-head",
	]) );
	set( "owner", "mill" );
	set( "build", 13063 );
	set( "light_up", 1 );
	set( "exits", ([
		"down"      : "/open/clan/13_luck/room/room128",
		"up"        : "/open/clan/13_luck/room/room85.c",
	]) );
	set( "long", @LONG

    一走下來就感到一鼓沉重的壓力，定神一看周圍廣闊無邊，難辨
遠近跟剛剛不知所謂的沉重壓力一比，造成極大的對比。心口一悶，
一股血氣上衝，差點暈了過去，內力不夠好的走到這就可能血濺當場
，暴斃而亡。原來這裡是狂龍宮殿前的廣場，前面的人影好像是在修
練武術，強大的鬥氣攏照，令人身形難辨。寥寥可數的幾人所發出的
鬥氣竟然讓這廣闊廣場尤如有著千軍萬馬般的氣勢。往下看去可見一
筆直大道通往狂龍殿。

LONG);
	setup();
	replace_program(ROOM);
}
