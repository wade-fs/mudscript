inherit ROOM;
void create() {
	set( "short", "小強房外庭園" );
	set( "owner", "panhermes" );
	set( "light_up", 1 );
	set( "object", ([
		"file4"    : "/open/ghost-hole/obj/light-spirit",
		"amount3"  : 1,
		"file2"    : "/open/killer/headkill/obj/e_dag",
		"file6"    : "/open/capital/obj/steps_book",
		"amount9"  : 15,
		"amount6"  : 1,
		"file9"    : "/open/killer/obj/black",
		"file10"   : "/open/capital/obj/force_book",
		"amount5"  : 1,
		"amount8"  : 1,
		"file8"    : "/open/killer/headkill/obj/w_dag",
		"amount10" : 1,
		"amount1"  : 1,
		"amount7"  : 1,
		"file1"    : "/obj/gift/bingtang",
		"amount2"  : 1,
		"file7"    : "/open/killer/memory/static",
		"file3"    : "/open/killer/headkill/obj/i_dag",
		"amount4"  : 1,
		"file5"    : "/open/port/obj/wolf_ring",
	]) );
	set( "build", 10060 );
	set( "exits", ([
		"west"      : "/open/clan/sky-wu-chi/room/room212",
	]) );
	set( "long", @LONG
這裡是一個很純樸的農家庭園打扮,你看到三步五時就有些村婦會
在這裡走在來走,所以你壓根都不會發現原來這裡住了一個世外高人
但是你不知道,原來裡面正是住著一個傳奇的人物,她善常用刀,因
為她現在有事情要外出,所以你也就找不到她的人影了,看看著庭園
外的景色真是怡人ㄚ,依山傍水的,正是個清修的好環境,你不自覺的
也就響往了起來,也希望過著這樣子的生活...

LONG);
	setup();
	replace_program(ROOM);
}
