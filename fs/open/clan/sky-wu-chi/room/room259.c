inherit ROOM;
void create() {
	set( "short", "helmet" );
	set( "owner", "hild" );
	set( "object", ([
		"amount2"  : 1,
		"amount4"  : 1,
		"file4"    : "/open/ghost-hole/obj/eq/ghost-helmet",
		"amount7"  : 1,
		"amount5"  : 1,
		"file5"    : "/open/ghost-hole/obj/eq/ghost-helmet",
		"file2"    : "/open/ghost-hole/obj/eq/ghost-helmet",
		"file6"    : "/open/ghost-hole/obj/eq/ghost-helmet",
		"file7"    : "/open/ghost-hole/obj/eq/ghost-helmet",
		"amount10" : 1,
		"amount6"  : 1,
		"file10"   : "/open/ghost-hole/obj/eq/ghost-helmet",
	]) );
	set( "light_up", 1 );
	set( "build", 10184 );
	set( "exits", ([
		"out"       : "/open/clan/sky-wu-chi/room/room116.c",
	]) );
	set( "long", @LONG
這是一個與世隔絕的地方,四周的空氣瀰漫著花香,樹林傳來陣陣的鳥語,
這裡遠離了世俗的塵埃,是一個稀少人會知道的世外仙境,沒有戰爭只有
和平,也因為這裡的寧靜正好是一個讓人能夠快速修養身心的好地方,
如果你有足夠的緣分到達此世外仙境,希望你自己可以保持此仙境的寧靜和平.
LONG);
	setup();
	replace_program(ROOM);
}
