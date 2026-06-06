inherit ROOM;
void create() {
	set( "short", "刀魔幻境 ==天== " );
	set( "owner", "hild" );
	set( "build", 10154 );
	set( "light_up", 1 );
	set( "exits", ([
		"up"        : "/open/clan/sky-wu-chi/room/room545.c",
		"down"      : "/open/clan/sky-wu-chi/room/room547.c",
		"out"       : "/open/clan/sky-wu-chi/room/room441",
	]) );
	set( "long", @LONG
哇！這裡真是好恐怖，好像某個傳說中的陣法組合成的房間，但
是這裡又跟刀有何關係呢？而刀跟這個陣法跟魔又有何關係呢？你無
從何地去探討出來，除非找出這裡的主人，不然你也只能靠運氣走出
這裡了，但是這裡周邊事物真的是讓你很吸引著。
LONG);
	setup();
	replace_program(ROOM);
}
