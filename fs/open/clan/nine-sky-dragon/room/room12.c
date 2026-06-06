inherit ROOM;
void create() {
	set( "short", "客棧大廳" );
	set( "object", ([
		"file7"    : "/open/magic-manor/obj/hwa-je-icer",
		"file8"    : "/open/magic-manor/obj/fon-sky-sword",
		"amount6"  : 1,
		"amount8"  : 1,
		"file2"    : "/open/magic-manor/obj/maun-shadow-blade",
		"file5"    : "/open/magic-manor/obj/fire-color-ribbon",
		"file1"    : "/open/magic-manor/obj/maun-shadow-blade",
		"amount10" : 1,
		"amount7"  : 1,
		"file9"    : "/open/magic-manor/obj/golden-ball",
		"file6"    : "/open/magic-manor/obj/evil-kill-claw",
		"file4"    : "/open/magic-manor/obj/evil-gwe-blade",
		"amount4"  : 1,
		"amount1"  : 1,
		"file10"   : "/open/magic-manor/obj/wood-ball",
		"amount2"  : 1,
		"file3"    : "/open/magic-manor/obj/dark-soul-dagger",
		"amount5"  : 1,
		"amount3"  : 1,
		"amount9"  : 1,
	]) );
	set( "build", 10104 );
	set( "light_up", 1 );
	set( "exits", ([
		"out"       : "/open/clan/nine-sky-dragon/room/room10.c",
		"醉仙樓"    : "/open/clan/nine-sky-dragon/room/room11.c",
	]) );
	set( "long", @LONG

　　由巨龍口進門繞過一道淡紅絲綢的屏風，迎面的牆上頭掛著一副
『　龍　吟　虎　嘯　』圖，工筆彩繪，豪邁奔放，氣勢十足。正中
央擺著一張雕花楠木青漆嵌玉的櫃臺，掌櫃的在櫃臺後忙著幫旅客們
處理住宿事宜，店小二則忙著招呼剛入門的客人，十分忙碌。

LONG);
	setup();
	replace_program(ROOM);
}
