inherit ROOM;
void create() {
	set( "short", "$HIR$妖刀$HIG$正宗$HIB$ソ塚$NOR$" );
	set( "owner", "hild" );
	set( "object", ([
		"amount3"  : 1,
		"amount5"  : 1,
		"amount1"  : 1,
		"amount6"  : 1,
		"amount9"  : 1,
		"file8"    : "/open/main/room/sp/stone",
		"file1"    : "/open/main/room/sp/stone",
		"file3"    : "/open/main/room/sp/stone",
		"amount10" : 1,
		"file10"   : "/open/main/room/sp/stone",
		"file9"    : "/open/main/room/sp/stone",
		"amount2"  : 1,
		"amount8"  : 1,
		"file7"    : "/open/main/room/sp/stone",
		"file2"    : "/open/main/room/sp/stone",
		"file5"    : "/open/main/room/sp/stone",
		"file6"    : "/open/main/room/sp/stone",
		"amount7"  : 1,
	]) );
	set( "build", 10004 );
	set( "light_up", 1 );
	set( "exits", ([
		"west"      : "/open/clan/sky-wu-chi/room/room73.c",
		"south"     : "/open/clan/sky-wu-chi/room/room87",
	]) );
	set( "long", @LONG
就是岡崎五郎入道正宗所作之刀，正宗為正劍的代表，後來更成為
權力授與的印信，大名將一國賜與重臣管理時，往往會贈予名刀作為象
徵品，因此當大名給予重臣正宗刀，往往是代表授與一國國主的無上光
榮，關之原大戰後，石田三成被田中吉政所捉，後來面臨死刑的命運，
臨死前繳回兩把正宗刀，除了證明自己曾受太閣重用之外，也是對家康
的無言抗議。 

LONG);
	setup();
	replace_program(ROOM);
}
