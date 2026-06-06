inherit ROOM;
void create() {
	set( "short", "小燕的全家便利商店" );
	set( "exits", ([
		"south"     : "/open/clan/ou-cloud-club/room/room153",
	]) );
	set( "owner", "pigdevil" );
	set( "object", ([
		"file2"    : "/open/magic-manor/water/obj/water-ribbon",
		"file3"    : "/open/magic-manor/ghost/obj/five-turn-ball",
		"file8"    : "/open/magic-manor/water/obj/water-ribbon",
		"file1"    : "/open/magic-manor/obj/fire-color-ribbon",
		"amount5"  : 1,
		"file9"    : "/open/killer/obj/dagger",
		"amount2"  : 1,
		"file10"   : "/open/sky/obj/lucky_grasslink",
		"amount3"  : 1,
		"amount8"  : 1,
		"amount1"  : 1,
		"file5"    : "/open/mogi/castle/obj/blood-water",
		"amount6"  : 1,
		"amount10" : 1,
		"amount4"  : 1,
		"file4"    : "/open/magic-manor/obj/fire-color-ribbon",
		"file6"    : "/open/magic-manor/obj/dark-soul-dagger",
		"amount9"  : 1,
	]) );
	set( "build", 10030 );
	set( "long", @LONG

     這是一間南北很長的房間,西邊是一排糊滿蟬翼紗的長窗,下半窗固定上半窗可開
 可闔.北邊和東牆都是依山鑿石而成,房頂偏東開著亮窗,坐在窗下仰望,山上雲樹婆娑
 ,瀑布溪流宛若圖畫,附近絕岩泉水叮咚透窗而入.屋裡陳設簡單,幾張杌子和茶几設在
 東窗下,靠門一座金自鳴鐘,盡北又一道活動門牆,摺疊起來大炕居北面南,展開隔柵門
 ,又像一道嚴嚴實實的屏風.

LONG);
	setup();
	replace_program(ROOM);
}
