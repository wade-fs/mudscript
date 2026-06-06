inherit ROOM;
void create() {
	set( "short", "狐狸窩" );
	set( "build", 1175 );
	set( "owner", "devilfox" );
	set( "exits", ([
		"south"     : "/open/clan/ou-cloud-club/room/room150.c",
		"north"     : "/open/clan/ou-cloud-club/room/room730",
	]) );
	set( "long", @LONG
這是百年老不死Xman的龜窩,經過4年的塵封,Xman回到了FS,
現在Xman沒事就會龜在這,這裡的擺飾亂七八糟,整個房間像是被
亂槍掃射過,可見Xman這個死老頭沒事只會顧玩FS,完全沒在整理
房間,真難想像這種房間怎麼可以住人


LONG);
	setup();
	replace_program(ROOM);
}
