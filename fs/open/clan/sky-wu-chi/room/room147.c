inherit ROOM;
void create() {
	set( "short", "小嫺的閨房" );
	set( "object", ([
		"file10"   : "/daemon/class/fighter/armband",
		"file7"    : "/open/mon/obj/ghost-claw",
		"file3"    : "/daemon/class/bonze/puty_pullium",
		"file4"    : "/open/dancer/obj/yuawaist",
		"amount7"  : 1,
		"amount10" : 1,
		"file5"    : "/open/dancer/obj/yuaboots",
		"amount8"  : 1,
		"file8"    : "/open/ping/obj/ring-2",
		"file6"    : "/open/sky/obj/lucky_grasslink",
		"amount5"  : 1,
		"amount4"  : 1,
		"file2"    : "/open/scholar/obj/icefan",
		"amount3"  : 1,
		"file1"    : "/open/ping/obj/chilin_legging",
		"amount6"  : 1,
		"amount9"  : 1,
		"amount1"  : 1,
		"file9"    : "/daemon/class/blademan/obj/shield",
		"amount2"  : 1,
	]) );
	set( "light_up", 1 );
	set( "build", 10103 );
	set( "exits", ([
		"east"      : "/open/clan/sky-wu-chi/room/room149",
	]) );
	set( "long", @LONG
當你一進入我想上的房間，不禁慾火焚身，開始想要起來了，真是奇怪，平時都起不來
，現在變成這樣。就好像我都踢了你一下你怎麼可能還站的起來。

其不傳絕學小宇宙拳如：
我想上把聖衣脫下，燃燒了自己的小宇宙，大喝第一式：看我的『星　雲　風　暴』～～～

我想上大喝第二式：看我的『曙  光  女  神  之  寬  恕』～～～『鑽  石  巨  拳』

我想上燃燒了全身的小宇宙，大喝第三式：看我的『鳳  翼  天  翔』～～～

最後突發奇想創出最強一擊

我想上大喝一聲最終式：看我的「天  馬  流  星  拳」～～～

LONG);
	setup();
	replace_program(ROOM);
}
