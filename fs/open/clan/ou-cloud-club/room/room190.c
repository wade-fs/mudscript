inherit ROOM;
void create() {
	set( "short", "$HIB$沉璧$NOR$" );
	set( "owner", "bbsboss" );
	set( "light_up", 1 );
	set( "object", ([
		"amount5"  : 1,
		"file8"    : "/open/gblade/obj/sa-head",
		"file10"   : "/open/mogi/dragon/obj/scale",
		"file2"    : "/open/gsword/obj/spsword-1",
		"amount9"  : 1,
		"file1"    : "/open/killer/obj/k_ring",
		"file7"    : "/autoload/swordsman/sun_sword_book",
		"amount2"  : 1,
		"file4"    : "/open/mogi/dragon/obj/scale",
		"file3"    : "/open/mogi/dragon/obj/scale",
		"file5"    : "/open/gblade/obj/sa-head",
		"amount6"  : 1,
		"amount1"  : 1,
		"file6"    : "/open/mogi/dragon/obj/scale",
		"amount4"  : 1,
		"file9"    : "/open/killer/obj/kill_yar_head",
		"amount8"  : 1,
		"amount10" : 1,
		"amount3"  : 1,
		"amount7"  : 1,
	]) );
	set( "build", 10016 );
	set( "exits", ([
		"east"      : "/open/clan/ou-cloud-club/room/room128.c",
		"west"      : "/open/clan/ou-cloud-club/room/room189.c",
	]) );
	set( "long", @LONG

     $HIR$這是皇室的祖傳兵器，能夠完完全全的配合皇室絕學$NOR$


這個房間影約一直發出著湛藍的螢光....
定神一看...咦..這不是皇室所專用的兵器嘛....
莫非前些日子皇宮遭盜..是小馬所為...
這可是殺頭之罪耶.....看來小馬可真是亡命之徒
LONG);
	setup();
	replace_program(ROOM);
}
