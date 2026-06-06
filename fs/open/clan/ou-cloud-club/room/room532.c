inherit ROOM;
void create() {
	set( "short", "惹火尤物" );
	set( "owner", "ctx" );
	set( "object", ([
		"amount2"  : 1,
		"amount1"  : 1,
		"file3"    : "/obj/gift/lingzhi",
		"file8"    : "/obj/gift/bingtang",
		"file9"    : "/obj/gift/bingtang",
		"amount4"  : 1,
		"amount6"  : 1,
		"file5"    : "/obj/gift/bingtang",
		"amount9"  : 1,
		"amount8"  : 1,
		"amount7"  : 1,
		"file2"    : "/obj/gift/lingzhi",
		"file1"    : "/obj/gift/bingtang",
		"file6"    : "/obj/gift/bingtang",
		"amount10" : 1,
		"amount3"  : 1,
		"amount5"  : 1,
		"file10"   : "/obj/gift/lingzhi",
		"file7"    : "/obj/gift/bingtang",
		"file4"    : "/obj/gift/bingtang",
	]) );
	set( "light_up", 1 );
	set( "build", 10278 );
	set( "exits", ([
		"north"     : "/open/clan/ou-cloud-club/room/room528",
	]) );
	set( "long", @LONG
在一個叫「慕龍」的神秘大陸板塊上,那的人就想他們所居
住的這塊大陸的名稱一樣，把龍當做神一樣,看到和龍定了契約
的人（是龍和人定契約，就是人認龍做主人）會崇拜，愛慕,主
角在一次偶然的意外下,和一位女性從現實世界意外的進入了神
秘大陸，開始了種種的旅程。

LONG);
	setup();
	replace_program(ROOM);
}
