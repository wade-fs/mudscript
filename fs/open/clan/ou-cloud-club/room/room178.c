inherit ROOM;
void create() {
	set( "short", "糯米雞的私人閨房" );
	set( "owner", "sisao" );
	set( "object", ([
		"amount2"  : 1,
		"amount1"  : 1,
		"file1"    : "/open/killer/headkill/obj/world_dag",
		"file2"    : "/open/killer/headkill/obj/world_dag",
	]) );
	set( "light_up", 1 );
	set( "build", 10076 );
	set( "exits", ([
		"west"      : "/open/clan/ou-cloud-club/room/room151",
	]) );
	set( "long", @LONG
  這裡是火焰鴨給小雯的私人閨房,因為小雯的東西一間房間已經放不
下了,房間裡頭到處放著的都是火焰鴨送給小雯的東西,桌上放著一條
水晶項鍊,是小雯今年的生日禮物,所以他特地放在桌上,角落裡頭則放
了一些常用的裝備.
  
LONG);
	setup();
	replace_program(ROOM);
}
