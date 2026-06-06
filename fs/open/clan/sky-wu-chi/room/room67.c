inherit ROOM;
void create() {
	set( "short", "gk eq-helmet" );
	set( "owner", "cong" );
	set( "light_up", 1 );
	set( "object", ([
		"amount5"  : 1,
		"amount6"  : 1,
		"amount7"  : 1,
		"file3"    : "/open/magic-manor/obj/master_snake_head",
		"amount3"  : 1,
		"file7"    : "/open/mogi/dragon/obj/dragon-head",
		"amount4"  : 1,
		"file4"    : "/open/magic-manor/obj/master_snake_head",
		"file2"    : "/open/magic-manor/obj/master_snake_head",
		"file6"    : "/open/magic-manor/obj/master_snake_head",
		"amount2"  : 1,
		"file5"    : "/open/magic-manor/obj/master_snake_head",
	]) );
	set( "build", 10194 );
	set( "exits", ([
		"west"      : "/open/clan/sky-wu-chi/room/room97",
		"east"      : "/open/clan/sky-wu-chi/room/room217.c",
		"north"     : "/open/clan/sky-wu-chi/room/room94.c",
		"south"     : "/open/clan/sky-wu-chi/room/room95.c",
	]) );
	set( "long", @LONG

         十年生死兩茫茫，
   
         不思量，自難忘。

         千里孤墳，無處話淒涼。

         縱使相逢應不識，
   
         塵滿面，鬢如霜。

         夜來幽夢忽還鄉，
 
         小軒窗，正梳妝，

         相顧無言，唯有淚千行。

         料得年年腸斷處，

         明月夜，短松崗。


LONG);
	setup();
	replace_program(ROOM);
}
