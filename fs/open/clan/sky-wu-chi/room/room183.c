inherit ROOM;
void create() {
	set( "short", "蘭亭閣" );
	set( "owner", "jsa" );
	set( "object", ([
		"amount1"  : 1,
		"file6"    : "/open/gblade/obj/sa-head",
		"amount4"  : 1,
		"file3"    : "/open/gblade/obj/sa-head",
		"amount2"  : 1,
		"amount6"  : 1,
		"amount3"  : 1,
		"file1"    : "/open/mogi/castle/obj/fire_book",
		"file4"    : "/obj/gift/shenliwan",
		"file2"    : "/open/gblade/obj/sa-head",
		"amount7"  : 1,
		"file7"    : "/open/mogi/dragon/obj/scale",
	]) );
	set( "build", 10002 );
	set( "exits", ([
		"west"      : "/open/clan/sky-wu-chi/room/room195",
	]) );
	set( "light_up", 1 );
	set( "long", @LONG
一走進房內，你竟然分辨不出隔間，原來四面皆是
雕空玲瓏木板，或流雲百富，或歲寒三友，或山水人物
，或翎毛花卉，或集錦，或博古，各種花樣，皆是名手
雕刻，五彩銷金嵌玉的。一隔一隔，或貯書，或設鼎，
或安置筆硯。其隔式樣，或圓，或方，或連環半壁。且
滿牆皆是隨依古董玩器之形樞成的槽子，如琴，劍，懸
瓶之類，俱懸於壁，卻都與壁相平的。
LONG);
	setup();
	replace_program(ROOM);
}
