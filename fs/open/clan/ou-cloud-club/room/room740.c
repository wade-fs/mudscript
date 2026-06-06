inherit ROOM;
void create() {
	set( "short", "朵麗雅的惡夢" );
	set( "owner", "snowy" );
	set( "object", ([
		"file4"    : "/obj/gift/hobowdan",
		"amount4"  : 1,
		"file3"    : "/obj/gift/hobowdan",
		"amount7"  : 1,
		"file7"    : "/obj/gift/hobowdan",
		"file6"    : "/obj/gift/hobowdan",
		"file10"   : "/obj/gift/unknowdan",
		"file1"    : "/obj/gift/unknowdan",
		"file5"    : "/obj/gift/unknowdan",
		"amount1"  : 1,
		"file2"    : "/obj/gift/hobowdan",
		"amount3"  : 1,
		"amount8"  : 1,
		"amount2"  : 1,
		"amount10" : 1,
		"amount6"  : 1,
		"file8"    : "/obj/gift/unknowdan",
		"amount5"  : 1,
	]) );
	set( "build", 10033 );
	set( "exits", ([
		"north"     : "/open/clan/ou-cloud-club/room/room83.c",
		"down"      : "/open/clan/ou-cloud-club/room/room753",
		"west"      : "/open/clan/ou-cloud-club/room/room751.c",
		"east"      : "/open/clan/ou-cloud-club/room/room750.c",
		"up"        : "/open/clan/ou-cloud-club/room/room752.c",
	]) );
	set( "long", @LONG
一片黑暗，無止盡的黑暗，彷彿連思想與精神都會被遮蔽的黑暗，這裡
是夢境還是現實已經無法分辨，因為恐懼亦或是因為空氣中瀰漫的似有似是
夢境還是現實已經無法分辨，因為恐懼亦或是因為空氣中瀰漫的似無的血腥
氣味，但都不重要了，你已經失去了方向感，失去了所有應付這怪異環境的
計畫，甚至感覺到腦中的記憶都慢慢的流失，彷彿逐漸成為夢境的一部份，
還是趕快逃離這裡吧。
LONG);
	setup();
	replace_program(ROOM);
}
