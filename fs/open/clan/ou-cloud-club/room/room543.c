inherit ROOM;
void create() {
	set( "short", "龍之天空" );
	set( "owner", "ctx" );
	set( "object", ([
		"amount1"  : 1,
		"file4"    : "/obj/gift/bingtang",
		"amount5"  : 1,
		"file1"    : "/obj/gift/lingzhi",
		"amount6"  : 1,
		"amount4"  : 1,
		"file5"    : "/obj/gift/bingtang",
		"file8"    : "/obj/gift/bingtang",
		"amount2"  : 1,
		"amount9"  : 1,
		"amount8"  : 1,
		"file9"    : "/obj/gift/bingtang",
		"file3"    : "/obj/gift/lingzhi",
		"file10"   : "/obj/gift/lingzhi",
		"file7"    : "/obj/gift/lingzhi",
		"amount3"  : 1,
		"file6"    : "/obj/gift/lingzhi",
		"amount7"  : 1,
		"file2"    : "/obj/gift/lingzhi",
		"amount10" : 1,
	]) );
	set( "build", 10044 );
	set( "light_up", 1 );
	set( "exits", ([
		"north"     : "/open/clan/ou-cloud-club/room/room540",
	]) );
	set( "long", @LONG
這裡也是一個簡體為主的奇幻文學網站，不同於玄幻書殿的
是，這裡並沒有像是玄幻書殿那樣超人氣，更新速度也只是普通
不過這裡有一個特點是，這邊有整理好的每本小說的電子檔，也
就是說如果想要找已經出完的小說，想要抓整本的電子檔的話，
這邊就是一個相當不錯的選擇。

LONG);
	setup();
	replace_program(ROOM);
}
