inherit ROOM;
void create() {
	set( "short", "懶蟲的家" );
	set( "owner", "scs" );
	set( "object", ([
		"file9"    : "/open/magic-manor/obj/golden-ball",
		"file3"    : "/open/ping/obj/poison_pill",
		"amount1"  : 10,
		"file1"    : "/open/fire-hole/obj/k-pill",
		"file7"    : "/open/gsword/obj1/blosword",
		"amount4"  : 242,
		"amount3"  : 143,
		"file5"    : "/open/fire-hole/obj/y-pill",
		"amount2"  : 158,
		"amount9"  : 1,
		"amount5"  : 108,
		"file2"    : "/open/mon/obj/mon-pill",
		"file4"    : "/open/fire-hole/obj/g-pill",
		"file6"    : "/open/fire-hole/obj/r-pill",
		"amount6"  : 184,
		"amount7"  : 1,
	]) );
	set( "light_up", 1 );
	set( "build", 10013 );
	set( "exits", ([
		"west"      : "/open/clan/ou-cloud-club/room/room125",
		"east"      : "/open/clan/ou-cloud-club/room/room226.c",
	]) );
	set( "long", @LONG
這是傲雲山莊內,號稱點子之王的懶蟲的練功房裡面藏著
他爭戰狂想多年的寶物,擺設看似簡單其實內藏玄機,暗中布有
陣式防像oasis這樣的小人。最近懶蟲正在苦思新招式,希望能
一舉打敗焚天這個魔頭,牆上深刻的刀痕,都顯示著他實力的增
加.聽說他已經領務出幔羅千葉刀法的終極絕招,相信不久後他
會成為傲雲山莊內不可或缺的高手之一.
LONG);
	setup();
	replace_program(ROOM);
}
