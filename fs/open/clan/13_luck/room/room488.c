inherit ROOM;
void create() {
	set( "short", "英雄戰場" );
	set( "owner", "mill" );
	set( "object", ([
		"file4"    : "/open/fire-hole/obj/w-pill",
		"amount1"  : 1,
		"file1"    : "/open/fire-hole/obj/b-pill",
		"amount4"  : 5,
	]) );
	set( "build", 10002 );
	set( "light_up", 1 );
	set( "exits", ([
		"west"      : "/open/clan/13_luck/room/room486",
		"north"     : "/open/clan/13_luck/room/room369",
		"east"      : "/open/clan/13_luck/room/room487.c",
	]) );
	set( "long", @LONG

    冷冷的蕭風﹐肅殺的氣息﹐這裡就是名聞江湖的決鬥聖地﹑『英雄
戰場』﹐許多武林好手都會聚集於此地﹐將自己的生命賭注在這靈魂的
鬥技場中﹐來證明自己花了半輩子努力修練的成果﹐是否白廢﹐而這座
城堡的主人，據說武藝十分高強﹐最特別的是﹐他是個雙頭三臂的怪人

LONG);
	setup();
	replace_program(ROOM);
}
