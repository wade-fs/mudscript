inherit ROOM;
void create() {
	set( "short", "龍之崖" );
	set( "owner", "pighead" );
	set( "object", ([
		"file6"    : "/open/sky/obj/lucky_grasslink",
		"amount5"  : 1,
		"amount2"  : 1,
		"amount7"  : 1,
		"file8"    : "/daemon/class/bonze/puty_pullium",
		"file7"    : "/open/ping/obj/gold_hand",
		"file4"    : "/open/mon/obj/ghost-legging",
		"amount3"  : 1,
		"amount8"  : 1,
		"amount6"  : 1,
		"file1"    : "/open/snow/obj/figring",
		"file5"    : "/open/dancer/obj/yuawaist",
		"amount4"  : 1,
		"amount1"  : 1,
		"file3"    : "/open/mon/obj/ghost-cloak",
		"amount9"  : 1,
		"amount10" : 1,
		"file10"   : "/open/scholar/obj/icefan",
		"file9"    : "/open/gsword/obj/yuskirt",
		"file2"    : "/open/mon/obj/ghost-claw",
	]) );
	set( "item_desc", ([
		"滅殺龍" : @ITEM
你眼前一黑，接著什麼都不知道了....
你死了
陰曹入口-
          你已經來到了陰間的入口。雖然距離地府還有一段距離，但是你已經
感受到陣陣刺骨的陰風。四周一片荒涼，但是卻鬼影幢幢，看來這邊的夜
總會蠻熱鬧的，應該不愁沒伴。南邊和上面好像是和人世間相通的管道，
不過好像有一股無形的力量隔開這兩個不同的世界，看來要從這兩個方向
回去不是那麼簡*漕き﹛C
    這裡唯一的出口是 north。
ITEM,
		"stone" : @ITEM

一個巨大的石頭，其上留下著一個深重的掌印，下面並烙下四個
極深的大字 
               ◎  波  動  ●  皇  拳  ◎ 
ITEM,
	]) );
	set( "build", 10959 );
	set( "light_up", 1 );
	set( "exits", ([
		"enter"     : "/open/clan/13_luck/room/room276",
		"north"     : "/open/clan/13_luck/room/room100.c",
	]) );
	set( "long", @LONG

    四處空蕩，一走進這懸崖，便只聽到自己的腳步聲迴蕩在山谷之
中不絕於耳，仔細聆聽，似乎可聽見風中傳來微弱的練功吆喝聲，閉
眼按運內力耳聽八方，風中之聲竟是失傳己久的【波動皇拳】只見懸
崖下散出千萬丈的金光，一時間龍騰九天迴旋空，瞬間消失無蹤，驚
厄之中突然一道閃光從山谷下飛縱至你面前，眼前正是
            【波動皇拳】唯一傳人‧滅殺龍
$HIY$只見其身旁金色龍形$HIY$護身氣勁光芒圍繞其修為之高令人暗自讚嘆！

LONG);
	setup();
	replace_program(ROOM);
}
