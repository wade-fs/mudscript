inherit ROOM;
void create() {
	set( "short", "簡單愛" );
	set( "owner", "woan" );
	set( "exits", ([
		"east"      : "/open/clan/13_luck/room/room326.c",
		"west"      : "/open/clan/13_luck/room/room327",
	]) );
	set( "object", ([
		"file9"    : "/open/fire-hole/obj/g-pill",
		"file4"    : "/open/mogi/castle/obj/ninepill",
		"file2"    : "/open/mogi/dragon/obj/scale",
		"file1"    : "/open/fire-hole/obj/r-pill",
		"amount7"  : 1,
		"file3"    : "/open/fire-hole/obj/g-pill",
		"file7"    : "/open/capital/obj/blade2",
		"file8"    : "/open/fire-hole/obj/r-pill",
		"amount4"  : 37,
		"amount9"  : 4,
		"amount8"  : 4,
		"amount3"  : 16,
		"amount6"  : 1,
		"file5"    : "/open/fire-hole/obj/w-pill",
		"amount5"  : 4,
		"amount1"  : 15,
		"amount2"  : 1,
		"file6"    : "/open/mogi/dragon/obj/scale",
	]) );
	set( "build", 14106 );
	set( "light_up", 1 );
	set( "long", @LONG
    說不上為什麼，我變得很主動，若愛上一個人，什麼都會
值得去做，我想大聲宣布，對你依依不舍，連隔壁鄰居都猜到
我現在的感受，河邊的風，在吹著頭髮飄動，牽著你的手一陣
莫名感動，我想帶你，回我的外婆家，一起看著日落，一直到
我們都睡著，我想就這樣牽著你的手不放開，愛能不能夠永遠
單純沒悲哀，我，想和你騎單車，我，想和你看棒球，像這樣
沒擔憂，唱著歌，一直走，我想就這樣牽著你的手不放開，愛
可不可以簡簡單單沒有傷害，你靠著我的肩膀，你在我胸口睡
著，像這樣的生活，我愛你，你愛我。 

               想 簡！簡！單！單！ 愛

     　　　　　想 簡！簡！單！單！ 愛  


LONG);
	setup();
	replace_program(ROOM);
}
