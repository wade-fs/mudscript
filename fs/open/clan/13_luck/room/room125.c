inherit ROOM;
void create() {
	set( "short", "思定" );
	set( "object", ([
		"amount5"  : 1,
		"amount2"  : 1,
		"file1"    : "/open/scholar/obj/icefan",
		"file9"    : "/open/gsword/obj/dragon-cloth",
		"file10"   : "/open/gsword/obj/ring-1",
		"amount1"  : 1,
		"file7"    : "/open/ping/obj/chilin_legging",
		"amount4"  : 1,
		"amount3"  : 1,
		"amount6"  : 1,
		"amount7"  : 1,
		"amount9"  : 1,
		"amount10" : 1,
		"amount8"  : 1,
		"file2"    : "/daemon/class/blademan/obj/shield",
		"file6"    : "/open/mon/obj/ghost-claw",
		"file8"    : "/open/ping/obj/gold_hand",
		"file5"    : "/open/magic-manor/obj/dark-soul-dagger",
		"file3"    : "/open/badman/obj/badhelmet",
		"file4"    : "/open/sky/obj/lucky_grasslink",
	]) );
	set( "owner", "dunga" );
	set( "build", 11226 );
	set( "light_up", 1 );
	set( "exits", ([
		"north"     : "/open/clan/13_luck/room/room124",
		"south"     : "/open/clan/13_luck/room/room121",
	]) );
	set( "long", @LONG
                
                 思定

由前廳走進來為思定是邪王的練功房，武功到達
到這種級數，拳腳只屬末流，高手對決比的就是
心靈層面的思維，故邪王以思定為名，沉靜自己
的思緒，以達到 混元混殺 的極峰境界，只看兩旁
簡單直接的青花石佈置，就可以了解邪王就是只
要單純的一個目的就是要---       強
LONG);
	setup();
	replace_program(ROOM);
}
