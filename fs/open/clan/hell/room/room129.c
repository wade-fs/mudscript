inherit ROOM;
void create() {
	set( "short", "狂想空間入口處" );
	set( "exits", ([
		"up"        : "/open/clan/hell/room/room130.c",
		"down"      : "/open/clan/hell/room/room132.c",
	]) );
	set( "long", @LONG

歡迎各位來到狂想空間的世界,希望這裏能給你不同的發現!!! :)
新手請多多使用 help 指令哦~~~~~ :)

 往上走就是狂想空間幫派言論廣場。
 往西為狂想技能建言的言論廣場。
 往東為狂想玩家申請備份檔案的地方。
 往南為狂想制度建言的討論區。
 往北為違反狂想空間制度的公佈欄。
 往東北方為歷代狂想巫師紀念榜。
 往下走你將會正式進入狂想空間的世界。

  小女孩(Little girl)
  $HIC$投票專用箱$NOR$ (box) [ $HIR$沒有投票活動$NOR$ ]
LONG);
	setup();
	replace_program(ROOM);
}
