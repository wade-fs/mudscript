inherit ROOM;
void create() {
	set( "short", "無條件為你" );
	set( "owner", "yaoblade" );
	set( "object", ([
		"amount5"  : 1,
		"file5"    : "/open/ghost-hole/obj/eq/ghost-ring",
		"file4"    : "/open/ghost-hole/obj/eq/ghost-armband",
		"amount7"  : 1,
		"amount9"  : 1,
		"amount2"  : 1,
		"file9"    : "/open/ghost-hole/obj/eq/ghost-helmet",
		"file6"    : "/open/ghost-hole/obj/eq/ghost-gem",
		"file3"    : "/open/ghost-hole/obj/eq/ghost-cloak",
		"amount3"  : 1,
		"file1"    : "/open/ghost-hole/obj/eq/ghost-belt",
		"amount8"  : 1,
		"amount10" : 1,
		"amount6"  : 1,
		"amount4"  : 1,
		"file2"    : "/open/ghost-hole/obj/eq/ghost-leggings",
		"amount1"  : 1,
		"file10"   : "/open/ghost-hole/obj/eq/ghost-pants",
		"file8"    : "/open/ghost-hole/obj/eq/ghost-gloves",
		"file7"    : "/open/ghost-hole/obj/eq/ghost-shield",
	]) );
	set( "build", 10080 );
	set( "exits", ([
		"north"     : "/open/clan/nine-sky-dragon/room/room25",
	]) );
	set( "long", @LONG
愛你等於擁有 一片天空任何風吹草動 都有你存在其中 
自然而然的輕鬆 一路到 夏天的尾聲無所謂 到過於激動 
我們有笑容 我們曾心動不再是 無動於衷 
無條件為你 不顧明天的安穩為你變堅強 相信你的眼神 
不敢想 不敢問 有一天壞的可能 
無條件為你 放棄單獨的旅程為你堅強 就不怕犧牲 
我的靈魂 如此沸騰 為我愛的人 喜歡複雜還是 
習慣單純我願盡力完成 你在我心中幾分 難以形容的責任 
愛一個人 付出才會完整無條件 越愛就越深 永遠不分 喔...

LONG);
	setup();
	replace_program(ROOM);
}
