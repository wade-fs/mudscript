inherit ROOM;
void create() {
	set( "short", "$HIC$劍神界$NOR$" );
	set( "object", ([
		"amount3"  : 1,
		"file3"    : "/open/ping/obj/cloud",
		"amount1"  : 1,
		"file1"    : "/open/ghost-hole/obj/eq/ghost-gem",
		"file6"    : "/open/gsword/obj1/bball",
		"amount6"  : 1,
		"amount2"  : 5,
		"file2"    : "/open/fire-hole/obj/b-pill",
	]) );
	set( "build", 10285 );
	set( "light_up", 1 );
	set( "exits", ([
		"down"      : "/open/clan/hell/room/room12.c",
		"up"        : "/open/clan/hell/room/room9.c",
		"east"      : "/open/clan/hell/room/room118",
		"west"      : "/open/clan/hell/room/room57.c",
	]) );
	set( "long", @LONG
    這裡是$HIR$陰曹地府$NOR$中第三層的劍神界，不是說這裡的
人是劍神，而是要被 賤 神們給$HIR$SM$NOR$，看到滿是傷痕的破
劍真不知道是怎麼被柔虐的。。。

$HIR$喂，你這個新來的還不把衣服拖了。
就是你就是你，還看！！$NOR$

  幸運一把抓的屍體(Corpse)
LONG);
	setup();
	replace_program(ROOM);
}
