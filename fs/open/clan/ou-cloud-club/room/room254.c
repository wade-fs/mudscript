inherit ROOM;
void create() {
	set( "short", "射擊指揮所" );
	set( "owner", "really" );
	set( "object", ([
		"amount1"  : 39,
		"file2"    : "/obj/gift/hobowdan",
		"file10"   : "/obj/gift/lingzhi",
		"amount8"  : 1,
		"file9"    : "/obj/gift/xisuidan",
		"amount5"  : 1,
		"amount10" : 1,
		"file6"    : "/obj/stone/suipian",
		"file5"    : "/open/magic-manor/obj/lunar-heart",
		"file1"    : "/obj/stone/powder",
		"file8"    : "/obj/gift/unknowdan",
		"amount7"  : 1,
		"amount2"  : 1,
		"file7"    : "/obj/gift/bingtang",
		"amount9"  : 1,
		"amount3"  : 1,
		"amount6"  : 2,
		"amount4"  : 1,
		"file3"    : "/open/capital/guard/gring",
		"file4"    : "/obj/gift/unknowdan",
	]) );
	set( "light_up", 1 );
	set( "build", 10189 );
	set( "exits", ([
		"add"       : "/open/clan/ou-cloud-club/room/room356",
		"down"      : "/open/clan/ou-cloud-club/room/room298",
		"south"     : "/open/clan/ou-cloud-club/room/room244.c",
	]) );
	set( "long", @LONG
這裡是一片空曠的草原，綠油油的一片讓人看了心曠神
怡，正前方不遠處有一顆七尺高的大樹，樹下有幾個人正圍
在一張小小的桌子旁邊，你走近一看，發現桌上放著一張方
眼紙，上面畫滿了你看不懂得記號，身旁三尺處有一個人正
對著有線電的話筒喊著：『全排、榴彈、Ａ批號、五號裝藥
、瞬發信管』，幾秒鐘以後聽筒也傳來複誦的聲音。
  
  射擊指揮所組長(Mortar leader)
  射擊指揮所組員(Mortar man1-2)
LONG);
	setup();
	replace_program(ROOM);
}
