inherit ROOM;
void create() {
	set( "short", "$HIG$OOQ西廂房$NOR$" );
	set( "object", ([
		"amount2"  : 1,
		"file2"    : "/open/gsword/obj1/bpball",
		"amount1"  : 1,
		"file1"    : "/open/gsword/obj1/bpball",
	]) );
	set( "exits", ([
		"east"      : "/open/clan/ou-cloud-club/room/room133",
	]) );
	set( "build", 10229 );
	set( "light_up", 1 );
	set( "long", @LONG
西廂房西廂房西廂房西廂房西廂房西廂房
西廂房西廂房西廂房西廂房西廂房西廂房西廂房
西廂房西廂房西廂房西廂房西廂房西廂房西廂房
西廂房西廂房西廂房西廂房西廂房西廂房西廂房
西廂房西廂房西廂房西廂房西廂房西廂房西廂房
LONG);
	setup();
	replace_program(ROOM);
}
