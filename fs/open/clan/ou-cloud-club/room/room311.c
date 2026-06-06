inherit ROOM;
void create() {
	set( "short", "xxxxxxxxxxu" );
	set( "object", ([
		"amount6"  : 1,
		"file3"    : "/open/killer/headkill/obj/world_dag",
		"amount4"  : 1,
		"amount2"  : 1,
		"amount3"  : 1,
		"file5"    : "/open/firedancer/npc/eq/r_pants",
		"amount7"  : 1,
		"file4"    : "/open/firedancer/npc/eq/r_boots",
		"file2"    : "/open/gsword/obj1/ring",
		"file6"    : "/open/killer/headkill/obj/world_dag",
		"file7"    : "/open/doctor/obj/feather",
		"amount5"  : 1,
	]) );
	set( "exits", ([
		"up"        : "/open/clan/ou-cloud-club/room/room298",
		"down"      : "/open/clan/ou-cloud-club/room/room210.c",
	]) );
	set( "owner", "del" );
	set( "build", 10093 );
	set( "light_up", 1 );
	set( "long", @LONG
聚靈八傑兵器庫聚靈八傑兵器庫聚靈八傑兵器庫聚靈八傑兵器庫
聚靈八傑兵器庫聚靈八傑兵器庫聚靈八傑兵器庫聚靈八傑兵器庫
聚靈八傑兵器庫聚靈八傑兵器庫聚靈八傑兵器庫聚靈八傑兵器庫
聚靈八傑兵器庫聚靈八傑兵器庫聚靈八傑兵器庫聚靈八傑兵器庫
聚靈八傑兵器庫聚靈八傑兵器庫聚靈八傑兵器庫聚靈八傑兵器庫
LONG);
	setup();
	replace_program(ROOM);
}
