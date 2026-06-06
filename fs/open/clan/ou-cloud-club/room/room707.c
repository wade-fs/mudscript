inherit ROOM;
void create() {
	set( "short", "$HIR$焚天魔王的人頭$NOR$" );
	set( "object", ([
		"amount2"  : 1,
		"amount8"  : 1,
		"amount6"  : 1,
		"file8"    : "/open/mogi/castle/obj/fire-king-head",
		"amount9"  : 1,
		"amount7"  : 1,
		"file3"    : "/open/mogi/castle/obj/fire-king-head",
		"file9"    : "/open/mogi/castle/obj/fire-king-head",
		"file1"    : "/open/mogi/castle/obj/fire-king-head",
		"file5"    : "/open/mogi/castle/obj/fire-king-head",
		"amount1"  : 1,
		"file6"    : "/open/mogi/castle/obj/fire-king-head",
		"file2"    : "/open/mogi/castle/obj/fire-king-head",
		"file4"    : "/open/mogi/castle/obj/fire-king-head",
		"amount3"  : 1,
		"file7"    : "/open/mogi/castle/obj/fire-king-head",
		"amount4"  : 1,
		"amount5"  : 1,
	]) );
	set( "build", 10537 );
	set( "exits", ([
		"west"      : "/open/clan/ou-cloud-club/room/room708",
		"north"     : "/open/clan/ou-cloud-club/room/room703.c",
	]) );
	set( "light_up", 1 );
	set( "long", @LONG

   ( $HIY$1$NOR$) $HIR$焚天魔王的人頭$NOR$
   ( $HIY$2$NOR$) $HIR$焚天魔王的人頭$NOR$
   ( $HIY$3$NOR$) $HIR$焚天魔王的人頭$NOR$
   ( $HIY$4$NOR$) $HIR$焚天魔王的人頭$NOR$
   ( $HIY$5$NOR$) $HIR$焚天魔王的人頭$NOR$
   ( $HIY$6$NOR$) $HIR$焚天魔王的人頭$NOR$
   ( $HIY$7$NOR$) $HIR$焚天魔王的人頭$NOR$
   ( $HIY$8$NOR$) $HIR$焚天魔王的人頭$NOR$
   ( $HIY$9$NOR$) $HIR$焚天魔王的人頭$NOR$
   ($HIY$10$NOR$) $HIR$焚天魔王的人頭$NOR$
    
LONG);
	setup();
	replace_program(ROOM);
}
