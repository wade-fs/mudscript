inherit ROOM;
void create() {
	set( "short", "jtl 大樓2-1" );
	set( "owner", "panhermes" );
	set( "object", ([
		"amount10" : 200,
		"amount2"  : 1,
		"file6"    : "/open/main/room/sp/stone",
		"amount1"  : 5,
		"amount9"  : 200,
		"file9"    : "/open/mogi/castle/obj/sspill",
		"amount5"  : 1,
		"amount3"  : 1,
		"amount7"  : 1,
		"file1"    : "/open/mon/obj/mon-pill",
		"file3"    : "/open/capital/obj/chen_dagger",
		"file5"    : "/open/center/obj/clan-master-head",
		"file10"   : "/open/mogi/castle/obj/sspill",
		"file7"    : "/open/main/room/sp/stone",
		"file2"    : "/open/capital/obj/chen_dagger",
		"amount6"  : 1,
		"file8"    : "/open/mogi/castle/obj/sspill",
		"amount8"  : 200,
	]) );
	set( "build", 14118 );
	set( "light_up", 1 );
	set( "exits", ([
		"southwest" : "/open/clan/sky-wu-chi/room/room329",
		"east"      : "/open/clan/sky-wu-chi/room/room322.c",
		"north"     : "/open/clan/sky-wu-chi/room/room325.c",
		"south"     : "/open/clan/sky-wu-chi/room/room324.c",
		"southeast" : "/open/clan/sky-wu-chi/room/room328.c",
		"northwest" : "/open/clan/sky-wu-chi/room/room326.c",
		"west"      : "/open/clan/sky-wu-chi/room/room323.c",
		"down"      : "/open/clan/sky-wu-chi/room/room318.c",
		"northeast" : "/open/clan/sky-wu-chi/room/room327.c",
	]) );
	set( "long", @LONG
這裡是miffy 的一些wp 分類房,你可以看到以這裡為中心有分為東西南北四房
而東西南北四房分別為東房殺意錐,西房千古恨,南房滅神匕,北房絕世匕
而從東西南北四房在延伸出去的有西北房為雜物房,東北房為丹藥房
西南房雜器房,東南房為救神神丹房,等等總類共分為八大房
所以第二層乃是miffy 房的重點房...也禁止一些人物的禁入..這是為了安全起見
LONG);
	setup();
	replace_program(ROOM);
}
