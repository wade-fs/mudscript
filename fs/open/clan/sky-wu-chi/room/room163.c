inherit ROOM;
void create() {
	set( "short", "翠峰" );
	set( "owner", "herononame" );
	set( "object", ([
		"file4"    : "/obj/gift/unknowdan",
		"amount7"  : 15,
		"file7"    : "/obj/stone/powder",
		"amount5"  : 1,
		"file1"    : "/open/dancer/obj/maple_ribbon",
		"amount6"  : 1,
		"amount4"  : 1,
		"amount9"  : 1,
		"file2"    : "/obj/gift/xisuidan",
		"amount1"  : 1,
		"amount3"  : 2,
		"file3"    : "/obj/stone/suipian",
		"amount2"  : 1,
		"amount8"  : 1,
		"file9"    : "/open/wu/obj/figring",
		"file8"    : "/obj/gift/bingtang",
		"file6"    : "/obj/gift/hobowdan",
		"file5"    : "/obj/gift/bingtang",
	]) );
	set( "light_up", 1 );
	set( "build", 10960 );
	set( "exits", ([
		"north"     : "/open/clan/sky-wu-chi/room/room166",
	]) );
	set( "long", @LONG
眼前一塊石敢當使你停下了腳步，只見上面刻著大大的兩
個字『翠峰』，喔，原來是到了目的地了，只是，好像沒看到
神仙耶，你不禁委屈的流下淚下，不過，這裡還真是美麗，山
壁上一道涓絲般的瀑布緩緩的流著，四周更是充滿了不少罕見
的花草走獸，雖然沒看到神仙，能見到如斯美景，也算不虛此
行了。
LONG);
	setup();
	replace_program(ROOM);
}
