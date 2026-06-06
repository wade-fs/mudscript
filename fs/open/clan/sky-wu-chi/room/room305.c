inherit ROOM;
void create() {
	set( "short", "血痕居" );
	set( "owner", "holeman" );
	set( "object", ([
		"file1"    : "/open/mogi/castle/obj/ninepill",
		"file3"    : "/open/mogi/castle/obj/sspill",
		"amount6"  : 263,
		"amount3"  : 227,
		"file9"    : "/open/mogi/castle/obj/lochagem",
		"file6"    : "/open/doctor/pill/sky_pill",
		"amount2"  : 81,
		"amount1"  : 400,
		"file2"    : "/open/doctor/pill/gnd_pill",
		"file7"    : "/open/doctor/pill/human_pill",
		"amount9"  : 1,
		"amount7"  : 149,
	]) );
	set( "light_up", 1 );
	set( "build", 10904 );
	set( "exits", ([
		"north"     : "/open/clan/sky-wu-chi/room/room298.c",
		"west"      : "/open/clan/sky-wu-chi/room/room300.c",
		"up"        : "/open/clan/sky-wu-chi/room/room518",
		"east"      : "/open/clan/sky-wu-chi/room/room301.c",
		"chome"     : "/open/clan/sky-wu-chi/room/hall.c",
	]) );
	set( "long", @LONG

    原以為從外表看來完全不起眼的房子，沒想到在一打開
大門竟然有一股驚天的殺氣向你直衝而來，令你不得不運起
十成的功力來抵擋，但完全沒想到這股殺氣在你面前卻消失
的無影無蹤，看來此屋的主人功力以達到隨心所欲的境界了
。當你進來此屋之後卻驚訝的發覺，原來屋子裡面除了簡單
的裝潢之外並沒有看到任何人，看來還是不要繼續逗留或許
會比較安全吧。


LONG);
	setup();
	replace_program(ROOM);
}
