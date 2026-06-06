inherit ROOM;
void create() {
	set( "short", "$HIY$內室$NOR$" );
	set( "owner", "pony" );
	set( "object", ([
		"amount5"  : 32,
		"file5"    : "/open/fire-hole/obj/w-pill",
		"file7"    : "/open/fire-hole/obj/g-pill",
		"file6"    : "/open/fire-hole/obj/r-pill",
		"file10"   : "/open/doctor/pill/f_pill",
		"amount10" : 41,
		"file1"    : "/open/fire-hole/obj/b-pill",
		"amount6"  : 56,
		"amount9"  : 19,
		"amount4"  : 20,
		"amount7"  : 35,
		"file9"    : "/open/fire-hole/obj/g-pill",
		"file3"    : "/open/mon/obj/mon-pill",
		"file4"    : "/open/fire-hole/obj/k-pill",
		"amount3"  : 56,
		"amount1"  : 24,
	]) );
	set( "build", 10632 );
	set( "light_up", 1 );
	set( "exits", ([
		"west"      : "/open/clan/ou-cloud-club/room/room148",
	]) );
	set( "long", @LONG
這間房間繼承了起居室的風格，同樣是以極簡的設計搭配自然的建材來
讓整個房間散發出自然的品味。右手邊有一張松木床，淡黃的原木色配上淺
藍色的天鵝絨床墊使得整張床看來舒適極了。左手邊則擺了張書桌，桌上散
落著幾本沒收齊的書，攤開的頁面正在述說ＭＵＤ在近年來的興起與沒落。
LONG);
	setup();
	replace_program(ROOM);
}
