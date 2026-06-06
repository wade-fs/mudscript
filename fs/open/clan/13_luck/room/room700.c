inherit ROOM;
void create() {
	set( "short", "二樓south" );
	set( "object", ([
		"file7"    : "/open/fire-hole/obj/b-pill",
		"amount9"  : 5,
		"amount5"  : 60,
		"file10"   : "/open/fire-hole/obj/r-pill",
		"file2"    : "/open/mogi/castle/obj/ninepill",
		"amount10" : 18,
		"file9"    : "/open/fire-hole/obj/g-pill",
		"amount8"  : 45,
		"file6"    : "/open/fire-hole/obj/y-pill",
		"file4"    : "/open/capital/obj/4-2",
		"file3"    : "/open/mogi/castle/obj/ninepill",
		"amount6"  : 60,
		"amount7"  : 44,
		"file5"    : "/open/fire-hole/obj/w-pill",
		"amount4"  : 1,
		"amount3"  : 300,
		"amount1"  : 240,
		"file8"    : "/open/fire-hole/obj/p-pill",
		"file1"    : "/open/mogi/castle/obj/ninepill",
		"amount2"  : 300,
	]) );
	set( "owner", "djlh" );
	set( "build", 10030 );
	set( "exits", ([
		"east"      : "/open/clan/13_luck/room/room705",
		"north"     : "/open/clan/13_luck/room/room662.c",
		"west"      : "/open/clan/13_luck/room/room702.c",
	]) );
	set( "long", @LONG

  ╭══╦═══════════════∮林曉培══════════════╮  
╮║╭╭╯══╮自從我看到你 就每天失眠食慾不振 因為我不是你喜歡的那種女生  ║  
╰║╯╠═══╣我不想討你歡心又擔心自己難過 但你的要求總讓每個女生覺得殘忍 ║  
╭╯╮╠═══╣我只要看到你就胃快抽筋心律不整 你知道我不是很做作的那種女生 ║  
║  ║╰═══╯我不想改變髮型 也不想變換口氣 只為了讓你讓你讓你愛我更認真  ║  
╯  ╰═╯  ╰═══════════════════════════════╯  
╭╮煩哪煩哪　煩得不能呼吸　煩哪煩哪　煩得沒有力氣（歇斯底里）煩哪　我煩啊╭╮  
　╰╮　　你說你愛我　就是不愛我的鞋跟　你說你不愛我　只因為我的嘴唇　　╭╯    
　╭╯　　　我說我喜歡短裙　喜歡香水　喜歡粉　我就喜歡我是這種女生　　　╰╮    
　╰════════════════════════════ by djlh  ══╯    

LONG);
	setup();
	replace_program(ROOM);
}
