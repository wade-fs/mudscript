inherit ROOM;
void create() {
	set( "short", "台積電 - FS廠" );
	set( "object", ([
		"amount10" : 1,
		"amount6"  : 1,
		"file8"    : "/obj/gift/unknowdan",
		"file6"    : "/obj/gift/unknowdan",
		"file10"   : "/open/main/room/sp/stone",
		"amount8"  : 1,
		"file2"    : "/open/ghost-hole/obj/water-spirit",
		"amount2"  : 1,
		"file9"    : "/obj/gift/shenliwan",
		"amount9"  : 1,
		"file1"    : "/open/mogi/castle/obj/ninepill",
		"file5"    : "/obj/gift/shenliwan",
		"amount1"  : 400,
		"amount5"  : 1,
	]) );
	set( "owner", "tomorrow" );
	set( "build", 10300 );
	set( "light_up", 1 );
	set( "exits", ([
		"west"      : "/open/clan/13_luck/room/room581",
	]) );
	set( "long", @LONG
八卦乾為首     五行金第一     百善孝為先

    南通洲     北通洲     南北通洲通南北
    東當舖     西當舖     東西當舖當東西
    大賭場     小賭場     大小賭場賭大小

    月照紗窗     個個孔明諸葛亮
    似水流年     首首金曲梅豔芳

LONG);
	setup();
	replace_program(ROOM);
}
