inherit ROOM;
void create() {
	set( "short", "$HIW$野人的$HIB$小$HIC$宇$HIY$宙$NOR$" );
	set( "object", ([
		"amount4"  : 28,
		"amount7"  : 1,
		"amount6"  : 1,
		"file3"    : "/open/magic-manor/fire/obj/fire-fan",
		"file5"    : "/open/capital/obj/king-cloak",
		"amount2"  : 1,
		"file8"    : "/obj/stone/powder",
		"amount5"  : 1,
		"amount8"  : 6,
		"file6"    : "/open/capital/obj/king-ring",
		"amount3"  : 1,
		"file1"    : "/open/capital/obj/4-4",
		"amount1"  : 1,
		"amount9"  : 1,
		"file7"    : "/open/killer/weapon/k_torch",
		"file2"    : "/open/gsword/obj1/blosword",
		"file4"    : "/open/fire-hole/obj/w-pill",
		"file9"    : "/open/common/obj/liz_meat",
	]) );
	set( "owner", "juzn" );
	set( "build", 10068 );
	set( "light_up", 1 );
	set( "exits", ([
		"north"     : "/open/clan/ou-cloud-club/room/room419",
	]) );
	set( "long", @LONG
這裡的結構十分怪異,一切均是野人以強大的能量強行架構而出,
六面均是有如銀河般的閃爍星光,處在這個空間讓人有總漂浮其中的
怪異感覺,四周除了星光就是一片駭人的黑暗,沒錯這裡就是野人架構
的專屬領域,除了野人沒有人可以在這裡取得優勢,一但你踏進了這個
領域,除了安靜的離開,否則就是以更強大的能量來打破野人的小宇宙。

   這裡漂浮著一尊$HIC$野人的雕像$NOR$($HIB$uncivilized juzn's effigy$NOR$)

LONG);
	setup();
	replace_program(ROOM);
}
