inherit ROOM;
void create() {
	set( "short", "勇氣" );
	set( "owner", "yaoblade" );
	set( "object", ([
		"amount3"  : 10,
		"file2"    : "/open/magic-manor/ghost/obj/trigram-pill",
		"file7"    : "/open/mogi/dragon/obj/scale",
		"file6"    : "/open/mogi/castle/obj/ninepill",
		"amount6"  : 120,
		"amount1"  : 122,
		"file4"    : "/open/fire-hole/obj/w-pill",
		"amount2"  : 62,
		"amount4"  : 7,
		"file1"    : "/open/magic-manor/ghost/obj/trigram-pill",
		"file3"    : "/open/mon/obj/mon-pill",
		"amount7"  : 1,
		"file8"    : "/open/mogi/dragon/obj/scale",
		"amount8"  : 1,
	]) );
	set( "build", 10098 );
	set( "exits", ([
		"west"      : "/open/clan/nine-sky-dragon/room/room27.c",
		"east"      : "/open/clan/nine-sky-dragon/room/room28.c",
		"north"     : "/open/clan/nine-sky-dragon/room/room29.c",
		"south"     : "/open/clan/nine-sky-dragon/room/room30",
		"down"      : "/open/clan/nine-sky-dragon/room/room20.c",
	]) );
	set( "long", @LONG
終於做了這個決定 別人怎麼說我不理 只要你也一樣的肯定 
我願意天涯海角都隨你去 我知道一切不容易 
我的心一直溫習說服自己 最怕你忽然說要放棄 
愛真的需要勇氣 來面對流言蜚語 
只要你一個眼神肯定 我愛你的意義(我的愛就有意義) 
我們都需要勇氣 去相信會在一起 人潮擁擠我能感覺你 
放在我手心 你的真心 
如果我的堅強任性 會不小心傷害了你 
你能不能溫柔提醒 我雖然心太急 更害怕錯過你

LONG);
	setup();
	replace_program(ROOM);
}
