inherit ROOM;
void create() {
	set( "short", "秘密森林" );
	set( "outdoors", "/open/clan/13_luck" );
	set( "light_up", 1 );
	set( "owner", "meimei" );
	set( "object", ([
		"file2"    : "/open/fire-hole/obj/b-pill",
		"file6"    : "/open/fire-hole/obj/y-pill",
		"amount6"  : 17,
		"file5"    : "/open/fire-hole/obj/g-pill",
		"file3"    : "/open/fire-hole/obj/w-pill",
		"amount4"  : 12,
		"amount5"  : 12,
		"amount2"  : 12,
		"file1"    : "/open/fire-hole/obj/r-pill",
		"amount1"  : 12,
		"file4"    : "/open/fire-hole/obj/p-pill",
		"amount3"  : 12,
	]) );
	set( "build", 11192 );
	set( "exits", ([
		"out"       : "/open/clan/13_luck/room/room756",
	]) );
	set( "long", @LONG
初升的曙光輕輕地穿過細密的竹林，撒落了一地的金黃，震耳欲聾的水
聲似乎在昭示著水勢的浩大，峭壁上兩條玉龍直掛而下。雙瀑並瀉，屈曲回
旋，朦朧的水霧淡淡地飄散在身旁，讓晨曦亦步亦隨的環繞在你的身邊，如
帷幔般直瀉而下的瀑布，佔去了你絕大部份的目光範圍，如此壯觀的景色，
讓你捨不得移開視線。
LONG);
	setup();
	replace_program(ROOM);
}
