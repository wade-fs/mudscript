inherit ROOM;
void create() {
	set( "short", "夜夢宮" );
	set( "object", ([
		"file9"    : "/open/gsword/obj1/bbladeball",
		"amount7"  : 1,
		"amount8"  : 1,
		"amount6"  : 1,
		"file1"    : "/open/gsword/obj1/bbladeball",
		"amount2"  : 1,
		"file4"    : "/open/gsword/obj1/bbladeball",
		"file5"    : "/open/gsword/obj1/bbladeball",
		"file7"    : "/open/gsword/obj1/bbladeball",
		"file6"    : "/open/gsword/obj1/bbladeball",
		"amount5"  : 1,
		"amount4"  : 1,
		"amount9"  : 1,
		"amount1"  : 1,
		"file2"    : "/open/gsword/obj1/bbladeball",
		"file8"    : "/open/gsword/obj1/bbladeball",
	]) );
	set( "build", 10099 );
	set( "light_up", 1 );
	set( "exits", ([
		"south"     : "/open/clan/nine-sky-dragon/room/room4",
	]) );
	set( "long", @LONG
    這裡是位於湖心小築的中心,空氣中散佈著陣陣的花香和異常強大的靈力,
強大的靈力彷彿形成一道無形的防護結界,不輕易讓外來客進出,四周的動
植物們似乎不是非常的歡迎外來客的到訪,前方的黑影像是一個人,而黑影
的後面是一座美輪美奐的建築物,你忽然想到前面就是傳說中的夜夢宮,
而那道黑影想必就是---夜夢宮宮主--「千水凝冰」--劍如冰.
LONG);
	setup();
	replace_program(ROOM);
}
