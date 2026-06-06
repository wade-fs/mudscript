inherit ROOM;
void create() {
	set( "short", "寶寶的惡夢" );
	set( "owner", "snowy" );
	set( "object", ([
		"file9"    : "/open/fire-hole/obj/w-pill",
		"amount8"  : 557,
		"file3"    : "/open/fire-hole/obj/k-pill",
		"amount2"  : 13687,
		"file6"    : "/open/fire-hole/obj/b-pill",
		"amount7"  : 788,
		"amount3"  : 673,
		"file7"    : "/open/fire-hole/obj/p-pill",
		"file4"    : "/open/fire-hole/obj/y-pill",
		"file5"    : "/open/fire-hole/obj/g-pill",
		"amount1"  : 454,
		"file8"    : "/open/fire-hole/obj/r-pill",
		"file2"    : "/open/killer/obj/atman_pill",
		"amount4"  : 345,
		"file1"    : "/open/ping/obj/poison_pill",
		"amount9"  : 222,
		"amount6"  : 617,
		"amount5"  : 944,
		"file10"   : "/open/doctor/pill/human_pill",
		"amount10" : 220,
	]) );
	set( "build", 10795 );
	set( "exits", ([
		"east"      : "/open/clan/ou-cloud-club/room/room740",
	]) );
	set( "long", @LONG
這個恐怖陰森的夢境似乎沒有出口，無論走了多遠，無盡的紫黑夢靨永
遠圍繞在四周，灼熱的焦黑土地上屍塊與血液沸騰著，無數如夢幻一般的活
死屍和獸人在這個夢境裡不斷的互相殘殺，天空是黑色的，血紅色的雷電不
時劈下，打在矗立在地上的絞刑台，永恆不斷的痛苦記憶在這被詛咒的土地
上上演，沒有人知道何時才會結束。
LONG);
	setup();
	replace_program(ROOM);
}
