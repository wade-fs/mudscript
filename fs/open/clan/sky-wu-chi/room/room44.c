inherit ROOM;
void create(){
set("long",@LONG
一走進天龍學堂，發現在牆上有一副橫匾，上面寫著斗大的◎天龍學堂◎四個
字，在橫匾兩旁是一副對聯，左邊寫著文蹈，右邊寫的是武略，這裡就是平南書院
教導學生『御』課程的地方，能在這裡授課的講師，不是大理王國的大將軍，就是
正丞相等朝廷重要的文武大臣，有時候，還會邀請到大理王朝的軍師講述一些治理
國家或對外關係所需要用的謀略等。在門口旁邊有一個架子，是要讓進到裡面來的
人能有放置裝備的地方。
LONG);
	set( "short", "$HIY$【平南書院】 $HIC$天龍學堂$NOR$" );
	set( "owner", "lonsan" );
	set( "object", ([
		"file10"   : "/obj/gift/xiandan",
		"file7"    : "/open/doctor/obj/curebook",
		"amount10" : 1,
		"file4"    : "/open/ping/questsfan/obj/weaponmap",
		"amount9"  : 1,
		"amount8"  : 1,
		"file6"    : "/obj/gift/shenliwan",
		"file2"    : "/open/tailong/obj/six_book",
		"file9"    : "/open/mogi/castle/obj/blood-water",
		"amount2"  : 1,
		"file8"    : "/open/mogi/castle/obj/leave",
		"amount7"  : 1,
		"file5"    : "/open/tendo/obj/book2",
		"amount4"  : 1,
		"amount6"  : 1,
		"file1"    : "/open/mogi/castle/obj/fire_book",
		"amount3"  : 1,
		"amount5"  : 1,
		"amount1"  : 1,
		"file3"    : "/open/gblade/obj/book",
	]) );
	set( "light_up", 1 );
	set( "build", 10152 );
	set( "exits", ([
		"east"      : "/open/clan/sky-wu-chi/room/room139",
	]) );
        set("no_transmit",1);
        set("cmkroom",1);
        setup();
        replace_program(ROOM);
}
