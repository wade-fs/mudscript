inherit ROOM;
void create() {
	set( "short", "$HIG$狂$HIY$霸$HIC$惡$HIR$殺$NOR$" );
	set( "owner", "baby" );
	set( "object", ([
		"amount5"  : 1,
		"file7"    : "/open/mogi/dragon/obj/scale",
		"amount2"  : 1,
		"amount10" : 1,
		"file9"    : "/open/mogi/dragon/obj/scale",
		"amount6"  : 1,
		"amount8"  : 1,
		"file1"    : "/open/mogi/dragon/obj/scale",
		"file6"    : "/open/mogi/dragon/obj/scale",
		"file2"    : "/open/mogi/dragon/obj/scale",
		"file3"    : "/open/killer/obj/fire-knife",
		"file4"    : "/open/mogi/dragon/obj/scale",
		"file10"   : "/open/mogi/dragon/obj/scale",
		"amount7"  : 1,
		"amount3"  : 1,
		"file5"    : "/open/mogi/dragon/obj/scale",
		"amount1"  : 1,
		"file8"    : "/open/mogi/dragon/obj/scale",
		"amount9"  : 1,
		"amount4"  : 1,
	]) );
	set( "light_up", 1 );
	set( "build", 10495 );
	set( "exits", ([
		"east"      : "/open/clan/ou-cloud-club/room/room193",
		"west"      : "/open/clan/ou-cloud-club/room/room195",
	]) );
	set( "long", @LONG

$HIG$       ...           $HIY$       ''::'''     $HIC$      ......:'''     $HIR$      ...    ...$NOR$
$HIG$   ':. ::'           $HIY$   ::...:::'::'::: $HIC$        :: ::'...    $HIR$  ':..:'  ::''::$NOR$
$HIG$     ::: ....::'''   $HIY$  ''' :::::::.     $HIC$     ..:'' ''''::'   $HIR$   .::'::.::  ::$NOR$
$HIG$  ..:'::    :::      $HIY$     ::'::'......  $HIC$     ::.... ..:''    $HIR$  '' :::..:'  '''''$NOR$
$HIG$     .::: ..:::...   $HIY$   ..::::''::: ::  $HIC$        ::' ::...    $HIR$  ...::.:'...::::$NOR$
$HIG$    :::::   '::      $HIY$     '::...::''::  $HIC$    '::'''''''' ''   $HIR$ ''..::::  ':.::$NOR$
$HIG$ .:'' :::    :: .... $HIY$    ::::.:':::'::  $HIC$      ::  '::   '::. $HIR$  .:'::::.. :::.$NOR$
$HIG$    ..::'''''''''''''$HIY$ .....:::''::  ::  $HIC$   ::  ':.    ':..   $HIR$ .:' ::  ..:' :::..$NOR$
$HIG$     '''             $HIY$      :: .:' ':::  $HIC$   ''    ''':::'''   $HIR$     ''        '''$NOR$
LONG);
	setup();
	replace_program(ROOM);
}
