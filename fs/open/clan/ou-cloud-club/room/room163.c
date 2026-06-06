inherit ROOM;
void create() {
	set( "short", "$HIY$OOQ東廂房$NOR$" );
	set( "object", ([
		"amount1"  : 5,
		"file1"    : "/open/fire-hole/obj/y-pill",
	]) );
	set( "exits", ([
		"west"      : "/open/clan/ou-cloud-club/room/room133",
	]) );
	set( "build", 14697 );
	set( "light_up", 1 );
	set( "long", @LONG

    前方瀰漫著些許濃霧,令你看不清四周環境,而此刻身旁的時空只有比
剛剛更加錯亂顛倒,這是接近神的境界所引發的種種異象啊,凡人若妄想進
入神的領域,是會遭受天譴的,在濃霧較為稀散之時,你隱約望見前方出現
一座神秘的古城...

LONG);
	setup();
	replace_program(ROOM);
}
