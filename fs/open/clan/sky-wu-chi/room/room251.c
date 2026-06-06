inherit ROOM;
void create() {
	set( "short", "$HIM$天$HIC$道$HIY$夢谷$HIR$藥園$NOR$" );
	set( "owner", "amei" );
	set( "object", ([
		"amount8"  : 1,
		"file6"    : "/obj/gift/karwan",
		"amount1"  : 2,
		"file3"    : "/obj/stone/suipian",
		"file2"    : "/open/mogi/castle/obj/ninepill",
		"file5"    : "/open/doctor/obj/gneedle",
		"amount4"  : 1,
		"file1"    : "/open/mon/obj/thousand-nectar",
		"amount5"  : 1,
		"file7"    : "/open/doctor/obj/gneedle",
		"amount3"  : 2,
		"amount2"  : 3,
		"file4"    : "/open/gsword/obj1/bbladeball",
		"file8"    : "/open/doctor/obj/gneedle",
		"amount7"  : 1,
		"amount6"  : 1,
	]) );
	set( "light_up", 1 );
	set( "build", 10136 );
	set( "exits", ([
		"pill"      : "/open/clan/sky-wu-chi/room/room293",
		"chome"     : "/open/clan/sky-wu-chi/room/hall.c",
		"north"     : "/open/clan/sky-wu-chi/room/room208",
	]) );
	set( "long", @LONG
這裡是天道無極的專屬藥草園，四周充滿了各式各樣的藥草，有些
竟然是一些前所未見的珍貴藥草，令你頓時眼睛為之一亮，心想要是能
拔一些珍貴草藥拿去賣，不知道該有多好，剛想到四周突然漫起大霧，
害你什麼都看不見了！
LONG);
	setup();
	replace_program(ROOM);
}
