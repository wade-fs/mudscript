inherit ROOM;
void create() {
	set( "short", "二樓east" );
	set( "owner", "djlh" );
	set( "object", ([
		"file7"    : "/daemon/class/bonze/puty_pullium",
		"amount4"  : 1,
		"file4"    : "/open/mon/obj/ghost-legging",
		"amount9"  : 1,
		"amount2"  : 1,
		"amount7"  : 1,
		"file3"    : "/open/mon/obj/ghost-helmet",
		"file9"    : "/open/poison/obj/armband1",
		"amount3"  : 1,
		"file2"    : "/open/magic-manor/obj/dark-soul-dagger",
		"file8"    : "/open/tendo/obj/chaosbelt",
		"file1"    : "/open/magic-manor/obj/dark-soul-dagger",
		"amount1"  : 1,
		"amount8"  : 1,
	]) );
	set( "build", 10032 );
	set( "exits", ([
		"south"     : "/open/clan/13_luck/room/room705",
		"west"      : "/open/clan/13_luck/room/room662.c",
		"north"     : "/open/clan/13_luck/room/room704.c",
	]) );
	set( "long", @LONG

    ╬╬╬╬╬╬╬╬╬★☆╬╬╬╬╬╬╬╬╬╬╬╬╬★☆╬╬╬╬╬╬╬╬        
    ╬★☆╬╬ 不願承認不願面對 ═╤╨╤═ 我真的愛你很深很深 ╬☆╬╬╬        
    ╬╬╬╬╬ 一個笑容一句話語 ║║  ║║ 都讓我心跳很快很快 ╬╬★☆╬        
    ╬╬╬╬☆ 每個思索每個慾望 ╚╡  ╞╯ 全被你佔據很滿很滿 ╬╬╬╬╬        
    ╬╬╬╬╬ 無法平靜不想透露 ═╧═╧═ 因為愛你快樂很久   ╬★☆╬╬        
    ╬★☆╬╬ 情願  醉死在夢裡 ║║═  ║ 當一切都變得無力   ╬╬╬☆╬        
    ╬╬╬╬╬ 情願  為你而美麗 ╯╰═╯╰ 當你呼喚我的名字   ╬╬╬╬╬        
    ╬╬╬★╬ 情願  默默的隱藏            當它只是一個錯誤   ╬★☆╬╬        
    ╬★☆╬╬ 情願  很久的以後            當一切都被時間沖淡 ╬╬╬☆╬        
    ╬╬╬╬╬ 只會更愛你            ‧李心潔‧戀‧李心潔‧戀 ╬╬╬╬╬        

LONG);
	setup();
	replace_program(ROOM);
}
