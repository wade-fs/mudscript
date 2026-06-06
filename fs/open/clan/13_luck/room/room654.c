inherit ROOM;
void create() {
	set( "short", "神界" );
	set( "exits", ([
		"out"       : "/open/clan/13_luck/room/room74",
	]) );
	set( "owner", "amdxp" );
	set( "object", ([
		"file3"    : "/open/capital/obj/4-4",
		"amount2"  : 1,
		"amount3"  : 1,
		"file4"    : "/open/mogi/castle/obj/lochagem",
		"amount5"  : 1,
		"file1"    : "/open/killer/headkill/obj/world_dag",
		"file2"    : "/obj/gift/xiandan",
		"file5"    : "/obj/gift/shenliwan",
		"amount1"  : 1,
		"amount4"  : 1,
	]) );
	set( "build", 10010 );
	set( "light_up", 1 );
	set( "long", @LONG

                  ◢◣◢◣◢█◣◢◣◢◣
      ███◣◢█████████████◣◢███
      █████◤　◢███████◣　◥█████
      ████◤◥◣█神        界█◢◤◥████
      ███◤　　█◤███████◥█　　◥███
      ██◤  　                              ◥██
      ██                                      ██
      ██                                      ██
      ██                                      ██
      ██◣                                  ◢██

LONG);
	setup();
	replace_program(ROOM);
}
