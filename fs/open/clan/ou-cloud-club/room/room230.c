inherit ROOM;
void create() {
	set( "short", "$HIW$正$HIG$‧$HIR$邪$HIG$‧$HIB$道$NOR$" );
	set( "owner", "del" );
	set( "object", ([
		"file3"    : "/daemon/class/blademan/obj/hstone",
		"amount6"  : 1,
		"amount2"  : 1,
		"amount4"  : 1,
		"amount3"  : 1,
		"file5"    : "/daemon/class/blademan/obj/wastone",
		"amount7"  : 1,
		"file1"    : "/daemon/class/blademan/obj/gstone",
		"amount1"  : 1,
		"file2"    : "/daemon/class/blademan/obj/fstone",
		"file4"    : "/daemon/class/blademan/obj/wstone",
		"file7"    : "/open/magic-manor/obj/magic-sign",
		"file6"    : "/daemon/class/blademan/obj/estone",
		"amount5"  : 1,
	]) );
	set( "item_desc", ([
		"words" : @ITEM
    
    正    邪    兩    [1;33,不    分
      
ITEM,
	]) );
	set( "build", 10049 );
	set( "light_up", 1 );
	set( "exits", ([
		"north"     : "/open/clan/ou-cloud-club/room/room33.c",
		"add"       : "/open/clan/ou-cloud-club/room/room356.c",
	]) );
	set( "long", @LONG
沿著小徑緩緩前進，來到了一間空間廣闊的石室，光線
是從較為上層的石壁透光而來，仰頭望去，有一座懸空的平
台，靠著十六條手腕般粗的鐵鍊與周圍的牆壁連結，鐵鍊上
佈滿了數以萬計的蜘蛛，平台上有一塊小石碑，上面刻著幾
個大字(words) ，石碑周圍有幾把兵器隱隱泛著金光。
  
LONG);
	setup();
	replace_program(ROOM);
}
