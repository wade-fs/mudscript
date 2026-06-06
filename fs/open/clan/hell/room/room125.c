inherit ROOM;
void create() {
	set( "short", "小笨蛋的臥室" );
	set( "object", ([
		"amount5"  : 1,
		"amount2"  : 1,
		"amount1"  : 1,
		"file4"    : "/open/killer/obj/hate_knife",
		"file7"    : "/open/sky/obj/lucky_grasslink",
		"file3"    : "/open/killer/headkill/obj/i_dag",
		"amount7"  : 1,
		"amount3"  : 1,
		"file5"    : "/open/killer/obj/dagger",
		"amount4"  : 12555,
		"file1"    : "/open/sky/obj/lucky_grasslink",
		"file2"    : "/open/killer/headkill/obj/e_dag",
	]) );
	set( "owner", "acelan" );
	set( "build", 10482 );
	set( "item_desc", ([
		"漂亮妹妹" : @ITEM
他突然轉過頭來瞪你一眼
ITEM,
		"書目資料" : @ITEM
基本拳譜
基本刺術
三字經
基本劍術
賭神秘術
just kidding ^_^
ITEM,
		"個人資料" : @ITEM
請參考我的網頁吧 ^_^
http://www.ice.cycu.edu.tw/~s8827142/
ITEM,
	]) );
	set( "light_up", 1 );
	set( "exits", ([
		"east"      : "/open/clan/hell/room/room126.c",
		"west"      : "/open/clan/hell/room/room124",
	]) );
	set( "long", @LONG
小笨蛋的臥室四周被一個透明的大蛋殼給包圍起來，就像一個大
透明球，在外牆上還刻著小笨蛋的(個人資料)，還有小笨蛋最喜歡的
(書目資料)。此外還有個(漂亮妹妹)在房間裡遊蕩，她可是小笨蛋的
女朋友喔，不過她滿兇的，大家要小心別惹到她了 :P
LONG);
	setup();
	replace_program(ROOM);
}
