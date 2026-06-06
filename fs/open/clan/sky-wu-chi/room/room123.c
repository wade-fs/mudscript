inherit ROOM;
void create() {
	set( "short", "浧慕澐小房" );
	set( "owner", "miffy" );
	set( "object", ([
		"amount1"  : 19,
		"file1"    : "/open/fire-hole/obj/p-pill",
	]) );
	set( "light_up", 1 );
	set( "build", 10035 );
	set( "exits", ([
		"west"      : "/open/clan/sky-wu-chi/room/room228",
		"east"      : "/open/clan/sky-wu-chi/room/room50",
	]) );
	set( "long", @LONG
在這個小房裡並沒有什麼樣的東西...有的只是他輕遍的一些小衣
但是你想要在這裡看到什麼東西的話,也許是要你失望了..因為這裡沒
有你所想要看到的東西..突然間你看到了一些裝備..看起來是非常豪
華的..有
王母腰帶(Girl belt)寶蓮靴(Girl boots)曉月披肩(Girl cloak)鳳袍(Girl cloth)
哇..真是給他有夠好的裝備呢...

LONG);
	setup();
	replace_program(ROOM);
}
