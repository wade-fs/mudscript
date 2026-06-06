inherit ROOM;
void create() {
	set( "short", "$HIC$欣$HIR$ソ$HIY$草藥房$NOR$" );
	set( "object", ([
		"file6"    : "/open/main/obj/m_cloak",
		"amount1"  : 1,
		"file3"    : "/open/dancer/obj/yuawaist",
		"amount4"  : 1,
		"amount6"  : 1,
		"amount2"  : 1,
		"amount3"  : 1,
		"file1"    : "/open/magic-manor/water/obj/water-ribbon",
		"amount5"  : 1,
		"file4"    : "/open/main/obj/bird_legging",
		"file5"    : "/open/gblade/obj/dragon_book",
		"file2"    : "/open/scholar/room/newplan/obj/s-shield",
	]) );
	set( "light_up", 1 );
	set( "build", 11246 );
	set( "exits", ([
		"east"      : "/open/clan/sky-wu-chi/room/room127.c",
	]) );
	set( "long", @LONG
   這裡是夜空下的欣的草藥房所有的草藥都整齊劃一的排列在草藥房裡
每個草藥都散發著他們的香味,導致整各房間瀰漫著香味,你看到裡面所
收藏的魔龍麟..不禁嘖嘖稱其.所有的草藥在欣提.刀作戰時,則
給了欣一道強勁的回復力.....


LONG);
	setup();
	replace_program(ROOM);
}
