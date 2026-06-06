inherit ROOM;
void create() {
	set( "short", "$HIC$ξ$HIG$牙$HIR$之$HIY$聖域$HIC$ξ$NOR$" );
	set( "owner", "coling" );
	set( "object", ([
		"file8"    : "/open/fire-hole/obj/r-pill",
		"file4"    : "/open/snow/obj/stone",
		"amount4"  : 1,
		"amount8"  : 4,
		"amount10" : 4,
		"file10"   : "/open/fire-hole/obj/p-pill",
		"amount5"  : 1,
		"file9"    : "/open/fire-hole/obj/g-pill",
		"amount1"  : 1,
		"amount6"  : 8,
		"file6"    : "/open/fire-hole/obj/b-pill",
		"file1"    : "/open/mogi/dragon/obj/scale",
		"file5"    : "/obj/gift/shenliwan",
		"amount9"  : 4,
	]) );
	set( "light_up", 1 );
	set( "build", 10014 );
	set( "exits", ([
		"chome"     : "/open/clan/sky-wu-chi/room/hall",
	]) );
	set( "long", @LONG

$HIC$                                                                 ◢
                                                           ◢  ◢█
                                                         ◢█◢██ 
                                                     ◢██████
                                            $HIC$     ◢████████◤$HIW$□
                                            $HIC$   ◢█◤  ◢████◤$HIW$□□
                                           $HIC$◢███████████◤$HIW$□ 
$HIG$           ◢██████████████$HIW$□$HIC$█████████████$HIW$□      $HIG$          ██
$HIG$         ◢███████████████$HIC$  ◥  ＼◥ ◥██████◤ $HIW$□$HIG$██████████
$HIG$       ◢████████████████$HIC$        ＼   ██████◣ $HIW$□$HIG$██████████
$HIG$     ◢█████████████████$HIC$          ◤  ██$HIW$□□□□□□$HIG$██████████
$HIG$   ◢██████████████████$HIC$        ◤  ██◤$HIW$□□□□□□$HIG$██████████
$HIG$ ◢███████████████████$HIW$□□□$HIC$ ◥█◤$HIW$□□□□□□□ □$HIG$██████████
                                                               $HIW$□□□□                $HIG$██ $NOR$

LONG);
	setup();
	replace_program(ROOM);
}
